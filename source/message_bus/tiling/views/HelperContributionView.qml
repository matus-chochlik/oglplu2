import QtQuick 2.12
import QtCharts 2.1
import "qrc:///views"

ChartView {
    id: helperContributionView
    property var model: null

    theme: backend.theme.light
        ? ChartView.ChartThemeLight
        : ChartView.ChartThemeDark
    antialiasing: true

    BarSeries {
        axisX: BarCategoryAxis {
            labelsAngle: 90
            categories: helperContributionView.model
                ? helperContributionView.model.helperIds
                : []
        }

        axisY: ValueAxis {
            min: 0
            max: helperContributionView.model
                ? helperContributionView.model.maxSolvedCount
                : 1
        }

        BarSet {
            label: qsTr("count of solutions by helper")
            values: helperContributionView.model
                ? helperContributionView.model.solvedCounts
                : []
        }
    }
}
