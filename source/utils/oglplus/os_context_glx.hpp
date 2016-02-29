/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_GLX_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_GLX_1107121519_HPP

#include <oglplus/glx/context.hpp>
#include <oglplus/glx/fb_configs.hpp>
#include <oglplus/glx/version.hpp>
#include <oglplus/glx/pbuffer.hpp>
#include <oglplus/x11/color_map.hpp>
#include <oglplus/x11/visual_info.hpp>
#include <oglplus/x11/display.hpp>
#include "os_context_common.hpp"

namespace oglplus {

class offscreen_context_glx
{
private:
	static
	const int* visual_attribs(void)
	noexcept
	{
		static int vas[] =
		{
			GLX_X_RENDERABLE    , True,
			GLX_DRAWABLE_TYPE   , GLX_PBUFFER_BIT,
			GLX_RENDER_TYPE     , GLX_RGBA_BIT,
			GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
			GLX_RED_SIZE        , 8,
			GLX_GREEN_SIZE      , 8,
			GLX_BLUE_SIZE       , 8,
			GLX_ALPHA_SIZE      , 8,
			GLX_DEPTH_SIZE      , 24,
			GLX_STENCIL_SIZE    , 8,
			None
		};
		return vas;
	}

	static
	const int* pbuffer_attribs(const offscreen_context_params& p)
	noexcept
	{
		static int pbas [] = {
			GLX_PBUFFER_WIDTH  , 64,
			GLX_PBUFFER_HEIGHT , 64,
			None
		};
		pbas[1] = p.width;
		pbas[3] = p.height;
		return pbas;
	}

	x11::Display display;
	glx::Version version;
	glx::FBConfig fbconfig;
	x11::VisualInfo visualinfo;
	glx::Context context;
	glx::Pbuffer pbuffer;
public:
	offscreen_context_glx(const offscreen_context_params& p)
	 : display()
	 , version(display)
	 , fbconfig(glx::FBConfigs(display, visual_attribs()).FindBest(display))
	 , visualinfo(display, fbconfig)
	 , context(display, fbconfig, p.version_major,p.version_minor,true,true)
	 , pbuffer(display, fbconfig, pbuffer_attribs(p))
	{
		context.MakeCurrent(pbuffer);
	}
};

} // namespace oglplus

#endif
