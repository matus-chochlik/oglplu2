/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/assert.hpp>
#include <eagine/reflect/enumerators.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
static inline auto vertex_attrib_name(vertex_attrib_kind attrib) noexcept {
    return enumerator_name(
      attrib, type_identity<vertex_attrib_kind>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
static inline auto primitive_type_from(string_view str) noexcept {
    return from_string(str, type_identity<primitive_type>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
static inline auto attrib_data_type_from(string_view str) noexcept {
    return from_string(
      str, type_identity<attrib_data_type>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
static inline auto index_data_type_from(string_view str) noexcept {
    return from_string(str, type_identity<index_data_type>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::_attr_mask(const valtree::compound& source) noexcept
  -> vertex_attrib_bits {
    vertex_attrib_bits result;
    for(auto& info : enumerator_mapping(
          type_identity<vertex_attrib_kind>{}, value_tree_tag{})) {
        if(source.nested(info.name)) {
            result |= info.enumerator;
        }
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
value_tree_loader::value_tree_loader(
  valtree::compound source,
  main_ctx_parent parent) noexcept
  : main_ctx_object{EAGINE_ID(ValTreLoad), parent}
  , _base{_attr_mask(source)}
  , _source{std::move(source)} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::vertex_count() -> span_size_t {
    span_size_t result{};
    if(auto count_a{_source.nested("vertex_count")}) {
        if(_source.fetch_value(count_a, result)) {
            return result;
        } else {
            log_error("could not fetch shape vertex count");
        }
    } else {
        log_error("could not find shape vertex count attribute");
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::attribute_variants(vertex_attrib_kind attrib)
  -> span_size_t {
    if(auto attrib_a{_source.nested(vertex_attrib_name(attrib))}) {
        return _source.nested_count(attrib_a);
    } else {
        log_error("could not query vertex attribute variant count")
          .arg(EAGINE_ID(attribute), attrib);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::variant_name(vertex_attrib_variant vav) -> string_view {
    if(auto attrib_a{_source.nested(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{_source.nested(attrib_a, vav.index())}) {
            if(auto vpv_a{_source.nested(variant_a, "name")}) {
                auto pos = _variant_names.find(vav);
                if(pos != _variant_names.end()) {
                    return {std::get<1>(*pos)};
                }
                auto& name = _variant_names[vav] = {};
                if(_source.fetch_value(vpv_a, name)) {
                    log_debug("cached attribute variant name")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index())
                      .arg(EAGINE_ID(name), name);
                    return {name};
                } else {
                    log_error("could not fetch attribute variant name")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }
        } else {
            log_error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        log_error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::values_per_vertex(vertex_attrib_variant vav)
  -> span_size_t {
    if(auto attrib_a{_source.nested(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{_source.nested(attrib_a, vav.index())}) {
            if(auto vpv_a{_source.nested(variant_a, "values_per_vertex")}) {
                span_size_t result{};
                if(_source.fetch_value(vpv_a, result)) {
                    return result;
                } else {
                    log_error("could not fetch attribute variant vertex count")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }
        } else {
            log_error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        log_error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return _base::values_per_vertex(vav);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::attrib_type(vertex_attrib_variant vav)
  -> attrib_data_type {
    if(auto attrib_a{_source.nested(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{_source.nested(attrib_a, vav.index())}) {
            if(auto type_a{_source.nested(variant_a, "type")}) {
                if(_source.fetch_value(type_a, _temp)) {
                    if(auto type{attrib_data_type_from(view(_temp))}) {
                        return extract(type);
                    } else {
                        log_error("unknown attribute variant data type")
                          .arg(EAGINE_ID(type), view(_temp))
                          .arg(EAGINE_ID(attribute), vav.attrib)
                          .arg(EAGINE_ID(variant), vav.index());
                    }
                } else {
                    log_error("could not fetch attribute variant data type")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }
        } else {
            log_error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        log_error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return attrib_data_type::float_;
}
//------------------------------------------------------------------------------
auto value_tree_loader::is_attrib_normalized(vertex_attrib_variant vav)
  -> bool {
    if(auto attrib_a{_source.nested(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{_source.nested(attrib_a, vav.index())}) {
            if(auto norm_a{_source.nested(variant_a, "normalized")}) {
                bool normalized{false};
                if(_source.fetch_value(norm_a, normalized)) {
                    return normalized;
                } else {
                    log_error("could not fetch attribute variant normalized")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            } else if(auto type_a{_source.nested(variant_a, "type")}) {
                if(_source.fetch_value(type_a, _temp)) {
                    if(auto type{attrib_data_type_from(view(_temp))}) {
                        return extract(type) != attrib_data_type::float_;
                    } else {
                        log_error("unknown attribute variant data type")
                          .arg(EAGINE_ID(type), view(_temp))
                          .arg(EAGINE_ID(attribute), vav.attrib)
                          .arg(EAGINE_ID(variant), vav.index());
                    }
                } else {
                    log_error("could not fetch attribute variant data type")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }

        } else {
            log_error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        log_error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T>
void value_tree_loader::_attrib_values(vertex_attrib_variant vav, span<T> dest) {
    if(auto attrib_a{_source.nested(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{_source.nested(attrib_a, vav.index())}) {
            if(auto data_a{_source.nested(variant_a, "data")}) {
                if(_source.fetch_values(data_a, dest)) {
                    log_debug("loaded vertex attribute data")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                } else {
                    log_error("could not fetch vertex attribute data")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            } else {
                log_error("could not find vertex attribute data")
                  .arg(EAGINE_ID(attribute), vav.attrib)
                  .arg(EAGINE_ID(variant), vav.index());
            }
        } else {
            log_error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        log_error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav,
  span<byte> dest) {
    _attrib_values(vav, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav,
  span<std::int16_t> dest) {
    _attrib_values(vav, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav,
  span<std::int32_t> dest) {
    _attrib_values(vav, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav,
  span<std::uint16_t> dest) {
    _attrib_values(vav, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav,
  span<std::uint32_t> dest) {
    _attrib_values(vav, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav,
  span<float> dest) {
    _attrib_values(vav, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::index_type(drawing_variant) -> index_data_type {
    if(auto type_a{_source.nested("index_type")}) {
        if(_source.fetch_value(type_a, _temp)) {
            if(auto type{index_data_type_from(view(_temp))}) {
                return extract(type);
            } else {
                log_error("unsupported index type value")
                  .arg(EAGINE_ID(type), view(_temp));
            }
        } else {
            log_error("could not fetch index type value");
        }
    }
    return index_data_type::none;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::index_count(drawing_variant) -> span_size_t {
    if(auto indices_a{_source.nested("indices")}) {
        return _source.value_count(indices_a);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::indices(drawing_variant, span<std::uint16_t> dest) {
    if(auto indices_a{_source.nested("indices")}) {
        if(_source.fetch_values(indices_a, dest)) {
            log_debug("loaded indices");
        } else {
            log_error("could not fetch shape 32-bit indices");
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::indices(drawing_variant, span<std::uint32_t> dest) {
    if(auto indices_a{_source.nested("indices")}) {
        if(_source.fetch_values(indices_a, dest)) {
            log_debug("loaded indices").arg(EAGINE_ID(indices), view(dest));
        } else {
            log_error("could not fetch shape 32-bit indices");
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto value_tree_loader::operation_count(drawing_variant) -> span_size_t {
    if(auto instrs_a{_source.nested("instructions")}) {
        return _source.nested_count(instrs_a);
    } else {
        log_error("could not query shape draw instructions count");
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::instructions(drawing_variant, span<draw_operation> ops) {
    bool btemp{};
    if(auto instrs_a{_source.nested("instructions")}) {
        if(ops.size() == _source.nested_count(instrs_a)) {
            for(auto i : integer_range(ops.size())) {
                if(auto instr_a{_source.nested(instrs_a, i)}) {
                    auto& op = ops[i];

                    // first
                    if(auto first_a{_source.nested(instr_a, "first")}) {
                        if(!_source.fetch_value(first_a, op.first)) {
                            log_error("could not fetch shape draw offset")
                              .arg(EAGINE_ID(index), i);
                        }
                    } else {
                        log_error("could not find shape draw offset")
                          .arg(EAGINE_ID(index), i);
                    }

                    // count
                    if(auto count_a{_source.nested(instr_a, "count")}) {
                        if(!_source.fetch_value(count_a, op.count)) {
                            log_error("could not fetch shape draw count")
                              .arg(EAGINE_ID(index), i);
                        }
                    } else {
                        log_error("could not find shape draw count")
                          .arg(EAGINE_ID(index), i);
                    }

                    // phase
                    if(auto phase_a{_source.nested(instr_a, "phase")}) {
                        if(!_source.fetch_value(phase_a, op.phase)) {
                            log_error("could not fetch draw phase value")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // primitive restart index
                    if(auto pri_a{
                         _source.nested(instr_a, "primitive_restart_index")}) {
                        if(!_source.fetch_value(
                             pri_a, op.primitive_restart_index)) {
                            log_error("could not fetch restart index")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // patch_vertices
                    if(auto ptch_vert_a{
                         _source.nested(instr_a, "patch_vertices")}) {
                        if(!_source.fetch_value(
                             ptch_vert_a, op.patch_vertices)) {
                            log_error("could not fetch patch vertex count")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // draw mode
                    if(auto mode_a{_source.nested(instr_a, "mode")}) {
                        if(_source.fetch_value(mode_a, _temp)) {
                            if(auto mode{primitive_type_from(view(_temp))}) {
                                op.mode = extract(mode);
                            } else {
                                log_error("unsupported shape draw mode")
                                  .arg(EAGINE_ID(mode), view(_temp))
                                  .arg(EAGINE_ID(index), i);
                            }
                        } else {
                            log_error("could not fetch shape draw mode")
                              .arg(EAGINE_ID(index), i);
                        }
                    } else {
                        log_error("could not find shape draw mode")
                          .arg(EAGINE_ID(index), i);
                    }

                    // index type
                    if(auto type_a{_source.nested(instr_a, "index_type")}) {
                        if(_source.fetch_value(type_a, _temp)) {
                            if(auto type{index_data_type_from(view(_temp))}) {
                                op.idx_type = extract(type);
                            } else {
                                log_error("unsupported index type value")
                                  .arg(EAGINE_ID(type), view(_temp));
                            }
                        } else {
                            log_error("could not fetch index type value");
                        }
                    }

                    // primitive restart
                    if(auto prirest_a{
                         _source.nested(instr_a, "primitive_restart")}) {
                        if(!_source.fetch_value(prirest_a, btemp)) {
                            op.primitive_restart = btemp;
                        } else {
                            log_error("invalid primitive restart flag")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // face winding direction
                    if(auto cwfw_a{
                         _source.nested(instr_a, "cw_face_winding")}) {
                        if(_source.fetch_value(cwfw_a, btemp)) {
                            op.cw_face_winding = btemp;
                        } else {
                            log_error("invalid face winding direction")
                              .arg(EAGINE_ID(index), i);
                        }
                    }
                    log_debug("loaded draw operation")
                      .arg(EAGINE_ID(first), op.first)
                      .arg(EAGINE_ID(count), op.count)
                      .arg(EAGINE_ID(phase), op.phase)
                      .arg(EAGINE_ID(prmRstrIdx), op.primitive_restart_index)
                      .arg(EAGINE_ID(mode), op.mode)
                      .arg(EAGINE_ID(indexType), op.idx_type)
                      .arg(EAGINE_ID(primRstrt), bool(op.primitive_restart))
                      .arg(EAGINE_ID(cwFaceWndg), bool(op.cw_face_winding));
                } else {
                    log_error("could not get shape draw instruction")
                      .arg(EAGINE_ID(index), i);
                }
            }
        } else {
            log_error("shape draw instructions destination size mismatch")
              .arg(EAGINE_ID(dest), ops.size())
              .arg(EAGINE_ID(actual), _source.nested_count(instrs_a));
        }
    } else {
        log_error("could not find shape draw instructions");
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
