/**
 *  @file eagine/resources.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/environment.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/logging/program_args.hpp>
#include <eagine/memory/buffer.hpp>
#include <eagine/memory/span_algo.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block fetch_resource(
  string_view description,
  string_view env_var_name,
  string_view prog_arg_name,
  memory::const_block embedded_blk,
  memory::buffer& buf,
  const program_args& args,
  logger& log) {

    if(const auto path_var{get_environment_variable(env_var_name)}) {
        if(const auto contents = file_contents(extract(path_var))) {
            const auto blk = contents.block();
            buf.resize(blk.size());
            copy(blk, cover(buf));

            log.debug("using ${resource} from file ${path}")
              .arg(EAGINE_ID(resource), description)
              .arg(EAGINE_ID(variable), EAGINE_ID(EnviVarble), env_var_name)
              .arg(EAGINE_ID(path), EAGINE_ID(FsPath), extract(path_var));
            log.trace("${resource} content:")
              .arg(EAGINE_ID(resource), description)
              .arg(EAGINE_ID(blob), view(buf));
            return view(buf);
        } else {
            log.error("failed to load ${resource} from file ${path}")
              .arg(EAGINE_ID(resource), description)
              .arg(EAGINE_ID(variable), EAGINE_ID(EnviVarble), env_var_name)
              .arg(EAGINE_ID(path), EAGINE_ID(FsPath), extract(path_var));
        }
    } else if(const auto tag_arg{args.find(prog_arg_name)}) {
        if(const auto path_arg{tag_arg.next()}) {
            if(const auto contents{file_contents(path_arg)}) {
                const auto blk = contents.block();
                buf.resize(blk.size());
                copy(blk, cover(buf));

                log.debug("using ${resource} loaded from ${path}")
                  .arg(EAGINE_ID(resource), description)
                  .arg(EAGINE_ID(option), tag_arg)
                  .arg(EAGINE_ID(path), EAGINE_ID(FsPath), extract(path_arg));
                log.trace("${resource} content:")
                  .arg(EAGINE_ID(resource), description)
                  .arg(EAGINE_ID(blob), view(buf));
                return view(buf);
            } else {
                log.error("failed to load ${resource} from ${path}")
                  .arg(EAGINE_ID(resource), description)
                  .arg(EAGINE_ID(option), tag_arg)
                  .arg(EAGINE_ID(path), EAGINE_ID(FsPath), extract(path_arg));
            }
        } else {
            log.error("missing path argument after ${option}")
              .arg(EAGINE_ID(option), tag_arg);
        }
    } else if(embedded_blk) {
        log.debug("using embedded ${resource}")
          .arg(EAGINE_ID(resource), description);
        log.trace("${resource} content:")
          .arg(EAGINE_ID(resource), description)
          .arg(EAGINE_ID(blob), embedded_blk);
        return embedded_blk;
    }

    log.warning("could not fetch ${resource}")
      .arg(EAGINE_ID(resource), description);
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block ca_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  const program_args& args,
  logger& log) {
    return fetch_resource(
      string_view{"CA certificate"},
      string_view{"EAGINE_CA_CERT_PATH"},
      string_view{"--ca-cert-path"},
      embedded_blk,
      buf,
      args,
      log);
}
//------------------------------------------------------------------------------
} // namespace eagine

