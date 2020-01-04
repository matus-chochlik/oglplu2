#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
# usage: blender -b myfile.blend -P render_cubemap.py [-- [--help|options...]]

import os
import sys
import math
import argparse
# ------------------------------------------------------------------------------
class CubeMapArgParser(argparse.ArgumentParser):
    # --------------------------------------------------------------------------
    def _positive_int(self, x):
        try:
            i = int(x)
            assert(i > 0)
            return i
        except:
            self.error("`%s' is not a positive integer value" % str(x))
    # --------------------------------------------------------------------------
    def __init__(self, **kw):
        argparse.ArgumentParser.__init__(self, **kw)

        self.add_argument(
            '--size', '-s',
            type=self._positive_int,
            action="store",
            default=1024
        )

        self.add_argument(
            '--prefix', '-P',
            type=os.path.realpath,
            action="store",
            default="/tmp"
        )

        self.add_argument(
            '--name', '-n',
            type=str,
            action="store",
            default="cubemap"
        )

        self.add_argument(
            '--engine', '-E',
            type=str,
            action="store",
            default=None,
            choices=["CYCLES", "BLENDER_EEVEE", "BLENDER_WORKBENCH"]
        )

        self.add_argument(
            '--threads', '-T',
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--samples', '-S',
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--tile-width', '-TW',
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--tile-height', '-TH',
            type=self._positive_int,
            action="store",
            default=None
        )
    # --------------------------------------------------------------------------
    def process_parsed_options(self, options):
        return options
    # --------------------------------------------------------------------------
    def parse_args(self, args):
        return self.process_parsed_options(
            argparse.ArgumentParser.parse_args(self, args)
        )

# ------------------------------------------------------------------------------
def make_argument_parser():
    return CubeMapArgParser(
            prog=os.path.basename(__file__),
            description="""
            Blender cube-map renderer script
        """
    )
# ------------------------------------------------------------------------------
def cm_cam_rotations():
    rad_90 = math.pi/2
    rad_180 = math.pi
    rad_270 = (3*math.pi)/2

    return {
        "0-Xp": (rad_90, 0, -rad_90),
        "1-Xn": (rad_90, 0, -rad_270),
        "2-Yp": (rad_180, 0, -rad_180),
        "3-Yn": (0, 0, -rad_180),
        "4-Zp": (rad_90, 0, rad_180),
        "5-Zn": (rad_90, 0, 0),
    }
# ------------------------------------------------------------------------------
def cm_cam_rotation(axis_name):
    return cm_cam_rotations()[axis_name]
# ------------------------------------------------------------------------------
def do_render_face(axis_name, options):
    try:
        import bpy
        camname = "camera-%s" % axis_name
        camera = bpy.data.cameras.new(name=camname)
        camera.type = "PERSP"
        camera.lens_unit = "FOV"
        camera.lens = 18.0
        camobj = bpy.data.objects.new(name=camname, object_data = camera)
        camobj.location = (0.0, 0.0, 0.0)
        camobj.rotation_mode = "XYZ"
        camobj.rotation_euler = cm_cam_rotation(axis_name)

        scene = bpy.context.scene
        scene.camera = camobj
        scene.render.image_settings.color_mode ='RGBA'
        scene.render.image_settings.file_format ='PNG'
        scene.render.filepath = os.path.realpath("%s/%s-%s.png" % (
                options.prefix,
                options.name,
                axis_name
            )
        )
        scene.render.resolution_x = options.size
        scene.render.resolution_y = options.size

        if options.engine:
            scene.render.engine = options.engine
        if options.threads:
            scene.render.threads = options.threads
        if options.tile_width:
            scene.render.tile_x = options.tile_width
        if options.tile_height:
            scene.render.tile_y = options.tile_height

        if options.samples:
            scene.cycles.samples = options.samples
            
        sys.stdout.write("Rendering: %s\n" % scene.render.filepath)
        bpy.ops.render.render(write_still=True)
        
        bpy.data.objects.remove(camobj)
        bpy.data.cameras.remove(camera)
    except ModuleNotFoundError:
        sys.stderr.write("must be run from blender!\n")
# ------------------------------------------------------------------------------
def render_all(options):
    for axis_name in cm_cam_rotations():
        do_render_face(axis_name, options)
# ------------------------------------------------------------------------------
def main():
    try:
        arg_parser = make_argument_parser()
        try: args = sys.argv[sys.argv.index("--") + 1:]
        except ValueError: args = sys.argv[1:]
        options = arg_parser.parse_args(args)
        render_all(options)
    finally:
        try:
            import bpy
            bpy.ops.wm.quit_blender()
        except: pass
# ------------------------------------------------------------------------------
main()




