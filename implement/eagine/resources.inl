/**
 *  @file eagine/resources.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application_config.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/logging/type/program_args.hpp>
#include <eagine/memory/buffer.hpp>
#include <eagine/memory/span_algo.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto fetch_resource(
  string_view description,
  string_view key,
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) -> memory::const_block {

    if(const auto res_path{cfg.get<std::string>(key)}) {
        if(const auto contents{file_contents(extract(res_path))}) {
            const auto blk = contents.block();
            buf.resize(blk.size());
            copy(blk, cover(buf));

            log.debug("using ${resource} from file ${path}")
              .arg(EAGINE_ID(resource), description)
              .arg(EAGINE_ID(key), key)
              .arg(EAGINE_ID(path), EAGINE_ID(FsPath), extract(res_path));
            log.trace("${resource} content:")
              .arg(EAGINE_ID(resource), description)
              .arg(EAGINE_ID(blob), view(buf));
            return view(buf);
        } else {
            log.error("failed to load ${resource} from file ${path}")
              .arg(EAGINE_ID(resource), description)
              .arg(EAGINE_ID(key), key)
              .arg(EAGINE_ID(path), EAGINE_ID(FsPath), extract(res_path));
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
auto ca_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) -> memory::const_block {
    return fetch_resource(
      string_view{"CA certificate"},
      string_view{"ca_cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
} // namespace eagine
