#!/usr/bin/python3
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
import os
import re
import sys
import zlib
import signal
import shutil
import argparse
import tempfile
import subprocess

# ------------------------------------------------------------------------------
class FramedumpArgumentParser(argparse.ArgumentParser):
    # -------------------------------------------------------------------------
    def __init__(self, **kw):
        argparse.ArgumentParser.__init__(self, **kw)

        def PositiveInt(arg):
            try:
                result = int(arg)
                assert result > 0
                return result
            except:
                msg = "'%s' is not a positive integer" % str(arg)
                raise argparse.ArgumentTypeError(msg)

        def OutputSizeType(arg):
            if re.match("[0-9]+[kMG]?", arg):
                return arg
            msg = "'%s' is not a valid file size specification" % str(arg)
            raise argparse.ArgumentTypeError(msg)

        self.add_argument(
            "--work-dir", "-w", 
            metavar='DIR-PATH',
            dest='work_dir_path',
            nargs='?',
            type=os.path.realpath,
            default=None
        )

        self.add_argument(
            "--application", "-a", 
            metavar='EXECUTABLE-PATH',
            dest='application_path',
            nargs='?',
            type=os.path.realpath,
            default=None
        )

        self.add_argument(
            "--output", "-o", 
            metavar='OUTPUT-FILE',
            dest='output_path',
            nargs='?',
            type=os.path.realpath,
            default=None
        )

        self.add_argument(
            "--fps",
            help="""Number of frames per second""",
            type=int,
            default="30",
            action="store",
            dest="fps"
        )

        self.add_argument(
            "--scale",
            help="""
                Scaling factor for the render frame.
            """,
            type=int,
            dest="render_scale",
            action="store",
            default="1"
        )

        self.add_argument(
            "--max-frames",
            help="""
                Maximum number of output video frames.
            """,
            type=PositiveInt,
            dest="max_frames",
            action="store",
            default=None
        )

        self.add_argument(
            "--max-bytes",
            help="""
                Maximum output video size in bytes.
            """,
            type=OutputSizeType,
            dest="max_bytes",
            action="store",
            default=None
        )

        self.add_argument(
            "--gif",
            help="""Render output into GIF format""",
            default=False,
            action="store_true",
            dest="gif_output"
        )

        self.add_argument(
            "--args",
            dest="app_options",
            nargs=argparse.REMAINDER,
            default=list(),
            help="""
                Everything following this option will be passed
                to the application verbatim.
            """
        )

    # -------------------------------------------------------------------------
    def parseArgs(self):
        # ----------------------------------------------------------------------
        class _Options(object):
            # ------------------------------------------------------------------
            def __init__(self, base):
                self.__dict__.update(base.__dict__)
                if self.work_dir_path is None:
                    self.temp_dir = tempfile.mkdtemp()
                    self.work_dir_path = self.temp_dir
                else:
                    self.temp_dir = None

                if self.application_path is None:
                    msg = "missing application path"
                    raise argparse.ArgumentTypeError(msg)

                self.job_name = os.path.basename(self.application_path)

                if self.output_path is None:
                    if self.gif_output:
                        self.output_path = os.path.realpath("oglplus.gif")
                    else:
                        self.output_path = os.path.realpath("oglplus.avi")


            # ------------------------------------------------------------------
            def __del__(self):
                if self.temp_dir:
                    shutil.rmtree(self.temp_dir)

        return _Options(argparse.ArgumentParser.parse_args(self))
# ------------------------------------------------------------------------------
def getArgumentParser():
    return FramedumpArgumentParser(
        prog=os.path.basename(__file__),
        description="""
        Script creating videos from OGLplus application raw image frame dump.
        """
    )
