/**
 *  @file eagine/value_tree/filesystem.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <filesystem>
#include <memory>
#include <tuple>
#include <vector>

namespace eagine::valtree {
//------------------------------------------------------------------------------
class filesystem_compound;
class filesystem_node : public attribute_interface {
public:
    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(filesystem);
    }

    auto name() -> string_view {
        return {};
    }

    auto nested_count() -> span_size_t {
        return 0;
    }

    auto nested(filesystem_compound& owner, span_size_t index)
      -> attribute_interface* {
        EAGINE_MAYBE_UNUSED(owner);
        EAGINE_MAYBE_UNUSED(index);
        return nullptr;
    }

    auto nested(filesystem_compound& owner, string_view name)
      -> attribute_interface* {
        EAGINE_MAYBE_UNUSED(owner);
        EAGINE_MAYBE_UNUSED(name);
        return nullptr;
    }

    auto find(filesystem_compound& owner, const basic_string_path& path)
      -> attribute_interface* {
        EAGINE_MAYBE_UNUSED(owner);
        EAGINE_MAYBE_UNUSED(path);
        return nullptr;
    }

    auto value_count() -> span_size_t {
        return 0;
    }

    template <typename T>
    auto fetch_values(span_size_t offset, span<T> dest) -> span_size_t {
        EAGINE_MAYBE_UNUSED(offset);
        EAGINE_MAYBE_UNUSED(dest);
        return 0;
    }

private:
    std::filesystem::path _node_path;
};
//------------------------------------------------------------------------------
class filesystem_compound
  : public compound_implementation<filesystem_compound> {

    std::filesystem::path _root_path;
    std::vector<std::tuple<span_size_t, std::unique_ptr<filesystem_node>>>
      _nodes{};

    inline auto _unwrap(attribute_interface& attrib) const noexcept -> auto& {
        EAGINE_ASSERT(attrib.type_id() == type_id());
        EAGINE_ASSERT(dynamic_cast<filesystem_node*>(&attrib));
        return static_cast<filesystem_node&>(attrib);
    }

public:
    filesystem_compound(string_view fs_path, logger&)
      : _root_path{std::string_view{fs_path}} {}

    static auto make_shared(string_view fs_path, logger& log)
      -> std::shared_ptr<filesystem_compound> {
        return std::make_shared<filesystem_compound>(fs_path, log);
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(filesystem);
    }

    void add_ref(attribute_interface& attrib) noexcept final {
        auto& that = _unwrap(attrib);
        for(auto& [ref_count, node_ptr] : _nodes) {
            if(&that == node_ptr.get()) {
                ++ref_count;
            }
        }
    }

    void release(attribute_interface& attrib) noexcept final {
        auto& that = _unwrap(attrib);
        for(auto pos = _nodes.begin(); pos != _nodes.end(); ++pos) {
            auto& [ref_count, node_ptr] = *pos;
            if(&that == node_ptr.get()) {
                if(--ref_count <= 0) {
                    _nodes.erase(pos);
                    break;
                }
            }
        }
    }

    auto structure() -> attribute_interface* final {
        return nullptr;
    }

    auto attribute_name(attribute_interface& attrib) -> string_view final {
        return _unwrap(attrib).name();
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
EAGINE_LIB_FUNC
auto from_filesystem_path(string_view fs_path, logger& log) -> compound {
    return compound::make<filesystem_compound>(fs_path, log);
}
//------------------------------------------------------------------------------
} // namespace eagine::valtree
