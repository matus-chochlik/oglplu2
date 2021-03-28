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
import math
import stat
import time
import errno
import socket
import signal
import string
import base64
import xml.sax
import argparse
import textwrap
import threading

try:
    import selectors
except ImportError:
    import selectors2 as selectors

# ------------------------------------------------------------------------------
def permanentTranslations():
    return {
        "bool": {
            "type": int,
            "opts": {
                0: "False",
                1: "True"
            }
        },
        "DbgOutSrce": {
            "type": int,
            "opts": {
                0x8246: "API",
                0x8247: "window system",
                0x8248: "shader compiler",
                0x8249: "third party",
                0x824A: "application",
                0x824B: "other"
            }
        },
        "DbgOutType": {
            "type": int,
            "opts": {
                0x824C: "error",
                0x824D: "deprecated behavior",
                0x824E: "undefined  behavior",
                0x824F: "portability",
                0x8250: "performance",
                0x8251: "other"
            }
        },
        "DbgOutSvrt": {
            "type": int,
            "opts": {
                0x9146: "high",
                0x9147: "medium",
                0x9148: "low",
                0x826B: "notification"
            }
        }
    }
# ------------------------------------------------------------------------------
def formatRelTime(s):
    if s >= 60480000:
        return "%dw" % (int(s) / 604800)
    if s >= 604800:
        return "%2dw %2dd" % (int(s) / 604800, (int(s) % 604800) / 86400)
    if s >= 86400:
        return "%2dd %2dh" % (int(s) / 86400, (int(s) % 86400) / 3600)
    if s >= 3600:
        return "%2dh %02dm" % (int(s) / 3600, (int(s) % 3600) / 60)
    if s >= 60:
        return "%2dm %02ds" % (int(s) / 60, int(s) % 60)
    if s >= 10:
        return "%3ds" % int(s)
    if s >= 0.01:
        return "%4dms" % int(s*10**3)
    if s <= 0.0:
        return "0"
    return "%dμs" % int(s*10**6)

# ------------------------------------------------------------------------------
class ArgumentParser(argparse.ArgumentParser):
    # -------------------------------------------------------------------------
    def __init__(self, **kw):
        def _positive_int(x):
            try:
                assert(int(x) > 0)
                return int(x)
            except:
                self.error("`%s' is not a positive integer value" % str(x))

        argparse.ArgumentParser.__init__(self, **kw)

        self.add_argument(
            "--output", "-o", 
            metavar='OUTPUT-FILE',
            dest='output_path',
            nargs='?',
            type=os.path.realpath,
            default=None
        )

        self.add_argument(
            "--keep-running", "-k",
            dest="keep_running",
            action="store_true",
            default=False,
            help="""
            Keeps running even after all logging backends have disconnected.
            """
        )
        try:
            import matplotlib.pyplot as plt
            self.add_argument(
                "--plot-charts", "-p",
                dest="plot_charts",
                action="store_true",
                default=False,
                help="""
                Plots charts from statistic samples received from the backends.
                """
            )

            self.add_argument(
                "--plot-output", "-P", 
                metavar='OUTPUT-FILE',
                dest='plot_output_path',
                nargs='?',
                type=os.path.realpath,
                default=None,
                help="""
                Specifies the plot output PDF file path.
                """
            )

            self.add_argument(
                "--plot-reduce", "-R", 
                metavar='MAX-SAMPLES',
                dest='plot_reduce_count',
                nargs='?',
                type=_positive_int,
                default=None,
                help="""
                Reduces plot series sample count to at most MAX-SAMPLES.
                """
            )

            self.add_argument(
                "--plot-normalize", "-N", 
                dest='plot_normalize',
                action="store_true",
                default=False,
                help="""
                Makes the plot series normalized.
                """
            )
        except ImportError:
            self.add_argument(
                "--plot-charts", "-p",
                dest="plot_charts",
                action="store_false",
                default=False,
                help="""
                The matplotlib module cannot be imported.
                This option has no effect.
                """
            )

    # -------------------------------------------------------------------------
    def processParsedOptions(self, options):

        if options.output_path is None:
            options.log_output = sys.stdout
        else:
            options.log_output = open(options.output_path, "wt")
        return options

    # -------------------------------------------------------------------------
    def parseArgs(self):
        # ----------------------------------------------------------------------
        class _Options(object):
            # ------------------------------------------------------------------
            def __init__(self, base):
                self.__dict__.update(base.__dict__)
            # ------------------------------------------------------------------
            def initialize(self, plot, fig):
                if self.plot_output_path:
                    fig.set_size_inches(8, 4.5)
            # ------------------------------------------------------------------
            def finalize(self, plot):
                if self.plot_output_path:
                    plot.savefig(
                        self.output_path,
                        papertype="a3",
                        orientation="landscape",
                        transparent=True,
                        format="pdf"
                    )
                else:
                    plot.show()

        return _Options(self.processParsedOptions(
            argparse.ArgumentParser.parse_args(self)
        ))

