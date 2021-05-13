.pragma library

function durationStr(seconds) {
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
