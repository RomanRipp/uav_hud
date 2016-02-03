import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls 1.3

Window {
    property alias container: container
    property alias image: image
    property alias battery: battery
    visible: true

    Item {
        id: container
        anchors.fill: parent

        property var textSize: 16
        property var paramColor: "#46b71b"
        property var locationColor: "white"
        property var margin: 8
        visible: true

        Image {
            objectName: "Image"
            id: image
            source: "../images/NoSignal.png"
            anchors.fill: parent
        }

        Text {
            objectName: "Battery"
            id: battery
            width: contentWidth
            height: contentHeight
            color: parent.paramColor
            text: qsTr("BAT 000%")
            anchors.left: parent.left
            anchors.leftMargin: parent.margin
            anchors.top: parent.top
            anchors.topMargin: parent.margin
            font.pixelSize: parent.textSize
        }

        Text {
            objectName: "SAT"
            id: gps
            width: contentWidth
            height: contentHeight
            color: parent.paramColor
            text: qsTr("SAT 00")
            anchors.top: parent.top
            anchors.topMargin: parent.margin
            anchors.left: battery.right
            anchors.leftMargin: parent.margin
            font.pixelSize: parent.textSize
        }

        Text {
            objectName: "ALT"
            id: altitude
            width: contentWidth
            height: contentHeight
            color: parent.locationColor
            text: qsTr("ALT 000")
            anchors.topMargin: parent.margin
            anchors.top: latitude.bottom
            anchors.right: parent.right
            anchors.rightMargin: parent.margin
            font.pixelSize: parent.textSize
        }

        Text {
            objectName: "LON"
            id: longitude
            width: contentWidth
            height: contentHeight
            color: parent.locationColor
            text: qsTr("LON 000000")
            anchors.topMargin: parent.margin
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.rightMargin: parent.margin
            font.pixelSize: parent.textSize
        }

        Text {
            objectName: "LAT"
            id: latitude
            width: contentWidth
            height: contentHeight
            color: parent.locationColor
            text: qsTr("LAT 000000")
            anchors.top: longitude.bottom
            anchors.topMargin: parent.margin
            anchors.right: parent.right
            anchors.rightMargin: parent.margin
            font.pixelSize: parent.textSize
        }


        Text {
            objectName: "FlyingState"
            id: flying
            width: contentWidth
            height: contentHeight
            color: parent.paramColor
            text: qsTr("Flying State: LANDED")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.margin
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: parent.textSize
        }

        Item {
            objectName: "Nose"
            id: nose
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Rectangle {
                id: horisonr
                x: (camera.width/2) + 5
                width: camera.width * 3
                height: 1
                color: container.paramColor
                border.color: container.paramColor
                border.width: 1
            }

            Rectangle {
                id: horisonl
                width: camera.width * 3
                x: - (width + camera.width / 2 + 5)
                height: 1
                color: container.paramColor
                border.color: container.paramColor
                border.width: 1
            }

            Rectangle {
                id: center
                width: 2
                height: width
                color: container.paramColor
                border.color: container.paramColor
                border.width: 1
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                radius: width / 2
            }
        }

        Image {
            id: camera
            width: parent.textSize * 2
            height: width
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -2
            source: "../images/cam.svg"
        }
    }
}
