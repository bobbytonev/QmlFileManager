import QtQuick 2.12
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.0
Item{


 property var settingsNames: ["Audio","Video","Images","Main storage","Downloads","External Storage"]
 


NumberAnimation{
id:animation
target: grid
to:1
from:0
property:"opacity"
duration: 1000

}
Component.onCompleted: {
animation.start()
}



    Flow {

        id: grid
        opacity: 1

       anchors.fill: parent
        //spacing: 40

        Repeater{
            id:rep
            model:settingsNames.length
            Button{
                id:control
                     text: settingsNames[index];
                width: parent.width/3
				icon.source:settingsNames[index]+".png"
                height: window.largeSize
                 onClicked: {
                    
					if(index>2&&index<5){
                        window.isListModel=true;
						
						
                    }else
                        window.isListModel=false;
						
					if(index===3){
						window.folderModel.folder="file:///home/bobby"
					}else if(index===4){
						window.folderModel.folder="file:///home/bobby/Downloads"
						
						
					}
					window.stackView.push((text=="Downloads" ? "Main storage":text)+"-page.qml");
                    window.stackView.currentItem.objectName=text;



                }
                //Image{
                //    id:image
                  // source: "images/"+control.text+".png"
                    // width:control.height/2.7
                    // height: width
                    // x:16
                    // y:control.height/2-height/2

               // }
                //leftPadding: 18+image.width



        }
    }
}
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
