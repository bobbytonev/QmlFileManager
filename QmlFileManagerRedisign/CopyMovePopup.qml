import QtQuick 2.0
import QtQuick.Controls 2.12
Popup {

closePolicy:Popup.NoAutoClose
    width:parent.width
    height: parent.height

id:popup


property var copy:false

    Component.onCompleted: {
        window.copyMoveModel.folder="file:///home/bobby"
		

    } 
	
	 onVisibleChanged: {if(!visible){ copy=false; window.copyMoveModel.folder="" } else  window.copyMoveModel.folder="file:///home/bobby"  }


    Column{
        anchors.fill: parent
  ListView{
        id:view
        width: parent.width
        height: parent.height-row.height
        clip:true
        spacing:5

        model:window.copyMoveModel
        delegate:Button{

            text:fileName
            width: view.width
            height: window.mediumSize
            ///new code


            onClicked: {
                if(window.copyMoveModel.isFolder(index)===true){

                    window.copyMoveModel.folder+="/"+text

                }



            }


        }

  }

  Row{
      id:row
      width: parent.width
      layoutDirection: Qt.RightToLeft
        Button{

            text:"Close"
            onClicked: {
                popup.close();

            }
        }
        Button{

             text:"Okey"
			 onClicked:{
				window.copyMoveFiles(copy);
				popup.close();
			 }


        }


    }
    }



}
