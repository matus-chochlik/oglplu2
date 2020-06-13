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
      attrib, identity<vertex_attrib_kind>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
static inline auto primitive_type_from(string_view str) noexcept {
    return from_string(str, identity<primitive_type>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
static inline auto attrib_data_type_from(string_view str) noexcept {
    return from_string(str, identity<attrib_data_type>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
static inline auto index_data_type_from(string_view str) noexcept {
    return from_string(str, identity<index_data_type>{}, value_tree_tag{});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits value_tree_loader::_attr_mask(
  const valtree::compound& source) noexcept {
    vertex_attrib_bits result;
    for(auto& info :
        enumerator_mapping(identity<vertex_attrib_kind>{}, value_tree_tag{})) {
        if(source.has(info.name)) {
            result |= info.enumerator;
        }
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
value_tree_loader::value_tree_loader(
  valtree::compound source, logger& parent) noexcept
  : _base{_attr_mask(source)}
  , _log{EAGINE_ID(ValTreLoad), parent}
  , _source{std::move(source)} {
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t value_tree_loader::vertex_count() {
    span_size_t result{};
    if(_source.fetch_value("vertex_count", result)) {
        return result;
    } else {
        _log.error("could not query shape vertex count");
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t value_tree_loader::attribute_variants(vertex_attrib_kind attrib) {
    if(auto attrib_a{_source.find(vertex_attrib_name(attrib))}) {
        return attrib_a.nested_count();
    } else {
        _log.error("could not query vertex attribute variant count")
          .arg(EAGINE_ID(attribute), attrib);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view value_tree_loader::variant_name(vertex_attrib_variant vav) {
    if(auto attrib_a{_source.find(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{attrib_a.nested(vav.index())}) {
            if(auto vpv_a{variant_a.find("name")}) {
                auto pos = _variant_names.find(vav);
                if(pos != _variant_names.end()) {
                    return {std::get<1>(*pos)};
                }
                auto& name = _variant_names[vav] = {};
                if(_source.fetch_value(vpv_a, name)) {
                    _log.debug("cached attribute variant name")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index())
                      .arg(EAGINE_ID(name), name);
                    return {name};
                } else {
                    _log.error("could not fetch attribute variant name")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }
        } else {
            _log.error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        _log.error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t value_tree_loader::values_per_vertex(vertex_attrib_variant vav) {
    if(auto attrib_a{_source.find(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{attrib_a.nested(vav.index())}) {
            if(auto vpv_a{variant_a.find("values_per_vertex")}) {
                span_size_t result{};
                if(_source.fetch_value(vpv_a, result)) {
                    return result;
                } else {
                    _log.error("could not fetch attribute variant vertex count")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }
        } else {
            _log.error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        _log.error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return _base::values_per_vertex(vav);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
attrib_data_type value_tree_loader::attrib_type(vertex_attrib_variant vav) {
    if(auto attrib_a{_source.find(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{attrib_a.nested(vav.index())}) {
            if(auto type_a{variant_a.find("type")}) {
                if(_source.fetch_value(type_a, _temp)) {
                    if(auto type{attrib_data_type_from(view(_temp))}) {
                        return extract(type);
                    } else {
                        _log.error("unknown attribute variant data type")
                          .arg(EAGINE_ID(type), view(_temp))
                          .arg(EAGINE_ID(attribute), vav.attrib)
                          .arg(EAGINE_ID(variant), vav.index());
                    }
                } else {
                    _log.error("could not fetch attribute variant data type")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            }
        } else {
            _log.error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        _log.error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
    return attrib_data_type::float_;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::attrib_values(
  vertex_attrib_variant vav, span<float> dest) {
    if(auto attrib_a{_source.find(vertex_attrib_name(vav.attrib))}) {
        if(auto variant_a{attrib_a.nested(vav.index())}) {
            if(auto data_a{variant_a.find("data")}) {
                if(_source.fetch_values(data_a, dest)) {
                    _log.debug("loaded vertex attribute data")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                } else {
                    _log.error("could not fetch vertex attribute data")
                      .arg(EAGINE_ID(attribute), vav.attrib)
                      .arg(EAGINE_ID(variant), vav.index());
                }
            } else {
                _log.error("could not find vertex attribute data")
                  .arg(EAGINE_ID(attribute), vav.attrib)
                  .arg(EAGINE_ID(variant), vav.index());
            }
        } else {
            _log.error("could not find vertex attribute variant")
              .arg(EAGINE_ID(attribute), vav.attrib)
              .arg(EAGINE_ID(variant), vav.index());
        }
    } else {
        _log.error("could not find vertex attribute")
          .arg(EAGINE_ID(attribute), vav.attrib);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type value_tree_loader::index_type() {
    if(auto type_a{_source.find("index_type")}) {
        if(_source.fetch_value(type_a, _temp)) {
            if(auto type{index_data_type_from(view(_temp))}) {
                return extract(type);
            } else {
                _log.error("unsupported index type value")
                  .arg(EAGINE_ID(type), view(_temp));
            }
        } else {
            _log.error("could not fetch index type value");
        }
    }
    return index_data_type::none;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t value_tree_loader::index_count() {
    if(auto indices_a{_source.find("indices")}) {
        return _source.value_count(indices_a);
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::indices(span<std::uint16_t> dest) {
    if(auto indices_a{_source.find("indices")}) {
        if(_source.fetch_values(indices_a, dest)) {
            _log.debug("loaded indices");
        } else {
            _log.error("could not fetch shape 32-bit indices");
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::indices(span<std::uint32_t> dest) {
    if(auto indices_a{_source.find("indices")}) {
        if(_source.fetch_values(indices_a, dest)) {
            _log.debug("loaded indices").arg(EAGINE_ID(indices), view(dest));
        } else {
            _log.error("could not fetch shape 32-bit indices");
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t value_tree_loader::operation_count() {
    if(auto instrs_a{_source.find("instructions")}) {
        return instrs_a.nested_count();
    } else {
        _log.error("could not query shape draw instructions count");
    }
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void value_tree_loader::instructions(span<draw_operation> ops) {
    bool btemp{};
    if(auto instrs_a{_source.find("instructions")}) {
        if(ops.size() == instrs_a.nested_count()) {
            for(span_size_t i = 0; i < ops.size(); ++i) {
                if(auto instr_a{instrs_a.nested(i)}) {
                    auto& op = ops[i];

                    // first
                    if(auto first_a{instr_a.find("first")}) {
                        if(!_source.fetch_value(first_a, op.first)) {
                            _log.error("could not fetch shape draw offset")
                              .arg(EAGINE_ID(index), i);
                        }
                    } else {
                        _log.error("could not find shape draw offset")
                          .arg(EAGINE_ID(index), i);
                    }

                    // count
                    if(auto count_a{instr_a.find("count")}) {
                        if(!_source.fetch_value(count_a, op.count)) {
                            _log.error("could not fetch shape draw count")
                              .arg(EAGINE_ID(index), i);
                        }
                    } else {
                        _log.error("could not find shape draw count")
                          .arg(EAGINE_ID(index), i);
                    }

                    // phase
                    if(auto phase_a{instr_a.find("phase")}) {
                        if(!_source.fetch_value(phase_a, op.phase)) {
                            _log.error("could not fetch draw phase value")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // primitive restart index
                    if(auto pri_a{instr_a.find("primitive_restart_index")}) {
                        if(!_source.fetch_value(
                             pri_a, op.primitive_restart_index)) {
                            _log.error("could not fetch restart index")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // patch_vertices
                    if(auto ptch_vert_a{instr_a.find("patch_vertices")}) {
                        if(!_source.fetch_value(
                             ptch_vert_a, op.patch_vertices)) {
                            _log.error("could not fetch patch vertex count")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // draw mode
                    if(auto mode_a{instr_a.find("mode")}) {
                        if(_source.fetch_value(mode_a, _temp)) {
                            if(auto mode{primitive_type_from(view(_temp))}) {
                                op.mode = extract(mode);
                            } else {
                                _log.error("unsupported shape draw mode")
                                  .arg(EAGINE_ID(mode), view(_temp))
                                  .arg(EAGINE_ID(index), i);
                            }
                        } else {
                            _log.error("could not fetch shape draw mode")
                              .arg(EAGINE_ID(index), i);
                        }
                    } else {
                        _log.error("could not find shape draw mode")
                          .arg(EAGINE_ID(index), i);
                    }

                    // index type
                    if(auto type_a{instr_a.find("index_type")}) {
                        if(_source.fetch_value(type_a, _temp)) {
                            if(auto type{index_data_type_from(view(_temp))}) {
                                op.idx_type = extract(type);
                            } else {
                                _log.error("unsupported index type value")
                                  .arg(EAGINE_ID(type), view(_temp));
                            }
                        } else {
                            _log.error("could not fetch index type value");
                        }
                    }

                    // primitive restart
                    if(auto prirest_a{instr_a.find("primitive_restart")}) {
                        if(!_source.fetch_value(prirest_a, btemp)) {
                            op.primitive_restart = btemp;
                        } else {
                            _log.error("invalid primitive restart flag")
                              .arg(EAGINE_ID(index), i);
                        }
                    }

                    // face winding direction
                    if(auto cwfw_a{instr_a.find("cw_face_winding")}) {
                        if(_source.fetch_value(cwfw_a, btemp)) {
                            op.cw_face_winding = btemp;
                        } else {
                            _log.error("invalid face winding direction")
                              .arg(EAGINE_ID(index), i);
                        }
                    }
                    _log.debug("loaded draw operation")
                      .arg(EAGINE_ID(first), op.first)
                      .arg(EAGINE_ID(count), op.count)
                      .arg(EAGINE_ID(phase), op.phase)
                      .arg(EAGINE_ID(prmRstrIdx), op.primitive_restart_index)
                      .arg(EAGINE_ID(mode), op.mode)
                      .arg(EAGINE_ID(indexType), op.idx_type)
                      .arg(EAGINE_ID(primRstrt), bool(op.primitive_restart))
                      .arg(EAGINE_ID(cwFaceWndg), bool(op.cw_face_winding));
                } else {
                    _log.error("could not get shape draw instruction")
                      .arg(EAGINE_ID(index), i);
                }
            }
        } else {
            _log.error("shape draw instructions destination size mismatch")
              .arg(EAGINE_ID(dest), ops.size())
              .arg(EAGINE_ID(actual), instrs_a.nested_count());
        }
    } else {
        _log.error("could not find shape draw instructions");
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
