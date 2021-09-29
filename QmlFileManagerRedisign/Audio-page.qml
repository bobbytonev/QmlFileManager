import QtQuick 2.0
import QtQuick.Controls 2.12
Item {

    Component.onCompleted:{
        //fileManager.reload("*.png");
        fileManager.reload("*.mp3");


    }



    ListView{

        anchors.fill: parent
        spacing: 5
         clip:true
        model:fileManager.files.length
        delegate: Button{
               text:fileManager.files[index][0]
               width: parent.width
               height: window.mediumSize

        }



    }
}
