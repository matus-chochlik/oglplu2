#!/usr/bin/env python3
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
import errno
import socket
import signal
import string
import base64
import xml.sax
import threading

try:
    import selectors
except ImportError:
    import selectors2 as selectors

# ------------------------------------------------------------------------------
class XmlLogFormatter(object):
    # --------------------------------------------------------------------------
    def _ttyEsc(self, escseq):
        if self._out.isatty():
            return escseq
        return ""

    # --------------------------------------------------------------------------
    def _ttyReset(self):
        return self._ttyEsc("\x1b[0m")

    # --------------------------------------------------------------------------
    def _ttyGray(self):
        return self._ttyEsc("\x1b[0;30m")

    # --------------------------------------------------------------------------
    def _ttyRed(self):
        return self._ttyEsc("\x1b[0;31m")

    # --------------------------------------------------------------------------
    def _ttyGreen(self):
        return self._ttyEsc("\x1b[0;32m")

    # --------------------------------------------------------------------------
    def _ttyYellow(self):
        return self._ttyEsc("\x1b[0;33m")

    # --------------------------------------------------------------------------
    def _ttyBlue(self):
        return self._ttyEsc("\x1b[0;34m")

    # --------------------------------------------------------------------------
    def _ttyCyan(self):
        return self._ttyEsc("\x1b[0;36m")

    # --------------------------------------------------------------------------
    def _ttyWhite(self):
        return self._ttyEsc("\x1b[0;37m")

    # --------------------------------------------------------------------------
    def _ttyBoldGray(self):
        return self._ttyEsc("\x1b[0;37m")

    # --------------------------------------------------------------------------
    def _ttyBoldRed(self):
        return self._ttyEsc("\x1b[1;31m")

    # --------------------------------------------------------------------------
    def _ttyBoldGreen(self):
        return self._ttyEsc("\x1b[1;32m")

    # --------------------------------------------------------------------------
    def _ttyBoldYellow(self):
        return self._ttyEsc("\x1b[1;33m")

    # --------------------------------------------------------------------------
    def _ttyBoldBlue(self):
        return self._ttyEsc("\x1b[1;34m")

    # --------------------------------------------------------------------------
    def _ttyBoldCyan(self):
        return self._ttyEsc("\x1b[1;36m")

    # --------------------------------------------------------------------------
    def _ttyBoldWhite(self):
        return self._ttyEsc("\x1b[1;37m")

    # --------------------------------------------------------------------------
    def _formatByteSize(self, n):
        result = None
        if n > 0:
            umult = ["GiB", "MiB", "kiB"]
            l = len(umult)
            for i in range(l):
                m = 1024**(l-i)
                if (n / m > 1024) or (n % m == 0):
                    result = str(int(n / m)) + " " + umult[i]
                    break
        if not result:
            result = str(n) + " B"

        return self._ttyBoldWhite() + result + self._ttyReset()

    # --------------------------------------------------------------------------
    def _formatFsPath(self, p):
        if os.path.exists(p):
            if os.path.islink(p):
                return self._ttyBlue() + p + self._ttyReset()
            if os.path.isdir(p):
                return self._ttyGreen() + p + self._ttyReset()
            return self._ttyBoldGreen() + p + self._ttyReset()

        return self._ttyBoldRed() + p + self._ttyReset()

    # --------------------------------------------------------------------------
    def __init__(self, selector, log_output):
        self._re_var = re.compile(".*(\${([A-Za-z][A-Za-z_0-9]*)}).*")
        self._lock = threading.Lock()
        self._out = log_output

        self._decorators = {
            "FsPath": self._formatFsPath,
            "ByteSize": lambda x: self._formatByteSize(int(x))
        }
        self._sources = []

        with self._lock:
            self._out.write("╮\n")
    # --------------------------------------------------------------------------
    def __del__(self):
        with self._lock:
            self._out.write("╯\n")
            self._out.close()

    # --------------------------------------------------------------------------
    def beginLog(self, srcid, info):
        with self._lock:
            #
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" │")
            self._out.write("   ╭────────────╮\n")
            #
            self._out.write("┝")
            for sid in self._sources:
                self._out.write("━━")
            self._out.write("━┯━┥")
            self._out.write(self._ttyGreen())
            self._out.write("starting log")
            self._out.write(self._ttyReset())
            self._out.write("│")
            self._out.write("\n")
            #
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" │")
            self._out.write(" │ ╰────────────╯\n")
            self._sources.append(srcid)

    # --------------------------------------------------------------------------
    def finishLog(self, srcid):
        with self._lock:
            # L0
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" │")
            self._out.write(" ╭────────────╮\n")
            # L1
            self._out.write("┊")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write(" ┕")
                elif conn:
                    self._out.write("━━")
                else:
                    self._out.write(" │")
            self._out.write("━┥")
            self._out.write(self._ttyBlue())
            self._out.write("closing  log")
            self._out.write(self._ttyReset())
            self._out.write("│")
            self._out.write("\n")
            # L2
            self._out.write("┊")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write("  ")
                elif conn:
                    self._out.write("╭╯")
                else:
                    self._out.write(" │")
            self._out.write(" ╰────────────╯\n")
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
                    self._out.write(" │")
            self._out.write("\n")
            self._sources = [sid for sid in self._sources if sid != srcid]

    # --------------------------------------------------------------------------
    def translateLevel(self, level):
        if level == "debug":
            return self._ttyBoldCyan()   + "  debug  " + self._ttyReset()
        if level == "info":
            return self._ttyBoldWhite()  + "  info   " + self._ttyReset()
        if level == "warning":
            return self._ttyYellow()     + " warning " + self._ttyReset()
        if level == "error":
            return self._ttyBoldRed()    + "  error  " + self._ttyReset()
        if level == "trace":
            return self._ttyCyan()       + "  trace  " + self._ttyReset()
        if level == "critical":
            return self._ttyRed()        + " critical" + self._ttyReset()
        if level == "backtrace":
            return self._ttyCyan()       + "backtrace" + self._ttyReset()
        return "%7s" % level

    # --------------------------------------------------------------------------
    def translateArg(self, arg, info):
        if info.get("blob", False):
            return "BLOB"

        info["used"] = True

        decorate = self._decorators.get(info.get("type"), lambda x: x)
        try:
            value = decorate(info["value"])
        except KeyError:
            value = arg
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
                self._out.write(" │")
            self._out.write("\n")

            self._out.write("┊")
            conn = False
            for sid in self._sources:
                if sid == srcid:
                    conn = True
                    self._out.write(" ┝")
                elif conn:
                    self._out.write("━━")
                else:
                    self._out.write(" │")
            self._out.write("━┑")
            self._out.write("%s│" % self.translateLevel(info["level"]))
            self._out.write("%10s│" % info["source"])
            self._out.write(message)
            self._out.write("\n")
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" │")
            self._out.write(" ╰─────────┴──────────╯")
            self._out.write("\n")
            # BLOBs
            for name, info in args.items():
                if not info["used"]:
                    self._out.write("┊")
                    for sid in self._sources:
                        self._out.write(" │")
                    self._out.write("  ")
                    self._out.write(name)
                    self._out.write(": ")
                    self._out.write(self.translateArg(name, info))
                    self._out.write("\n")
                    if info["blob"]:
                        blob = info["value"]
                        if len(blob) % 4 != 0:
                            blob += '=' * (4 - len(blob) % 4)
                        blob = base64.standard_b64decode(blob)
                        while blob:
                            self._out.write("┊")
                            for sid in self._sources:
                                self._out.write(" │")
                            self._out.write("  ")
                            for i in range(16):
                                if i == 8:
                                    self._out.write(" ")
                                try:
                                    self._out.write(" %02x" % blob[i])
                                except IndexError:
                                    self._out.write(" ..")
                            self._out.write(" │ ")

                            for i in range(16):
                                if i == 8:
                                    self._out.write(" ")
                                try:
                                    c = bytes([blob[i]]).decode('ascii')
                                    assert c.isprintable()
                                    self._out.write(c)
                                except:
                                    self._out.write(".")
                            self._out.write("\n")
                            blob = blob[16:]

            #
            self._out.flush()

