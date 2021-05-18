.pragma library

var lc = Qt.locale("C")

function percentStr(value) {
	return value
		? "%1 %".arg(Number(value*100.0).toLocaleString(lc, "f", 1))
		: "-"
}

function kilobyteStr(value) {
	return value
		? "%1 kB".arg(Number(value/1000).toLocaleString(lc, "f", 1))
		: "-"
}

function megabyteStr(value) {
	return value
		? "%1 MB".arg(Number(value/1000000).toLocaleString(lc, "f", 1))
		: "-"
}

function durationStr(seconds) {
	if(seconds) {
		seconds = Math.trunc(seconds)
		var days = Math.floor(seconds / 86400)
		seconds = seconds - days * 86400
		var hours = Math.floor(seconds / 3600)
		seconds = seconds - hours * 3600
		var minutes = Math.floor(seconds / 60)
		seconds = seconds - minutes * 60

		if(days > 0) {
			return "%1 d %2 hr".arg(days).arg(hours)
		}
		if(hours > 0) {
			return "%1 hr %2 min".arg(hours).arg(minutes)
		}
		if(minutes > 0) {
			return "%1 min %2 sec".arg(minutes).arg(seconds)
		}
		return "%1 sec".arg(seconds)
	}
	return "-"
}

function temperature(kelvins) {
	if(kelvins) {
		return"%1 °C"
			.arg(Number(kelvins - 273.15).toLocaleString(lc, "f", 1))
	}
	return "-"
}
function temperatureDelta(kelvins) {
	if(kelvins) {
		return"%1 °C"
			.arg(Number(kelvins).toLocaleString(lc, "f", 1))
	}
	return "-"
}
