/**
 *  @file oglplus/utils/program_file_io.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_FILE_IO_1509260923_HPP
#define OGLPLUS_UTILS_PROGRAM_FILE_IO_1509260923_HPP

#include "memory_block.hpp"
#include "program_file_hdr.hpp"
#include "span.hpp"
#include <eagine/memory/align.hpp>
#include <iostream>

namespace oglplus {
//------------------------------------------------------------------------------
inline void write_and_pad_shader_source_header(
  std::ostream& output,
  shader_source_header& header,
  span_size_t source_text_size,
  span_size_t& spos) {
    using eagine::memory::is_aligned_as;
    while(!is_aligned_as<shader_source_header>(spos)) {
        output.put('\0');
        ++spos;
    }

    // if changing this also change shader_block
    // in write_and_pad_program_source_header
    const span_size_t size = 40;
    span_size_t done = 0;
    assert(size >= span_size(sizeof(shader_source_header)));

    eagine::memory::const_address hdraddr(&header);

    header.source_text.reset(hdraddr + std::ptrdiff_t(size), source_text_size);

    output.write(static_cast<const char*>(hdraddr), sizeof(header));
    spos += sizeof(header);
    done += sizeof(header);

    while(done < size) {
        output.put('\0');
        ++spos;
        ++done;
    }
}
//------------------------------------------------------------------------------
inline void write_shader_source(
  std::ostream& output,
  shader_source_header& header,
  const_memory_block source_text,
  span_size_t& spos) {
    write_and_pad_shader_source_header(
      output, header, span_size(source_text.size()), spos);

    eagine::write_to_stream(output, as_bytes(source_text));
    output.put('\0');
    spos += span_size(source_text.size() + 1);
}
//------------------------------------------------------------------------------
inline void write_shader_source(
  std::ostream& output,
  shader_source_header& header,
  const_memory_block source_text) {
    span_size_t spos = 0;

    if(output.tellp() >= 0) {
        spos = span_size_t(output.tellp());
    }

    write_shader_source(output, header, source_text, spos);
}
//------------------------------------------------------------------------------
inline void write_and_pad_program_source_header(
  std::ostream& output,
  program_source_header& header,
  span<const span_size_t> shader_source_lengths,
  span_size_t& spos) {

    using eagine::memory::is_aligned_as;

    // initial padding
    while(!is_aligned_as<program_source_header>(spos)) {
        output.put('\0');
        ++spos;
    }

    const span_size_t size = 32;
    span_size_t done = 0;
    assert(size >= span_size(sizeof(program_source_header)));

    eagine::memory::const_address hdraddr(&header);

    header.shader_sources.reset(
      hdraddr + std::ptrdiff_t(size),
      span_size(shader_source_lengths.size()) // shader count
    );

    eagine::write_to_stream(output, as_bytes(eagine::view_one(header)));
    spos += sizeof(header);
    done += sizeof(header);

    while(done < size) {
        output.put('\0');
        ++spos;
        ++done;
    }

    span_size_t algn = alignof(shader_source_header);
    std::ptrdiff_t offs = std::ptrdiff_t(shader_source_lengths.size()) *
                          std::ptrdiff_t(sizeof(std::ptrdiff_t));

    if(offs % 8 != 0) {
        offs += 8 - (offs % 8);
    }

    for(span_size_t len : shader_source_lengths) {
        eagine::write_to_stream(output, as_bytes(eagine::view_one(offs)));
        spos += sizeof(offs);
        done += sizeof(offs);

        // if changing this also change size
        // in write_and_pad_shader_source_header
        span_size_t shader_block_size = 40;
        shader_block_size += len;

        if(span_size_t misalign = shader_block_size % algn) {
            shader_block_size += (algn - misalign);
        }

        offs += std::ptrdiff_t(shader_block_size);
        // offs -= std::ptrdiff_t(sizeof(std::ptrdiff_t));
    }

    while(spos % 8 != 0) {
        output.put('\0');
        ++spos;
    }
}
//------------------------------------------------------------------------------
} // namespace oglplus

#endif // include guard
