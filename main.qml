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
    width: 600
    height: 600
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
            ListView {
                id: mainBoard
                model: myBoardModel
                anchors.fill: parent
                orientation: ListView.Horizontal
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
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
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
                                        source: myColumn.model.getSource(itemType)

                                    }
                                    MouseArea {
                                        id:myItemMouseArea
                                        anchors.fill: parent
                                        onClicked: console.log (index,positionInModelRowRole)
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



//import QtQuick 2.4
//import QtQuick.Window 2.2
//import QtQuick.Controls 1.4
//import QtQuick.Dialogs 1.2
//import QtQml.Models 2.1
//import QtQuick.Layouts 1.0
//import QtQuick 2.0
//import QtQuick 2.3
//import QtLocation 5.3

//ApplicationWindow {
//    width: 1000
//    height: 1000
//    visible: true

//    Rectangle {
//        id:mainRect
//        anchors.fill: parent
//        color: "gray"
//        Item {
//            id: name
//            anchors.left: parent.left
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            width: 100

//            ListView {
//                id: mainBoard
//                model: mycolumnModel
//                anchors.fill: parent
//                delegate: Component {
//                    Item {
//                        id: myColumndelegate
//                        focus: true
//                        anchors.left: parent.left
//                        anchors.right: parent.right
//                        height:100
//                        width: 100
//                        Image {
//                            id: itemImage
//                            width: 100
//                            height: 100
//                            anchors.centerIn:   parent.Center
//                            source: mainBoard.model.getSource(itemType)
//                        }
//                        MouseArea {
//                            anchors.fill: parent
//                            onClicked: console.log(index,itemType)
//                        }
//                    }
//                }

//            }

//        }
//    }
//}



