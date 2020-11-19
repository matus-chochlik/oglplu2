/**
 *  @file eagine/value_tree/filesystem.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/from_string.hpp>
#include <eagine/logging/type/exception.hpp>
#include <eagine/logging/type/filesystem.hpp>
#include <eagine/main_ctx_object.hpp>
#include <eagine/value_tree/implementation.hpp>
#include <filesystem>
#include <fstream>
#include <tuple>
#include <vector>

namespace eagine::valtree {
//------------------------------------------------------------------------------
class filesystem_compound;
class filesystem_node;
//------------------------------------------------------------------------------
static auto filesystem_make_node(
  filesystem_compound& owner,
  const std::filesystem::path& fs_path) -> attribute_interface*;
static auto filesystem_object_of(filesystem_compound& owner)
  -> main_ctx_object&;
//------------------------------------------------------------------------------
class filesystem_node : public attribute_interface {
public:
    filesystem_node(
      std::filesystem::path node_path,
      std::filesystem::path real_path)
      : _node_path{std::move(node_path)}
      , _real_path{std::move(real_path)}
      , _name{_node_path.filename()} {}

    filesystem_node(const std::filesystem::path& fs_path)
      : filesystem_node{fs_path, canonical(fs_path)} {}

    friend auto
    operator==(const filesystem_node& l, const filesystem_node& r) noexcept
      -> bool {
        return l._node_path == r._node_path;
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(filesystem);
    }

    auto name() -> string_view {
        return {_name};
    }

    auto is_link() const -> bool {
        return is_symlink(_node_path);
    }

    auto nested_count(filesystem_compound& owner) -> span_size_t {
        if(is_directory(_real_path)) {
            try {
                const auto iter =
                  std::filesystem::directory_iterator(_node_path);
                return span_size(std::distance(begin(iter), end(iter)));
            } catch(std::filesystem::filesystem_error& err) {
                filesystem_object_of(owner)
                  .log_debug("failed to get filesystem node count")
                  .arg(EAGINE_ID(path), _node_path)
                  .arg(EAGINE_ID(error), err);
            }
        }
        return 0;
    }

    auto nested(filesystem_compound& owner, span_size_t index)
      -> attribute_interface* {
        try {
            if(is_directory(_real_path)) {
                for(auto& ent :
                    std::filesystem::directory_iterator(_node_path)) {
                    if(index > 0) {
                        --index;
                    } else {
                        return filesystem_make_node(owner, ent);
                    }
                }
            }
        } catch(std::filesystem::filesystem_error& err) {
            filesystem_object_of(owner)
              .log_debug("failed to get nested filesystem node for '${path}'")
              .arg(EAGINE_ID(index), index)
              .arg(EAGINE_ID(path), _node_path)
              .arg(EAGINE_ID(error), err);
        }
        return nullptr;
    }

    auto nested(filesystem_compound& owner, string_view name)
      -> attribute_interface* {
        try {
            if(is_directory(_real_path)) {
                for(auto& ent :
                    std::filesystem::directory_iterator(_node_path)) {
                    const std::filesystem::path& epath{ent};
                    const std::string& ename{epath.filename()};
                    if(are_equal(name, string_view(ename))) {
                        return filesystem_make_node(owner, epath);
                    }
                }
            }
        } catch(std::filesystem::filesystem_error& err) {
            filesystem_object_of(owner)
              .log_debug("failed to get nested filesystem node for '${path}'")
              .arg(EAGINE_ID(name), name)
              .arg(EAGINE_ID(path), _node_path)
              .arg(EAGINE_ID(error), err);
        }
        return nullptr;
    }

    auto find(filesystem_compound& owner, const basic_string_path& path)
      -> attribute_interface* {
        auto spath{_node_path};
        for(auto ent : path) {
            spath.append(std::string_view(ent));
        }
        if(exists(spath)) {
            return filesystem_make_node(owner, spath);
        }
        return nullptr;
    }

    auto value_count() -> span_size_t {
        if(is_regular_file(_real_path)) {
            return file_size(_real_path);
        }
        return 0;
    }

    auto fetch_values(span_size_t offset, memory::block dest) -> span_size_t {
        if(exists(_real_path) && is_regular_file(_real_path)) {
            std::ifstream file;
            file.open(_real_path, std::ios::in | std::ios::binary);
            file.seekg(offset, std::ios::beg);
            if(!file
                  .read(
                    reinterpret_cast<char*>(dest.data()),
                    static_cast<std::streamsize>(dest.size()))
                  .bad()) {
                return span_size(file.gcount());
            }
        }
        return 0;
    }

    auto fetch_values(span_size_t offset, span<char> dest) -> span_size_t {
        if(exists(_real_path) && is_regular_file(_real_path)) {
            std::ifstream file;
            file.open(_real_path, std::ios::in);
            file.seekg(offset, std::ios::beg);
            if(!file
                  .read(dest.data(), static_cast<std::streamsize>(dest.size()))
                  .bad()) {
                return span_size(file.gcount());
            }
        }
        return 0;
    }

    template <typename T>
    auto fetch_values(span_size_t offset, span<T> dest) -> span_size_t {
        if(dest.size() == 1) {
            char temp[64];
            if(auto len{fetch_values(offset, cover(temp))}) {
                auto issep = [](char c) {
                    return !c || std::isspace(c);
                };
                if(auto src{take_until(head(memory::view(temp), len), issep)}) {
                    if(auto fetched{from_string<T>(src)}) {
                        dest.front() = extract(fetched);
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

private:
    const std::filesystem::path _node_path;
    const std::filesystem::path _real_path;
    const std::string _name;
};
//------------------------------------------------------------------------------
class filesystem_compound
  : public main_ctx_object
  , public compound_with_refcounted_node<filesystem_compound, filesystem_node> {
    using base =
      compound_with_refcounted_node<filesystem_compound, filesystem_node>;
    using base::_unwrap;

    filesystem_node _root;
    std::shared_ptr<file_compound_factory> _compound_factory;

public:
    filesystem_compound(
      main_ctx_parent parent,
      string_view fs_path,
      std::shared_ptr<file_compound_factory> factory)
      : main_ctx_object{EAGINE_ID(FsVtCmpnd), parent}
      , _root{std::string_view{fs_path}}
      , _compound_factory{std::move(factory)} {}

    static auto make_shared(
      main_ctx_parent parent,
      string_view fs_path,
      std::shared_ptr<file_compound_factory> factory)
      -> std::shared_ptr<filesystem_compound> {
        return std::make_shared<filesystem_compound>(
          parent, fs_path, std::move(factory));
    }

    auto type_id() const noexcept -> identifier_t final {
        return EAGINE_ID_V(filesystem);
    }

    auto structure() -> attribute_interface* final {
        return &_root;
    }

    auto attribute_name(attribute_interface& attrib) -> string_view final {
        return _unwrap(attrib).name();
    }

    auto canonical_type(attribute_interface&) -> value_type final {
        return value_type::byte_type;
    }

    auto is_link(attribute_interface& attrib) -> bool final {
        return _unwrap(attrib).is_link();
    }

    auto nested_count(attribute_interface& attrib) -> span_size_t final {
        return _unwrap(attrib).nested_count(*this);
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
static inline auto filesystem_object_of(filesystem_compound& owner)
  -> main_ctx_object& {
    return owner;
}
//------------------------------------------------------------------------------
static inline auto filesystem_make_node(
  filesystem_compound& owner,
  const std::filesystem::path& fs_path) -> attribute_interface* {
    if(!fs_path.empty()) {
        try {
            return owner.make_node(fs_path, canonical(fs_path));
        } catch(std::filesystem::filesystem_error&) {
            owner.log_debug("failed to create filesystem node '${path}'")
              .arg(EAGINE_ID(path), EAGINE_ID(FsPath), fs_path);
        }
    }
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto from_filesystem_path(
  string_view fs_path,
  main_ctx_parent parent,
  std::shared_ptr<file_compound_factory> factory) -> compound {
    return compound::make<filesystem_compound>(
      parent, fs_path, std::move(factory));
}
//------------------------------------------------------------------------------
} // namespace eagine::valtree
