import QtQuick 2.3
import QtQuick.Window 2.2
import veiko.qt.ColorMaker 1.0
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 400;
    height: 400;

    Button{
        id: start;
        text: qsTr("Start");
        width: 100;
        height: 28;

        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.leftMargin: 5;
        anchors.topMargin: 5;

        onClicked: {
            colorMaker.start();
        }
    }

    Button{
        id:stop;
        text: qsTr("Stop");
        width: 100;
        height: 28;

        anchors.left: start.right;
        anchors.top: parent.top;
        anchors.leftMargin: 5;
        anchors.topMargin: 5;

        onClicked: {
            colorMaker.stop();
        }
    }

    ColorMaker{
        id:colorMaker;
        color: "#443366";
    }

    Rectangle{
        id: colorRect;
        anchors.left: parent.left;
        anchors.top: start.bottom;
        anchors.leftMargin: 5;
        anchors.topMargin: 5;

        width: 50;
        height: 50;

        color: "#FFFFFF";
    }

    function changAlgorithm(button,algorithm){
        switch(algorithm){
        case 0:
            button.text = "RandomRGB";
            break;

        case 1:
            button.text = "RandomRed";
            break;

        case 2:
            button.text = "RandomGreen";
            break;

        case 3:
            button.text = "RandomBlue";
            break;

        case 4:
            button.text = "LinearIncrease";
            break;
        }
    }

    Button{
        id: colorAlgorithm;
        anchors.left: stop.right;
        anchors.top: parent.top;
        anchors.leftMargin: 5;
        anchors.topMargin: 5;

        text: qsTr("RandomRGB");

        onClicked: {
            var algorithm = (colorMaker.algorithm() + 1) % 5;
            changAlgorithm(colorAlgorithm,algorithm);
            colorMaker.setAlgorithm(algorithm);
        }
    }

    Component.onCompleted: {
        colorMaker.color = Qt.rgba(0,180,120,255);
        colorMaker.setAlgorithm(ColorMaker.increase);
        changAlgorithm(colorAlgorithm,colorMaker.algorithm());
    }

    Text{
        id: timeLabel;

        anchors.left: parent.left;
        anchors.top: colorRect.bottom;
        anchors.leftMargin: 5;
        anchors.topMargin: 5;

        width: 300;
        height: 28;

        font.bold: true;
        font.pointSize: 10;
    }

    Connections{
        target: colorMaker;
        onCurrentTime:{
            timeLabel.text = strTime;
            timeLabel.color = colorMaker.colorTime;
        }
    }

    Connections{
        target: colorMaker;
        onColorChanged:{
            colorRect.color = color;
        }
    }
}

