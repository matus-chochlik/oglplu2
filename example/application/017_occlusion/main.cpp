/// @example application/017_occlusion/main.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/camera.hpp>
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/embed.hpp>
#include <eagine/shapes/value_tree.hpp>
#include <eagine/timeout.hpp>
#include <eagine/value_tree/json.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_occlusion : public application {
public:
    example_occlusion(
      execution_context&,
      video_context&,
      string_view shape_file_path,
      string_view color_variant_name);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void clean_up() noexcept final;

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    std::vector<oglp::shape_draw_operation> _ops;
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name colors;
    oglp::owned_buffer_name normals;
    oglp::owned_buffer_name occlusion;
    oglp::owned_buffer_name roughness;
    oglp::owned_buffer_name indices;

    oglp::owned_program_name prog;

    orbiting_camera camera;
    oglp::uniform_location camera_loc;
};
//------------------------------------------------------------------------------
example_occlusion::example_occlusion(
  execution_context& ec,
  video_context& vc,
  string_view shape_file_path,
  string_view color_variant_name)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    // vertex shader
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    oglp::owned_shader_name vs;
    gl.create_shader(GL.vertex_shader) >> vs;
    auto cleanup_vs = gl.delete_shader.raii(vs);
    gl.shader_source(vs, oglp::glsl_string_ref(vs_source.unpack(ec)));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_source = embed(EAGINE_ID(FragShader), "fragment.glsl");
    oglp::owned_shader_name fs;
    gl.create_shader(GL.fragment_shader) >> fs;
    auto cleanup_fs = gl.delete_shader.raii(fs);
    gl.shader_source(fs, oglp::glsl_string_ref(fs_source.unpack(ec)));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // geometry
    auto load_shape_data = [&]() {
        if(shape_file_path) {
            if(const auto json_content{file_contents(shape_file_path)}) {
                if(const auto json_text = as_chars(json_content.block())) {
                    return valtree::from_json_text(json_text, ec.as_parent());
                }
            }
        }
        const auto json_src{embed(EAGINE_ID(ShapeJson), "traffic_cone.json")};
        return valtree::from_json_text(
          as_chars(json_src.unpack(ec)), ec.as_parent());
    };

    oglp::shape_generator shape(
      glapi, shapes::from_value_tree(load_shape_data(), ec.as_parent()));

    _ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(_ops));

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    oglp::vertex_attrib_location position_loc{0};
    gl.gen_buffers() >> positions;
    shape.attrib_setup(
      glapi,
      vao,
      positions,
      position_loc,
      eagine::shapes::vertex_attrib_kind::position,
      _ctx.buffer());
    gl.bind_attrib_location(prog, position_loc, "Position");

    // colors
    oglp::vertex_attrib_location color_loc{1};
    gl.gen_buffers() >> colors;
    shape.attrib_setup(
      glapi,
      vao,
      colors,
      color_loc,
      shape.find_variant_or(
        eagine::shapes::vertex_attrib_kind::color, color_variant_name, 0),
      _ctx.buffer());
    gl.bind_attrib_location(prog, color_loc, "Color");

    // normals
    oglp::vertex_attrib_location normal_loc{2};
    gl.gen_buffers() >> normals;
    shape.attrib_setup(
      glapi,
      vao,
      normals,
      normal_loc,
      eagine::shapes::vertex_attrib_kind::normal,
      _ctx.buffer());
    gl.bind_attrib_location(prog, normal_loc, "Normal");

    // occlusion
    oglp::vertex_attrib_location occlusion_loc{3};
    gl.gen_buffers() >> occlusion;
    shape.attrib_setup(
      glapi,
      vao,
      occlusion,
      occlusion_loc,
      shape.find_variant_or(
        eagine::shapes::vertex_attrib_kind::occlusion, "AO", 0),
      _ctx.buffer());
    gl.bind_attrib_location(prog, occlusion_loc, "Occlusion");

    // roughness
    oglp::vertex_attrib_location roughness_loc{4};
    gl.gen_buffers() >> roughness;
    shape.attrib_setup(
      glapi,
      vao,
      roughness,
      roughness_loc,
      shape.find_variant_or(
        eagine::shapes::vertex_attrib_kind::weight, "Roughness", 0),
      _ctx.buffer());
    gl.bind_attrib_location(prog, roughness_loc, "Roughness");

    // indices
    gl.gen_buffers() >> indices;
    shape.index_setup(glapi, indices, _ctx.buffer());

    // camera
    const auto bs = shape.bounding_sphere();
    const auto sr = bs.radius();
    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    camera.set_target(bs.center())
      .set_near(sr * 0.1F)
      .set_far(sr * 5.0F)
      .set_orbit_min(sr * 1.2F)
      .set_orbit_max(sr * 2.4F)
      .set_fov(degrees_(75.F));

    gl.clear_color(0.45F, 0.45F, 0.45F, 1.0F);
    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);

    camera.connect_inputs(ec).basic_input_mapping(ec);
    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_occlusion::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_occlusion::update() noexcept {
    auto& state = _ctx.state();
    if(state.is_active()) {
        _is_done.reset();
    }
    if(state.user_idle_too_long()) {
        camera.idle_update(state);
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    if(camera.has_changed()) {
        glapi.set_uniform(prog, camera_loc, camera.matrix(_video));
    }
    oglp::draw_using_instructions(glapi, view(_ops));

    _video.commit();
}
//------------------------------------------------------------------------------
void example_occlusion::clean_up() noexcept {
    auto& gl = _video.gl_api();

    gl.delete_program(std::move(prog));
    gl.delete_buffers(std::move(indices));
    gl.delete_buffers(std::move(roughness));
    gl.delete_buffers(std::move(occlusion));
    gl.delete_buffers(std::move(normals));
    gl.delete_buffers(std::move(colors));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));

    _video.end();
}
//------------------------------------------------------------------------------
class example_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.no_audio().require_input().require_video();
        return true;
    }

    auto check_requirements(video_context& vc) -> bool {
        auto& [gl, GL] = vc.gl_api();

        return gl.disable && gl.clear_color && gl.create_shader &&
               gl.shader_source && gl.compile_shader && gl.create_program &&
               gl.attach_shader && gl.link_program && gl.use_program &&
               gl.gen_buffers && gl.bind_buffer && gl.buffer_data &&
               gl.gen_vertex_arrays && gl.bind_vertex_array &&
               gl.get_attrib_location && gl.vertex_attrib_pointer &&
               gl.enable_vertex_attrib_array && gl.draw_arrays &&
               GL.vertex_shader && GL.fragment_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    std::string shape_file_path;
                    ec.app_config().fetch("example.shape", shape_file_path);

                    std::string color_variant_name{"Color"};
                    ec.app_config().fetch("example.color", color_variant_name);

                    return {std::make_unique<example_occlusion>(
                      ec, vc, shape_file_path, color_variant_name)};
                }
            }
        }
        return {};
    }
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad> {
    return {std::make_unique<example_launchpad>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
