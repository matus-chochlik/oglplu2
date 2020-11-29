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
import math
import pathlib
import argparse
# ------------------------------------------------------------------------------
class ExportMeshArgParser(argparse.ArgumentParser):
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
            '--output', '-o',
            dest="output_path",
            type=os.path.realpath,
            action="store",
            default=None
        )

        self.attrib_kinds = [
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
                "weight",
                "occlusion",
                "polygon_id",
                "material_id"
            ]

        self.attrib_data_types = [
                "float",
                "int_16",
                "int_32",
                "uint_16",
                "uint_32",
                "ubyte"
            ]

        self.add_argument(
            '--attrib', '-a',
            dest="attributes",
            action="append",
            default=[],
            choices=self.attrib_kinds
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

        self.add_argument(
            '--precision', '-P',
            dest="precision",
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--color-precision', '-CP',
            dest="color_precision",
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--weight-precision', '-WP',
            dest="weight_precision",
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--occlude-precision', '-OP',
            dest="occlude_precision",
            type=self._positive_int,
            action="store",
            default=None
        )

        self.add_argument(
            '--color-type', '-CT',
            dest="color_type",
            action="store",
            default="float",
            choices=self.attrib_data_types
        )

        self.add_argument(
            '--weight-type', '-WT',
            dest="weight_type",
            action="store",
            default="float",
            choices=self.attrib_data_types
        )

        self.add_argument(
            '--occlude-type', '-OT',
            dest="occlude_type",
            action="store",
            default="float",
            choices=self.attrib_data_types
        )

        self.add_argument(
            '--no-alpha', '-A',
            dest="export_alpha",
            action="store_false",
            default=True
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

        for attr_type in self.attrib_kinds:
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
def fixnum(x, d = None):
    return (round(x, d) if d is not None else x) if x != round(x) else int(x)
# ------------------------------------------------------------------------------
def fixcomp(typ, x, d = None):
    assert -1.0 <= x and x <= 1.0
    if typ == "ubyte":
        return int(x * 255)
    if typ == "int_16":
        return int(x * 32767)
    if typ == "uint_16":
        return int(x * 65535)
    if typ == "int_32":
        return int(x * 2147483647)
    if typ == "uint_32":
        return int(x * 4294967295)
    return fixnum(x, d)
# ------------------------------------------------------------------------------
def fix_color(options, c):
    f = lambda x: fixcomp(options.color_type, x)
    if not options.export_alpha:
        return (f(c[0]), f(c[1]), f(c[2]))
    return (f(c[0]), f(c[1]), f(c[2]), f(c[3]))
# ------------------------------------------------------------------------------
def degenerate_triangle(a, b, c):
    _diff = lambda u, v: tuple(uc-vc for uc, vc in zip(u, v))
    _dot = lambda u, v: sum(tuple(uc*vc for uc, vc in zip(u, v)))
    _len = lambda u: math.sqrt(_dot(u, u))
    _cross = lambda u, v: (u[1]*v[2]-u[2]*v[1],u[2]*v[0]-u[0]*v[2],u[0]*v[1]-u[1]*v[0])

    ab = _diff(b, a)
    ac = _diff(c, a)

    return _len(_cross(ab, ac)) <= max(_len(ab), _len(ac))*0.000001
# ------------------------------------------------------------------------------
def get_diffuse_color(mat):
    # TODO Material.use_nodes / Material.node_tree
    return mat.diffuse_color
# ------------------------------------------------------------------------------
def get_specular_color(mat):
    # TODO Material.use_nodes / Material.node_tree
    return mat.specular_color
# ------------------------------------------------------------------------------
def has_same_values(options, obj, mesh, lil, fl, ll, vl, lir, fr, lr, vr):
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
            if vcs.data[lil].color != vcs.data[lir].color:
                return False
    if options.exp_polygon_id:
        if fl.index != fr.index:
            return False
    if options.exp_material_id:
        if fl.material_index != fr.material_index:
            return False
    if options.exp_material_diffuse_color:
        ml = obj.material_slots[fl.material_index].material
        mr = obj.material_slots[fr.material_index].material
        if get_diffuse_color(ml) != get_diffuse_color(mr):
            return False
    if options.exp_material_specular_color:
        ml = obj.material_slots[fl.material_index].material
        mr = obj.material_slots[fr.material_index].material
        if get_specular_color(ml) != get_specular_color(mr):
            return False
    if options.exp_wrap_coord:
        for uvs in mesh.uv_layers:
            if uvs.data[lil].uv != uvs.data[lir].uv:
                return False
    if options.exp_weight or options.exp_occlusion:
        for grp in obj.vertex_groups:
            try:
                wl = grp.weight(vl.index)
            except RuntimeError:
                wl = 0.0
            try:
                wr = grp.weight(vr.index)
            except RuntimeError:
                wr = 0.0
            if wl != wr:
                return False

    return True

# ------------------------------------------------------------------------------
def data_type_from(l):
    mx = max(l)
    mn = min(l)

    if mx < 2**8:
        if mn >= 0:
            return "ubyte"
    if mx < 2**16:
        if mn >= 0:
            return "uint_16"
        elif mn > -2**15:
            if mn < 2**15:
                return "int_16"
    if mx < 2**32:
        if mn >= 0:
            return "uint_32"
        elif mn > -2**31:
            if mn < 2**31:
                return "int_32"

    return "float"

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

    if options.exp_polygon_id:
        result["polygon_id"] = []

    if options.exp_material_id:
        result["material_id"] = []

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
    polygon_ids = []
    material_ids = []

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

    p = options.precision
    cp = options.color_precision
    wp = options.weight_precision
    op = options.occlude_precision

    for meshface in mesh.polygons:
        s = meshface.loop_start
        assert meshface.loop_total == 3

        tri_pos = (mesh.vertices[mesh.loops[s+i].vertex_index].co for i in range(3))
    
        if degenerate_triangle(*tri_pos):
            continue

        fn = [fixnum(x, p) for x in fixvec(meshface.normal)]
        for loop_index in range(s, s + 3):
            meshloop = mesh.loops[loop_index]
            meshvert = mesh.vertices[meshloop.vertex_index]

            emitted_vert = emitted[meshvert.index]
            reused_vertex = False
            for old_face_index, old_loop_index, emit_index in emitted_vert:
                if has_same_values(
                    options,
                    obj,
                    mesh,
                    old_loop_index,
                    mesh.polygons[old_face_index],
                    mesh.loops[old_loop_index],
                    meshvert,
                    loop_index,
                    meshface,
                    meshloop,
                    meshvert
                ):
                    reused_vertex = True
                    indices.append(emit_index)

            if not reused_vertex:
                positions += [fixnum(x, p) for x in fixvec(meshvert.co)]
                if options.exp_pivot:
                    pivots += [fixnum(x, p) for x in fixvec(obj.location)]
                if options.exp_vert_normal:
                    vert_normals += [fixnum(x, p) for x in fixvec(meshvert.normal)]
                if options.exp_face_normal:
                    face_normals += fn
                if options.exp_normal:
                    normals +=\
                        [fixnum(x, p) for x in fixvec(meshloop.normal)]
                if options.exp_tangential:
                    tangentials +=\
                        [fixnum(x, p) for x in fixvec(meshloop.tangent)]
                if options.exp_bitangential:
                    bitangentials +=\
                        [fixnum(x, p) for x in fixvec(meshloop.bitangent)]
                if options.exp_color:
                    for vcs in mesh.vertex_colors:
                        vc = fix_color(options, vcs.data[loop_index].color)
                        try:
                            colors[vcs.name] += [fixnum(x, cp) for x in vc]
                        except KeyError:
                            pass
                if options.exp_polygon_id:
                    polygon_ids += [meshface.index]
                if options.exp_material_id:
                    material_ids += [meshface.material_index]
                if options.exp_material_diffuse_color:
                    mat = obj.material_slots[meshface.material_index].material
                    dc = fix_color(options, get_diffuse_color(mat))
                    colors["material.diffuse"] += [fixnum(x, cp) for x in dc]
                if options.exp_material_specular_color:
                    mat = obj.material_slots[meshface.material_index].material
                    sc = fix_color(options, get_specular_color(mat))
                    colors["material.specular"] += [fixnum(x, cp) for x in sc]
                if options.exp_wrap_coord:
                    for uvs in mesh.uv_layers:
                        uv = uvs.data[loop_index].uv
                        try:
                            coords[uvs.name] += [fixnum(c, p) for c in uv]
                        except KeyError:
                            pass
                if options.exp_weight:
                    for grp in obj.vertex_groups:
                        try:
                            try:
                                w = grp.weight(meshvert.index)
                                groups[grp.name].append(
                                    fixcomp(options.weight_type, w, wp)
                                )
                            except RuntimeError:
                                groups[grp.name].append(
                                    fixcomp(options.weight_type, 0, wp)
                                )
                        except KeyError:
                            pass
                if options.exp_occlusion:
                    for grp in obj.vertex_groups:
                        try:
                            try:
                                w = grp.weight(meshvert.index)
                                occls[grp.name].append(
                                    fixcomp(options.occlude_type, w, op)
                                )
                            except RuntimeError:
                                occls[grp.name].append(
                                    fixcomp(options.occlude_type, 0, op)
                                )
                        except KeyError:
                            pass

                emitted_vert.add((meshface.index, meshloop.index, vertex_index))
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
                "values_per_vertex": 4 if options.export_alpha else 3,
                "type": options.color_type,
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
                "type": options.weight_type,
                "name": name,
                "data": data
            })

    if options.exp_occlusion:
        for name, data in occls.items():
            result["occlusion"].append({
                "values_per_vertex": 1,
                "type": options.occlude_type,
                "name": name,
                "data": data
            })

    if options.exp_polygon_id:
        result["polygon_id"].append({
            "values_per_vertex": 1,
            "type": data_type_from(polygon_ids),
            "data": polygon_ids
        })

    if options.exp_material_id:
        result["material_id"].append({
            "values_per_vertex": 1,
            "type": data_type_from(material_ids),
            "data": material_ids
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


