/**
 *  @file eagine/value_tree/filesystem.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/logging/logger.hpp>
#include <eagine/value_tree/implementation.hpp>
#include <filesystem>
#include <tuple>
#include <vector>

namespace eagine::valtree {
//------------------------------------------------------------------------------
class filesystem_compound;
class filesystem_node : public attribute_interface {
public:
    filesystem_node(const std::filesystem::path& fs_path) noexcept
      : _name{fs_path.filename()}
      , _node_path{canonical(fs_path)} {}

    friend auto
    operator==(const filesystem_node& l, const filesystem_node& r) noexcept
      -> bool {
        return (l._node_path == r._node_path) && (l._name == r._name);
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(filesystem);
    }

    auto name() -> string_view {
        return {_name};
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
    const std::string _name;
    const std::filesystem::path _node_path;
};
//------------------------------------------------------------------------------
class filesystem_compound
  : public compound_with_refcounted_node<filesystem_compound, filesystem_node> {
    using base =
      compound_with_refcounted_node<filesystem_compound, filesystem_node>;
    using base::_unwrap;

    logger _log;
    std::filesystem::path _root_path;
    std::shared_ptr<file_compound_factory> _compound_factory;

public:
    filesystem_compound(
      logger& log,
      string_view fs_path,
      std::shared_ptr<file_compound_factory> factory)
      : _log{EAGINE_ID(FsVtCmpnd), log}
      , _root_path{std::string_view{fs_path}}
      , _compound_factory{std::move(factory)} {}

    static auto make_shared(
      logger& log,
      string_view fs_path,
      std::shared_ptr<file_compound_factory> factory)
      -> std::shared_ptr<filesystem_compound> {
        return std::make_shared<filesystem_compound>(
          log, fs_path, std::move(factory));
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(filesystem);
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
auto from_filesystem_path(
  string_view fs_path,
  logger& log,
  std::shared_ptr<file_compound_factory> factory) -> compound {
    return compound::make<filesystem_compound>(
      log, fs_path, std::move(factory));
}
//------------------------------------------------------------------------------
} // namespace eagine::valtree
