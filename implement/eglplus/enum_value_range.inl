//  File implement/eglplus/enum_value_range.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//

namespace eglplus {

EGLPLUS_LIB_FUNC
std::pair<const void*, std::size_t>
get_enum_value_range(const any_enum_class& aec)
noexcept
{
	switch(aec._type_id)
	{
		case 0: /* color_buffer_type */
		{
			static const EGLenum vr[] = {
#ifdef EGL_LUMINANCE_BUFFER
				EGL_LUMINANCE_BUFFER,
#endif
#ifdef EGL_RGB_BUFFER
				EGL_RGB_BUFFER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 1: /* config_attrib */
		{
			static const EGLenum vr[] = {
#ifdef EGL_ALPHA_MASK_SIZE
				EGL_ALPHA_MASK_SIZE,
#endif
#ifdef EGL_ALPHA_SIZE
				EGL_ALPHA_SIZE,
#endif
#ifdef EGL_BIND_TO_TEXTURE_RGB
				EGL_BIND_TO_TEXTURE_RGB,
#endif
#ifdef EGL_BIND_TO_TEXTURE_RGBA
				EGL_BIND_TO_TEXTURE_RGBA,
#endif
#ifdef EGL_BLUE_SIZE
				EGL_BLUE_SIZE,
#endif
#ifdef EGL_BUFFER_SIZE
				EGL_BUFFER_SIZE,
#endif
#ifdef EGL_COLOR_BUFFER_TYPE
				EGL_COLOR_BUFFER_TYPE,
#endif
#ifdef EGL_CONFIG_CAVEAT
				EGL_CONFIG_CAVEAT,
#endif
#ifdef EGL_CONFIG_ID
				EGL_CONFIG_ID,
#endif
#ifdef EGL_CONFORMANT
				EGL_CONFORMANT,
#endif
#ifdef EGL_DEPTH_SIZE
				EGL_DEPTH_SIZE,
#endif
#ifdef EGL_GREEN_SIZE
				EGL_GREEN_SIZE,
#endif
#ifdef EGL_LEVEL
				EGL_LEVEL,
#endif
#ifdef EGL_LUMINANCE_SIZE
				EGL_LUMINANCE_SIZE,
#endif
#ifdef EGL_MAX_PBUFFER_HEIGHT
				EGL_MAX_PBUFFER_HEIGHT,
#endif
#ifdef EGL_MAX_PBUFFER_PIXELS
				EGL_MAX_PBUFFER_PIXELS,
#endif
#ifdef EGL_MAX_PBUFFER_WIDTH
				EGL_MAX_PBUFFER_WIDTH,
#endif
#ifdef EGL_MAX_SWAP_INTERVAL
				EGL_MAX_SWAP_INTERVAL,
#endif
#ifdef EGL_MIN_SWAP_INTERVAL
				EGL_MIN_SWAP_INTERVAL,
#endif
#ifdef EGL_NATIVE_RENDERABLE
				EGL_NATIVE_RENDERABLE,
#endif
#ifdef EGL_NATIVE_VISUAL_ID
				EGL_NATIVE_VISUAL_ID,
#endif
#ifdef EGL_NATIVE_VISUAL_TYPE
				EGL_NATIVE_VISUAL_TYPE,
#endif
#ifdef EGL_RED_SIZE
				EGL_RED_SIZE,
#endif
#ifdef EGL_RENDERABLE_TYPE
				EGL_RENDERABLE_TYPE,
#endif
#ifdef EGL_SAMPLES
				EGL_SAMPLES,
#endif
#ifdef EGL_SAMPLE_BUFFERS
				EGL_SAMPLE_BUFFERS,
#endif
#ifdef EGL_STENCIL_SIZE
				EGL_STENCIL_SIZE,
#endif
#ifdef EGL_SURFACE_TYPE
				EGL_SURFACE_TYPE,
#endif
#ifdef EGL_TRANSPARENT_BLUE_VALUE
				EGL_TRANSPARENT_BLUE_VALUE,
#endif
#ifdef EGL_TRANSPARENT_GREEN_VALUE
				EGL_TRANSPARENT_GREEN_VALUE,
#endif
#ifdef EGL_TRANSPARENT_RED_VALUE
				EGL_TRANSPARENT_RED_VALUE,
#endif
#ifdef EGL_TRANSPARENT_TYPE
				EGL_TRANSPARENT_TYPE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 2: /* config_caveat */
		{
			static const EGLenum vr[] = {
#ifdef EGL_NONE
				EGL_NONE,
#endif
#ifdef EGL_NON_CONFORMANT_CONFIG
				EGL_NON_CONFORMANT_CONFIG,
#endif
#ifdef EGL_SLOW_CONFIG
				EGL_SLOW_CONFIG,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 3: /* context_attrib */
		{
			static const EGLenum vr[] = {
#ifdef EGL_CONTEXT_FLAGS
				EGL_CONTEXT_FLAGS,
#endif
#ifdef EGL_CONTEXT_MAJOR_VERSION
				EGL_CONTEXT_MAJOR_VERSION,
#endif
#ifdef EGL_CONTEXT_MINOR_VERSION
				EGL_CONTEXT_MINOR_VERSION,
#endif
#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
				EGL_CONTEXT_OPENGL_PROFILE_MASK,
#endif
#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
				EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 4: /* context_flag */
		{
			static const EGLenum vr[] = {
#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
				EGL_CONTEXT_OPENGL_DEBUG_BIT,
#endif
#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
				EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT,
#endif
#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
				EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 5: /* error_code */
		{
			static const EGLenum vr[] = {
#ifdef EGL_BAD_ACCESS
				EGL_BAD_ACCESS,
#endif
#ifdef EGL_BAD_ALLOC
				EGL_BAD_ALLOC,
#endif
#ifdef EGL_BAD_ATTRIBUTE
				EGL_BAD_ATTRIBUTE,
#endif
#ifdef EGL_BAD_CONFIG
				EGL_BAD_CONFIG,
#endif
#ifdef EGL_BAD_CONTEXT
				EGL_BAD_CONTEXT,
#endif
#ifdef EGL_BAD_CURRENT_SURFACE
				EGL_BAD_CURRENT_SURFACE,
#endif
#ifdef EGL_BAD_DISPLAY
				EGL_BAD_DISPLAY,
#endif
#ifdef EGL_BAD_MATCH
				EGL_BAD_MATCH,
#endif
#ifdef EGL_BAD_NATIVE_PIXMAP
				EGL_BAD_NATIVE_PIXMAP,
#endif
#ifdef EGL_BAD_NATIVE_WINDOW
				EGL_BAD_NATIVE_WINDOW,
#endif
#ifdef EGL_BAD_PARAMETER
				EGL_BAD_PARAMETER,
#endif
#ifdef EGL_BAD_SURFACE
				EGL_BAD_SURFACE,
#endif
#ifdef EGL_CONTEXT_LOST
				EGL_CONTEXT_LOST,
#endif
#ifdef EGL_NOT_INITIALIZED
				EGL_NOT_INITIALIZED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 6: /* gl_colorspace */
		{
			static const EGLenum vr[] = {
#ifdef EGL_GL_COLORSPACE_LINEAR
				EGL_GL_COLORSPACE_LINEAR,
#endif
#ifdef EGL_GL_COLORSPACE_sRGB
				EGL_GL_COLORSPACE_sRGB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 7: /* multisample_resolve */
		{
			static const EGLenum vr[] = {
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
				EGL_MULTISAMPLE_RESOLVE_BOX,
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
				EGL_MULTISAMPLE_RESOLVE_DEFAULT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 8: /* opengl_profile_bit */
		{
			static const EGLenum vr[] = {
#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
				EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT,
#endif
#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
				EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 9: /* opengl_rns */
		{
			static const EGLenum vr[] = {
#ifdef EGL_LOSE_CONTEXT_ON_RESET
				EGL_LOSE_CONTEXT_ON_RESET,
#endif
#ifdef EGL_NO_RESET_NOTIFICATION
				EGL_NO_RESET_NOTIFICATION,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 10: /* render_buffer */
		{
			static const EGLenum vr[] = {
#ifdef EGL_BACK_BUFFER
				EGL_BACK_BUFFER,
#endif
#ifdef EGL_SINGLE_BUFFER
				EGL_SINGLE_BUFFER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 11: /* renderable_type_bit */
		{
			static const EGLenum vr[] = {
#ifdef EGL_OPENGL_BIT
				EGL_OPENGL_BIT,
#endif
#ifdef EGL_OPENGL_ES2_BIT
				EGL_OPENGL_ES2_BIT,
#endif
#ifdef EGL_OPENGL_ES3_BIT
				EGL_OPENGL_ES3_BIT,
#endif
#ifdef EGL_OPENGL_ES_BIT
				EGL_OPENGL_ES_BIT,
#endif
#ifdef EGL_OPENVG_BIT
				EGL_OPENVG_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 12: /* rendering_api */
		{
			static const EGLenum vr[] = {
#ifdef EGL_NONE
				EGL_NONE,
#endif
#ifdef EGL_OPENGL_API
				EGL_OPENGL_API,
#endif
#ifdef EGL_OPENGL_ES_API
				EGL_OPENGL_ES_API,
#endif
#ifdef EGL_OPENVG_API
				EGL_OPENVG_API,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 13: /* string_query */
		{
			static const EGLenum vr[] = {
#ifdef EGL_CLIENT_APIS
				EGL_CLIENT_APIS,
#endif
#ifdef EGL_EXTENSIONS
				EGL_EXTENSIONS,
#endif
#ifdef EGL_VENDOR
				EGL_VENDOR,
#endif
#ifdef EGL_VERSION
				EGL_VERSION,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 14: /* surface_attrib */
		{
			static const EGLenum vr[] = {
#ifdef EGL_CONFIG_ID
				EGL_CONFIG_ID,
#endif
#ifdef EGL_GL_COLORSPACE
				EGL_GL_COLORSPACE,
#endif
#ifdef EGL_HEIGHT
				EGL_HEIGHT,
#endif
#ifdef EGL_HORIZONTAL_RESOLUTION
				EGL_HORIZONTAL_RESOLUTION,
#endif
#ifdef EGL_LARGEST_PBUFFER
				EGL_LARGEST_PBUFFER,
#endif
#ifdef EGL_MIPMAP_LEVEL
				EGL_MIPMAP_LEVEL,
#endif
#ifdef EGL_MIPMAP_TEXTURE
				EGL_MIPMAP_TEXTURE,
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE
				EGL_MULTISAMPLE_RESOLVE,
#endif
#ifdef EGL_PIXEL_ASPECT_RATIO
				EGL_PIXEL_ASPECT_RATIO,
#endif
#ifdef EGL_RENDER_BUFFER
				EGL_RENDER_BUFFER,
#endif
#ifdef EGL_SWAP_BEHAVIOR
				EGL_SWAP_BEHAVIOR,
#endif
#ifdef EGL_TEXTURE_FORMAT
				EGL_TEXTURE_FORMAT,
#endif
#ifdef EGL_TEXTURE_TARGET
				EGL_TEXTURE_TARGET,
#endif
#ifdef EGL_VERTICAL_RESOLUTION
				EGL_VERTICAL_RESOLUTION,
#endif
#ifdef EGL_VG_ALPHA_FORMAT
				EGL_VG_ALPHA_FORMAT,
#endif
#ifdef EGL_VG_COLORSPACE
				EGL_VG_COLORSPACE,
#endif
#ifdef EGL_WIDTH
				EGL_WIDTH,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 15: /* surface_type_bit */
		{
			static const EGLenum vr[] = {
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
				EGL_MULTISAMPLE_RESOLVE_BOX_BIT,
#endif
#ifdef EGL_PBUFFER_BIT
				EGL_PBUFFER_BIT,
#endif
#ifdef EGL_PIXMAP_BIT
				EGL_PIXMAP_BIT,
#endif
#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
				EGL_SWAP_BEHAVIOR_PRESERVED_BIT,
#endif
#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
				EGL_VG_ALPHA_FORMAT_PRE_BIT,
#endif
#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
				EGL_VG_COLORSPACE_LINEAR_BIT,
#endif
#ifdef EGL_WINDOW_BIT
				EGL_WINDOW_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 16: /* swap_behavior */
		{
			static const EGLenum vr[] = {
#ifdef EGL_BUFFER_DESTROYED
				EGL_BUFFER_DESTROYED,
#endif
#ifdef EGL_BUFFER_PRESERVED
				EGL_BUFFER_PRESERVED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 17: /* texture_format */
		{
			static const EGLenum vr[] = {
#ifdef EGL_NO_TEXTURE
				EGL_NO_TEXTURE,
#endif
#ifdef EGL_TEXTURE_RGB
				EGL_TEXTURE_RGB,
#endif
#ifdef EGL_TEXTURE_RGBA
				EGL_TEXTURE_RGBA,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 18: /* texture_target */
		{
			static const EGLenum vr[] = {
#ifdef EGL_NO_TEXTURE
				EGL_NO_TEXTURE,
#endif
#ifdef EGL_TEXTURE_2D
				EGL_TEXTURE_2D,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 19: /* transparent_type */
		{
			static const EGLenum vr[] = {
#ifdef EGL_NONE
				EGL_NONE,
#endif
#ifdef EGL_TRANSPARENT_RGB
				EGL_TRANSPARENT_RGB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 20: /* vg_alpha_format */
		{
			static const EGLenum vr[] = {
#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
				EGL_VG_ALPHA_FORMAT_NONPRE,
#endif
#ifdef EGL_VG_ALPHA_FORMAT_PRE
				EGL_VG_ALPHA_FORMAT_PRE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 21: /* vg_colorspace */
		{
			static const EGLenum vr[] = {
#ifdef EGL_VG_COLORSPACE_LINEAR
				EGL_VG_COLORSPACE_LINEAR,
#endif
#ifdef EGL_VG_COLORSPACE_sRGB
				EGL_VG_COLORSPACE_sRGB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
	default:;
	}

	(void)aec;
	return {nullptr, 0};
}

} // namespace eglplus
