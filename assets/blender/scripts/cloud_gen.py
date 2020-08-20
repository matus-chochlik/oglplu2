#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
# usage: blender -b myfile.blend -P cloudgen.py [-- [--help|options...]]

import os
import sys
import math
import pathlib
import argparse
# ------------------------------------------------------------------------------
class CloudGenArgParser(argparse.ArgumentParser):
    # --------------------------------------------------------------------------
    def _distance(self, x):
        try:
            f = float(x)
            assert(f >= 0.0)
            return f
        except:
            self.error("`%s' is not a valid distance value" % str(x))
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
            '--u-steps', '-U',
            type=self._positive_int,
            dest="u_steps",
            action="store",
            default=512
        )

        self.add_argument(
            '--v-steps', '-V',
            type=self._positive_int,
            dest="v_steps",
            action="store",
            default=512
        )

        self.add_argument(
            '--w-steps', '-W',
            type=self._positive_int,
            dest="w_steps",
            action="store",
            default=256
        )
    # --------------------------------------------------------------------------
    def process_parsed_options(self, options):
        options.n_steps = min(options.u_steps, options.v_steps, options.w_steps)

        return options
    # --------------------------------------------------------------------------
    def parse_args(self, args):
        return self.process_parsed_options(
            argparse.ArgumentParser.parse_args(self, args)
        )

# ------------------------------------------------------------------------------
def make_argument_parser():
    return CloudGenArgParser(
            prog=os.path.basename(__file__),
            description="""
            Blender cloud mesh generator
        """
    )
# ------------------------------------------------------------------------------
class Metaballs(object):
    # --------------------------------------------------------------------------
    def __init__(self, opts):
        self._metaballs = []
        self._metaballs.append(((-0.4, 0.0, 0.0), 4))
        self._metaballs.append(((+0.3, 0.0, 0.0), 4))

    # --------------------------------------------------------------------------
    def __call__(self, coord):
        _diff = lambda a, b: tuple(ac-bc for ac, bc in zip(a, b))
        _dot = lambda a, b: sum(tuple(ac*bc for ac, bc in zip(a, b)))
        _slen = lambda a: _dot(a, a)

        result = 0.0

        for center, threshold in self._metaballs:
            result += 1.0/_slen(_diff(coord, center)) - threshold

        return result

