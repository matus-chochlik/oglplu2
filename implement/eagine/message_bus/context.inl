/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::context(logger& parent)
  : _log{EAGINE_ID(MsgBusCtxt), parent} {

    if(ok make_result{_ssl.new_x509_store()}) {
        _ssl_store = std::move(make_result.get());
    } else {
        _log.error("failed to create certificate store: ${reason}")
          .arg(EAGINE_ID(reason), (!make_result).message());
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::context(logger& parent, const program_args& args)
  : context{parent} {
    std::string temp;
    for(auto arg = args.first(); arg; arg = arg.next()) {
        if(arg.is_tag("--msg-bus-ssl-engine")) {
            if(arg.next().parse(temp, _log.error_stream())) {
                _ssl.load_builtin_engines();

                if(ok open_result{_ssl.open_engine(temp)}) {
                    _ssl_engine = std::move(open_result.get());
                    if(ok init_result{_ssl.init_engine(_ssl_engine)}) {
                        _log.info("successfully loaded ssl engine ${name}")
                          .arg(EAGINE_ID(name), temp);
                    } else {
                        _log
                          .error("failed to init ssl engine ${name}: ${reason}")
                          .arg(EAGINE_ID(name), temp)
                          .arg(EAGINE_ID(reason), (!init_result).message());
                    }
                } else {
                    _log.error("failed to load ssl engine ${name}: ${reason}")
                      .arg(EAGINE_ID(name), temp)
                      .arg(EAGINE_ID(reason), (!open_result).message());
                }
                arg = arg.next();
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::~context() noexcept {
    if(_ssl_engine) {
        _ssl.finish_engine(_ssl_engine);
        _ssl.delete_engine(_ssl_engine);
    }

    if(_ssl_store) {
        _ssl.delete_x509_store(_ssl_store);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
message_sequence_t context::next_sequence_no(
  identifier_t class_id, identifier_t method_id) noexcept {

    auto [pos, newone] =
      _msg_id_seq.try_emplace(std::make_tuple(class_id, method_id));

    if(newone) {
        std::get<1>(*pos) = 0U;
        _log.debug("creating sequence for message type ${message}")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    }
    return std::get<1>(*pos)++;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<context> make_context(logger& parent) {
    return std::make_unique<context>(parent);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC std::unique_ptr<context> make_context(
  logger& parent, const program_args& args) {
    return std::make_unique<context>(parent, args);
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine
