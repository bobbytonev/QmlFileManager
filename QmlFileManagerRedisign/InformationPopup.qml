import QtQuick 2.0

import QtQuick.Controls 2.12
Popup {
 id:popup
   
	width:parent.width
	height:parent.height
    
	MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.BackButton
        onPressed:{
           popup.close()
        }


    }

Column{
anchors.fill:parent
	Button{
		height:128
		width:parent.width
		text:isListModel ? window.folderModel.folder :  window.stackView.currentItem.objectName;
		icon.source:"folder.png"
		display:Button.TextUnderIcon
		
	}
	
	MenuSeparator {
		width:parent.width
	}
	
	Label{
	property var str: isListModel ? window.folderModel.count :  fileManager.files.length;
		text:"Number of items:"+ str;
		height:window.mediumSize
		width:parent.width
	}

}


}