# ------------------------------------------------------------------------------
keepRunning = True
# ------------------------------------------------------------------------------
class Framedump(object):
    # -------------------------------------------------------------------------
    def __init__(self, options):
        self.options = options
        assert os.path.isdir(str(self.options.work_dir_path))
        self.frame_re = re.compile(
            "^(.*)"+
            "-([0-9]+)x([0-9]+)x([0-9]+)"+
            "-(rgba|depth|stencil)"+
            "-(byte|float)_type"+
            "-([0-9]+)((.zlib)?$)"
        )

        cmd_line = [
            options.application_path,
            "--application-video-framedump-color", "byte",
            "--application-video-framedump-prefix",
            os.path.join(self.options.work_dir_path, self.options.job_name)
        ]

        if self.options.max_frames:
            cmd_line += ["--application-max-frames", self.options.max_frames]

        cmd_line += self.options.app_options

        self.proc = subprocess.Popen(
            [str(arg) for arg in cmd_line],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=None
        )

    # -------------------------------------------------------------------------
    def runConvert(self, args):

        cmd_line = ['convert'] + args

        ret = subprocess.call(cmd_line, cwd = self.options.work_dir_path)
        if ret < 0:
            raise RuntimeError("Convert killed by signal %d" % -ret)
        elif ret > 0:
            raise RuntimeError("Convert failed with code %d" % ret)

    # -------------------------------------------------------------------------
    def generateFrames(self):
        global keepRunning
        while keepRunning:
            frame_path_raw = self.proc.stdout.readline()
            if frame_path_raw:
                self.proc.stdin.write(frame_path_raw)
                self.proc.stdin.flush()
                frame_path_raw = frame_path_raw.decode('utf-8').rstrip()
                match = re.match(self.frame_re, os.path.basename(frame_path_raw))
                if match and match.group(1) == self.options.job_name:
                    yield {
                        "job_name": match.group(1),
                        "width": int(match.group(2)),
                        "height": int(match.group(3)),
                        "channels": int(match.group(4)),
                        "mode": match.group(5),
                        "type": match.group(6),
                        "frame": int(match.group(7)),
                        "zlib": match.group(9) == ".zlib",
                        "prefix": frame_path_raw[:-len(match.group(8))],
                        "path": frame_path_raw
                    }
            else:
                break

    # -------------------------------------------------------------------------
    def convertFormat(self, info):
        # TODO: properly translate mode and type into imagemagick format
        return info["mode"]

    # -------------------------------------------------------------------------
    def framesToPng(self):
        for info in self.generateFrames():
            if info["zlib"]:
                print(info["prefix"])
                with open(info["path"], "rb") as zipped:
                    os.unlink(info["path"])
                    info["path"] = info["prefix"] + ".raw"
                    with open(info["path"], "wb") as unzipped:
                        unzipped.write(zlib.decompress(zipped.read()))
            assert os.path.isfile(info["path"])

            png_path = os.path.join(
                self.options.work_dir_path,
                "%(job_name)s-%(frame)06d.png" % info
            )
            self.runConvert([
                '-size', '%dx%d' % (
                    info["width"]  * self.options.render_scale,
                    info["height"] * self.options.render_scale
                ),
                '-depth', '8',
                "%s:%s" % (self.convertFormat(info), info["path"]),
                '-flip',
                '-scale', '%dx%d' % (info["width"], info["height"]),
                '-alpha', 'Off',
                png_path
            ])
            os.unlink(info["path"])
            info["path"] = png_path
            yield info

    # -------------------------------------------------------------------------
    def encodeVideo(self):
        cmd_line = [
            "ffmpeg",
            "-loglevel", "error",
            "-y", "-f", "image2",
            "-i", os.path.join(
                self.options.work_dir_path,
                "%s-%%06d.png" % self.options.job_name
            ),
            "-r", str(self.options.fps)
        ]

        if self.options.max_bytes:
            cmd_line += ["-fs", self.options.max_bytes]

        if not self.options.gif_output:
            cmd_line += [
                "-vcodec", "mpeg4",
                "-b", "8000k"
            ]
        cmd_line += [
            self.options.output_path
        ]

        ret = subprocess.call(cmd_line, cwd = self.options.work_dir_path)

    # -------------------------------------------------------------------------
    def run(self):
        for info in self.framesToPng():
            pass
        self.encodeVideo();

# ------------------------------------------------------------------------------
def handleInterrupt(sig, frame):
    global keepRunning
    keepRunning = False
# ------------------------------------------------------------------------------
def main():
    try:
        signal.signal(signal.SIGINT, handleInterrupt)
        signal.signal(signal.SIGTERM, handleInterrupt)
        framedump = Framedump(getArgumentParser().parseArgs())
        framedump.run()
    except KeyboardInterrupt:
        return 0
# ------------------------------------------------------------------------------
if __name__ == "__main__":
        sys.exit(main())

