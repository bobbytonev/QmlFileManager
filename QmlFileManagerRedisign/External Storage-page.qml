import QtQuick 2.0
import Qt.labs.folderlistmodel 2.15
import QtQuick.Controls 2.12
Item {

property var devices:fileManager.getExternalDevices();


    
Column{
anchors.fill:parent



	ListView{
        id:view
        width:parent.width
		height:parent.height-reload.height
        clip:true
        spacing:5

        model:devices.length
        delegate:Button{
			text:devices[index][1];
			width:view.width
			height:window.mediumSize
			
			onClicked:{
			window.folderModel.folder="file://"+devices[index][1]
			window.folderModel.rootFolder="file://"+devices[index][1]
				window.stackView.push("Main storage-page.qml");
                    window.stackView.currentItem.objectName=text;
					  window.isListModel=true;
			}
			
		}
		
		}
		
		Button{
		id:reload
			width:parent.width
			height:window.mediumSize
			text:"Reload"
			display:Button.TextOnly
		}


}



}