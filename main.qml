import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQml.Models 2.1
import QtQuick.Layouts 1.0
import QtQuick 2.0
import QtQuick 2.3
import QtLocation 5.3

ApplicationWindow {
    width: 550
    height: 550
    visible: true

    Rectangle {
        id:mainRect
        width: 500
        height: 500
        anchors.fill: parent
        anchors.centerIn: parent
        color: "gray"
        Item {
            id: name
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 500
            height: 500

            ListView {
                id: mainBoard
                model: myBoardModel
                anchors.fill: parent
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                interactive: false
                spacing: 10
                      verticalLayoutDirection: ListView.BottomToTop
                orientation: ListView.Horizontal
                move: Transition {
                    NumberAnimation { properties: "x,y"; duration: 1000 }
                }
                delegate:
                    Component {
                    Item {
                        anchors.bottom: parent.bottom
                        anchors.top: parent.top
                        height:100
                        width: 100
                        ListView {
                            model: column
                            id:myColumn
                            verticalLayoutDirection: ListView.BottomToTop
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            interactive: false
                            spacing: 10

                            Text {text:  index +"MM"}
                            move: Transition { id:myTrans
                                NumberAnimation { properties: "x,y"; duration: 3000 }
                            }
                            moveDisplaced:{myTrans}
                            delegate:
                                Component {
                                Item {
                                    id: myColumndelegate
                                    focus: true
                                    anchors.left: parent.left
                                    anchors.right: parent.right
                                    height:100
                                    width: 100

                                    Image {

                                        id: itemImage
                                        width: 100
                                        height: 100
                                        anchors.centerIn: parent.Center
                                        Text {text: index}
                                        source: myColumn.model.getSource(itemType)
                                    }
                                    MouseArea {
                                        id:myItemMouseArea
                                        anchors.fill: parent
                                        onClicked:
                                        {
                                            console.log(index,positionInModelRowRole)
                                            if(myTrans.running) {

                                            }
                                            if(!myTrans.running) {
                                                myColumn.model.shiftingItems(index);

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        MouseArea
        {
            Rectangle{
                anchors.fill: parent
                color: globalMouseArea.enabled ? "#6fff0000" : "#00000000"
            }

            id:globalMouseArea
            anchors.fill: parent
            enabled: false;
        }
    }
}