# ------------------------------------------------------------------------------
class XmlLogProcessor(xml.sax.ContentHandler):
    # --------------------------------------------------------------------------
    def __init__(self, srcid, connection, formatter, selector):
        self._srcid = srcid
        self._ctag = None
        self._carg = None
        self._info = None
        self._connection = connection
        self._formatter= formatter
        self._parser = xml.sax.make_parser()
        self._parser.setContentHandler(self)
        self._selector = selector 
        self._buffer = str()

    # --------------------------------------------------------------------------
    def __del__(self):
        self._connection.close()

    # --------------------------------------------------------------------------
    def startElement(self, tag, attr):
        self._ctag = tag
        if tag == "log":
            self._formatter.beginLog(self._srcid, attr)
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
                "blob": attr.get("blob", False),
                "used": False
            }
        elif tag == "a":
            self._carg = None

    # --------------------------------------------------------------------------
    def endElement(self, tag):
        if tag == "log":
            self._formatter.finishLog(self._srcid)
        elif tag == "m":
            self._formatter.addMessage(self._srcid, self._info)
            self._info = None

    # --------------------------------------------------------------------------
    def characters(self, content):
        if self._info:
            if self._ctag == "f":
                self._info["format"] = content
            elif self._ctag == "a":
                self._info["args"][self._carg]["value"] = content

    # --------------------------------------------------------------------------
    def disconnect(self):
        self._parser.feed(self._buffer)
        self._selector.unregister(self._connection)

    # --------------------------------------------------------------------------
    def handleRead(self):
        try:
            data = self._connection.recv(4096)
            if data:
                self._buffer += data.decode("utf-8")
                lines = self._buffer.split('\n')
                for line in lines[:-1]:
                    self._parser.feed(line)
                self._buffer = lines[-1]
            else:
                self.disconnect()
        except socket.error:
            self.disconnect()

