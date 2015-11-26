/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_EAGINE_HELPER_MOCK_FUNC_HPP
#define TEST_EAGINE_HELPER_MOCK_FUNC_HPP

#include <oglplus/utils/nothing.hpp>
#include <cstring>
#include <cassert>

namespace eagine {

template <typename T>
struct mock_ptr
{
	T* _p;

	constexpr
	mock_ptr(void)
	 : _p(nullptr)
	{ }

	constexpr
	mock_ptr(std::nullptr_t)
	 : _p(nullptr)
	{ }

	mock_ptr(T* p)
	 : _p(p)
	{ }

	friend
	bool operator == (mock_ptr a, mock_ptr b)
	{
		return (a._p == b._p) || (a._p == nullptr) || (b._p == nullptr);
	}
};

template <typename Sig>
class mock_function;

template <typename Sig>
class mock_function_base;

template <typename R, typename ... P>
class mock_function_base<R(P...)>
{
protected:
	const char* _expected_func_name;
	std::tuple<P...> _expected_params;

	unsigned short _func_called;
	bool _func_ok : 1;
	bool _params_ok : 1;

	template <typename ... A>
	void _handle_call(const A& ... a)
	{
		++_func_called;
		_params_ok |= _expected_params == std::tie(a...);
	}
public:
	mock_function_base(
		const char* func_name,
		const std::tuple<P...>& params
	): _expected_func_name(func_name)
	 , _expected_params(params)
	 , _func_called(0)
	 , _func_ok(false)
	 , _params_ok(false)
	{ }

	mock_function_base(const char* func_name)
	 : mock_function_base(func_name, std::tuple<P...>())
	{ }

	mock_function<R(P...)>& self(void)
	{
		return static_cast<mock_function<R(P...)>&>(*this);
	}

	mock_function<R(P...)>& reset_params(const P& ... p)
	{
		_expected_params = std::tie(p...);
		_params_ok = false;
		return self();
	}

	mock_function<R(P...)>& reset_called(void)
	{
		_func_called = 0;
		return self();
	}

	mock_function<R(P...)>& called_function(const char* func_name)
	{
		assert(_expected_func_name != nullptr);
		_func_ok |= std::strcmp(_expected_func_name, func_name) == 0;
		return self();
	}

	bool was_called(void) const
	{
		return _func_called > 0;
	}

	bool all_ok_exclusive(void) const
	{
		return (_func_called == 1)  && (_func_ok) && (_params_ok);
	}
};

template <typename R, typename ... P>
class mock_function<R(P...)>
 : public mock_function_base<R(P...)>
{
private:
	R _result;
public:
	mock_function(const char* func_name)
	 : mock_function_base<R(P...)>(func_name)
	{ }

	mock_function& reset_result(const R& result)
	{
		_result = result;
		return *this;
	}

	template <typename ... A>
	R operator ()(const A& ... a)
	{
		this->_handle_call(a...);
		return _result;
	}
};

template <typename ... P>
class mock_function<void(P...)>
 : public mock_function_base<void(P...)>
{
public:
	mock_function(const char* func_name)
	 : mock_function_base<void(P...)>(func_name)
	{ }

	template <typename ... A>
	void operator ()(const A& ... a)
	{
		this->_handle_call(a...);
	}
};

template <typename F>
class mock_function_aoe_test;

template <typename R, typename ... P>
class mock_function_aoe_test<R(P...)>
{
private:
	mock_function<R(P...)>& _mf;
public:
	mock_function_aoe_test(mock_function<R(P...)>& mf, R r, P ... p)
	 : _mf(mf)
	{
		_mf.reset_result(r);
		_mf.reset_params(p...);
		_mf.reset_called();
		assert(!_mf.all_ok_exclusive());
	}

	explicit
	operator bool (void) const
	{
		return _mf.all_ok_exclusive();
	}
};

template <typename R, typename ... P>
static inline
mock_function_aoe_test<R(P...)>
make_aoe_test(mock_function<R(P...)>& mf, R r, P ... p)
{
	return {mf, r, p...};
}

template <typename ... P>
class mock_function_aoe_test<void(P...)>
{
private:
	mock_function<void(P...)>& _mf;
public:
	mock_function_aoe_test(mock_function<void(P...)>& mf, P ... p)
	 : _mf(mf)
	{
		_mf.reset_params(p...);
		_mf.reset_called();
		assert(!_mf.all_ok_exclusive());
	}

	explicit
	operator bool (void) const
	{
		return _mf.all_ok_exclusive();
	}
};

template <typename ... P>
static inline
mock_function_aoe_test<void(P...)>
make_aoe_test(mock_function<void(P...)>& mf, P ... p)
{
	return {mf, p...};
}

} // namespace eagine

#endif // include guard
