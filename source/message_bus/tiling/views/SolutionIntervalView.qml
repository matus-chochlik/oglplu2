import QtQuick 2.12
import QtCharts 2.1
import "qrc:///views"

ChartView {
    id: solutionIntervalView
    property var model: null

    theme: backend.theme.light
        ? ChartView.ChartThemeLight
        : ChartView.ChartThemeDark
    antialiasing: true

    BarSeries {
		axisX: ValueAxis {
			tickCount: 0
			titleVisible: false
			labelsVisible: false
		}

        axisY: ValueAxis {
			titleText: qsTr("duration (seconds)")
            min: 0
            max: solutionIntervalView.model
                ? solutionIntervalView.model.maxInterval
                : 1
        }

        BarSet {
            label: qsTr("interval between solutions")
            values: solutionIntervalView.model
                ? solutionIntervalView.model.intervals
                : []
        }
    }
}
