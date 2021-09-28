import QtQuick 2.0
import QtQuick.Controls 2.2
Column{

    property alias search: search
	
	signal textChanged()
        height: 64
        id:column
         width: window.width
         Row{

             spacing:10

             Button{
                 id:backButton
                display: Button.IconOnly
				 icon.source:"back.png"
                 anchors.verticalCenter: parent.verticalCenter
		   
		   height:48
		  width:48
                 visible: window.stackView.children.length >1
                 onClicked: {

                    window.back()

                 }
             }

        Label{
            id:  headerText
            property var name:!window.copyMove.visible ? window.folderModel.folder.toString().split('/') : window.copyMoveModel.folder.toString().split('/')
            text:!window.isListModel ? window.stackView.currentItem.objectName :window.highlights.length!==0&&!window.copyMove.visible ? window.highlights.length+" Selected": name[name.length-1]
            height: column.height-1
            visible: !search.visible
             font.pixelSize: 17
            width: column.width-(4*48)
           
        }

        TextField{
            id:search

            height: column.height-1
            visible:false
            width: headerText.width
           onTextChanged:{
             column.textChanged();

            }
            
            }

        Button{
         id:searchButton
         display:Button.IconOnly
		 anchors.verticalCenter: parent.verticalCenter
		 
		  height:48
		  width:48
	
	
		icon.source:search.visible ? "close.png" : window.highlights.length!==0 ? "delete.png":"search.png"
			
			
	
         visible: backButton.visible&&window.isListModel&&!window.copyMove.visible
          onVisibleChanged: {
             //if(!visible){search.visible=false}
         }
         onClicked: {
		 if(window.highlights.length!==0){
			window.deleteFiles();
			return;
		 }
				
              if(search.visible){
				search.text=""
			  }else{
			   search.visible=true
			   
			  }
			search.focus=true			  
			
         }

        }
        Button{
         id:options
		 
		  icon.source:"menu.png"
		  anchors.verticalCenter: parent.verticalCenter
		   
		   height:48
		  width:48
          display:Button.IconOnly
         visible: backButton.visible&&!search.visible&&!window.copyMove.visible
		 onClicked:{
		 if(window.highlights.length===0)
		 contextMenu.open();
		 else
		 fileMenu.open();
		 }


        }


         }
        Rectangle{
            width: window.width
            //enabled: false
            height: 1
            color: msg.colors[1]
        }
		Menu {
               id: contextMenu
               x:options.x
               y:options.y
               MenuItem { text: "New folder" ;enabled:window.isListModel;onClicked: {window.popup.open()} }
               MenuItem { enabled:window.isListModel;text:select.text;
			   onClicked: {
			  
			   window.selectDiselect();
			    } 
			   }
               MenuItem { text: "Information" ;onClicked:{window.information.open()}}
           }
		   Menu {
               id: fileMenu
               x:options.x
               y:options.y
               MenuItem { 
			   id:select
			   text: window.highlights.length===window.folderModel.count ? "Diselect all":"Select all"
			   onClicked: {
			  
				window.selectDiselect();
			    } 
			   
			   }
               MenuItem { text: "Delete" ;enabled:window.isListModel
			   
			   onClicked:{
			   if(window.highlights.length!==0)
					window.deleteFiles();
				}
			   
			   }
               MenuItem { text: "Rename" ;enabled:window.highlights.length<=1
			   onClicked:{
					window.popup.folder=false;
					window.popup.open();
			   }
			   
			   
			   }
			   MenuItem { text: "Copy"

				onClicked:{
					copyMove.open();
					copyMove.copy=true;
					
			   }

				}
			   MenuItem { text: "Move" 
			   
			   onClicked:{
					copyMove.open();
			   }
			   
			   
			   }
           }
    }
