

import QtQuick 2.0
import Qt.labs.folderlistmodel 2.15
import QtQuick.Controls 2.12
Item {

	

	
	StartWithPopup{
		id:startWithPopup
	}
	
	property var includeIndex:[]
    Connections {
        target: window.topPanel
        function onTextChanged(){
              
         
			includeIndex=[]
			for(var i = 0;i<window.folderModel.count; i++){
				if(!window.folderModel.get(i,"fileName").includes(window.topPanel.search.text)){
					
					includeIndex.push(i);
				}
			
			}
			includeIndex=includeIndex;
        }
    }

   
	
	ListView{
        id:view
        anchors.fill: parent
        clip:true
        spacing:5


        model:window.folderModel
        delegate:Button{

            text:fileName
            width: view.width
			visible:!includeIndex.includes(index);
            highlighted: window.highlights.includes(index);
            icon.source:window.folderModel.isFolder(index) ? "folder.png" : "file.png"
            height: window.mediumSize
            onClicked: {
               
                if(window.highlights.length!==0){
                    if(!highlighted){
                        window.highlights.push(index);
                    }else{
                        window.highlights.splice(window.highlights.indexOf(index), 1);
                    }
                        window.highlights= window.highlights;
                    return;
                }

                if(window.folderModel.isFolder(index)===true){

                    window.folderModel.folder+="/"+text
					console.log(window.folderModel.folder)

                }else{
					if(!fileManager.startApp(filePath)){
						startWithPopup.filePath=filePath;
						startWithPopup.open();
					}
				}
               


            }
            onPressAndHold: {
                  
               window.highlights.push(index);
                window.highlights= window.highlights;
                
            }

        }

    }

}
