import QtQuick
import Custom

Window {
	id: rootWindow
	width: 640
	height: 480
	visible: true
	title: qsTr("Test Qt Project")

	Repeater {
		model: Control.dataList
		delegate: Rectangle {
			width: 50
			height: 50
			x: modelData.x
			y: modelData.y
			color: modelData.clr

			Text {
				text: modelData.id
				anchors.centerIn: parent
			}
		}
	}
}
