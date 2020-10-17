/**
 *  @file eagine/value_tree/json.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/base64.hpp>
#include <eagine/from_string.hpp>
#include <eagine/identifier.hpp>
#include <eagine/is_within_limits.hpp>
#include <eagine/logging/logger.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/value_tree/implementation.hpp>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <vector>

namespace eagine::valtree {
//------------------------------------------------------------------------------
static inline auto view(const rapidjson::GenericStringRef<char>& str) {
    return string_view{str.s, span_size(str.length)};
}
//------------------------------------------------------------------------------
template <typename E, typename A>
static inline auto view(rapidjson::GenericValue<E, A>& val) -> string_view {
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
static auto rapidjson_make_value_node(
  rapidjson_document_compound<Encoding, Allocator, StackAlloc>& owner,
  rapidjson::GenericValue<Encoding, Allocator>& value,
  rapidjson::GenericValue<Encoding, Allocator>* name = nullptr)
  -> attribute_interface*;
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
      , _rj_name{rj_name} {}

    friend auto operator==(
      const rapidjson_value_node& l,
      const rapidjson_value_node& r) noexcept {
        return (l._rj_val == r._rj_val);
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(rapidjson);
    }

    auto name() -> string_view {
        if(_rj_name) {
            const auto& name = extract(_rj_name);
            return {name.GetString(), span_size(name.GetStringLength())};
        }
        return {};
    }

    auto nested_count() -> span_size_t {
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

    auto nested(_comp_t& owner, span_size_t index) -> attribute_interface* {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            if(val.IsArray()) {
                if(index < span_size(val.Size())) {
                    return rapidjson_make_value_node(
                      owner, val[rapidjson_size(index)]);
                }
            }
            if(val.IsObject()) {
                if(index < span_size(val.MemberCount())) {
                    auto pos = val.MemberBegin() + index;
                    return rapidjson_make_value_node(
                      owner, pos->value, &pos->name);
                }
            }
        }
        return {};
    }

    auto nested(_comp_t& owner, string_view name) -> attribute_interface* {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            if(val.IsObject()) {
                auto found = val.FindMember(c_str(name));
                if(found != val.MemberEnd()) {
                    return rapidjson_make_value_node(
                      owner, found->value, &found->name);
                }
            }
            if(auto opt_idx{from_string<span_size_t>(name)}) {
                return nested(owner, extract(opt_idx));
            }
        }
        return {};
    }

    auto find(_comp_t& owner, const basic_string_path& path)
      -> attribute_interface* {
        _val_t* result = _rj_val;
        _val_t* name = nullptr;
        for(auto& entry : path) {
            if(result) {
                if(result->IsObject()) {
                    auto found = result->FindMember(c_str(entry));
                    if(found != result->MemberEnd()) {
                        result = &found->value;
                        name = &found->name;
                        continue;
                    }
                }
                if(result->IsArray()) {
                    if(auto opt_idx{from_string<span_size_t>(entry)}) {
                        const auto index{extract(opt_idx)};
                        if(index < span_size(result->Size())) {
                            result = &(*result)[rapidjson_size(index)];
                            continue;
                        }
                    }
                }
            }
            result = nullptr;
            break;
        }

        if(result) {
            return rapidjson_make_value_node(owner, *result, name);
        }

        return {};
    }

    auto value_count() -> span_size_t {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            if(val.IsArray()) {
                return span_size(val.Size());
            }
            if(val.IsString()) {
                // for base64 encoded byte span
                return base64_decoded_length(span_size(val.GetStringLength()));
            }
        }
        return 0;
    }

    auto convert(_val_t& val, std::string& dest) -> bool {
        if(val.IsString()) {
            dest.assign(val.GetString(), std_size(val.GetStringLength()));
            return true;
        }
        return false;
    }

    template <typename T>
    auto convert_bool(_val_t& val, T& dest) -> bool {
        if(val.IsBool()) {
            if(auto converted{convert_if_fits<T>(val.GetBool())}) {
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
        if(val.IsString()) {
            if(auto converted{from_string<T>(view(val))}) {
                dest = extract(converted);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    auto convert_int(_val_t& val, T& dest) -> bool {
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
    auto convert_uint(_val_t& val, T& dest) -> bool {
        if(val.IsUint()) {
            if(auto converted{convert_if_fits<T>(val.GetUint())}) {
                dest = extract(converted);
                return true;
            }
        }
        if(val.IsUint64()) {
            if(auto converted{convert_if_fits<T>(val.GetUint64())}) {
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
    auto convert_real(_val_t& val, T& dest) -> bool {
        if(val.IsFloat()) {
            if(auto converted{convert_if_fits<T>(val.GetFloat())}) {
                dest = extract(converted);
                return true;
            }
        }
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

    template <typename R, typename P>
    auto convert_duration(_val_t& val, std::chrono::duration<R, P>& dest)
      -> bool {
        using _dur_t = std::chrono::duration<R, P>;
        if(val.IsFloat()) {
            if(auto converted{convert_if_fits<R>(val.GetFloat())}) {
                dest = _dur_t{extract(converted)};
                return true;
            }
        }
        if(val.IsDouble()) {
            if(auto converted{convert_if_fits<R>(val.GetDouble())}) {
                dest = _dur_t{extract(converted)};
                return true;
            }
        }
        if(val.IsInt()) {
            if(auto converted{convert_if_fits<R>(val.GetInt())}) {
                dest = _dur_t{extract(converted)};
                return true;
            }
        }
        if(val.IsInt64()) {
            if(auto converted{convert_if_fits<R>(val.GetInt64())}) {
                dest = _dur_t{extract(converted)};
                return true;
            }
        }
        if(val.IsString()) {
            if(auto converted{from_string<_dur_t>(view(val))}) {
                dest = extract(converted);
                return true;
            }
        }
        return false;
    }

    auto convert(_val_t& val, bool& dest) {
        return convert_bool(val, dest);
    }

    auto convert(_val_t& val, byte& dest) {
        return convert_uint(val, dest);
    }

    auto convert(_val_t& val, std::int16_t& dest) {
        return convert_int(val, dest);
    }

    auto convert(_val_t& val, std::int32_t& dest) {
        return convert_int(val, dest);
    }

    auto convert(_val_t& val, std::int64_t& dest) {
        return convert_int(val, dest);
    }

    auto convert(_val_t& val, std::uint16_t& dest) {
        return convert_uint(val, dest);
    }

    auto convert(_val_t& val, std::uint32_t& dest) {
        return convert_uint(val, dest);
    }

    auto convert(_val_t& val, std::uint64_t& dest) {
        return convert_uint(val, dest);
    }

    auto convert(_val_t& val, float& dest) {
        return convert_real(val, dest);
    }

    auto convert(_val_t& val, std::chrono::duration<float>& dest) {
        return convert_duration(val, dest);
    }

    template <typename T>
    auto do_fetch_values(span_size_t offset, span<T> dest) -> span_size_t {
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

    template <typename T>
    auto fetch_values(span_size_t offset, span<T> dest) -> span_size_t {
        return do_fetch_values(offset, dest);
    }

    auto fetch_values(span_size_t offset, span<byte> dest) -> span_size_t {
        if(_rj_val) {
            auto& val = extract(_rj_val);
            // blobs can also be decoded from base64 strings
            using memory::skip;
            if(val.IsString()) {
                const auto req_size =
                  base64_decoded_length(span_size(val.GetStringLength()));
                if(dest.size() < req_size) {
                    std::vector<byte> temp{};
                    if(auto dec{base64_decode(view(val), temp)}) {
                        if(auto src{skip(cover(extract(dec)), offset)}) {
                            copy(src, dest);
                            return src.size();
                        }
                    }
                    return 0;
                } else {
                    if(auto src{skip(base64_decode(view(val), dest), offset)}) {
                        copy(src, dest);
                        return src.size();
                    }
                    return 0;
                }
            }
        }
        return do_fetch_values(offset, dest);
    }
};
//------------------------------------------------------------------------------
template <typename Encoding, typename Allocator, typename StackAlloc>
class rapidjson_document_compound
  : public compound_with_refcounted_node<
      rapidjson_document_compound<Encoding, Allocator, StackAlloc>,
      rapidjson_value_node<Encoding, Allocator, StackAlloc>> {
private:
    using base = compound_with_refcounted_node<
      rapidjson_document_compound<Encoding, Allocator, StackAlloc>,
      rapidjson_value_node<Encoding, Allocator, StackAlloc>>;
    using base::_unwrap;

    using _doc_t = rapidjson::GenericDocument<Encoding, Allocator, StackAlloc>;
    using _val_t = rapidjson::GenericValue<Encoding, Allocator>;
    using _node_t = rapidjson_value_node<Encoding, Allocator, StackAlloc>;

    _doc_t _rj_doc{};
    _node_t _root{};

public:
    rapidjson_document_compound(_doc_t& rj_doc)
      : _rj_doc{std::move(rj_doc)}
      , _root{_rj_doc, nullptr} {}

    static auto make_shared(string_view json_str, logger& log)
      -> std::shared_ptr<rapidjson_document_compound> {
        _doc_t rj_doc;
        const rapidjson::ParseResult parse_ok{
          rj_doc.Parse(json_str.data(), rapidjson::SizeType(json_str.size()))};
        if(parse_ok) {
            return std::make_shared<rapidjson_document_compound>(rj_doc);
        }
        log.error("JSON parse error")
          .arg(EAGINE_ID(message), rapidjson::GetParseError_En(parse_ok.Code()))
          .arg(EAGINE_ID(offset), parse_ok.Offset());
        return {};
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(rapidjson);
    }

    auto structure() -> attribute_interface* final {
        return &_root;
    }

    auto attribute_name(attribute_interface& attrib) -> string_view final {
        return _unwrap(attrib).name();
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
template <typename Encoding, typename Allocator, typename StackAlloc>
static inline auto rapidjson_make_value_node(
  rapidjson_document_compound<Encoding, Allocator, StackAlloc>& owner,
  rapidjson::GenericValue<Encoding, Allocator>& value,
  rapidjson::GenericValue<Encoding, Allocator>* name) -> attribute_interface* {
    return owner.make_node(value, name);
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
auto from_json_text(string_view json_text, logger& log) -> compound {
    return compound::make<default_rapidjson_document_compound>(json_text, log);
}
//------------------------------------------------------------------------------
} // namespace eagine::valtree