# ------------------------------------------------------------------------------
def getArgumentParser():
    return ArgumentParser(
        prog=os.path.basename(__file__),
        description="""
            Process formatting the XML log output from one or several
            OGLplus logger backends.
        """
    )
# ------------------------------------------------------------------------------
keepRunning = True
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
    def _ttyInvert(self):
        return self._ttyEsc("\x1b[7m")

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
    def _formatFsPath(self, p):
        if os.path.exists(p):
            if os.path.islink(p):
                return self._ttyBlue() + p + self._ttyReset()
            if os.path.isdir(p):
                return self._ttyGreen() + p + self._ttyReset()
            return self._ttyBoldGreen() + p + self._ttyReset()

        return self._ttyBoldRed() + p + self._ttyReset()

    # --------------------------------------------------------------------------
    def _formatIdentifier(self, p):
        return "\"" + self._ttyBoldBlue() + p + self._ttyReset() + "\""

    # --------------------------------------------------------------------------
    def _formatProgArg(self, p):
        return "«" + self._ttyBoldWhite() + p + self._ttyReset() + "»"

    # --------------------------------------------------------------------------
    def _formatRatio(self, x):
        return self._ttyBoldWhite() + ("%3.1f%%" % float(x * 100)) + self._ttyReset()

    # --------------------------------------------------------------------------
    def _formatDuration(self, sec):
        return self._ttyBoldWhite() + formatRelTime(float(sec)) + self._ttyReset()

    # --------------------------------------------------------------------------
    def _formatYesNoMaybe(self, v):
        if v == "yes":
            return self._ttyBoldGreen() + v + self._ttyReset()
        if v == "no":
            return self._ttyBoldRed() + v + self._ttyReset()
        return self._ttyYellow() + "maybe" + self._ttyReset()
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
    def _formatValueBar(self, mn, x, mx, width, invert):
        coef = (x - mn) / (mx - mn)
        pos = coef * float(width)
        cnt = int(pos)
        lbl = " %.1f%% " % (100.0 * coef)

        i = 0
        result = "│"
        if invert:
            result += self._ttyInvert()

        if coef >= 0.5:
            while i + len(lbl) < cnt:
                result += "█"
                i += 1

            if i + len(lbl) <= cnt:
                if invert:
                    result += self._ttyReset()
                else:
                    result += self._ttyInvert()
                result += lbl
                i += len(lbl)
                if invert:
                    result += self._ttyInvert()
                else:
                    result += self._ttyReset()

        while i < cnt:
            result += "█"
            i += 1

        if i < width:
            parts = [" ", "▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"]
            result += parts[int(9 * (pos - float(cnt)))]
            i += 1

        if coef < 0.5:
            if i + len(lbl) < width:
                result += lbl
                i += len(lbl)

        while i < width:
            result += " "
            i += 1

        if invert:
            result += self._ttyReset()
        else:
            result += "│"

        return result

    # --------------------------------------------------------------------------
    def _formatInteger(self, s):
        return f"{int(s):,}".replace(",", "'")

    # --------------------------------------------------------------------------
    def _formatReal(self, s):
        return f"{float(s):,}".replace(",", "'")

    # --------------------------------------------------------------------------
    def __init__(self, options):
        self._options = options
        self._start_time = time.time()
        self._re_var = re.compile(".*(\${([A-Za-z][A-Za-z_0-9]*)}).*")
        self._lock = threading.Lock()
        self._out = options.log_output
        self._backend_count = 0

        self._translations = permanentTranslations()

        self._decorators = {
            "FsPath": self._formatFsPath,
            "Identifier": self._formatIdentifier,
            "ProgramArg": self._formatProgArg,
            "Ratio": lambda x: self._formatRatio(float(x)),
            "duration": lambda x: self._formatDuration(float(x)),
            "integer": self._formatInteger,
            "int64": self._formatInteger,
            "int32": self._formatInteger,
            "int16": self._formatInteger,
            "uint64": self._formatInteger,
            "uint32": self._formatInteger,
            "uint16": self._formatInteger,
            "real": self._formatReal,
            "YesNo": self._formatYesNoMaybe,
            "YesNoMaybe": self._formatYesNoMaybe,
            "ByteSize": lambda x: self._formatByteSize(int(float(x)))
        }
        self._source_id = 0
        self._sources = []
        self._loggers = {}
        self._root_ids = {}
        self._prev_times = {}

        with self._lock:
            self._out.write("╮\n")
    # --------------------------------------------------------------------------
    def __del__(self):
        with self._lock:
            self._out.write("╯\n")
            self._out.close()

    # --------------------------------------------------------------------------
    def beginLog(self, srcid, info):
        self._backend_count += 1
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
            self._root_ids[srcid] = None
            self._prev_times[srcid] = None

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
            del self._root_ids[srcid]
            del self._prev_times[srcid]

        self._backend_count -= 1
        if self._backend_count < 1:
            if self._options.plot_charts:
                self.plotCharts()
            if not self._options.keep_running:
                global keepRunning
                keepRunning = False

    # --------------------------------------------------------------------------
    def translateLevel(self, level):
        if level == "debug":
            return self._ttyBoldCyan()   + "  debug  " + self._ttyReset()
        if level == "info":
            return self._ttyBoldWhite()  + "  info   " + self._ttyReset()
        if level == "stat":
            return self._ttyBoldWhite()  + "  stat   " + self._ttyReset()
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
    def doTranslateArg(self, arg, info):
        if info.get("blob", False):
            return "BLOB"

        try:
            typ = info.get("type")
            value = info.get("value")
            try:
                trans = self._translations[typ]
                value = trans["opts"][trans["type"](value)] 
            except: pass
            decorate = self._decorators.get(typ, lambda x: x)
            value = decorate(value)
        except KeyError:
            value = arg
        return value

    # --------------------------------------------------------------------------
    def alwaysTranslateAsList(self, values):
        for v in values:
            if v["type"] == "bitfield":
                return True
        return False

    # --------------------------------------------------------------------------
    def translateArg(self, arg, info):
        info["used"] = True
        values = info.get("values", [])
        if len(values) == 1 and not self.alwaysTranslateAsList(values):
            return self.doTranslateArg(arg, values[0])
        values = [self.doTranslateArg(arg, v) for v in values]
        return '[' + ", ".join(values) + ']'

    # --------------------------------------------------------------------------
    def formatInstance(self, instance):
        instance = hash(instance) % ((sys.maxsize + 1) * 2)
        instance = instance.to_bytes(8, byteorder='big')
        instance = base64.b64encode(instance, altchars=b"'-")
        instance = instance.decode("utf-8")
        return instance

    # --------------------------------------------------------------------------
    def addMessage(self, srcid, info):
        args = info["args"]
        message = info["format"]

        if self._root_ids[srcid] is None:
            self._root_ids[srcid] = info["source"]

        curr_time = time.time()
        if self._prev_times[srcid] is None:
            time_diff = None
        else:
            time_diff = curr_time - self._prev_times[srcid]
        self._prev_times[srcid] = curr_time

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
            self._out.write("%9s│" % formatRelTime(float(info["timestamp"])))
            self._out.write("%9s│" % (formatRelTime(time_diff) if time_diff is not None else "   N/A   "))
            self._out.write("%s│" % self.translateLevel(info["level"]))
            self._out.write("%10s│" % self._root_ids[srcid])
            self._out.write("%10s│" % info["source"])
            self._out.write("%12s│" % self.formatInstance(info["instance"]))
            self._out.write("\n")
            self._out.write("┊")
            for sid in self._sources:
                self._out.write(" │")
            self._out.write(" ├─────────┴─────────┴─────────┴──────────┴──────────┴────────────╯")
            self._out.write("\n")

            cols = 80 - (len(self._sources) * 2)
            lno = 0
            for line in textwrap.wrap(message, cols):
                self._out.write("┊")
                for sid in self._sources:
                    self._out.write(" │")
                if lno == 0:
                    self._out.write(" ╰╴")
                else:
                    self._out.write("   ")
                lno += 1
                self._out.write(line)
                self._out.write("\n")
            # BLOBs and progress
            for name, info in args.items():
                if not info["used"]:
                    for value in info["values"]:
                        self._out.write("┊")
                        for sid in self._sources:
                            self._out.write(" │")
                        self._out.write("   ")
                        self._out.write(name)
                        self._out.write(": ")
                        if value["min"] is not None and value["max"] is not None:
                            self._out.write(
                                self._formatValueBar(
                                    float(value["min"]),
                                    float(value["value"]),
                                    float(value["max"]),
                                    cols - len(name) - 2,
                                    value["type"] in ["Progress"]
                                )
                            )
                            self._out.write("\n")
                        else:
                            self._out.write(self.doTranslateArg(name, value))
                            self._out.write("\n")
                        if value["blob"]:
                            blob = value["value"]
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

    # --------------------------------------------------------------------------
    def addLoggerInfos(self, srcid, infos):
        self._loggers[srcid] = infos

    # --------------------------------------------------------------------------
    def plotCharts(self):
        import matplotlib.pyplot as plt
        import matplotlib.ticker as pltckr

        def _formatTime(s, pos=None):
            h = int(s/3600)
            s -= h*3600
            m = int(s/60)
            s -= m*60
            return "%d:%02d:%02d" % (h, m, s)

        def _reduceSamples(lst):
            maxlen = self._options.plot_reduce_count 
            maxlen = maxlen if maxlen is not None else len(lst)
            if maxlen < len(lst):
                def _avg(x, y):
                    return (sum(x)/len(x), sum(y)/len(y))
                
                temp = []
                llen = len(lst)
                fact = int(math.ceil(llen / maxlen))
                nlen = int(math.ceil(llen / fact))
                for step in range(nlen):
                    bgn = step*fact
                    idx = [bgn + i for i in range(fact) if (bgn + i) < llen]
                    temp.append(_avg(*map(list, zip(*[lst[i] for i in idx]))))
                lst = temp
            return lst

        plt.style.use('dark_background')

        fig, spl = plt.subplots()
        self._options.initialize(plt, fig)

        spl.set_xlabel("Time [HH:MM:SS]")
        if not self._options.plot_normalize:
            spl.set_yscale("log")

        x_tick_interval = 5

        for srcid, loggers in self._loggers.items():
            for logger_id, instances in loggers.items():
                for instance_id, instance in instances.items():
                    for ser, series in instance["charts"].items():
                        x_tick_interval = max(x_tick_interval, series[-1][0])
                        x, y = map(list, zip(*_reduceSamples(series)))
                        if self._options.plot_normalize:
                            try:
                                ny = 1.0 / max([abs(v) for v in y])
                                y = [v*ny for v in y]
                            except ZeroDivisionError:
                                pass
                        label = "%s.%s" % (
                            instance.get("display_name", "%s[%s]" % (
                                logger_id,
                                self.formatInstance(instance_id)
                            )),
                            ser
                        )
                        spl.plot(x, y, label=label)

        tick_opts = [5,10,15,30,60,300,600,900,1800,3600,7200,86400]
        for t in tick_opts:
            x_tick_maj = t
            if x_tick_interval / x_tick_maj < 15:
                break

        spl.xaxis.set_major_locator(pltckr.MultipleLocator(x_tick_maj))
        spl.xaxis.set_minor_locator(pltckr.NullLocator())
        spl.xaxis.set_major_formatter(pltckr.FuncFormatter(_formatTime))
        spl.xaxis.set_tick_params(rotation=60)

        spl.yaxis.set_major_locator(pltckr.LogLocator(base=10,numdecs=None))
        spl.yaxis.set_minor_locator(pltckr.NullLocator())

        spl.grid(which="both", axis="both", alpha=0.15)
        spl.legend(bbox_to_anchor=(1,0), loc="lower left")
        self._options.finalize(plt)

    # --------------------------------------------------------------------------
    def makeProcessor(self):
        self._source_id += 1
        return XmlLogProcessor(self._source_id, self)

