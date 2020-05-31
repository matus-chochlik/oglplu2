/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/copy.hpp>

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
    if(_ca_cert) {
        _ssl.delete_x509(_ca_cert);
    }

    if(_node_cert) {
        _ssl.delete_x509(_node_cert);
    }

    if(_ssl_store) {
        _ssl.delete_x509_store(_ssl_store);
    }

    if(_ssl_engine) {
        _ssl.finish_engine(_ssl_engine);
        _ssl.delete_engine(_ssl_engine);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
message_sequence_t context::next_sequence_no(
  identifier_t class_id, identifier_t method_id) noexcept {

    auto [pos, newone] =
      _msg_id_seq.try_emplace(message_id_tuple{class_id, method_id});

    if(newone) {
        std::get<1>(*pos) = 0U;
        _log.debug("creating sequence for message type ${message}")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    }
    return std::get<1>(*pos)++;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::verify_node_certificate() {
    if(ok vrfy_ctx{_ssl.new_x509_store_ctx()}) {
        auto del_vrfy{_ssl.delete_x509_store_ctx.raii(vrfy_ctx)};

        if(_ssl.init_x509_store_ctx(vrfy_ctx, _ssl_store, _node_cert)) {
            if(ok verify_res{_ssl.x509_verify_certificate(vrfy_ctx)}) {
                return verify_res.get();
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::add_node_certificate_pem(memory::const_block blk) {
    if(blk) {
        if(ok cert{_ssl.parse_x509(blk, {})}) {
            if(_node_cert) {
                _ssl.delete_x509(_node_cert);
            }
            _node_cert = std::move(cert.get());
            memory::copy_into(blk, _node_cert_pem);
            return verify_node_certificate();
        } else {
            _log.error("failed to parse x509 node certificate from pem")
              .arg(EAGINE_ID(reason), (!cert).message())
              .arg(EAGINE_ID(pem), blk);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::add_ca_certificate_pem(memory::const_block blk) {
    if(blk) {
        if(ok cert{_ssl.parse_x509(blk, {})}) {
            if(_ssl.add_cert_into_x509_store(_ssl_store, cert)) {
                if(_ca_cert) {
                    _ssl.delete_x509(_ca_cert);
                }
                _ca_cert = std::move(cert.get());
                memory::copy_into(blk, _ca_cert_pem);
                return verify_node_certificate();
            } else {
                _log.error("failed to add x509 CA certificate to store")
                  .arg(EAGINE_ID(reason), (!cert).message())
                  .arg(EAGINE_ID(pem), blk);
            }
        } else {
            _log.error("failed to parse x509 CA certificate from pem")
              .arg(EAGINE_ID(reason), (!cert).message())
              .arg(EAGINE_ID(pem), blk);
        }
    }
    return false;
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
