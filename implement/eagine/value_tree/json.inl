/**
 *  @file eagine/value_tree/json.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/is_within_limits.hpp>
#include <rapidjson/document.h>
#include <vector>

namespace eagine {
namespace valtree {
//------------------------------------------------------------------------------
static inline auto rapidjson_string_ref(string_view str) {
    if(EAGINE_LIKELY(str)) {
        return rapidjson::StringRef(
          str.data(), rapidjson::SizeType(str.size()));
    }
    return rapidjson::StringRef("", 0U);
}
//------------------------------------------------------------------------------
static inline auto view(rapidjson::GenericStringRef<char> str) {
    return string_view{str.s, span_size(str.length)};
}
//------------------------------------------------------------------------------
template <typename E, typename A>
static inline string_view view(rapidjson::GenericValue<E, A>& val) {
    if(val.IsString()) {
        return {val.GetString(), span_size(val.GetStringLength())};
    }
    return {};
}
//------------------------------------------------------------------------------
static inline auto rapidjson_size(span_size_t s) {
    return limit_cast<rapidjson::SizeType>(s);
}
//------------------------------------------------------------------------------
template <typename Encoding, typename Allocator, typename StackAlloc>
class rapidjson_value_node;

template <typename Encoding, typename Allocator, typename StackAlloc>
class rapidjson_document_compound;
//------------------------------------------------------------------------------
template <typename Encoding, typename Allocator, typename StackAlloc>
static attribute_interface* rapidjson_make_value_node(
  rapidjson_document_compound<Encoding, Allocator, StackAlloc>& owner,
  rapidjson::GenericValue<Encoding, Allocator>& value,
  rapidjson::GenericValue<Encoding, Allocator>* name = nullptr);
//------------------------------------------------------------------------------
template <typename Encoding, typename Allocator, typename StackAlloc>
class rapidjson_value_node : public attribute_interface {
private:
    using _doc_t = rapidjson::GenericDocument<Encoding, Allocator, StackAlloc>;
    using _val_t = rapidjson::GenericValue<Encoding, Allocator>;
    using _node_t = rapidjson_value_node<Encoding, Allocator, StackAlloc>;
    using _comp_t =
      rapidjson_document_compound<Encoding, Allocator, StackAlloc>;

    _val_t* _rj_val{nullptr};
    _val_t* _rj_name{nullptr};

public:
    rapidjson_value_node(_val_t& rj_val, _val_t* rj_name = nullptr) noexcept
      : _rj_val{&rj_val}
      , _rj_name{rj_name} {
    }

    friend bool operator==(
      const rapidjson_value_node& l, const rapidjson_value_node& r) noexcept {
        return (l._rj_val == r._rj_val);
    }

    string_view name(compound_interface&) final {
        if(_rj_name) {
            const auto& name = extract(_rj_name);
            return {name.GetString(), span_size(name.GetStringLength())};
        }
        return {};
    }

    span_size_t nested_count(compound_interface&) final {
        if(_rj_val) {
            const auto& val = extract(_rj_val);
            if(val.IsArray()) {
                return span_size(val.Size());
            }
            if(val.IsObject()) {
                return span_size(val.MemberCount());
            }
        }
        return 0;
    }

    attribute_interface* nested(
      compound_interface& owner, span_size_t index) final {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            if(val.IsArray()) {
                if(index < span_size(val.Size())) {
                    EAGINE_ASSERT(dynamic_cast<_comp_t*>(&owner));
                    return rapidjson_make_value_node(
                      *static_cast<_comp_t*>(&owner),
                      val[rapidjson_size(index)]);
                }
            }
        }
        return {};
    }

    span_size_t value_count() {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            if(val.IsArray()) {
                return span_size(val.Size());
            }
        }
        return 0;
    }

    bool convert(_val_t& val, std::string& dest) {
        if(val.IsString()) {
            dest.assign(val.GetString(), std_size(val.GetStringLength()));
            return true;
        }
        return false;
    }

    template <typename T>
    bool convert_int(_val_t& val, T& dest) {
        if(val.IsInt()) {
            if(auto converted{convert_if_fits<T>(val.GetInt())}) {
                dest = extract(converted);
                return true;
            }
        }
        if(val.IsInt64()) {
            if(auto converted{convert_if_fits<T>(val.GetInt64())}) {
                dest = extract(converted);
                return true;
            }
        }
        if(val.IsString()) {
            if(auto converted{from_string<T>(view(val))}) {
                dest = extract(converted);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool convert_real(_val_t& val, T& dest) {
        if(val.IsDouble()) {
            if(auto converted{convert_if_fits<T>(val.GetDouble())}) {
                dest = extract(converted);
                return true;
            }
        }
        if(val.IsInt()) {
            if(auto converted{convert_if_fits<T>(val.GetInt())}) {
                dest = extract(converted);
                return true;
            }
        }
        if(val.IsInt64()) {
            if(auto converted{convert_if_fits<T>(val.GetInt64())}) {
                dest = extract(converted);
                return true;
            }
        }
        if(val.IsString()) {
            if(auto converted{from_string<T>(view(val))}) {
                dest = extract(converted);
                return true;
            }
        }
        return false;
    }

    bool convert(_val_t& val, std::int16_t& dest) {
        return convert_int(val, dest);
    }

    bool convert(_val_t& val, std::int32_t& dest) {
        return convert_int(val, dest);
    }

    bool convert(_val_t& val, std::int64_t& dest) {
        return convert_int(val, dest);
    }

    bool convert(_val_t& val, float& dest) {
        return convert_real(val, dest);
    }

    template <typename T>
    span_size_t fetch_values(span_size_t offset, span<T> dest) {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            if(val.IsArray()) {
                const auto n = span_size(val.Size());
                span_size_t i = 0;
                while((i + offset < n) && (i < dest.size())) {
                    if(!convert(val[rapidjson_size(i + offset)], dest[i])) {
                        break;
                    }
                    ++i;
                }
                return i;
            } else {
                if(!dest.empty()) {
                    if(convert(val, dest.front())) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

    attribute_interface* find(
      compound_interface& owner, const basic_string_path& path) {
        _val_t* result = _rj_val;
        _val_t* name = nullptr;
        for(auto& entry : path) {
            if(result && result->IsObject()) {
                auto found = result->FindMember(c_str(entry));
                if(found != result->MemberEnd()) {
                    result = &found->value;
                    name = &found->name;
                    continue;
                }
            }
            result = nullptr;
            break;
        }

        if(result) {
            EAGINE_ASSERT(dynamic_cast<_comp_t*>(&owner));
            return rapidjson_make_value_node(
              *static_cast<_comp_t*>(&owner), *result, name);
        }

        return {};
    }
};
//------------------------------------------------------------------------------
template <typename Encoding, typename Allocator, typename StackAlloc>
class rapidjson_document_compound : public compound_interface {
private:
    using _doc_t = rapidjson::GenericDocument<Encoding, Allocator, StackAlloc>;
    using _val_t = rapidjson::GenericValue<Encoding, Allocator>;
    using _node_t = rapidjson_value_node<Encoding, Allocator, StackAlloc>;

    _doc_t _rj_doc{};
    _node_t _root{};

    std::vector<std::tuple<span_size_t, _node_t>> _nodes{};

    static inline auto& _unwrap(attribute_interface& attrib) {
        EAGINE_ASSERT(dynamic_cast<_node_t*>(&attrib));
        return static_cast<_node_t&>(attrib);
    }

public:
    rapidjson_document_compound(_doc_t& rj_doc)
      : _rj_doc{std::move(rj_doc)}
      , _root{_rj_doc, nullptr} {
    }

    static std::shared_ptr<rapidjson_document_compound> make_shared(
      string_view json_str) {
        _doc_t rj_doc{};
        rj_doc.Parse(rapidjson_string_ref(json_str));
        if(!rj_doc.HasParseError()) {
            return std::make_shared<rapidjson_document_compound>(rj_doc);
        }
        return {};
    }

    _node_t* make_new(_val_t& rj_val, _val_t* rj_name) {
        _node_t temp{rj_val, rj_name};
        for(auto& [ref_count, node] : _nodes) {
            if(temp == node) {
                ++ref_count;
                return &node;
            }
        }
        _nodes.emplace_back(1, std::move(temp));
        return &std::get<1>(_nodes.back());
    }

    void add_ref(attribute_interface& attrib) noexcept final {
        auto& that = _unwrap(attrib);
        for(auto& [ref_count, node] : _nodes) {
            if(that == node) {
                ++ref_count;
            }
        }
    }

    void release(attribute_interface& attrib) noexcept final {
        auto& that = _unwrap(attrib);
        for(auto pos = _nodes.begin(); pos != _nodes.end(); ++pos) {
            auto& [ref_count, node] = *pos;
            if(that == node) {
                if(--ref_count <= 0) {
                    _nodes.erase(pos);
                    break;
                }
            }
        }
    }

    attribute_interface* structure() final {
        return &_root;
    }

    span_size_t value_count(attribute_interface& attrib) final {
        return _unwrap(attrib).value_count();
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int16_t> dest) final {
        return _unwrap(attrib).fetch_values(offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int32_t> dest) final {
        return _unwrap(attrib).fetch_values(offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int64_t> dest) final {
        return _unwrap(attrib).fetch_values(offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib, span_size_t offset, span<float> dest) final {
        return _unwrap(attrib).fetch_values(offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::string> dest) final {
        return _unwrap(attrib).fetch_values(offset, dest);
    }
};
//------------------------------------------------------------------------------
template <typename Encoding, typename Allocator, typename StackAlloc>
static inline attribute_interface* rapidjson_make_value_node(
  rapidjson_document_compound<Encoding, Allocator, StackAlloc>& owner,
  rapidjson::GenericValue<Encoding, Allocator>& value,
  rapidjson::GenericValue<Encoding, Allocator>* name) {
    return owner.make_new(value, name);
}
//------------------------------------------------------------------------------
template <typename Document>
struct get_rapidjson_document_compound;

template <typename Document>
using get_rapidjson_document_compound_t =
  typename get_rapidjson_document_compound<Document>::type;

template <typename Encoding, typename Allocator, typename StackAlloc>
struct get_rapidjson_document_compound<
  rapidjson::GenericDocument<Encoding, Allocator, StackAlloc>> {
    using type = rapidjson_document_compound<Encoding, Allocator, StackAlloc>;
};

using default_rapidjson_document_compound =
  get_rapidjson_document_compound_t<rapidjson::Document>;
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
compound from_json_text(string_view json_text) {
    return compound::make<default_rapidjson_document_compound>(json_text);
}
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