# ------------------------------------------------------------------------------
class CloudGenerator(object):
    # --------------------------------------------------------------------------
    def normalize(self, c):
        return tuple(((2.0*cc)/self._opts.n_steps) - 1.0 for cc in c)

    # --------------------------------------------------------------------------
    def __init__(self, opts):
        self._opts = opts
        self._transf = self.normalize
        self._field = Metaballs(opts)
        self._samples = dict()
        self._sections = [dict(), dict(), dict()]

        # direction, begin offset, end offset
        self._edges = [
            (0, (0, 0, 0), (1, 0, 0)), #  0
            (0, (0, 1, 0), (1, 1, 0)), #  1
            (0, (0, 0, 1), (1, 0, 1)), #  2
            (0, (0, 1, 1), (1, 1, 1)), #  3
            (1, (0, 0, 0), (0, 1, 0)), #  4
            (1, (1, 0, 0), (1, 1, 0)), #  5
            (1, (0, 0, 1), (0, 1, 1)), #  6
            (1, (1, 0, 1), (1, 1, 1)), #  7
            (2, (0, 0, 0), (0, 0, 1)), #  8
            (2, (1, 0, 0), (1, 0, 1)), #  9
            (2, (0, 1, 0), (0, 1, 1)), # 10
            (2, (1, 1, 0), (1, 1, 1)), # 11
        ]

    # --------------------------------------------------------------------------
    def edge_coords(self, u, v, w):
        for e in range(12):
            d, a, b = self._edges[e]
            yield (e, d, (u+a[0], v+a[1], w+a[2]), (u+b[0], v+b[1], w+b[2]))

    # --------------------------------------------------------------------------
    def get_sample(self, co):
        try:
            return self._samples[co]
        except KeyError:
            sam = self._field(self._transf(co))
            self._samples[co] = sam
            return sam

    # --------------------------------------------------------------------------
    def get_intersections(self, u, v, w):
        for e, d, a, b in self.edge_coords(u, v, w):
            try:
                yield self._sections[d][a]
            except KeyError:
                sa = self.get_sample(a)
                sb = self.get_sample(b)
                if sa != 0 or sb != 0:
                    if sa <= 0 and sb >= 0:
                        f = -sa/(sb-sa)
                        c = tuple(bc*f + ac*(1-f) for ac, bc in zip(a, b))
                        c = self.normalize(c)
                        self._sections[d][a] = c
                        yield c
                    elif sb <= 0 and sa >= 0:
                        f = -sb/(sa-sb)
                        c = tuple(ac*f + bc*(1-f) for ac, bc in zip(a, b))
                        c = self.normalize(c)
                        self._sections[d][a] = c
                        yield c

    # --------------------------------------------------------------------------
    def order_intersections(self, u, v, w):
        _plus = lambda a, b: tuple(ac+bc for ac, bc in zip(a, b))
        _diff = lambda a, b: tuple(ac-bc for ac, bc in zip(a, b))
        _div = lambda a, b: tuple(ac/b for ac in a)
        _dot = lambda a, b: sum(tuple(ac*bc for ac, bc in zip(a, b)))
        _len = lambda a: math.sqrt(_dot(a, a))
        _cross = lambda a, b: (a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0])
        _norm = lambda a: _div(a, _len(a))
        _det = lambda n, a, b: _dot(n, _cross(a, b))
        _angle = lambda n, a, b: math.atan2(_det(n, a, b), _dot(a, b))

        iss = [pos for pos in self.get_intersections(u, v, w)]
        l = len(iss)
        if l > 0:
            assert l >= 3
            piv = (0.0, 0.0, 0.0)
            for pos in iss:
                piv = _plus(piv, pos)
            piv = _div(piv, l)

            try:
                issv = [(_norm(_diff(pos, piv)), pos) for pos in iss]

                mind = abs(_dot(issv[0][0], issv[0][0]))
                o = 0
                for k in range(1, l):
                    d = abs(_dot(issv[0][0], issv[k][0]))
                    if mind > d:
                        mind = d
                        o = k
                assert o != 0

                n = _norm(_cross(issv[0][0], issv[o][0]))

                issa = [(_angle(n, issv[0][0], v), pos) for v, pos in issv]

                return [pos for a, pos in sorted(issa)]
            except AssertionError:
                pass
            except ZeroDivisionError:
                pass

        return None

    # --------------------------------------------------------------------------
    def process_cube(self, u, v, w):
        iss = self.order_intersections(u, v, w)
        if iss:
            bverts = [self._bmesh.verts.new(pos) for pos in iss]
            self._bmesh.faces.new(bverts)

    # --------------------------------------------------------------------------
    def generate(self):
        import bpy
        import bmesh
        self._bmesh = bmesh.new()

        for w in range(self._opts.w_steps):
            for v in range(self._opts.v_steps):
                for u in range(self._opts.u_steps):
                    self.process_cube(u, v, w)

        bmesh.ops.remove_doubles(
            self._bmesh,
            verts=self._bmesh.verts,
            dist=0.1/self._opts.n_steps
        )
        obj = bpy.data.objects.new("Cloud", bpy.data.meshes.new("Cloud"))
        col = bpy.data.collections.get("Collection")
        col.objects.link(obj)
        bpy.context.view_layer.objects.active = obj
        self._bmesh.to_mesh(bpy.context.object.data)
        self._bmesh.free()
        self._bmesh = None
        bpy.ops.object.mode_set(mode='EDIT')
        bpy.ops.mesh.select_all(action='SELECT')
        bpy.ops.mesh.normals_make_consistent(inside=False)
        bpy.ops.object.mode_set(mode='OBJECT')
        bpy.ops.wm.save_as_mainfile()

# ------------------------------------------------------------------------------
def main():
    arg_parser = make_argument_parser()
    try: args = sys.argv[sys.argv.index("--") + 1:]
    except ValueError: args = sys.argv[1:]
    options = arg_parser.parse_args(args)
    if options.debug:
        print(options)
    else:
        generator = CloudGenerator(options)
        generator.generate()
# ------------------------------------------------------------------------------
main()


