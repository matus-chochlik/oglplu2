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

        self.attrib_types = [
                "object_id",
                "face_normal",
                "vert_normal",
                "normal",
                "tangential",
                "bitangential",
                "pivot",
                "pivot_pivot",
                "vertex_pivot",
                "face_coord",
                "wrap_coord",
                "color",
                "material_diffuse_color",
                "material_specular_color",
                "emission",
                "weight",
                "occlusion",
                "material_id"
            ]
        self.add_argument(
            '--attrib', '-a',
            dest="attributes",
            action="append",
            default=[],
            choices=self.attrib_types
        )

        self.add_argument(
            '--color-names', '-C',
            dest="color_names",
            action="append",
            default=[]
        )

        self.add_argument(
            '--uv-names', '-U',
            dest="uv_names",
            action="append",
            default=[]
        )

        self.add_argument(
            '--group-names', '-G',
            dest="group_names",
            action="append",
            default=[]
        )

        self.add_argument(
            '--occl-names', '-O',
            dest="occl_names",
            action="append",
            default=[]
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

        for attr_type in self.attrib_types:
            do_exp = attr_type in options.attributes
            options.__dict__["exp_%s" % attr_type] = do_exp

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
def fixvec(v):
    return (v.x, v.z,-v.y)
# ------------------------------------------------------------------------------
def fixnum(x):
    return x if x != round(x) else int(x)
# ------------------------------------------------------------------------------
def get_diffuse_color(mat):
    # TODO Material.use_nodes / Material.node_tree
    return mat.diffuse_color
# ------------------------------------------------------------------------------
def get_specular_color(mat):
    # TODO Material.use_nodes / Material.node_tree
    return mat.specular_color
# ------------------------------------------------------------------------------
def has_same_values(options, obj, mesh, fl, ll, vl, fr, lr, vr):
    if vl.co != vr.co:
        return False
    if options.exp_vert_normal:
        if vl.normal != vr.normal:
            return False
    if options.exp_face_normal:
        if fl.normal != fr.normal:
            return False
    if options.exp_normal:
        if ll.normal != lr.normal:
            return False
    if options.exp_tangential:
        if ll.tangent != lr.tangent:
            return False
    if options.exp_bitangential:
        if ll.bitangent != lr.bitangent:
            return False
    if options.exp_color:
        for vcs in mesh.vertex_colors:
            if vcs.data[vl.index].color != vcs.data[vr.index].color:
                return False
    if options.exp_material_diffuse_color:
        ml = obj.material_slots[fl.material_index].material
        mr = obj.material_slots[fr.material_index].material
        if get_diffuse_color(ml) != get_diffuse_color(mr):
            return False;
    if options.exp_material_specular_color:
        ml = obj.material_slots[fl.material_index].material
        mr = obj.material_slots[fr.material_index].material
        if get_specular_color(ml) != get_specular_color(mr):
            return False;
    if options.exp_wrap_coord:
        for uvs in mesh.uv_layers:
            if uvs.data[vl.index].uv != uvs.data[vr.index].uv:
                return False
    if options.exp_weight or options.exp_occlusion:
        for grp in obj.vertex_groups:
            if grp.weight(vl.index) != grp.weight(vr.index):
                return False

    return True

# ------------------------------------------------------------------------------
def export_single(options, bdata, name, obj, mesh):
    if options.exp_normal or options.exp_tangential or options.exp_bitangential:
        mesh.calc_tangents() # TODO for each uv-map?

    result = {}
    result["name"] = name
    result["position"] = []

    if options.exp_pivot:
        result["pivot"] = []

    if options.exp_normal or options.exp_vert_normal or options.exp_face_normal:
        result["normal"] = []

    if options.exp_tangential:
        result["tangential"] = []

    if options.exp_bitangential:
        result["bitangential"] = []

    if options.exp_color or\
        options.exp_material_diffuse_color or\
        options.exp_material_specular_color:
        result["color"] = []

    if options.exp_wrap_coord:
        result["wrap_coord"] = []

    if options.exp_weight:
        result["weight"] = []

    if options.exp_occlusion:
        result["occlusion"] = []

    emitted = {}
    for meshvert in mesh.vertices:
        emitted[meshvert.index] = set()

    vertex_index = 0
    indices = []
    positions = []
    pivots = []
    vert_normals = []
    face_normals = []
    normals = []
    tangentials = []
    bitangentials = []

    colors = {}
    if options.exp_color:
        for vcs in mesh.vertex_colors:
            if (vcs.name in options.color_names) or (not options.color_names):
                colors[vcs.name] = []

    if options.exp_material_diffuse_color:
        colors["material.diffuse"] = []
    if options.exp_material_specular_color:
        colors["material.specular"] = []

    coords = {
        uvs.name: []
        for uvs in mesh.uv_layers
        if (uvs.name in options.uv_names) or (not options.uv_names)
    }

    groups = {
        grp.name: []
        for grp in obj.vertex_groups
        if (grp.name in options.group_names) or (not options.group_names)
    }

    occls = {
        grp.name: []
        for grp in obj.vertex_groups
        if grp.name in options.occl_names
    }

    for meshface in mesh.polygons:
        s = meshface.loop_start
        c = meshface.loop_total
        fn = [fixnum(x) for x in fixvec(meshface.normal)]
        for loop_index in range(s, s + c):
            meshloop = mesh.loops[loop_index]
            meshvert = mesh.vertices[meshloop.vertex_index]

            emitted_vert = emitted[meshvert.index]
            reused_vertex = False
            for old_face_index, old_loop_index, emit_index in emitted_vert:
                if has_same_values(
                    options,
                    obj,
                    mesh,
                    mesh.polygons[old_face_index],
                    mesh.loops[old_loop_index],
                    meshvert,
                    meshface,
                    meshloop,
                    meshvert
                ):
                    reused_vertex = True
                    indices.append(emit_index)

            if not reused_vertex:
                positions += [fixnum(x) for x in fixvec(meshvert.co)]
                if options.exp_pivot:
                    pivots += [fixnum(x) for x in fixvec(obj.location)]
                if options.exp_vert_normal:
                    vert_normals += [fixnum(x) for x in fixvec(meshvert.normal)]
                if options.exp_face_normal:
                    face_normals += fn
                if options.exp_normal:
                    normals +=\
                        [fixnum(x) for x in fixvec(meshloop.normal)]
                if options.exp_tangential:
                    tangentials +=\
                        [fixnum(x) for x in fixvec(meshloop.tangent)]
                if options.exp_bitangential:
                    bitangentials +=\
                        [fixnum(x) for x in fixvec(meshloop.bitangent)]
                if options.exp_color:
                    for vcs in mesh.vertex_colors:
                        vc = vcs.data[meshvert.index].color
                        try:
                            colors[vcs.name] += [fixnum(x) for x in vc]
                        except KeyError:
                            pass
                if options.exp_material_diffuse_color:
                    mat = obj.material_slots[meshface.material_index].material
                    dc = get_diffuse_color(mat)
                    colors["material.diffuse"] += [fixnum(x) for x in dc]
                if options.exp_material_specular_color:
                    mat = obj.material_slots[meshface.material_index].material
                    sc = get_specular_color(mat)
                    colors["material.specular"] += [fixnum(x) for x in sc]
                if options.exp_wrap_coord:
                    for uvs in mesh.uv_layers:
                        uv = uvs.data[meshvert.index].uv
                        try:
                            coords[uvs.name] += [fixnum(x) for x in uv]
                        except KeyError:
                            pass
                if options.exp_weight:
                    for grp in obj.vertex_groups:
                        w = grp.weight(meshvert.index)
                        try:
                            groups[grp.name].append(fixnum(w))
                        except KeyError:
                            pass
                if options.exp_occlusion:
                    for grp in obj.vertex_groups:
                        w = grp.weight(meshvert.index)
                        try:
                            occls[grp.name].append(fixnum(w))
                        except KeyError:
                            pass

                emitted_vert.add(
                    (meshface.index, meshloop.index, vertex_index)
                )
                indices.append(vertex_index)

                vertex_index += 1

    result["position"].append({
        "data": positions
    })

    if options.exp_pivot:
        result["pivot"].append({
            "data": pivots
        })

    if options.exp_normal:
        result["normal"].append({
            "data": normals
        })

    if options.exp_vert_normal:
        result["normal"].append({
            "name": "vertex",
            "data": vert_normals
        })

    if options.exp_face_normal:
        result["normal"].append({
            "name": "face",
            "data": face_normals
        })

    if options.exp_tangential:
        result["tangential"].append({
            "data": tangentials
        })

    if options.exp_bitangential:
        result["bitangential"].append({
            "data": bitangentials
        })

    if options.exp_color or\
        options.exp_material_diffuse_color or\
        options.exp_material_specular_color:
        for name, data in colors.items():
            result["color"].append({
                "values_per_vertex": 4,
                "name": name,
                "data": data
            })

    if options.exp_wrap_coord:
        for name, data in coords.items():
            result["wrap_coord"].append({
                "values_per_vertex": 2,
                "name": name,
                "data": data
            })

    if options.exp_weight:
        for name, data in groups.items():
            result["weight"].append({
                "values_per_vertex": 1,
                "name": name,
                "data": data
            })

    if options.exp_occlusion:
        for name, data in occls.items():
            result["occlusion"].append({
                "values_per_vertex": 1,
                "name": name,
                "data": data
            })

    index_type = "unsigned_16" if vertex_index < 2**16 else "unsigned_32"
    result["vertex_count"] = vertex_index
    result["index_type"] = index_type
    result["indices"] = indices
    result["instructions"] = [{
        "mode": "triangles",
        "first": 0,
        "count": len(indices),
        "index_type": index_type,
        "cw_face_winding": False
    }]
    return result
# ------------------------------------------------------------------------------
def do_export(options):
    try:
        import bpy
        result = []

        for name, obj in [(n, bpy.data.objects[n]) for n in options.meshes]:
            mesh = triangulate(options, obj)
            result.append(export_single(options, bpy.data, name, obj, mesh))
            del mesh

        if len(result) == 1:
            result = result[0]
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