# ------------------------------------------------------------------------------
class XmlLogProcessor(xml.sax.ContentHandler):
    # --------------------------------------------------------------------------
    def __init__(self, srcid, formatter):
        self._srcid = srcid
        self._ctag = None
        self._carg = None
        self._info = None
        self._loggers = {}
        self._start_time = time.time()
        self._formatter= formatter
        self._parser = xml.sax.make_parser()
        self._parser.setContentHandler(self)

    # --------------------------------------------------------------------------
    def startElement(self, tag, attr):
        time_ofs = self._start_time - self._formatter._start_time
        self._ctag = tag
        if tag == "log":
            self._formatter.beginLog(self._srcid, attr)
        elif tag == "m":
            self._info = {
                r: attr[k] for k, r in [
                    ("lvl", "level"),
                    ("src", "source"),
                    ("iid", "instance"),
                    ("ts",  "timestamp")
                ]
            }
            self._info["args"] = {}
        elif tag == "a":
            self._carg = attr["n"]
            iarg = {
                "value": "''",
                "min": attr.get("min"),
                "max": attr.get("max"),
                "type": attr["t"],
                "blob": attr.get("blob", False)
            }
            try: self._info["args"][self._carg]["values"].append(iarg)
            except KeyError:
                self._info["args"][self._carg] = {
                    "used": False,
                    "values": [iarg]
                }
        elif tag == "c":
            try: logger = self._loggers[attr["src"]]
            except KeyError: 
                logger = self._loggers[attr["src"]] = {}
            try: inst = logger[attr["iid"]]
            except KeyError:
                inst = logger[attr["iid"]] = {}
            try: charts = inst["charts"]
            except KeyError:
                charts = inst["charts"] = {}
            try: series = charts[attr["ser"]]
            except KeyError:
                series = charts[attr["ser"]] = []
            series.append((time_ofs+float(attr["ts"]), float(attr["v"])))
        elif tag == "d":
            try: logger = self._loggers[attr["src"]]
            except KeyError: 
                logger = self._loggers[attr["src"]] = {}
            try: inst = logger[attr["iid"]]
            except KeyError:
                inst = logger[attr["iid"]] = {}
            inst["display_name"] = attr["dn"]
            inst["description"] = attr["desc"]
            
    # --------------------------------------------------------------------------
    def endElement(self, tag):
        if tag == "log":
            self._formatter.addLoggerInfos(self._srcid, self._loggers)
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
                self._info["args"][self._carg]["values"][-1]["value"] = content

    # --------------------------------------------------------------------------
    def processLine(self, line):
        self._parser.feed(line)

