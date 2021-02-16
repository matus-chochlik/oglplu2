/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/compression.hpp>
#include <eagine/main_ctx_object.hpp>
#include <eagine/memory/buffer.hpp>
#include <eagine/span.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace eagine::application {
//------------------------------------------------------------------------------
class raw_framedump
  : public main_ctx_object
  , public framedump {
public:
    raw_framedump(main_ctx_parent parent)
      : main_ctx_object(EAGINE_ID(RawFrmDump), parent) {}

    auto initialize(execution_context&, const video_options&) -> bool final;

    auto get_buffer(span_size_t size) -> memory::block final;

    auto dump_frame(
      long frame_number,
      int width,
      int height,
      int elements,
      span_size_t element_size,
      framedump_pixel_format,
      framedump_data_type,
      memory::block data) -> bool final;

private:
    auto _write_to_file(const std::string&, memory::const_block) -> bool;

    string_view _prefix;
    std::string _feedback;
    memory::buffer _pixeldata;
    memory::buffer _compressed;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto raw_framedump::initialize(execution_context&, const video_options& opts)
  -> bool {
    _prefix = opts.framedump_prefix();
    log_info("frame dump prefix: ${prefix}")
      .arg(EAGINE_ID(prefix), EAGINE_ID(FsPath), _prefix);
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto raw_framedump::get_buffer(span_size_t size) -> memory::block {
    return head(cover(_pixeldata.ensure(size)), size);
}
//------------------------------------------------------------------------------
inline auto
raw_framedump::_write_to_file(const std::string& path, memory::const_block data)
  -> bool {
    std::ofstream out{path};
    if(!write_to_stream(out, data).flush().good()) {
        return false;
    }
    std::cout << path << std::endl << std::flush;
    return std::getline(std::cin, _feedback).good() && (_feedback == path);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto raw_framedump::dump_frame(
  long frame_number,
  int width,
  int height,
  int elements,
  span_size_t element_size,
  framedump_pixel_format format,
  framedump_data_type type,
  memory::block data) -> bool {
    EAGINE_MAYBE_UNUSED(element_size);
    EAGINE_MAYBE_UNUSED(data);

    std::stringstream path;
    path << _prefix << '-' << width << 'x' << height << 'x' << elements << '-'
         << enumerator_name(
              format, type_identity<framedump_pixel_format>(), value_tree_tag())
         << '-'
         << enumerator_name(
              type, type_identity<framedump_data_type>(), value_tree_tag())
         << '-' << std::setfill('0') << std::setw(6) << frame_number;

    if(auto packed{main_context().compressor().compress(
         data, _compressed, data_compression_level::highest)}) {
        path << ".zlib";
        return _write_to_file(path.str(), skip(packed, 1));
    }
    return _write_to_file(path.str(), data);
}
//------------------------------------------------------------------------------
auto make_raw_framedump(main_ctx_parent parent) -> std::shared_ptr<framedump> {
    return std::make_shared<raw_framedump>(parent);
}
//------------------------------------------------------------------------------
} // namespace eagine::application

