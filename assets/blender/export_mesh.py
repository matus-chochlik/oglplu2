#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
# usage: blender -b myfile.blend -P export_mesh.py [-- [--help|options...]]

import os
import sys
import json
import pathlib
import argparse
# ------------------------------------------------------------------------------
class ExportMeshArgParser(argparse.ArgumentParser):
    # --------------------------------------------------------------------------
    def __init__(self, **kw):
        argparse.ArgumentParser.__init__(self, **kw)

        self.add_argument(
            '--debug',
            action="store_true",
            default=False
        )
        self.add_argument(
            '--output', '-o',
            dest="output_path",
            type=os.path.realpath,
            action="store",
            default=None
        )
        self.add_argument(
            '--attrib', '-a',
            dest="attributes",
            action="append",
            default=[],
            choices=[
                "object_id",
                "position",
                "normal",
                "tangential",
                "bitangential",
                "pivot",
                "pivot_pivot",
                "vertex_pivot",
                "box_coord",
                "face_coord",
                "wrap_coord",
                "color",
                "emission",
                "weight",
                "occlusion",
                "material_id"
            ]
        )

        self.add_argument(
            '--mesh', '-m',
            dest="meshes",
            action="append",
            default=[]
        )

    # --------------------------------------------------------------------------
    def process_parsed_options(self, options):
        if options.output_path:
            options.prefix = os.path.dirname(options.output_path)
            if not os.path.isdir(options.prefix):
                pathlib.Path(options.prefix).mkdir(parents=True, exist_ok=True)
            options.output = open(options.output_path, "w")
        else:
            options.prefix = None
            options.output = sys.stdout

        if not options.attributes:
            options.attributes = ["position"]

        return options

    # --------------------------------------------------------------------------
    def parse_args(self, args):
        return self.process_parsed_options(
            argparse.ArgumentParser.parse_args(self, args)
        )

# ------------------------------------------------------------------------------
def make_argument_parser():
    return ExportMeshArgParser(
            prog=os.path.basename(__file__),
            description="""
            Blender mesh exporter script
        """
    )
# ------------------------------------------------------------------------------
def triangulate(options, obj):
    import bpy
    import bmesh
    bmsh = bmesh.new()
    bmsh.from_mesh(obj.data)
    bmesh.ops.triangulate(
        bmsh,
        faces=bmsh.faces[:],
        quad_method="BEAUTY",
        ngon_method="BEAUTY"
    )
    mesh = bpy.data.meshes.new("temp")
    bmsh.to_mesh(mesh)
    bmsh.free()
    return mesh
# ------------------------------------------------------------------------------
def fixnum(x):
    return x if x != round(x) else int(x)
# ------------------------------------------------------------------------------
def export_single(options, name, mesh):
    result = {}
    result["name"] = name
    vertex_count = 0
    positions = []
    for poly in mesh.polygons:
        s = poly.loop_start
        c = poly.loop_total
        for loop_index in range(s, s + c):
            coord = mesh.vertices[mesh.loops[loop_index].vertex_index].co
            positions += [fixnum(x) for x in coord]
            vertex_count += 1

    result["positions"] = [{
        "data": positions
    }]

    result["vertex_count"] = vertex_count
    result["instructions"] = [{
        "first": 0,
        "count": vertex_count
    }]
    return result
# ------------------------------------------------------------------------------
def do_export(options):
    try:
        import bpy
        result = []

        for name, obj in [(n, bpy.data.objects[n]) for n in options.meshes]:
            mesh = triangulate(options, obj)
            result.append(export_single(options, name, mesh))
            del mesh

        json.dump(result, options.output, separators=(',', ':'))
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
            do_export(options)
    finally:
        try:
            import bpy
            bpy.ops.wm.quit_blender()
        except: pass
# ------------------------------------------------------------------------------
main()


