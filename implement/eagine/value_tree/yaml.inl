/**
 *  @file eagine/value_tree/yaml.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/from_string.hpp>
#include <eagine/is_within_limits.hpp>
#include <eagine/main_ctx_object.hpp>
#include <eagine/value_tree/implementation.hpp>
#include <vector>

#if EAGINE_USE_RYML
#include <ryml.hpp>
#include <stdexcept>
#endif

namespace eagine::valtree {
#if EAGINE_USE_RYML
//------------------------------------------------------------------------------
static inline auto rapidyaml_cstrref(string_view str) noexcept {
    return c4::csubstr(str.data(), std_size(str.size()));
}
//------------------------------------------------------------------------------
static inline auto view(c4::csubstr str) noexcept {
    return string_view{str.data(), span_size(str.size())};
}
//------------------------------------------------------------------------------
class rapidyaml_callbacks {

    c4::yml::Callbacks _prev{};
    c4::yml::Callbacks _cbks{};

    void _do_handle_error(const std::string& msg) {
        throw std::runtime_error(msg);
    }

    static void
    _handle_error(const char* msg, size_t len, c4::yml::Location, void* self) {
        static_cast<rapidyaml_callbacks*>(self)->_do_handle_error(
          std::string(msg, len));
    }

public:
    rapidyaml_callbacks() {
#ifdef RYML_NO_DEFAULT_CALLBACKS
        _prev = {c4::yml::get_callbacks()};
        _cbks = {
          static_cast<void*>(this),
          _prev.m_allocate,
          _prev.m_free,
          &rapidyaml_callbacks::_handle_error};
#else
        _cbks = {
          static_cast<void*>(this),
          nullptr,
          nullptr,
          &rapidyaml_callbacks::_handle_error};
#endif
        c4::yml::set_callbacks(_cbks);
    }

    ~rapidyaml_callbacks() noexcept {
        c4::yml::set_callbacks(_prev);
    }

    rapidyaml_callbacks(rapidyaml_callbacks&&) = delete;
    rapidyaml_callbacks(const rapidyaml_callbacks&) = delete;
    auto operator=(rapidyaml_callbacks&&) = delete;
    auto operator=(const rapidyaml_callbacks&) = delete;
};
//------------------------------------------------------------------------------
class rapidyaml_tree_compound;
class rapidyaml_attribute;
static auto
rapidyaml_make_new_node(rapidyaml_tree_compound&, ryml::NodeRef) noexcept
  -> rapidyaml_attribute*;
//------------------------------------------------------------------------------
class rapidyaml_attribute : public attribute_interface {
    ryml::NodeRef _node{};

    static inline auto _usable(const ryml::NodeRef& n) noexcept {
        return n.valid() && !n.is_seed();
    }

public:
    rapidyaml_attribute(ryml::NodeRef node)
      : _node{node} {}

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(rapidyaml);
    }

    auto name() const noexcept -> string_view {
        if(_usable(_node) && _node.has_key()) {
            return view(_node.key());
        }
        return {};
    }

    auto canonical_type() const noexcept -> value_type {
        if(_usable(_node)) {
            if(_node.is_container()) {
                return value_type::composite;
            }
            return value_type::string_type;
        }
        return value_type::unknown;
    }

    auto nested_count() const noexcept -> span_size_t {
        if(_usable(_node)) {
            if(_node.is_container()) {
                return span_size(_node.num_children());
            }
        }
        return 0;
    }

    auto value_count() const noexcept -> span_size_t {
        if(_usable(_node)) {
            if(_node.is_seq()) {
                return span_size(_node.num_children());
            }
            if(!_node.is_map()) {
                return 1;
            }
        }
        return 0;
    }

    auto nested(rapidyaml_tree_compound& owner, span_size_t index) const noexcept
      -> attribute_interface* {
        if(_usable(_node)) {
            auto child{_node[std_size(index)]};
            if(_usable(child)) {
                return rapidyaml_make_new_node(owner, child);
            }
        }
        return nullptr;
    }

    auto nested(rapidyaml_tree_compound& owner, string_view name) const noexcept
      -> attribute_interface* {
        if(_usable(_node)) {
            if(_node.is_map()) {
                auto child{_node.find_child(rapidyaml_cstrref(name))};
                if(_usable(child)) {
                    return rapidyaml_make_new_node(owner, child);
                }
            }
        }
        return nullptr;
    }

    auto find(rapidyaml_tree_compound& owner, const basic_string_path& path)
      const noexcept -> attribute_interface* {
        auto result{_node};
        for(auto& entry : path) {
            if(_usable(result)) {
                if(result.is_map()) {
                    result = result.find_child(rapidyaml_cstrref(entry));
                    continue;
                }
                if(result.is_seq()) {
                    if(auto opt_idx{from_string<span_size_t>(entry)}) {
                        result = result[extract(opt_idx)];
                        continue;
                    }
                }
                result = {};
            }
        }

        if(_usable(result)) {
            return rapidyaml_make_new_node(owner, result);
        }
        return nullptr;
    }

    auto fetch_values(span_size_t offset, span<char> dest) -> span_size_t {
        if(_usable(_node)) {
            if(!_node.is_seq()) {
                if(_node.has_val()) {
                    const auto src{head(skip(view(_node.val()), offset), dest)};
                    copy(src, dest);
                    return src.size();
                }
            }
        }
        return 0;
    }

    template <typename T>
    auto fetch_values(span_size_t offset, span<T> dest) -> span_size_t {
        if(_usable(_node)) {
            if(_node.is_seq()) {
                span_size_t pos{0};
                for(auto child : _node.children()) {
                    if(child.has_val()) {
                        if(offset <= 0) {
                            if(auto opt_val{
                                 from_string<T>(view(child.val()))}) {
                                dest[pos] = std::move(extract(opt_val));
                                ++pos;
                            }
                        } else {
                            --offset;
                        }
                    }
                }
                return pos;
            }
            if(!dest.empty()) {
                if(_node.has_val()) {
                    if(auto opt_val{from_string<T>(view(_node.val()))}) {
                        dest.front() = std::move(extract(opt_val));
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

    friend auto operator==(
      const rapidyaml_attribute& l,
      const rapidyaml_attribute& r) noexcept {
        return l._node == r._node;
    }
};
//------------------------------------------------------------------------------
class rapidyaml_tree_compound
  : public main_ctx_object
  , public compound_with_refcounted_node<
      rapidyaml_tree_compound,
      rapidyaml_attribute> {

    using base =
      compound_with_refcounted_node<rapidyaml_tree_compound, rapidyaml_attribute>;
    using base::_unwrap;

    ryml::Tree _tree{};
    rapidyaml_attribute _root;

public:
    rapidyaml_tree_compound(ryml::Tree tree, main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(YamlValTre), parent}
      , _tree{std::move(tree)}
      , _root{_tree} {}

    rapidyaml_tree_compound(rapidyaml_tree_compound&&) = delete;
    rapidyaml_tree_compound(const rapidyaml_tree_compound&) = delete;
    auto operator=(rapidyaml_tree_compound&&) = delete;
    auto operator=(const rapidyaml_tree_compound&) = delete;

    ~rapidyaml_tree_compound() noexcept final = default;

    static auto make_shared(string_view yaml_text, main_ctx_parent parent)
      -> std::shared_ptr<rapidyaml_tree_compound> {
        try {
            rapidyaml_callbacks cbks{};
            c4::csubstr src{yaml_text.data(), std_size(yaml_text.size())};
            auto tree{ryml::parse(src)};
            tree.resolve();
            return std::make_shared<rapidyaml_tree_compound>(
              std::move(tree), parent);
        } catch(std::runtime_error& err) {
            main_ctx_object(EAGINE_ID(YamlParse), parent)
              .log_error("YAML parse error: ${message}")
              .arg(EAGINE_ID(message), string_view(err.what()));
        }
        return {};
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(rapidyaml);
    }

    auto structure() -> attribute_interface* final {
        return &_root;
    }

    auto attribute_name(attribute_interface& attrib) -> string_view final {
        return _unwrap(attrib).name();
    }

    auto canonical_type(attribute_interface& attrib) -> value_type final {
        return _unwrap(attrib).canonical_type();
    }

    auto is_link(attribute_interface&) -> bool final {
        return false;
    }

    auto nested_count(attribute_interface& attrib) -> span_size_t final {
        return _unwrap(attrib).nested_count();
    }

    auto nested(attribute_interface& attrib, span_size_t index)
      -> attribute_interface* final {
        return _unwrap(attrib).nested(*this, index);
    }

    auto nested(attribute_interface& attrib, string_view name)
      -> attribute_interface* final {
        return _unwrap(attrib).nested(*this, name);
    }

    auto find(attribute_interface& attrib, const basic_string_path& path)
      -> attribute_interface* final {
        return _unwrap(attrib).find(*this, path);
    }

    auto value_count(attribute_interface& attrib) -> span_size_t final {
        return _unwrap(attrib).value_count();
    }

    template <typename T>
    auto do_fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<T> dest) -> span_size_t {
        return _unwrap(attrib).fetch_values(offset, dest);
    }
};
//------------------------------------------------------------------------------
static auto rapidyaml_make_new_node(
  rapidyaml_tree_compound& owner,
  ryml::NodeRef node) noexcept -> rapidyaml_attribute* {
    return owner.make_node(node);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto from_yaml_text(string_view yaml_text, main_ctx_parent parent) -> compound {
    return compound::make<rapidyaml_tree_compound>(yaml_text, parent);
}
#else  // EAGINE_USE_RYML
EAGINE_LIB_FUNC
auto from_yaml_text(string_view, main_ctx_parent parent) -> compound {
    main_ctx_object{EAGINE_ID(YamlParse), parent}.log_warning(
      "built without the YAML parser");
    return {};
}
#endif // EAGINE_USE_RYML
//------------------------------------------------------------------------------
} // namespace eagine::valtree
