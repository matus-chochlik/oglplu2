#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

import bpy
import math

rad_90 = math.pi/2
rad_180 = math.pi
rad_270 = (3*math.pi)/2

cm_cam_rotation = {
    "0-Xp": (rad_90, 0, -rad_90),
    "1-Xn": (rad_90, 0, -rad_270),
    "2-Yp": (rad_180, 0, -rad_180),
    "3-Yn": (0, 0, -rad_180),
    "4-Zp": (rad_90, 0, rad_180),
    "5-Zn": (rad_90, 0, 0),
}

def do_render_face(axis_name, image_name, size):
    camname = "camera-%s" % axis_name
    camera = bpy.data.cameras.new(name=camname)
    camera.type = "PERSP"
    camera.lens_unit = "FOV"
    camera.lens = 18.0
    camobj = bpy.data.objects.new(name=camname, object_data = camera)
    camobj.location = (0.0, 0.0, 0.0)
    camobj.rotation_mode = "XYZ"
    camobj.rotation_euler = cm_cam_rotation[axis_name]

    scene = bpy.context.scene
    scene.camera = camobj
    scene.render.engine = "CYCLES"
    scene.render.image_settings.color_mode ='RGBA'
    scene.render.image_settings.file_format ='PNG'
    scene.render.filepath = "/tmp/%s-%s.png" % (image_name, axis_name)
    scene.render.resolution_x = size
    scene.render.resolution_y = size
        
    bpy.ops.render.render(write_still=True)
    
    bpy.data.objects.remove(camobj)
    bpy.data.cameras.remove(camera)
    
def render_all(image_name = "cm", size = 1024):
    for axis_name in cm_cam_rotation:
        print(axis_name)
        do_render_face(axis_name, image_name, size)
    
render_all()



