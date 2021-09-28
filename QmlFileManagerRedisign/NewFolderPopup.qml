import QtQuick 2.0
import QtQuick.Controls 2.12
Popup {
id:popup
modal:true
    x:parent.width/2-width/2
    y:parent.height/2-height/2


property var folder:true;


function submit(){
if(folderName.text!==""){
				
				if(folder)
					fileManager.newFolder(window.folderModel.folder.toString().replace("file://","")+"/"+folderName.text)
				else{
					fileManager.rename(window.folderModel.folder.toString().replace("file://","")+"/"+window.folderModel.get(highlights[0],"fileName"),window.folderModel.folder.toString().replace("file://","")+"/"+folderName.text);
					highlights=[];
				}
			  }
					popup.close()
}

 onVisibleChanged: {if(!visible){ folder=true; folderName.text="" } }
    Column{
        spacing:5
        Label{

           text:folder ? "New Folder" :"Rename"
		   

        }
        TextField{
			id:folderName
			  
			  font.pixelSize:13
			  Keys.onPressed: {


                    if (event.key === Qt.Key_Return) {

							submit();
					}

            }
		
        }
        Row{
            width: parent.width
        Button{
		
              text:"Okey"
			  display:Button.TextOnly
              width: parent.width/2
			  onClicked:{
				submit();
			  			
			}
			  
			 

        }
		
	
        Button{
			
            text:"Close"
			display:Button.TextOnly
              width: parent.width/2
              onClicked: {
                  popup.close()
              }
        }
        }

    }


}
