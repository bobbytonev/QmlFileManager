
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import Qt.labs.folderlistmodel 2.15

ApplicationWindow {
   id:window
    visible: true
    title: qsTr("FileManager")
    property alias stackView: stackView
	
      property alias folderModel: folderModel
	  
	   property var isListModel: false



	property var mediumSize: height/8
	property var largeSize: height/4.7
	
	property alias popup: popup
	property alias topPanel: topPanel
	property alias information:information
	
	
    property var highlights: []
	
	
	
	
	
	
	InformationPopup{
		id:information
	}
	
	onHighlightsChanged: {
        if(highlights.lenght!==0)
			topPanel.search.visible=false
        
    }
    

   property alias copyMoveModel: copyMoveModel
     property alias copyMove: copyMove

  
 

    FolderListModel {
        id: folderModel
        showDirsFirst: true
        
		      folder:""
        rootFolder: ""
		onFolderChanged: {
        //if(folder==rootFolder){
           // isListModel=false
        
       // }
 
 }
    }
	
	
    FolderListModel {
        id: copyMoveModel
        showDirsFirst: true
        folder:""

    }
   

  
    CopyMovePopup{
        id:copyMove

    }





    header:TopPanel{

		id:topPanel
		

    }



    StackView {
        id: stackView
        anchors.fill: parent



    }


    Component.onCompleted: {

        stackView.push("main-page.qml");
        stackView.currentItem.objectName="File manager";


    }
    MouseArea{
        id:mouse
        anchors.fill:parent
        acceptedButtons: Qt.BackButton
        onPressed: {
					back();
           
        }
    }
	 NewFolderPopup{

        id:popup
    }
	
	 function back(){
        
		
	
            if(copyMove.visible){


            if(window.copyMoveModel.folder=="file:///D:"){

           copyMove.close();

            } else{
            var temp1= window.copyMoveModel.folder.toString().split('/')
            window.copyMoveModel.folder=window.copyMoveModel.folder.toString().replace("/"+temp1[temp1.length-1],"");


            }
            return;
      }
     

		
		
		if(topPanel.search.visible){
            topPanel.search.visible=false;
            return;
        }


        if(highlights.length!==0) {
             highlights=[]
            return;
        }
       

        if(stackView.children.length===1){
            Qt.quit();
        }

        if(!window.isListModel||window.folderModel.folder=="file:///home/bobby"||window.folderModel.folder==window.folderModel.rootFolder){
           stackView.pop()
             window.isListModel=false;
			 window.folderModel.rootFolder=""

       } else{
            var temp= window.folderModel.folder.toString().split('/')
            window.folderModel.folder=window.folderModel.folder.toString().replace("/"+temp[temp.length-1],"");


        }
    }
	
	
	function selectDiselect(){
		if(highlights.length===folderModel.count){
				highlights=[];	
				return;		
		}
		
		highlights=[];	
		for(var i=0;i<folderModel.count;i++){
			highlights.push(i);
		}
		highlights=highlights;
	}

    function updateFilter()
       {
			var text=topPanel.search.text
           var filter = "*"
           for(var i = 0; i<text.length; i++)
               //if(!caseSensitiveCheckbox.checked)
                   filter+= "[%1%2]".arg(text[i].toUpperCase()).arg(text[i].toLowerCase())
              // else
                   //filter+= text[i]
           filter+="*"
          
           window.folderModel.nameFilters = [filter]
       }
	   function deleteFiles(){
		for(var i=0;i<highlights.length;i++){
			fileManager.deleteFile(folderModel.get(highlights[i],"filePath"),folderModel.isFolder(highlights[i]));
		
		}
		highlights=[];
		
	}
	function copyMoveFiles(copy){
		for(var i=0;i<highlights.length;i++){
			fileManager.copyMove(folderModel.get(highlights[i],"filePath"),copyMoveModel.folder.toString().replace("file://","")+"/"+folderModel.get(highlights[i],"fileName"),copy);
		
		}
		highlights=[];
		
	}




}
