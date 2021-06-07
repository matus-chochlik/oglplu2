/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// endpoint
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_uptime_seconds() -> std::int64_t {
    return std::chrono::duration_cast<std::chrono::seconds>(
             std::chrono::steady_clock::now() - _startup_time)
      .count();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_process_blobs() -> work_done {
    some_true something_done;
    something_done(_blobs.update(EAGINE_THIS_MEM_FUNC_REF(post)));
    const auto opt_max_size = max_data_size();
    if(EAGINE_LIKELY(opt_max_size)) {
        something_done(_blobs.process_outgoing(
          EAGINE_THIS_MEM_FUNC_REF(post), extract(opt_max_size)));
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_do_send(message_id msg_id, message_view message) -> bool {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_endpoint_id);
    if(EAGINE_LIKELY(_connection && _connection->send(msg_id, message))) {
        ++_stats.sent_messages;
        if(EAGINE_UNLIKELY(!_had_working_connection)) {
            _had_working_connection = true;
            connection_established(has_id());
        }
        log_trace("sending message ${message}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);
        return true;
    } else {
        if(_had_working_connection) {
            _had_working_connection = false;
            connection_lost();
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
            ++_stats.dropped_messages;
            log_warning("received own special message ${message}")
              .arg(EAGINE_ID(message), msg_id);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(blobFrgmnt))) {
            if(_blobs.process_incoming(message)) {
                _blobs.fetch_all(_store_handler);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(blobResend))) {
            _blobs.process_resend(message);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(assignId))) {
            if(!has_id()) {
                _endpoint_id = message.target_id;
                id_assigned(_endpoint_id);
                log_debug("assigned endpoint id ${id} by router")
                  .arg(EAGINE_ID(id), get_id());
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(confirmId))) {
            if(!has_id()) {
                _endpoint_id = message.target_id;
                if(EAGINE_LIKELY(get_id() == get_preconfigured_id())) {
                    id_assigned(_endpoint_id);
                    log_debug("confirmed endpoint id ${id} by router")
                      .arg(EAGINE_ID(id), get_id());
                    // send request for router certificate
                    post(EAGINE_MSGBUS_ID(rtrCertQry), {});
                } else {
                    log_error("mismatching preconfigured and confirmed ids")
                      .arg(EAGINE_ID(confirmed), get_id())
                      .arg(EAGINE_ID(preconfed), get_preconfigured_id());
                }
            }
            return true;
        } else if(
          msg_id.has_method(EAGINE_ID(ping)) ||
          msg_id.has_method(EAGINE_ID(pong)) ||
          msg_id.has_method(EAGINE_ID(subscribTo)) ||
          msg_id.has_method(EAGINE_ID(unsubFrom)) ||
          msg_id.has_method(EAGINE_ID(notSubTo)) ||
          msg_id.has_method(EAGINE_ID(qrySubscrp)) ||
          msg_id.has_method(EAGINE_ID(qrySubscrb))) {
            return false;
        } else if(msg_id.has_method(EAGINE_ID(msgFlowInf))) {
            default_deserialize(_flow_info, message.content());
            log_debug("changes in message flow information")
              .arg(EAGINE_ID(avgMsgAge), flow_average_message_age());
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptCertQry))) {
            post_certificate(message.source_id, message.sequence_no);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            log_trace("received remote endpoint certificate")
              .arg(EAGINE_ID(source), message.source_id)
              .arg(EAGINE_ID(pem), message.content());

            if(_context->add_remote_certificate_pem(
                 message.source_id, message.content())) {
                log_debug("verified and stored remote endpoint certificate")
                  .arg(EAGINE_ID(endpoint), _endpoint_id)
                  .arg(EAGINE_ID(source), message.source_id);

                if(auto nonce{_context->get_remote_nonce(message.source_id)}) {
                    post_blob(
                      EAGINE_MSGBUS_ID(eptSigNnce),
                      message.source_id,
                      message.sequence_no,
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
            if(auto signature{_context->get_own_signature(message.content())}) {
                post_blob(
                  EAGINE_MSGBUS_ID(eptNnceSig),
                  message.source_id,
                  message.sequence_no,
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
                 message.content(), message.source_id)) {
                log_debug("verified nonce signature")
                  .arg(EAGINE_ID(endpoint), _endpoint_id)
                  .arg(EAGINE_ID(source), message.source_id);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(rtrCertPem))) {
            log_trace("received router certificate")
              .arg(EAGINE_ID(pem), message.content());

            if(_context->add_router_certificate_pem(message.content())) {
                log_debug("verified and stored router certificate");
            }
            return true;
        } else if(
          msg_id.has_method(EAGINE_ID(byeByeEndp)) ||
          msg_id.has_method(EAGINE_ID(byeByeRutr)) ||
          msg_id.has_method(EAGINE_ID(byeByeBrdg)) ||
          msg_id.has_method(EAGINE_ID(stillAlive)) ||
          msg_id.has_method(EAGINE_ID(topoRutrCn)) ||
          msg_id.has_method(EAGINE_ID(topoBrdgCn)) ||
          msg_id.has_method(EAGINE_ID(topoEndpt))) {
            return false;
        } else if(msg_id.has_method(EAGINE_ID(topoQuery))) {
            endpoint_topology_info info{};
            info.endpoint_id = _endpoint_id;
            info.instance_id = _instance_id;
            auto temp{default_serialize_buffer_for(info)};
            if(auto serialized{default_serialize(info, cover(temp))}) {
                message_view response{extract(serialized)};
                response.setup_response(message);
                if(post(EAGINE_MSGBUS_ID(topoEndpt), response)) {
                    return true;
                }
            }
            log_warning("failed to respond to topology query from ${source}")
              .arg(EAGINE_ID(bufSize), temp.size())
              .arg(EAGINE_ID(source), message.source_id);
        } else if(msg_id.has_method(EAGINE_ID(statsQuery))) {
            _stats.sent_messages = _stats.sent_messages;
            _stats.uptime_seconds = _uptime_seconds();

            auto temp{default_serialize_buffer_for(_stats)};
            if(auto serialized{default_serialize(_stats, cover(temp))}) {
                message_view response{extract(serialized)};
                response.setup_response(message);
                if(post(EAGINE_MSGBUS_ID(statsEndpt), response)) {
                    return true;
                }
            }
            log_warning("failed to respond to statistics query from ${source}")
              .arg(EAGINE_ID(bufSize), temp.size())
              .arg(EAGINE_ID(source), message.source_id);
        }
        log_warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data());
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::_store_message(
  message_id msg_id,
  message_age msg_age,
  const message_view& message) -> bool {
    ++_stats.received_messages;
    if(!_handle_special(msg_id, message)) {
        if((message.target_id == _endpoint_id) || !is_valid_id(message.target_id)) {
            if(auto found{_find_incoming(msg_id)}) {
                log_trace("stored message ${message}")
                  .arg(EAGINE_ID(message), msg_id);
                extract(found).queue.push(message).add_age(msg_age);
            } else {
                auto& state = _ensure_incoming(msg_id);
                EAGINE_ASSERT(state.subscription_count == 0);
                log_debug("storing new type of message ${message}")
                  .arg(EAGINE_ID(message), msg_id);
                state.queue.push(message).add_age(msg_age);
            }
        } else {
            ++_stats.dropped_messages;
            log_warning("trying to store message for target ${target}")
              .arg(EAGINE_ID(self), _endpoint_id)
              .arg(EAGINE_ID(target), message.target_id)
              .arg(EAGINE_ID(message), msg_id);
            say_not_a_router();
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
    if(auto found{_find_incoming(msg_id)}) {
        if((message.target_id == _endpoint_id) || !is_valid_id(message.target_id)) {
            log_trace("accepted message ${message}")
              .arg(EAGINE_ID(message), msg_id);
            extract(found).queue.push(message);
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
        log_debug("flushing outbox (size: ${count})")
          .arg(EAGINE_ID(count), _outgoing.count());

        _outgoing.fetch_all(EAGINE_THIS_MEM_FUNC_REF(_handle_send));

        if(EAGINE_LIKELY(_connection)) {
            _connection->update();
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
            message_id& dst_msg_id,
            message_timestamp&,
            stored_message& message) {
              message.assign(msg_view);
              if(message.store_and_sign(
                   msg_view.content(), max_size, ctx(), *this)) {
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
auto endpoint::update() -> work_done {
    some_true something_done{};

    something_done(_process_blobs());

    if(EAGINE_UNLIKELY(!_connection)) {
        log_warning("endpoint has no connection");
    }

    const bool had_id = has_id();
    if(EAGINE_LIKELY(_connection)) {
        if(EAGINE_UNLIKELY(!_had_working_connection)) {
            _had_working_connection = true;
            connection_established(had_id);
        }
        if(EAGINE_UNLIKELY(!had_id && _no_id_timeout)) {
            if(!has_preconfigured_id()) {
                log_debug("requesting endpoint id");
                _connection->send(EAGINE_MSGBUS_ID(requestId), {});
                ++_stats.sent_messages;
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
                    ++_stats.sent_messages;
                    _no_id_timeout.reset();
                    something_done();
                }
            }
        }
    }

    if(_should_notify_alive) {
        say_still_alive();
    }

    // if we have a valid id and we have messages in outbox
    if(EAGINE_UNLIKELY(has_id() && !_outgoing.empty())) {
        log_debug("sending ${count} messages from outbox")
          .arg(EAGINE_ID(count), _outgoing.count());
        something_done(
          _outgoing.fetch_all(EAGINE_THIS_MEM_FUNC_REF(_handle_send)));
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::subscribe(message_id msg_id) {
    auto& state = _ensure_incoming(msg_id);
    if(!state.subscription_count) {
        log_debug("subscribing to message ${message}")
          .arg(EAGINE_ID(message), msg_id);
    }
    ++state.subscription_count;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::unsubscribe(message_id msg_id) {
    auto pos = _incoming.find(msg_id);
    if(pos != _incoming.end()) {
        EAGINE_ASSERT(pos->second);
        auto& state = *pos->second;
        if(--state.subscription_count <= 0) {
            _incoming.erase(pos);
            log_debug("unsubscribing from message ${message}")
              .arg(EAGINE_ID(message), msg_id);
        }
    }
}
//------------------------------------------------------------------------------
auto endpoint::say_not_a_router() -> bool {
    log_debug("saying not a router");
    return post(EAGINE_MSGBUS_ID(notARouter), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::say_still_alive() -> bool {
    log_trace("saying still alive");
    message_view msg{};
    msg.set_sequence_no(_instance_id);
    return post(EAGINE_MSGBUS_ID(stillAlive), msg);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::say_bye() -> bool {
    log_debug("saying bye-bye");
    return post(EAGINE_MSGBUS_ID(byeByeEndp), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::post_meta_message(message_id meta_msg_id, message_id msg_id) {
    auto temp{default_serialize_buffer_for(msg_id)};
    if(auto serialized{default_serialize_message_type(msg_id, cover(temp))}) {
        message_view meta_msg{extract(serialized)};
        meta_msg.set_sequence_no(_instance_id);
        post(meta_msg_id, meta_msg);
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
    auto temp{default_serialize_buffer_for(msg_id)};
    if(auto serialized{default_serialize_message_type(msg_id, cover(temp))}) {
        message_view meta_msg{extract(serialized)};
        meta_msg.set_target_id(target_id);
        meta_msg.set_sequence_no(_instance_id);
        post(meta_msg_id, meta_msg);
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
void endpoint::query_subscriptions_of(identifier_t target_id) {
    log_debug("querying subscribed messages of endpoint ${target}")
      .arg(EAGINE_ID(target), target_id);
    message_view msg{};
    msg.set_target_id(target_id);
    post(EAGINE_MSGBUS_ID(qrySubscrp), msg);
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
auto endpoint::post_certificate(identifier_t target_id, blob_id_t target_blob_id)
  -> bool {
    EAGINE_ASSERT(_context);
    if(auto cert_pem{_context->get_own_certificate_pem()}) {
        return post_blob(
          EAGINE_MSGBUS_ID(eptCertPem),
          target_id,
          target_blob_id,
          cert_pem,
          adjusted_duration(std::chrono::seconds{30}),
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
          adjusted_duration(std::chrono::seconds{30}),
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
    if(auto found{_find_incoming(msg_id)}) {
        const message_context msg_ctx{*this, msg_id};
        return extract(found).queue.process_one(msg_ctx, handler);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::process_all(message_id msg_id, method_handler handler)
  -> span_size_t {
    if(auto found{_find_incoming(msg_id)}) {
        const message_context msg_ctx{*this, msg_id};
        return extract(found).queue.process_all(msg_ctx, handler);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint::process_everything(method_handler handler) -> span_size_t {
    span_size_t result = 0;

    for(auto& [msg_id, state] : _incoming) {
        const message_context msg_ctx{*this, msg_id};
        result += extract(state).queue.process_all(msg_ctx, handler);
    }
    return result;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
