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
#include <vector>

#if EAGINE_USE_RYML
#include <ryml.hpp>
#include <stdexcept>
#endif

namespace eagine {
namespace valtree {
#if EAGINE_USE_RYML
//------------------------------------------------------------------------------
class rapidyaml_callbacks {

    c4::yml::Callbacks _prev{};
    c4::yml::Callbacks _cbks{};

    void _do_handle_error(const std::string& msg) {
        throw std::runtime_error(msg);
    }

    static void _handle_error(
      const char* msg, size_t len, c4::yml::Location, void* self) {
        static_cast<rapidyaml_callbacks*>(self)->_do_handle_error(
          std::string(msg, len));
    }

public:
    rapidyaml_callbacks() {
#ifdef RYML_NO_DEFAULT_CALLBACKS
        _prev = {c4::yml::get_callbacks()};
        _cbks = {static_cast<void*>(this),
                 _prev.m_allocate,
                 _prev.m_free,
                 &rapidyaml_callbacks::_handle_error};
#else
        _cbks = {static_cast<void*>(this),
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
    rapidyaml_callbacks& operator=(rapidyaml_callbacks&&) = delete;
    rapidyaml_callbacks& operator=(const rapidyaml_callbacks&) = delete;
};
//------------------------------------------------------------------------------
class rapidyaml_attribute : public attribute_interface {
public:
    identifier_t type_id() noexcept final {
        return EAGINE_ID_V(rapidyaml);
    }
};
//------------------------------------------------------------------------------
class rapidyaml_tree_compound
  : public compound_implementation<rapidyaml_tree_compound> {
    ryml::Tree _tree{};

public:
    rapidyaml_tree_compound(ryml::Tree rymlt)
      : _tree{std::move(rymlt)} {
    }

    static std::shared_ptr<rapidyaml_tree_compound> make_shared(
      string_view yaml_text) {
        try {
            rapidyaml_callbacks cbks{};
            c4::csubstr src{yaml_text.data(), std_size(yaml_text.size())};
            return std::make_shared<rapidyaml_tree_compound>(ryml::parse(src));
        } catch(std::runtime_error&) {
        }
        return {};
    }

    identifier_t type_id() noexcept final {
        return EAGINE_ID_V(rapidyaml);
    }

    void add_ref(attribute_interface&) noexcept final {
    }

    void release(attribute_interface&) noexcept final {
    }

    attribute_interface* structure() final {
        return nullptr;
    }

    string_view attribute_name(attribute_interface&) final {
        return {};
    }

    span_size_t nested_count(attribute_interface&) final {
        return 0;
    }

    attribute_interface* nested(attribute_interface&, span_size_t) final {
        return nullptr;
    }

    attribute_interface* nested(attribute_interface&, string_view) final {
        return nullptr;
    }

    attribute_interface* find(
      attribute_interface&, const basic_string_path&) final {
        return nullptr;
    }

    span_size_t value_count(attribute_interface&) final {
        return 0;
    }

    template <typename T>
    span_size_t do_fetch_values(attribute_interface&, span_size_t, span<T>) {
        return 0;
    }
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
compound from_yaml_text(string_view yaml_text) {
    return compound::make<rapidyaml_tree_compound>(yaml_text);
}
#else  // EAGINE_USE_RYML
EAGINE_LIB_FUNC
compound from_yaml_text(string_view) {
    return {};
}
#endif // EAGINE_USE_RYML
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

