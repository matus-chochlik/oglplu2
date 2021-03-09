/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_WRITE_BACKEND_HPP
#define EAGINE_SERIALIZE_WRITE_BACKEND_HPP

#include "../identifier.hpp"
#include "../interface.hpp"
#include "../reflect/decl_name.hpp"
#include "data_sink.hpp"
#include "result.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Interface for serialization write backends.
/// @ingroup serialization
/// @see common_serializer_backend
/// @see deserializer_backend
/// @see serializer_data_sink
struct serializer_backend : interface<serializer_backend> {

    /// @brief Alias for the serialization operations result type.
    using result = serialization_errors;

    /// @brief Returns a descriptive identifier of the implementation.
    virtual auto type_id() -> identifier = 0;

    /// @brief Returns a pointer to the associated data sink, if any.
    virtual auto sink() -> serializer_data_sink* = 0;

    /// @brie Indicates if the backed stores enumerators as strings (or numeric values).
    virtual auto enum_as_string() -> bool = 0;

    /// @brief Starts the serialization of a potentially complex structured value.
    virtual auto begin() -> result = 0;

    /// @brief Writes boolean values, returns how many were done through second argument.
    virtual auto write(span<const bool>, span_size_t&) -> result = 0;

    /// @brief Writes character values, returns how many were done through second argument.
    virtual auto write(span<const char>, span_size_t&) -> result = 0;

    /// @brief Writes 8-bit int values, returns how many were done through second argument.
    virtual auto write(span<const std::int8_t>, span_size_t&) -> result = 0;

    /// @brief Writes short int values, returns how many were done through second argument.
    virtual auto write(span<const short>, span_size_t&) -> result = 0;

    /// @brief Writes int values, returns how many were done through second argument.
    virtual auto write(span<const int>, span_size_t&) -> result = 0;

    /// @brief Writes long values, returns how many were done through second argument.
    virtual auto write(span<const long>, span_size_t&) -> result = 0;

    /// @brief Writes long long values, returns how many were done through second argument.
    virtual auto write(span<const long long>, span_size_t&) -> result = 0;

    /// @brief Writes 8-bit uint values, returns how many were done through second argument.
    virtual auto write(span<const std::uint8_t>, span_size_t&) -> result = 0;

    /// @brief Writes ushort values, returns how many were done through second argument.
    virtual auto write(span<const unsigned short>, span_size_t&) -> result = 0;

    /// @brief Writes uint values, returns how many were done through second argument.
    virtual auto write(span<const unsigned>, span_size_t&) -> result = 0;

    /// @brief Writes ulong values, returns how many were done through second argument.
    virtual auto write(span<const unsigned long>, span_size_t&) -> result = 0;

    /// @brief Writes ulong long values, returns how many were done through second argument.
    virtual auto write(span<const unsigned long long>, span_size_t&)
      -> result = 0;

    /// @brief Writes float values, returns how many were done through second argument.
    virtual auto write(span<const float>, span_size_t&) -> result = 0;

    /// @brief Writes double values, returns how many were done through second argument.
    virtual auto write(span<const double>, span_size_t&) -> result = 0;

    /// @brief Writes identifier values, returns how many were done through second argument.
    virtual auto write(span<const identifier>, span_size_t&) -> result = 0;

    /// @brief Writes decl_name values, returns how many were done through second argument.
    virtual auto write(span<const decl_name>, span_size_t&) -> result = 0;

    /// @brief Writes string values, returns how many were done through second argument.
    virtual auto write(span<const string_view>, span_size_t&) -> result = 0;

    /// @brief Begins the serialization of a structure instance.
    virtual auto begin_struct(span_size_t member_count) -> result = 0;

    /// @brief Begins the serialization of a structure data member.
    virtual auto begin_member(string_view name) -> result = 0;

    /// @brief Finishes the serialization of a structure data member.
    virtual auto finish_member(string_view name) -> result = 0;

    /// @brief Finishes the serialization of a structure instance.
    virtual auto finish_struct() -> result = 0;

    /// @brief Begins the serialization of a container instance.
    virtual auto begin_list(span_size_t element_count) -> result = 0;

    /// @brief Begins the serialization of a container element.
    virtual auto begin_element(span_size_t index) -> result = 0;

    /// @brief Finishes the serialization of a container element.
    virtual auto finish_element(span_size_t index) -> result = 0;

    /// @brief Finishes the serialization of a container instance.
    virtual auto finish_list() -> result = 0;

    /// @brief Finishes the serialization of a potentially complex structured value.
    virtual auto finish() -> result = 0;
};
//------------------------------------------------------------------------------
/// @brief CRTP mixin implementing the common parts of serializer backends.
/// @ingroup serialization
/// @tparam Derived the derived backend implementation
/// @tparam Sink the data sink type.
template <typename Derived, typename Sink = serializer_data_sink>
class common_serializer_backend : public serializer_backend {
public:
    /// @brief Default constructor.
    common_serializer_backend() noexcept = default;

    /// @brief Construction from a reference to a Sink.
    common_serializer_backend(Sink& s) noexcept
      : _sink{&s} {}

    /// @brief Sets a reference to a new Sink object.
    auto set_sink(Sink& s) noexcept -> auto& {
        _sink = &s;
        return derived();
    }

    auto sink() -> serializer_data_sink* final {
        return _sink;
    }

    auto enum_as_string() -> bool override {
        return false;
    }

    auto begin() -> result override {
        return {};
    }

    auto write(span<const bool> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const char> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const std::int8_t> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const short> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const int> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const long> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const long long> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const std::uint8_t> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned short> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned long> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned long long> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const float> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const double> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const identifier> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const decl_name> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const string_view> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto begin_struct(span_size_t) -> result override {
        return {};
    }
    auto begin_member(string_view) -> result override {
        return {};
    }
    auto finish_member(string_view) -> result override {
        return {};
    }
    auto finish_struct() -> result override {
        return {};
    }
    auto begin_list(span_size_t) -> result override {
        return {};
    }
    auto begin_element(span_size_t) -> result override {
        return {};
    }
    auto finish_element(span_size_t) -> result override {
        return {};
    }
    auto finish_list() -> result override {
        return {};
    }
    auto finish() -> result override {
        return {};
    }

protected:
    auto remaining_size() const -> span_size_t {
        EAGINE_ASSERT(_sink);
        return _sink->remaining_size();
    }

    template <typename... Args>
    auto sink(Args&&... args) const -> result {
        EAGINE_ASSERT(_sink);
        return _sink->write(std::forward<Args>(args)...);
    }

private:
    Sink* _sink{nullptr};

    auto derived() noexcept -> Derived& {
        return *static_cast<Derived*>(this);
    }
};
//------------------------------------------------------------------------------
/// @brief Base class partially implementing serializer and deserialized backends.
/// @ingroup serialization
/// @see serializer_backend
/// @see deserializer_backend
template <typename Base, identifier_t Id>
class serializer_backend_id : public Base {
public:
    using Base::Base;

    static constexpr const identifier_t id_value = Id;

    auto type_id() -> identifier final {
        return identifier{Id};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_WRITE_BACKEND_HPP