# ------------------------------------------------------------------------------
class XmlLogClientHandler(xml.sax.ContentHandler):

    # --------------------------------------------------------------------------
    def __init__(self, processor, connection, selector):
        self._processor = processor
        self._connection = connection
        self._selector = selector 
        self._buffer = bytes()

    # --------------------------------------------------------------------------
    def __del__(self):
        self._connection.close()

    # --------------------------------------------------------------------------
    def disconnect(self):
        self._processor.processLine(self._buffer)
        self._selector.unregister(self._connection)

    # --------------------------------------------------------------------------
    def handleRead(self):
        try:
            data = self._connection.recv(4096)
            if data:
                sep = bytes('\n','utf-8')
                self._buffer += data
                lines = self._buffer.split(sep)
                done = 0
                for line in lines[:-1]:
                    try:
                        self._processor.processLine(line.decode('utf-8'))
                        done += 1
                    except UnicodeDecodeError: 
                        print(line)
                        break
                self._buffer = sep.join(lines[done:])
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
def handle_connections(socket_path, formatter):
    try:
        global keepRunning
        lsock = open_socket(socket_path)
        with selectors.DefaultSelector() as selector:
            selector.register(
                lsock,
                selectors.EVENT_READ,
                data = formatter
            )

            while keepRunning:
                events = selector.select(timeout=1.0)
                for key, mask in events:
                    if type(key.data) is XmlLogFormatter:
                        connection, addr = lsock.accept()
                        connection.setblocking(False)
                        selector.register(
                            connection,
                            selectors.EVENT_READ,
                            data = XmlLogClientHandler(
                                key.data.makeProcessor(),
                                connection,
                                selector
                            )
                        )
                    elif type(key.data) is XmlLogClientHandler:
                        if mask & selectors.EVENT_READ:
                            key.data.handleRead()
    finally:
        try:
            lsock.close()
            os.unlink(socket_path)
        except: pass

# ------------------------------------------------------------------------------
def handleInterrupt(sig, frame):
    global keepRunning
    keepRunning = False
# ------------------------------------------------------------------------------
def main():
    try:
        options = getArgumentParser().parseArgs()
        signal.signal(signal.SIGINT, handleInterrupt)
        signal.signal(signal.SIGTERM, handleInterrupt)
        formatter = XmlLogFormatter(options)
        handle_connections("/tmp/eagine-xmllog", formatter)
    except KeyboardInterrupt:
        return 0
# ------------------------------------------------------------------------------
if __name__ == "__main__":
        sys.exit(main())

