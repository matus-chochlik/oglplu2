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
import stat
import xml.sax
import threading

# ------------------------------------------------------------------------------
class XmlLogFormatter(object):
    # --------------------------------------------------------------------------
    def __init__(self, log_output):
        self._re_var = re.compile(".*(\${([A-Za-z][A-Za-z_0-9]*)}).*")
        self._lock = threading.Lock()
        self._out = log_output
        with self._lock:
            self._sources = []
            self._out.write("╮\n")

    # --------------------------------------------------------------------------
    def __del__(self):
        with self._lock:
            self._out.write("╯\n")
            self._out.close()

    # --------------------------------------------------------------------------
    def beginLog(self, srcid, info):
        with self._lock:
            self._out.write("┝")
            for sid in self._sources:
                self._out.write("━┿")
            self._out.write("━┯━┑starting log│\n")
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" ┊")
            self._out.write(" ┊ ╰┄┄┄┄┄┄┄┄┄┄┄┄╯\n")
            self._sources.append(srcid)

    # --------------------------------------------------------------------------
    def finishLog(self, srcid):
        with self._lock:
            # L1
            self._out.write("┊")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write(" ┝")
                elif conn:
                    self._out.write("━┿")
                else:
                    self._out.write(" ┊")
            self._out.write("━┑closing  log│\n")
            # L2
            self._out.write("├")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write("┈╯")
                elif conn:
                    self._out.write("╭╯")
                else:
                    self._out.write("┈┼")
            self._out.write(" ╰┄┄┄┄┄┄┄┄┄┄┄┄╯\n")
            # L3
            self._out.write("┊")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write(" ")
                elif conn:
                    self._out.write("╭╯")
                else:
                    self._out.write(" ┊")
            self._out.write("\n")
            self._sources = [sid for sid in self._sources if sid != srcid]

    # --------------------------------------------------------------------------
    def translateArg(self, arg, info):
        info["used"] = True
        value = info.get("value", arg)
        return value

    # --------------------------------------------------------------------------
    def addMessage(self, srcid, info):
        args = info["args"]
        message = info["format"]
        found = re.match(self._re_var, message)
        while found:
            prev = message[:found.start(1)]
            repl = self.translateArg(
                found.group(2),
                args.get(found.group(2), {})
            )
            folw = message[found.end(1):]
            message = prev + repl + folw
            found = re.match(self._re_var, message)

        with self._lock:
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" ┊")
            self._out.write("\n")

            self._out.write("┊")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write(" ┝")
                elif conn:
                    self._out.write("━┿")
                else:
                    self._out.write(" ┊")
            self._out.write("━┑")
            self._out.write("%7s│" % info["level"])
            self._out.write("%10s│" % info["source"])
            self._out.write(message)
            self._out.write("\n")
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" ┊")
            self._out.write(" ╰┄┄┄┄┄┄┄┴┄┄┄┄┄┄┄┄┄┄╯\n")
            self._out.flush()

# ------------------------------------------------------------------------------
class XmlLogProcessor(threading.Thread, xml.sax.ContentHandler):
    # --------------------------------------------------------------------------
    def __init__(self, xml_input, processor):
        threading.Thread.__init__(self, target=self.run)
        self._xmlin = xml_input
        self._srcid = hash(self._xmlin)
        self._proc = processor
        self._ctag = None
        self._carg = None
        self._info = None
        threading.Thread.start(self)

    # --------------------------------------------------------------------------
    def __del__(self):
        self._xmlin.close()

    # --------------------------------------------------------------------------
    def startElement(self, tag, attr):
        self._ctag = tag
        if tag == "log":
            self._proc.beginLog(self._srcid, attr)
        elif tag == "m":
            self._info = {
                r: attr[k] for k, r in [
                    ("lvl", "level"),
                    ("src", "source"),
                    ("ts",  "timestamp")
                ]
            }
            self._info["args"] = {}
        elif tag == "a":
            self._carg = attr["n"]
            self._info["args"][self._carg] = {
                "value": "''",
                "type": attr["t"],
                "used": False
            }
        elif tag == "a":
            self._carg = None

    # --------------------------------------------------------------------------
    def endElement(self, tag):
        if tag == "log":
            self._proc.finishLog(self._srcid)
        elif tag == "m":
            self._proc.addMessage(self._srcid, self._info)
            self._info = None

    # --------------------------------------------------------------------------
    def characters(self, content):
        if self._info:
            if self._ctag == "f":
                self._info["format"] = content
            elif self._ctag == "a":
                self._info["args"][self._carg]["value"] = content

    # --------------------------------------------------------------------------
    def process(self):
        parser = xml.sax.make_parser()
        parser.setContentHandler(self)
        line = self._xmlin.readline()
        while line:
            parser.feed(line)
            line = self._xmlin.readline()

    # --------------------------------------------------------------------------
    def run(self):
        self.process()

# ------------------------------------------------------------------------------
def main(args):
    for arg in args:
        if not os.path.exists(arg):
            os.mkfifo(arg)

    formatter = XmlLogFormatter(sys.stdout)
    procs = [XmlLogProcessor(open(arg, "rt"), formatter) for arg in args]

    for p in procs:
        p.join()

    return 0

# ------------------------------------------------------------------------------
if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

