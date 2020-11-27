/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_cleanup_blobs() -> bool {
    return _blobs.cleanup();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_process_blobs() -> bool {
    const auto opt_max_size = max_data_size();
    if(EAGINE_LIKELY(opt_max_size)) {
        return _blobs.process_outgoing(
          blob_manipulator::send_handler{
            this, EAGINE_MEM_FUNC_C(endpoint, _handle_post)},
          extract(opt_max_size));
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_do_allow_blob(message_id msg_id) -> bool {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            return true;
        }
        if(msg_id.has_method(EAGINE_ID(eptSigNnce))) {
            return true;
        }
        if(msg_id.has_method(EAGINE_ID(eptNnceSig))) {
            return true;
        }
        if(msg_id.has_method(EAGINE_ID(rtrCertPem))) {
            return true;
        }
    }
    return _allow_blob && _allow_blob(msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_do_send(message_id msg_id, message_view message) -> bool {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_endpoint_id);
    if(EAGINE_LIKELY(_connection)) {
        if(_connection->send(msg_id, message)) {
            log_trace("sending message ${message}")
              .arg(EAGINE_ID(message), msg_id);
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_handle_special(
  message_id msg_id,
  const message_view& message) noexcept -> bool {

    EAGINE_ASSERT(_context);
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        log_debug("endpoint handling special message ${message}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(endpoint), _endpoint_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(EAGINE_UNLIKELY(has_id() && (message.source_id == _endpoint_id))) {
            log_warning("received own special message ${message}")
              .arg(EAGINE_ID(message), msg_id);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(blobFrgmnt))) {
            if(_blobs.process_incoming(
                 blob_manipulator::filter_function(
                   this, EAGINE_MEM_FUNC_C(endpoint, _do_allow_blob)),
                 message)) {
                _blobs.fetch_all(_store_handler);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(assignId))) {
            if(!has_id()) {
                _endpoint_id = message.target_id;
                log_debug("assigned endpoint id ${id} by router")
                  .arg(EAGINE_ID(id), get_id());
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(confirmId))) {
            if(!has_id()) {
                _endpoint_id = message.target_id;
                if(EAGINE_LIKELY(get_id() == get_preconfigured_id())) {
                    log_debug("confirmed endpoint id ${id} by router")
                      .arg(EAGINE_ID(id), get_id());
                    // send request for router certificate
                    _do_send(EAGINE_MSGBUS_ID(rtrCertQry), {});
                } else {
                    log_error("mismatching preconfigured and confirmed ids")
                      .arg(EAGINE_ID(confirmed), get_id())
                      .arg(EAGINE_ID(preconfed), get_preconfigured_id());
                }
            }
            return true;
        } else if(
          msg_id.has_method(EAGINE_ID(subscribTo)) ||
          msg_id.has_method(EAGINE_ID(unsubFrom)) ||
          msg_id.has_method(EAGINE_ID(notSubTo)) ||
          msg_id.has_method(EAGINE_ID(qrySubscrb))) {
            return false;
        } else if(msg_id.has_method(EAGINE_ID(eptCertQry))) {
            post_certificate(message.source_id);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            log_trace("received remote endpoint certificate")
              .arg(EAGINE_ID(source), message.source_id)
              .arg(EAGINE_ID(pem), message.data);

            if(_context->add_remote_certificate_pem(
                 message.source_id, view(message.data))) {
                log_debug("verified and stored remote endpoint certificate")
                  .arg(EAGINE_ID(endpoint), _endpoint_id)
                  .arg(EAGINE_ID(source), message.source_id);

                if(auto nonce{_context->get_remote_nonce(message.source_id)}) {
                    post_blob(
                      EAGINE_MSGBUS_ID(eptSigNnce),
                      message.source_id,
                      nonce,
                      std::chrono::seconds(30),
                      message_priority::normal);
                    log_debug("sending nonce sign request")
                      .arg(EAGINE_ID(endpoint), _endpoint_id)
                      .arg(EAGINE_ID(target), message.source_id);
                }
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptSigNnce))) {
            if(auto signature{_context->get_own_signature(message.data)}) {
                post_blob(
                  EAGINE_MSGBUS_ID(eptNnceSig),
                  message.source_id,
                  signature,
                  std::chrono::seconds(30),
                  message_priority::normal);
                log_debug("sending nonce signature")
                  .arg(EAGINE_ID(endpoint), _endpoint_id)
                  .arg(EAGINE_ID(target), message.source_id);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptNnceSig))) {
            if(_context->verify_remote_signature(
                 message.data, message.source_id)) {
                log_debug("verified nonce signature")
                  .arg(EAGINE_ID(endpoint), _endpoint_id)
                  .arg(EAGINE_ID(source), message.source_id);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(rtrCertPem))) {
            log_trace("received router certificate")
              .arg(EAGINE_ID(pem), message.data);

            if(_context->add_router_certificate_pem(view(message.data))) {
                log_debug("verified and stored router certificate");
            }
            return true;
        } else if(
          msg_id.has_method(EAGINE_ID(topoRutrCn)) ||
          msg_id.has_method(EAGINE_ID(topoBrdgCn)) ||
          msg_id.has_method(EAGINE_ID(topoEndpt))) {
            return false;
        } else if(msg_id.has_method(EAGINE_ID(topoQuery))) {
            std::array<byte, 256> temp{};
            endpoint_topology_info info{};
            info.endpoint_id = _endpoint_id;
            if(auto serialized{default_serialize(info, cover(temp))}) {
                message_view response{extract(serialized)};
                response.setup_response(message);
                return send(EAGINE_MSGBUS_ID(topoEndpt), response);
            }
        }
        log_warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_store_message(
  message_id msg_id,
  message_age,
  const message_view& message) -> bool {
    // TODO: use message age
    if(!_handle_special(msg_id, message)) {
        if((message.target_id == _endpoint_id) || !is_valid_id(message.target_id)) {
            auto pos = _incoming.find(msg_id);
            if(pos != _incoming.end()) {
                log_trace("stored message ${message}")
                  .arg(EAGINE_ID(message), msg_id);
                _get_queue(*pos).push(message);
            } else if(_allow_blob && _allow_blob(msg_id)) {
                auto [newpos, newone] = _incoming.try_emplace(msg_id);
                EAGINE_MAYBE_UNUSED(newone);
                EAGINE_ASSERT(newone);
                _get_counter(*newpos) = 0;
                log_debug("storing new type of message ${message}")
                  .arg(EAGINE_ID(message), msg_id);
                _get_queue(*newpos).push(message);
            }
        } else {
            log_warning("trying to store message for target ${target}")
              .arg(EAGINE_ID(self), _endpoint_id)
              .arg(EAGINE_ID(target), message.target_id)
              .arg(EAGINE_ID(message), msg_id);
            post(EAGINE_MSGBUS_ID(notARouter), {});
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_accept_message(message_id msg_id, const message_view& message)
  -> bool {
    if(_handle_special(msg_id, message)) {
        return true;
    }
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        if((message.target_id == _endpoint_id) || !is_valid_id(message.target_id)) {
            log_trace("accepted message ${message}")
              .arg(EAGINE_ID(message), msg_id);
            _get_queue(*pos).push(message);
        }
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::add_certificate_pem(memory::const_block blk) {
    EAGINE_ASSERT(_context);
    if(_context) {
        if(_context->add_own_certificate_pem(blk)) {
            broadcast_certificate();
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::add_ca_certificate_pem(memory::const_block blk) {
    EAGINE_ASSERT(_context);
    if(_context) {
        if(_context->add_ca_certificate_pem(blk)) {
            broadcast_certificate();
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::add_connection(std::unique_ptr<connection> conn) -> bool {
    if(EAGINE_LIKELY(conn)) {
        if(_connection) {
            log_debug("replacing connection type ${oldType} with ${newType}")
              .arg(EAGINE_ID(oldType), _connection->type_id())
              .arg(EAGINE_ID(newType), conn->type_id());
        } else {
            log_debug("adding connection type ${type}")
              .arg(EAGINE_ID(type), conn->type_id());
        }
        _connection = std::move(conn);
        return true;
    } else {
        log_error("assigning invalid connection");
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::is_usable() const -> bool {
    if(EAGINE_LIKELY(_connection)) {
        if(_connection->is_usable()) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::max_data_size() const -> valid_if_positive<span_size_t> {
    span_size_t result{0};
    if(EAGINE_LIKELY(_connection)) {
        if(_connection->is_usable()) {
            if(const auto opt_max_size = _connection->max_data_size()) {
                const auto max_size = extract(opt_max_size);
                if(result > 0) {
                    if(result > max_size) {
                        result = max_size;
                    }
                } else {
                    result = max_size;
                }
            }
        }
    }
    return {result};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::flush_outbox() {
    if(has_id()) {
        log_debug("flushing outbox (size: ${size})")
          .arg(EAGINE_ID(size), _outgoing.size());
        _outgoing.fetch_all(message_storage::fetch_handler{
          this, EAGINE_MEM_FUNC_C(endpoint, _handle_send)});
        if(EAGINE_LIKELY(_connection)) {
            _connection->cleanup();
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::set_next_sequence_id(message_id msg_id, message_info& message)
  -> bool {
    EAGINE_ASSERT(_context);
    message.set_sequence_no(_context->next_sequence_no(msg_id));
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::post_signed(message_id msg_id, message_view msg_view) -> bool {
    if(const auto opt_size = max_data_size()) {
        const auto max_size = extract(opt_size);
        return _outgoing.push_if(
          [this, msg_id, &msg_view, max_size](
            message_id& dst_msg_id, stored_message& message) {
              message.assign(msg_view);
              if(message.store_and_sign(
                   msg_view.data, max_size, ctx(), *this)) {
                  dst_msg_id = msg_id;
                  return true;
              }
              return false;
          },
          max_size);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::update() -> bool {
    some_true something_done{};

    something_done(_cleanup_blobs());
    something_done(_process_blobs());

    if(EAGINE_UNLIKELY(!_connection)) {
        log_warning("endpoint has no connection");
    }

    const bool had_id = has_id();
    if(EAGINE_LIKELY(_connection)) {
        if(EAGINE_UNLIKELY(!had_id && _no_id_timeout)) {
            if(!has_preconfigured_id()) {
                log_debug("requesting endpoint id");
                _connection->send(EAGINE_MSGBUS_ID(requestId), {});
                _no_id_timeout.reset();
                something_done();
            }
        }
        something_done(_connection->update());
        something_done(_connection->fetch_messages(_store_handler));
    }

    // if processing the messages assigned the endpoint id
    if(EAGINE_UNLIKELY(!had_id)) {
        if(_connection) {
            if(has_id()) {
                log_debug("announcing endpoint id ${id} assigned by router")
                  .arg(EAGINE_ID(id), get_id());
                // send the endpoint id through all connections
                _do_send(EAGINE_MSGBUS_ID(annEndptId), {});
                // send request for router certificate
                _do_send(EAGINE_MSGBUS_ID(rtrCertQry), {});
                something_done();
            } else if(has_preconfigured_id()) {
                if(_no_id_timeout) {
                    log_debug("announcing preconfigured endpoint id ${id}")
                      .arg(EAGINE_ID(id), get_preconfigured_id());
                    // send the endpoint id through all connections
                    message_view ann_in_msg{};
                    ann_in_msg.set_source_id(get_preconfigured_id());
                    _connection->send(EAGINE_MSGBUS_ID(annEndptId), ann_in_msg);
                    _no_id_timeout.reset();
                    something_done();
                }
            }
        }
    }

    // if we have a valid id and we have messages in outbox
    if(EAGINE_UNLIKELY(has_id() && !_outgoing.empty())) {
        log_debug("sending ${count} messages from outbox")
          .arg(EAGINE_ID(count), _outgoing.size());
        something_done(_outgoing.fetch_all(message_storage::fetch_handler{
          this, EAGINE_MEM_FUNC_C(endpoint, _handle_send)}));
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::subscribe(message_id msg_id) {
    auto [pos, newone] = _incoming.try_emplace(msg_id);
    if(newone) {
        _get_counter(*pos) = 0;
        log_debug("subscribing to message ${message}")
          .arg(EAGINE_ID(message), msg_id);
    }
    ++_get_counter(*pos);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::unsubscribe(message_id msg_id) {
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        if(--_get_counter(*pos) <= 0) {
            _incoming.erase(pos);
            log_debug("unsubscribing from message ${message}")
              .arg(EAGINE_ID(message), msg_id);
        }
    }
}
//------------------------------------------------------------------------------
auto endpoint::say_not_a_router() -> bool {
    log_debug("saying not a router");
    return send(EAGINE_MSGBUS_ID(notARouter));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::say_bye() -> bool {
    log_debug("saying bye-bye");
    return send(EAGINE_MSGBUS_ID(byeBye));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::post_meta_message(message_id meta_msg_id, message_id msg_id) {
    std::array<byte, 64> temp{};
    if(auto serialized = default_serialize_message_type(msg_id, cover(temp))) {
        post(meta_msg_id, message_view(extract(serialized)));
    } else {
        log_debug("failed to serialize meta-message ${meta}")
          .arg(EAGINE_ID(meta), meta_msg_id)
          .arg(EAGINE_ID(message), msg_id);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::post_meta_message_to(
  identifier_t target_id,
  message_id meta_msg_id,
  message_id msg_id) {
    std::array<byte, 64> temp{};
    if(auto serialized = default_serialize_message_type(msg_id, cover(temp))) {
        message_view msg{extract(serialized)};
        msg.set_target_id(target_id);
        post(meta_msg_id, msg);
    } else {
        log_debug("failed to serialize meta-message ${meta}")
          .arg(EAGINE_ID(meta), meta_msg_id)
          .arg(EAGINE_ID(target), target_id)
          .arg(EAGINE_ID(message), msg_id);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_subscribes_to(message_id msg_id) {
    log_debug("announces subscription to message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(subscribTo), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_subscribes_to(identifier_t target_id, message_id msg_id) {
    log_debug("announces subscription to message ${message}")
      .arg(EAGINE_ID(target), target_id)
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message_to(target_id, EAGINE_MSGBUS_ID(subscribTo), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_not_subscribed_to(identifier_t target_id, message_id msg_id) {
    log_debug("denies subscription to message ${message}")
      .arg(EAGINE_ID(target), target_id)
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message_to(target_id, EAGINE_MSGBUS_ID(notSubTo), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_unsubscribes_from(message_id msg_id) {
    log_debug("retracting subscription to message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(unsubFrom), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::query_subscribers_of(message_id msg_id) {
    log_debug("querying subscribers of message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(qrySubscrb), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::clear_block_list() {
    log_debug("sending clear block list");
    post(EAGINE_MSGBUS_ID(clrBlkList), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::block_message_type(message_id msg_id) {
    log_debug("blocking message ${message}").arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(msgBlkList), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::clear_allow_list() {
    log_debug("sending clear allow list");
    post(EAGINE_MSGBUS_ID(clrAlwList), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::allow_message_type(message_id msg_id) {
    log_debug("allowing message ${message}").arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(msgAlwList), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::post_certificate(identifier_t target_id) -> bool {
    EAGINE_ASSERT(_context);
    if(auto cert_pem{_context->get_own_certificate_pem()}) {
        return post_blob(
          EAGINE_MSGBUS_ID(eptCertPem),
          target_id,
          cert_pem,
          std::chrono::seconds(30),
          message_priority::normal);
    }
    log_debug("no endpoint certificate to send yet");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::broadcast_certificate() -> bool {
    EAGINE_ASSERT(_context);
    if(auto cert_pem{_context->get_own_certificate_pem()}) {
        return broadcast_blob(
          EAGINE_MSGBUS_ID(eptCertPem),
          cert_pem,
          std::chrono::seconds(30),
          message_priority::normal);
    }
    log_debug("no endpoint certificate to broadcast yet");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::query_certificate_of(identifier_t endpoint_id) {
    log_debug("querying certificate of endpoint ${endpoint}")
      .arg(EAGINE_ID(endpoint), endpoint_id);
    message_view msg{};
    msg.set_target_id(endpoint_id);
    post(EAGINE_MSGBUS_ID(eptCertQry), msg);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::process_one(message_id msg_id, method_handler handler) -> bool {
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        const message_context msg_ctx{*this, msg_id};
        return _get_queue(*pos).process_one(msg_ctx, handler);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::process_all(message_id msg_id, method_handler handler)
  -> span_size_t {
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        const message_context msg_ctx{*this, msg_id};
        return _get_queue(*pos).process_all(msg_ctx, handler);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::process_everything(method_handler handler) -> span_size_t {
    span_size_t result = 0;

    for(auto& incoming : _incoming) {
        const message_context msg_ctx{*this, std::get<0>(incoming)};
        result += _get_queue(incoming).process_all(msg_ctx, handler);
    }
    return result;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
