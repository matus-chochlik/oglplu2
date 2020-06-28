#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
# usage: blender -b myfile.blend -P bake_light.py [-- [--help|options...]]

import os
import sys
import math
import pathlib
import argparse
# ------------------------------------------------------------------------------
class BakeLightArgParser(argparse.ArgumentParser):
    # --------------------------------------------------------------------------
    def _distance(self, x):
        try:
            f = float(x)
            assert(f >= 0.0)
            return f
        except:
            self.error("`%s' is not a valid distance value" % str(x))
    # --------------------------------------------------------------------------
    def _index(self, x):
        try:
            i = int(x)
            assert(i >= 0)
            return i
        except:
            self.error("`%s' is not a valid index value" % str(x))
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
            '--debug',
            action="store_true",
            default=False
        )

        self.add_argument(
            '--size', '-s',
            type=self._positive_int,
            action="store",
            default=512
        )

        self.add_argument(
            '--target', '-t',
            type=str,
            action="store",
            default="BakeTarget"
        )

        self.add_argument(
            '--positions', '-p',
            type=str,
            action="store",
            default="LightPositions"
        )

        self.add_argument(
            '--distances', '-d',
            type=self._distance,
            action="append",
            default=[]
        )

        self.add_argument(
            '--lights', '-l',
            type=str,
            action="append",
            default=[]
        )

        self.add_argument(
            '--index', '-i',
            type=self._index,
            action="append",
            default=[]
        )

        self.add_argument(
            '--prefix', '-P',
            type=os.path.realpath,
            action="store",
            default="/tmp"
        )

        self.add_argument(
            '--bake-type', '-T',
            type=str,
            action="store",
            default="COMBINED",
            choices=[
                "COMBINED",
                "AO",
                "SHADOW",
                "EMIT",
                "DIFFUSE",
                "GLOSSY",
                "TRANSMISSION"
            ]
        )

        self.add_argument(
            '--engine', '-E',
            type=str,
            action="store",
            default=None,
            choices=["CYCLES", "BLENDER_EEVEE", "BLENDER_WORKBENCH"]
        )

        self.add_argument(
            '--samples', '-S',
            type=self._positive_int,
            action="store",
            default = 16*1024
        )
    # --------------------------------------------------------------------------
    def process_parsed_options(self, options):
        if not options.distances:
            options.distances = [1.0]
        if not options.lights:
            options.lights = ["Light"]
        while len(options.distances) < len(options.lights):
            options.distances.append(options.distances[-1])

        return options
    # --------------------------------------------------------------------------
    def parse_args(self, args):
        return self.process_parsed_options(
            argparse.ArgumentParser.parse_args(self, args)
        )

# ------------------------------------------------------------------------------
def make_argument_parser():
    return BakeLightArgParser(
            prog=os.path.basename(__file__),
            description="""
            Blender object lighting texture bake script
        """
    )
# ------------------------------------------------------------------------------
def do_bake(options):
    try:
        import bpy

        if not os.path.isdir(options.prefix):
            pathlib.Path(options.prefix).mkdir(parents=True, exist_ok=True)

        scene = bpy.context.scene
        if options.engine:
            scene.render.engine = options.engine
        if options.samples:
            scene.render.bake_samples = options.samples
            scene.cycles.samples = options.samples

        target = bpy.data.objects[options.target]
        positions = bpy.data.objects[options.positions]
        lights = [bpy.data.objects[l] for l in options.lights]
        bake_mat = target.active_material
        bake_mat.use_nodes = True
        bake_node = bake_mat.node_tree.nodes.new("ShaderNodeTexImage")

        if options.index:
            indices = options.index
        else: indices = range(len(positions.data.vertices))

        target.select_set(True)
        for i in indices:
            pos = positions.data.vertices[i].co
            for l in range(len(lights)):
                lights[l].location = pos * options.distances[l]

            baked_image = bpy.data.images.new(
                "BakeImage",
                alpha=False,
                width=options.size,
                height=options.size
            )
            baked_image.file_format = 'PNG'
            bake_node.image = baked_image

            baked_image.filepath = os.path.realpath("%s/%s_%f_%f_%f.png" % (
                options.prefix,
                options.bake_type,
                pos.x,
                pos.y,
                pos.z
            ))
        
            bpy.ops.object.bake(
                type=options.bake_type,
                use_clear=True
            )
            baked_image.save()

        bpy.data.images.remove(baked_image)
        bpy.data.materials.remove(bake_mat)

    except ModuleNotFoundError:
        sys.stderr.write("must be run from blender!\n")
# ------------------------------------------------------------------------------
def main():
    try:
        arg_parser = make_argument_parser()
        try: args = sys.argv[sys.argv.index("--") + 1:]
        except ValueError: args = sys.argv[1:]
        options = arg_parser.parse_args(args)
        if options.debug:
            print(options)
        else:
            do_bake(options)
    finally:
        try:
            import bpy
            bpy.ops.wm.quit_blender()
        except: pass
# ------------------------------------------------------------------------------
main()