# ------------------------------------------------------------------------------
def open_socket(socket_path):
    try: os.unlink(socket_path)
    except OSError as os_error:
        if os_error.errno != errno.ENOENT:
            raise
    uds = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    uds.bind(socket_path)
    uds.listen(50)
    uds.setblocking(False)
    return uds

# ------------------------------------------------------------------------------
keep_running = True
# ------------------------------------------------------------------------------
def display_logs(socket_path):
    try:
        global keep_running
        lsock = open_socket(socket_path)
        with selectors.DefaultSelector() as selector:
            selector.register(
                lsock,
                selectors.EVENT_READ,
                data = XmlLogFormatter(selector, sys.stdout)
            )

            source_id = 0
            while keep_running:
                events = selector.select(timeout=1.0)
                for key, mask in events:
                    if type(key.data) is XmlLogFormatter:
                        connection, addr = lsock.accept()
                        connection.setblocking(False)
                        selector.register(
                            connection,
                            selectors.EVENT_READ,
                            data = XmlLogProcessor(
                                source_id,
                                connection,
                                key.data,
                                selector
                            )
                        )
                        source_id += 1
                    elif type(key.data) is XmlLogProcessor:
                        if mask & selectors.EVENT_READ:
                            key.data.handleRead()
    finally:
        try:
            lsock.close()
            os.unlink(socket_path)
        except: pass

# ------------------------------------------------------------------------------
def handle_interrupt(sig, frame):
    global keep_running
    keep_running = False
# ------------------------------------------------------------------------------
def main():
    signal.signal(signal.SIGINT, handle_interrupt)
    signal.signal(signal.SIGTERM, handle_interrupt)
    display_logs("/tmp/eagine-xmllog")
    return 0
# ------------------------------------------------------------------------------
if __name__ == "__main__":
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        pass
