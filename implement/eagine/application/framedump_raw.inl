/**
 *  @file eagine/application/framedump_raw.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main_ctx_object.hpp>
#include <eagine/memory/buffer.hpp>
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

    void dump_frame(
      long frame_number,
      int width,
      int height,
      int elements,
      span_size_t element_size,
      framedump_pixel_format,
      framedump_data_type,
      memory::block data) final;

private:
    string_view _prefix;
    std::stringstream _path;
    memory::buffer _buffer;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto raw_framedump::initialize(execution_context&, const video_options& opts)
  -> bool {
    _prefix = opts.framedump_prefix();
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto raw_framedump::get_buffer(span_size_t size) -> memory::block {
    return head(cover(_buffer.ensure(size)), size);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void raw_framedump::dump_frame(
  long frame_number,
  int width,
  int height,
  int elements,
  span_size_t element_size,
  framedump_pixel_format format,
  framedump_data_type type,
  memory::block data) {
    EAGINE_MAYBE_UNUSED(elements);
    EAGINE_MAYBE_UNUSED(element_size);
    EAGINE_MAYBE_UNUSED(data);

    _path.str({});
    _path << _prefix << '-' << width << 'x' << height << '-'
          << enumerator_name(
               format,
               type_identity<framedump_pixel_format>(),
               value_tree_tag())
          << '-'
          << enumerator_name(
               type, type_identity<framedump_data_type>(), value_tree_tag())
          << '-' << std::setfill('0') << std::setw(6) << frame_number;

    std::cout << _path.str() << std::endl;
}
//------------------------------------------------------------------------------
auto make_raw_framedump(main_ctx_parent parent) -> std::shared_ptr<framedump> {
    return std::make_shared<raw_framedump>(parent);
}
//------------------------------------------------------------------------------
} // namespace eagine::application

