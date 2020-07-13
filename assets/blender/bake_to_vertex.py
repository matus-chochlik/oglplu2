#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
# usage: blender -b myfile.blend -P bake_to_vertex.py [-- [--help|options...]]

import os
import sys
import math
import pathlib
import argparse
# ------------------------------------------------------------------------------
class BakeLightArgParser(argparse.ArgumentParser):
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
            default=256
        )

        self.add_argument(
            '--target', '-t',
            type=str,
            action="store",
            default="BakeTarget"
        )

        self.add_argument(
            '--keep-image', '-k',
            action="store_true",
            default=False
        )

        self.add_argument(
            '--path', '-P',
            type=os.path.realpath,
            action="store",
            default=None
        )

        self.add_argument(
            '--as-weights', '-w',
            action="store_true",
            default=False
        )

        self.add_argument(
            '--bake-type', '-T',
            dest="bake_type",
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
            '--combined',
            dest="bake_type",
            action="store_const",
            const="COMBINED"
        )

        self.add_argument(
            '--ao',
            dest="bake_type",
            action="store_const",
            const="AO"
        )

        self.add_argument(
            '--shadow',
            dest="bake_type",
            action="store_const",
            const="SHADOW"
        )

        self.add_argument(
            '--emit',
            dest="bake_type",
            action="store_const",
            const="EMIT"
        )

        self.add_argument(
            '--diffuse',
            dest="bake_type",
            action="store_const",
            const="DIFFUSE"
        )

        self.add_argument(
            '--transmission',
            dest="bake_type",
            action="store_const",
            const="TRANSMISSION"
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
            default = 8*1024
        )
    # --------------------------------------------------------------------------
    def process_parsed_options(self, options):
        options.prefix = None
        if options.keep_image:
            if options.path is None:
                options.path = os.path.join('/tmp', '%s.png' % options.bake_type)
                options.prefix = os.path.dirname(options.path)

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
            Blender bake to vertex color script
        """
    )
# ------------------------------------------------------------------------------
def do_bake(options):
    try:
        import bpy

        if options.prefix and not os.path.isdir(options.prefix):
            pathlib.Path(options.prefix).mkdir(parents=True, exist_ok=True)

        scene = bpy.context.scene
        if options.engine:
            scene.render.engine = options.engine
        if options.samples:
            scene.render.bake_samples = options.samples
            scene.cycles.samples = options.samples

        bpy.ops.object.mode_set(mode = "OBJECT")
        target = bpy.data.objects[options.target]
        target.select_set(True)

        mat_info = [
            (
                mat,
                mat.node_tree.nodes.new("ShaderNodeTexImage"),
                bpy.data.images.new(
                    "%s-BakeImage" % mat.name,
                    alpha=True,
                    width=options.size,
                    height=options.size
                )
            ) for mat in target.data.materials
        ]
        for bake_mat, bake_node, bake_image in mat_info:
            bake_mat.use_nodes = True
            bake_mat.node_tree.nodes.active = bake_node
            bake_node.image = bake_image
            bake_node.select = True
            if options.keep_image:
                bake_image.file_format = 'PNG'
                bake_image.filepath = os.path.join(
                    options.prefix,
                    "%s-%s" % (bake_mat.name, os.path.basename(options.prefix))
                )
    
        bpy.ops.object.bake(
            type=options.bake_type,
            use_clear=True
        )

        mesh = target.data
        if options.as_weights:
            vgroup = None
            if target.vertex_groups:
                try:
                    vgroup = target.vertex_groups[options.bake_type]
                except KeyError:
                    pass

            if not vgroup:
                vgroup = target.vertex_groups.new(
                    name=options.bake_type
                )

            def _store_vertex_color(vertex_index, loop_index, c):
                weight = 0.2126 * c[0] + 0.7152 * c[1] + 0.0722 * c[2]
                vgroup.add([vertex_index], weight, "REPLACE")

        else:
            vcolors = None
            if mesh.vertex_colors:
                try:
                    vcolors = mesh.vertex_colors[options.bake_type]
                except KeyError:
                    pass

            if not vcolors:
                vcolors = mesh.vertex_colors.new(
                    name=options.bake_type
                )

            def _store_vertex_color(vertex_index, loop_index, color):
                vcolors.data[loop_index].color = color

        uvcoords = mesh.uv_layers.active

        for bake_mat, bake_node, bake_image in mat_info:
            for meshface in mesh.polygons:
                face_mat = target.material_slots[meshface.material_index].material
                if bake_mat == face_mat:
                    nc = bake_image.channels
                    for loop_index in meshface.loop_indices:
                        meshloop = mesh.loops[loop_index]
                        vertex_index = meshloop.vertex_index
                        try:
                            uv = uvcoords.data[loop_index].uv
                            w, h = uv * options.size
                        except IndexError:
                            w = 0.5
                            h = 0.5
                        idx = (options.size * int(h) + int(w)) * nc
                        pixel = tuple(
                            bake_image.pixels[idx + c] if c < nc else 1.0
                            for c in range(4)
                        )
                        _store_vertex_color(vertex_index, loop_index, pixel)

        for bake_mat, bake_node, bake_image in mat_info:
            if options.keep_image:
                bake_image.save()
                print("saved image to %s" % bake_image.filepath)
            bpy.data.images.remove(bake_image)
            bake_mat.node_tree.nodes.remove(bake_node)

        bpy.ops.wm.save_as_mainfile()

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




