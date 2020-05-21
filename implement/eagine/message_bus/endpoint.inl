/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>

namespace eagine {
namespace msgbus {
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
          extract(opt_max_size),
          _log);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_do_send(
  identifier_t class_id, identifier_t method_id, message_view message) {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_id);
    for(auto& connection : _connections) {
        EAGINE_ASSERT(connection);
        if(connection->send(class_id, method_id, message)) {
            log()
              .trace("sending message ${message}")
              .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_handle_special(
  identifier_t class_id,
  identifier_t method_id,
  const message_view& message) noexcept {
    if(EAGINE_UNLIKELY(EAGINE_ID(eagiMsgBus).matches(class_id))) {
        if(EAGINE_ID(blobFrgmnt).matches(method_id)) {
        } else if(EAGINE_ID(assignId).matches(method_id)) {
            if(!has_id()) {
                _id = message.target_id;
                log()
                  .debug("assigned endpoint id ${id}")
                  .arg(EAGINE_ID(id), _id);
            }
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_store_message(
  identifier_t class_id, identifier_t method_id, const message_view& message) {
    if(!_handle_special(class_id, method_id, message)) {
        if((message.target_id == _id) || !is_valid_id(message.target_id)) {
            auto pos = _incoming.find(_make_key(class_id, method_id));
            if(pos != _incoming.end()) {
                log()
                  .trace("stored message ${message}")
                  .arg(
                    EAGINE_ID(message), message_id_tuple(class_id, method_id));
                _get_queue(pos).push(message);
                return true;
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::_accept_message(
  identifier_t class_id, identifier_t method_id, const message_view& message) {
    if(_handle_special(class_id, method_id, message)) {
        return true;
    }
    auto pos = _incoming.find(_make_key(class_id, method_id));
    if(pos != _incoming.end()) {
        if((message.target_id == _id) || !is_valid_id(message.target_id)) {
            log()
              .trace("accepted message ${message}")
              .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
            _get_queue(pos).push(message);
        }
        return true;
    }
    return false;
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
    for(auto& connection : _connections) {
        EAGINE_ASSERT(connection);
        if(connection->is_usable()) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_positive<span_size_t> endpoint::max_data_size() const {
    span_size_t result{0};
    for(auto& connection : _connections) {
        EAGINE_ASSERT(connection);
        if(connection->is_usable()) {
            if(const auto opt_max_size = connection->max_data_size()) {
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
        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            connection->cleanup();
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::set_next_sequence_id(
  identifier_t class_id, identifier_t method_id, message_info& message) {
    if(EAGINE_LIKELY(_context)) {
        message.set_sequence_no(
          _context->next_sequence_no(class_id, method_id));
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::update() {
    some_true something_done{};

    something_done(_cleanup_blobs());
    something_done(_process_blobs());

    const bool had_id = has_id();

    if(EAGINE_UNLIKELY(_connections.empty())) {
        log().warning("endpoint has no connections");
    }

    for(auto& connection : _connections) {
        EAGINE_ASSERT(connection);
        something_done(connection->update());
        something_done(connection->fetch_messages(_store_handler));
    }

    // if processing the messages assigned the endpoint id
    if(EAGINE_UNLIKELY(has_id() && !had_id)) {
        log().debug("announcing endpoint id ${id}").arg(EAGINE_ID(id), _id);
        // send the endpoint id through all connections
        _do_send(EAGINE_MSG_ID(eagiMsgBus, announceId), {});
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
void endpoint::subscribe(identifier_t class_id, identifier_t method_id) {
    auto key = _make_key(class_id, method_id);
    auto [pos, newone] = _incoming.try_emplace(key);
    if(newone) {
        _get_counter(pos) = 0;
        log()
          .debug("subscribing to message ${message}")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    }
    ++_get_counter(pos);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::unsubscribe(identifier_t class_id, identifier_t method_id) {
    auto pos = _incoming.find(_make_key(class_id, method_id));
    if(pos != _incoming.end()) {
        if(--_get_counter(pos) <= 0) {
            _incoming.erase(pos);
            log()
              .debug("unsubscribing from message ${message}")
              .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::say_not_a_router() {
    log().debug("saying not a router");
    return send(EAGINE_MSG_ID(eagiMsgBus, notARouter));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::say_bye() {
    log().debug("saying bye-bye");
    return send(EAGINE_MSG_ID(eagiMsgBus, byeBye));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::post_meta_message(
  identifier_t meta_class_id,
  identifier_t meta_method_id,
  identifier_t class_id,
  identifier_t method_id) {
    std::array<byte, 64> temp{};
    if(
      auto serialized =
        default_serialize_message_type(class_id, method_id, cover(temp))) {
        post(meta_class_id, meta_method_id, message_view(extract(serialized)));
    } else {
        _log.debug("failed to serialize meta-message ${meta}")
          .arg(EAGINE_ID(meta), message_id_tuple(meta_class_id, meta_method_id))
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_subscribes_to(
  identifier_t class_id, identifier_t method_id) {
    log()
      .debug("requesting subscription to message ${message}")
      .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    post_meta_message(
      EAGINE_MSG_ID(eagiMsgBus, subscribTo), class_id, method_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::say_unsubscribes_from(
  identifier_t class_id, identifier_t method_id) {
    log()
      .debug("retracting subscription to message ${message}")
      .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    post_meta_message(
      EAGINE_MSG_ID(eagiMsgBus, unsubFrom), class_id, method_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::clear_block_list() {
    log().debug("sending clear block list");
    post(EAGINE_MSG_ID(eagiMsgBus, clrBlkList), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::block_message_type(
  identifier_t class_id, identifier_t method_id) {
    log()
      .debug("blocking message ${message}")
      .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    post_meta_message(
      EAGINE_MSG_ID(eagiMsgBus, msgBlkList), class_id, method_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::clear_allow_list() {
    log().debug("sending clear allow list");
    post(EAGINE_MSG_ID(eagiMsgBus, clrAlwList), {});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void endpoint::allow_message_type(
  identifier_t class_id, identifier_t method_id) {
    log()
      .debug("allowing message ${message}")
      .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    post_meta_message(
      EAGINE_MSG_ID(eagiMsgBus, msgAlwList), class_id, method_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool endpoint::process_one(
  identifier_t class_id, identifier_t method_id, const handler_type& handler) {
    auto pos = _incoming.find(_make_key(class_id, method_id));
    if(pos != _incoming.end()) {
        return _get_queue(pos).process_one(handler);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t endpoint::process_all(
  identifier_t class_id, identifier_t method_id, const handler_type& handler) {
    auto pos = _incoming.find(_make_key(class_id, method_id));
    if(pos != _incoming.end()) {
        return _get_queue(pos).process_all(handler);
    }
    return 0;
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

