import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15



Popup{
id:popup
width:parent.width
height:parent.height/2

y:parent.height/2


property var filePath

Rectangle{
	anchors.fill:parent	
	
	color:"transparent"
	
	border.color:popup.background.color.hslLightness > 0.5 ? "black"  : "white"
	border.width:1
}

 MouseArea{
       
        anchors.fill:parent
        acceptedButtons: Qt.BackButton
        onPressed: {

          popup.close();
        }
    }
onVisibleChanged: {
	if(visible) startWith.load(filePath);
}
	
	ListView{
 id:view
	clip:true
        anchors.fill: parent
       model:startWith.apps.length
    delegate:Button{
	
		
            width: parent.width
			
            text:startWith.apps[index][0]
			icon.color:"transparent"
			icon.source:"image://icons/"+startWith.apps[index][1]
              
            height: window.mediumSize
			onClicked:{
			popup.close();
			fileManager.startProgram(startWith.apps[index][2]+" "+filePath);
				
			
			}
	
	}
	}
	Label{
			text:"There is no app that can open this file"
			x:parent.width/2-width/2
			y:parent.height/2-height/2
			visible:view.count===0
			font.pixelSize: 18
		}


}