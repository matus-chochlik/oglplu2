/**
 *  @file eagine/callable_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_CALLABLE_REF_1509260923_HPP
#define EAGINE_CALLABLE_REF_1509260923_HPP

#include "mem_func_const.hpp"
#include "type_traits.hpp"
#include <utility>
#include <cassert>

namespace eagine {

template <typename FuncSig>
class callable_ref;

template <typename RV, typename ... P>
class callable_ref<RV(P...)>
{
private:
	void* _data;
	void(*_func)(void);

	typedef void(*_func_t)(void);
	typedef RV(*_func_pt)(P...);
	typedef RV(*_func_vpt)(void*, P...);

	template <typename C>
	static
	RV _cls_fn_call_op(void* that, P...p)
	{
		assert(that);
		C& obj = *(static_cast<C*>(that));
		return obj(std::forward<P>(p)...);
	}

	template <typename C>
	static
	RV _cls_fn_call_op_c(void* that, P...p)
	{
		assert(that);
		const C& obj = *(static_cast<const C*>(that));
		return obj(std::forward<P>(p)...);
	}
public:
	constexpr
	callable_ref(void)
	noexcept
	 : _data(nullptr)
	 , _func(nullptr)
	{ }
	callable_ref(RV(*func)(P...))
	noexcept
	 : _data(nullptr)
	 , _func(reinterpret_cast<_func_t>(func))
	{ }

	template <typename T>
	callable_ref(T* data, RV(*func)(T*, P...))
	noexcept
	 : _data(static_cast<void*>(data))
	 , _func(reinterpret_cast<_func_t>(func))
	{
		assert(_data != nullptr);
	}

	template <typename T>
	callable_ref(T& data, RV(*func)(T*, P...))
	noexcept
	 : _data(static_cast<void*>(&data))
	 , _func(reinterpret_cast<_func_t>(func))
	{ }

	template <typename C>
	explicit
	callable_ref(C& obj)
	noexcept
	 : _data(static_cast<void*>(&obj))
	 , _func(reinterpret_cast<_func_t>(&_cls_fn_call_op<C>))
	{ }

	template <typename C>
	explicit
	callable_ref(const C& obj)
	noexcept
	 : _data(static_cast<void*>(const_cast<C*>(&obj)))
	 , _func(reinterpret_cast<_func_t>(&_cls_fn_call_op_c<C>))
	{ }

	template <
		typename C,
		typename MF,
		MF Ptr,
		typename = std::enable_if_t<
			std::is_same<
				typename member_function_constant<
					MF,
					Ptr
				>::scope, C
			>::value
		>
	>
	callable_ref(
		C* obj,
		member_function_constant<MF, Ptr> mfc
	) noexcept
	 : _data(static_cast<void*>(obj))
	 , _func(reinterpret_cast<_func_t>(mfc.make_free()))
	{
		assert(_data != nullptr);
		assert(_func != nullptr);
	}

	constexpr
	bool is_valid(void) const
	noexcept
	{
		return _func != nullptr;
	}

	explicit constexpr
	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	constexpr
	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
	}

	template <typename ... A>
	RV operator()(A&&...a) const
	{
		assert(is_valid());
		if(_data == nullptr)
		{
			return (reinterpret_cast<_func_pt>(_func))(
				std::forward<A>(a)...
			);
		}
		else
		{
			return (reinterpret_cast<_func_vpt>(_func))(
				_data,
				std::forward<A>(a)...
			);
		}
	}
};

} // namespace eagine

#endif // include guard
