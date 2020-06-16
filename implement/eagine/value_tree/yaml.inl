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
#include <ryml.hpp>
#include <vector>

namespace eagine {
namespace valtree {
//------------------------------------------------------------------------------
class rapidyaml_tree_compound
  : public compound_implementation<rapidyaml_tree_compound> {
public:
    static std::shared_ptr<rapidyaml_tree_compound> make_shared(string_view) {
        /*
        _doc_t rj_doc{};
        rj_doc.Parse(rapidjson_string_ref(json_str));
        if(!rj_doc.HasParseError()) {
            return std::make_shared<rapidjson_document_compound>(rj_doc);
        }
        */
        return {};
    }

    void add_ref(attribute_interface&) noexcept final {
    }

    void release(attribute_interface&) noexcept final {
    }

    attribute_interface* structure() final {
        return nullptr;
    }

    span_size_t nested_count(attribute_interface&) final {
        return 0;
    }

    attribute_interface* nested(attribute_interface&, span_size_t) final {
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
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

