/**
 *  @file oalplus/error/info_alc.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oalplus {
//------------------------------------------------------------------------------
constexpr inline
error_info_alc::
error_info_alc(ALCdevice* device, ALenum alc_err_code)
noexcept
 : error_info_base<error_info_alc>(alc_err_code)
#if !OALPLUS_ERROR_NO_DEVICE
 , _device(device)
#endif
#if !OALPLUS_ERROR_NO_CONTEXT
 , _context(nullptr)
#endif
{ }
//------------------------------------------------------------------------------
inline
error_info_alc&
error_info_alc::
alc_device(::ALCdevice* alc_dev)
noexcept
{
#if !OALPLUS_ERROR_NO_DEVICE
	_device = alc_dev;
#else
	(void)alc_dev;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
::ALCdevice*
error_info_alc::
alc_device(void) const
noexcept
{
#if !OALPLUS_ERROR_NO_DEVICE
	return _device;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
inline
error_info_alc&
error_info_alc::
alc_context(const ::ALCcontext* alc_ctx)
noexcept
{
#if !OALPLUS_ERROR_NO_CONTEXT
	_context = alc_ctx;
#else
	(void)alc_ctx;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const ::ALCcontext*
error_info_alc::
alc_context(void) const
noexcept
{
#if !OALPLUS_ERROR_NO_CONTEXT
	return _context;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
} // namespace oalplus
