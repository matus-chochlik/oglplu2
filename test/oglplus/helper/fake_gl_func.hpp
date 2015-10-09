/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_OGLPLUS_HELPER_FAKE_GL_FUNC_HPP
#define TEST_OGLPLUS_HELPER_FAKE_GL_FUNC_HPP

#include <cstring>
#include <oglplus/utils/nothing.hpp>

namespace oglplus {

template <typename R, typename ... P>
class fake_gl_func_tester;

template <typename R, typename ... P>
class fake_gl_func_tester_base;

template <typename R, typename ... P>
class fake_gl_func_tester_base
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
	fake_gl_func_tester_base(
		const char* func_name,
		const std::tuple<P...>& params
	): _expected_func_name(func_name)
	 , _expected_params(params)
	 , _func_called(0)
	 , _func_ok(false)
	 , _params_ok(false)
	{ }

	fake_gl_func_tester_base(const char* func_name)
	 : fake_gl_func_tester_base(func_name, std::tuple<P...>())
	{ }

	fake_gl_func_tester<R, P...>& self(void)
	{
		return static_cast<fake_gl_func_tester<R, P...>&>(*this);
	}

	fake_gl_func_tester<R, P...>& reset_params(const P& ... p)
	{
		_expected_params = std::tie(p...);
		_params_ok = false;
		return self();
	}

	fake_gl_func_tester<R, P...>& called_function(const char* func_name)
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
class fake_gl_func_tester
 : public fake_gl_func_tester_base<R, P...>
{
private:
	R _result;
public:
	fake_gl_func_tester(const char* func_name)
	 : fake_gl_func_tester_base<R,P...>(func_name)
	{ }

	fake_gl_func_tester& reset_result(const R& result)
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
class fake_gl_func_tester<void, P...>
 : public fake_gl_func_tester_base<void, P...>
{
public:
	fake_gl_func_tester(const char* func_name)
	 : fake_gl_func_tester_base<void, P...>(func_name)
	{ }

	template <typename ... A>
	void operator ()(const A& ... a)
	{
		this->_handle_call(a...);
	}
};

static inline
GLenum fake_glGetError(void)
noexcept
{
	return GL_NO_ERROR;
}

#define OGLPLUS_GLFUNC(FUNC) \
	fake_gl##FUNC.called_function(#FUNC)

#define OGLPLUS_GL_GET_ERROR() \
	oglplus::fake_glGetError()

} // namespace oglplus

#endif // include guard
