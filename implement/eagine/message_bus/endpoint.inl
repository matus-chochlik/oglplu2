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
bool endpoint::_cleanup_blobs() {
    return _blobs.cleanup();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_process_blobs() {
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
bool endpoint::_do_allow_blob(message_id msg_id) {
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
bool endpoint::_do_send(message_id msg_id, message_view message) {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_id);
    for(auto& conn : _connections) {
        EAGINE_ASSERT(conn);
        if(conn->send(msg_id, message)) {
            log()
              .trace("sending message ${message}")
              .arg(EAGINE_ID(message), msg_id);
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_handle_special(
  message_id msg_id, const message_view& message) noexcept {

    EAGINE_ASSERT(_context);
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        log()
          .debug("handling special message ${message}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(endpoint), _id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(EAGINE_UNLIKELY(has_id() && (message.source_id == _id))) {
            log()
              .warning("received own special message ${message}")
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
                _id = message.target_id;
                log()
                  .debug("assigned endpoint id ${id}")
                  .arg(EAGINE_ID(id), _id);
            }
            return true;
        } else if(
          msg_id.has_method(EAGINE_ID(subscribTo)) ||
          msg_id.has_method(EAGINE_ID(unsubFrom)) ||
          msg_id.has_method(EAGINE_ID(qrySubscrb))) {
            return false;
        } else if(msg_id.has_method(EAGINE_ID(eptCertQry))) {
            post_certificate(message.source_id);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            _log.trace("received remote endpoint certificate")
              .arg(EAGINE_ID(source), message.source_id)
              .arg(EAGINE_ID(pem), message.data);

            if(_context->add_remote_certificate_pem(
                 message.source_id, view(message.data))) {
                _log.debug("verified and stored remote endpoint certificate")
                  .arg(EAGINE_ID(endpoint), _id)
                  .arg(EAGINE_ID(source), message.source_id);

                if(auto nonce{_context->get_remote_nonce(message.source_id)}) {
                    post_blob(
                      EAGINE_MSGBUS_ID(eptSigNnce),
                      message.source_id,
                      nonce,
                      std::chrono::seconds(30),
                      message_priority::normal);
                    _log.debug("sending nonce sign request")
                      .arg(EAGINE_ID(endpoint), _id)
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
                _log.debug("sending nonce signature")
                  .arg(EAGINE_ID(endpoint), _id)
                  .arg(EAGINE_ID(target), message.source_id);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptNnceSig))) {
            if(_context->verify_remote_signature(
                 message.data, message.source_id)) {
                _log.debug("verified nonce signature")
                  .arg(EAGINE_ID(endpoint), _id)
                  .arg(EAGINE_ID(source), message.source_id);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(rtrCertPem))) {
            _log.trace("received router certificate")
              .arg(EAGINE_ID(pem), message.data);

            if(_context->add_router_certificate_pem(view(message.data))) {
                _log.debug("verified and stored router certificate");
            }
            return true;
        } else if(
          msg_id.has_method(EAGINE_ID(topoRoutCn)) ||
          msg_id.has_method(EAGINE_ID(topoBrdgCn)) ||
          msg_id.has_method(EAGINE_ID(topoEndpt))) {
            return false;
        } else if(msg_id.has_method(EAGINE_ID(topoQuery))) {
            // TODO: additional info?
            return respond_to(message, EAGINE_MSGBUS_ID(topoEndpt));
        }
        _log.warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_store_message(
  message_id msg_id, message_age, const message_view& message) {
    // TODO: use message age
    if(_handle_special(msg_id, message)) {
        return true;
    } else {
        if((message.target_id == _id) || !is_valid_id(message.target_id)) {
            auto pos = _incoming.find(msg_id);
            if(pos != _incoming.end()) {
                log()
                  .trace("stored message ${message}")
                  .arg(EAGINE_ID(message), msg_id);
                _get_queue(*pos).push(message);
                return true;
            } else if(_allow_blob && _allow_blob(msg_id)) {
                auto [newpos, newone] = _incoming.try_emplace(msg_id);
                EAGINE_MAYBE_UNUSED(newone);
                EAGINE_ASSERT(newone);
                _get_counter(*newpos) = 0;
                log()
                  .debug("storing new type of message ${message}")
                  .arg(EAGINE_ID(message), msg_id);
                _get_queue(*newpos).push(message);
                return true;
            }
        } else {
            log()
              .warning("trying to store message for target ${target}")
              .arg(EAGINE_ID(target), message.target_id)
              .arg(EAGINE_ID(message), msg_id);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_accept_message(message_id msg_id, const message_view& message) {
    if(_handle_special(msg_id, message)) {
        return true;
    }
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        if((message.target_id == _id) || !is_valid_id(message.target_id)) {
            log()
              .trace("accepted message ${message}")
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
bool endpoint::add_connection(std::unique_ptr<connection> conn) {
    if(conn) {
        log()
          .debug("adding connection type ${type}")
          .arg(EAGINE_ID(type), conn->type_id());
        _connections.emplace_back(std::move(conn));
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::is_usable() const {
    for(auto& conn : _connections) {
        EAGINE_ASSERT(conn);
        if(conn->is_usable()) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_positive<span_size_t> endpoint::max_data_size() const {
    span_size_t result{0};
    for(auto& conn : _connections) {
        EAGINE_ASSERT(conn);
        if(conn->is_usable()) {
            if(const auto opt_max_size = conn->max_data_size()) {
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
        log()
          .debug("flushing outbox (size: ${size})")
          .arg(EAGINE_ID(size), _outgoing.size());
        _outgoing.fetch_all(message_storage::fetch_handler{
          this, EAGINE_MEM_FUNC_C(endpoint, _handle_send)});
        for(auto& conn : _connections) {
            EAGINE_ASSERT(conn);
            conn->cleanup();
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::set_next_sequence_id(message_id msg_id, message_info& message) {
    EAGINE_ASSERT(_context);
    message.set_sequence_no(_context->next_sequence_no(msg_id));
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::post_signed(message_id msg_id, message_view msg_view) {
    if(const auto opt_size = max_data_size()) {
        const auto max_size = extract(opt_size);
        return _outgoing.push_if(
          [this, msg_id, &msg_view, max_size](
            message_id& dst_msg_id, stored_message& message) {
              message.assign(msg_view);
              if(message.store_and_sign(
                   msg_view.data, max_size, ctx(), log())) {
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
bool endpoint::update() {
    some_true something_done{};

    something_done(_cleanup_blobs());
    something_done(_process_blobs());

    if(EAGINE_UNLIKELY(_connections.empty())) {
        log().warning("endpoint has no connections");
    }

    const bool had_id = has_id();
    for(auto& conn : _connections) {
        EAGINE_ASSERT(conn);
        if(EAGINE_UNLIKELY(!had_id && _no_id_timeout)) {
            log().debug("requesting endpoint id");
            conn->send(EAGINE_MSGBUS_ID(requestId), {});
            _no_id_timeout.reset();
            something_done();
        }
        something_done(conn->update());
        something_done(conn->fetch_messages(_store_handler));
    }

    // if processing the messages assigned the endpoint id
    if(EAGINE_UNLIKELY(has_id() && !had_id)) {
        log().debug("announcing endpoint id ${id}").arg(EAGINE_ID(id), _id);
        // send the endpoint id through all connections
        _do_send(EAGINE_MSGBUS_ID(announceId), {});
        // send request for router certificate
        _do_send(EAGINE_MSGBUS_ID(rtrCertQry), {});
        something_done();
    }

    // if we have a valid id and we have messages in outbox
    if(EAGINE_UNLIKELY(has_id() && !_outgoing.empty())) {
        log()
          .debug("sending ${count} messages from outbox")
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
        log()
          .debug("subscribing to message ${message}")
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
            log()
              .debug("unsubscribing from message ${message}")
              .arg(EAGINE_ID(message), msg_id);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::say_not_a_router() {
    log().debug("saying not a router");
    return send(EAGINE_MSGBUS_ID(notARouter));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::say_bye() {
    log().debug("saying bye-bye");
    return send(EAGINE_MSGBUS_ID(byeBye));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::post_meta_message(message_id meta_msg_id, message_id msg_id) {
    std::array<byte, 64> temp{};
    if(auto serialized = default_serialize_message_type(msg_id, cover(temp))) {
        post(meta_msg_id, message_view(extract(serialized)));
    } else {
        _log.debug("failed to serialize meta-message ${meta}")
          .arg(EAGINE_ID(meta), meta_msg_id)
          .arg(EAGINE_ID(message), msg_id);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::post_meta_message_to(
  identifier_t target_id, message_id meta_msg_id, message_id msg_id) {
    std::array<byte, 64> temp{};
    if(auto serialized = default_serialize_message_type(msg_id, cover(temp))) {
        message_view msg{extract(serialized)};
        msg.set_target_id(target_id);
        post(meta_msg_id, msg);
    } else {
        _log.debug("failed to serialize meta-message ${meta}")
          .arg(EAGINE_ID(meta), meta_msg_id)
          .arg(EAGINE_ID(target), target_id)
          .arg(EAGINE_ID(message), msg_id);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_subscribes_to(message_id msg_id) {
    log()
      .debug("announces subscription to message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(subscribTo), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_subscribes_to(identifier_t target_id, message_id msg_id) {
    log()
      .debug("announces subscription to message ${message}")
      .arg(EAGINE_ID(target), target_id)
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message_to(target_id, EAGINE_MSGBUS_ID(subscribTo), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::query_subscribers_of(message_id msg_id) {
    log()
      .debug("querying subscribers of message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(qrySubscrb), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_unsubscribes_from(message_id msg_id) {
    log()
      .debug("retracting subscription to message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(unsubFrom), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::clear_block_list() {
    log().debug("sending clear block list");
    post(EAGINE_MSGBUS_ID(clrBlkList), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::block_message_type(message_id msg_id) {
    log().debug("blocking message ${message}").arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(msgBlkList), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::clear_allow_list() {
    log().debug("sending clear allow list");
    post(EAGINE_MSGBUS_ID(clrAlwList), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::post_certificate(identifier_t target_id) {
    EAGINE_ASSERT(_context);
    if(auto cert_pem{_context->get_own_certificate_pem()}) {
        return post_blob(
          EAGINE_MSGBUS_ID(eptCertPem),
          target_id,
          cert_pem,
          std::chrono::seconds(30),
          message_priority::normal);
    }
    _log.debug("no endpoint certificate to send yet");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::broadcast_certificate() {
    EAGINE_ASSERT(_context);
    if(auto cert_pem{_context->get_own_certificate_pem()}) {
        return broadcast_blob(
          EAGINE_MSGBUS_ID(eptCertPem),
          cert_pem,
          std::chrono::seconds(30),
          message_priority::normal);
    }
    _log.debug("no endpoint certificate to broadcast yet");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::allow_message_type(message_id msg_id) {
    log().debug("allowing message ${message}").arg(EAGINE_ID(message), msg_id);
    post_meta_message(EAGINE_MSGBUS_ID(msgAlwList), msg_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::query_certificate_of(identifier_t endpoint_id) {
    log()
      .debug("querying certificate of endpoint ${endpoint}")
      .arg(EAGINE_ID(endpoint), endpoint_id);
    message_view msg{};
    msg.set_target_id(endpoint_id);
    post(EAGINE_MSGBUS_ID(eptCertQry), msg);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::process_one(message_id msg_id, method_handler handler) {
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        return _get_queue(*pos).process_one(handler);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t endpoint::process_all(message_id msg_id, method_handler handler) {
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        return _get_queue(*pos).process_all(handler);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t endpoint::process_everything(generic_handler handler) {
    span_size_t result = 0;
    for(auto& entry : _incoming) {
        auto wrapped_handler = [&entry, handler](stored_message& message) {
            return handler(std::get<0>(entry), message);
        };
        result += _get_queue(entry).do_process_all(wrapped_handler);
    }
    return result;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

