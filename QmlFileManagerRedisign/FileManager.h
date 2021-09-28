#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDirIterator>
#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QMimeType>
#include <QMimeDatabase>
#include <QSettings>
#include <QProcess>
#include <QStorageInfo>

class FileManager: public QObject
{

    Q_OBJECT


    Q_PROPERTY(QVariantList files READ files WRITE setFiles NOTIFY filesChanged)


    struct FileInfo{
        QString name,path,type;

    }info;

public:


Q_INVOKABLE QVariantList getExternalDevices(){
	QVariantList list;
	
	
	QList<QStorageInfo> storage = QStorageInfo::mountedVolumes();
	for(int i=0;i<storage.size();i++){
	qDebug() << "name:" << storage[i].rootPath();
    qDebug() << "fileSystemType:" << storage[i].fileSystemType();
    qDebug() << "size:" << storage[i].bytesTotal()/1000/1000 << "MB";
    qDebug() << "availableSize:" << storage[i].bytesAvailable()/1000/1000 << "MB";
		list.append(QStringList{storage[i].name(),storage[i].rootPath()});
        
	}
     
	return list;
	
}


Q_INVOKABLE void newFolder(QString path){
	
	QDir dir(path);
	
	
if (!dir.exists()){
	
    dir.mkpath(".");
}
}

Q_INVOKABLE void deleteFile(QString filePath,bool folder){
		if(folder){
        QDir dir(filePath);
		dir.removeRecursively();
		}else{
		QFile::remove(filePath);
		}
}

Q_INVOKABLE void rename(QString filePath,QString fileName){
	
        QFile file (filePath);
            file.rename(fileName);
			
			qDebug()<<filePath;
			qDebug()<<fileName;
}
Q_INVOKABLE void copyMove(QString filePath,QString newFilePath,bool copy){

qDebug()<<filePath;

qDebug()<<newFilePath;

 QFile file (filePath);
			if(copy)
             file.copy(newFilePath);
		 else
			 file.rename(newFilePath);

}

Q_INVOKABLE void startProgram(QString program){
	
	QProcess::startDetached(program);
	
}

Q_INVOKABLE bool startApp(QString path){

	QMimeDatabase db;
    QMimeType type = db.mimeTypeForFile(path);
  
	QString mimeType =type.name();
	
	
	QStringList list{"Audio","Video","Image"};
	
	
	QString program =getProgram(mimeType);
	

	
	if(!program.isEmpty()){
		
		QProcess::startDetached(program+" "+path);
		return true;
	}else{
		QString key;
		for(int i=0;i<list.size();i++){
			if (mimeType.contains(list[i].toLower(),Qt::CaseInsensitive)){
				key=list[i];
			}
		}
		QString program =getProgram(key);
		if(!program.isEmpty()){
			QProcess::startDetached(program+" "+path);
			return true;
		}else{
			return false;
		}
		
		
		
		
	}
	
	
	

}

 QString getProgram(QString key){
if(key.isEmpty()) return "";
	
	QSettings settings(QSettings::NativeFormat,QSettings::UserScope,"kos-default-apps", "Apps");
             settings.beginGroup("Apps");
			 QString value =settings.value(key,"").toString();
			 
		
			  if(value.isEmpty()){
				  
				 return "";
				}
			 QStringList list = value.split(',');
			 
			
			 settings.endGroup();
			 
			  
			 qDebug()<<"HERE";
			 
			 return list[2];
	
	

}
    
    
Q_INVOKABLE void reload(QStringList regex){
       m_files.clear();
       //WINDOWS
       QDirIterator it("file:///home/bobby",{regex},QDir::Files,QDirIterator::Subdirectories);
       //LINIX


        while (it.hasNext()) {
            it.next();
            info.name=it.fileName();
            info.path="file:///"+it.filePath();


            m_files.append(QStringList{info.name, info.path});

      }


        setFiles(m_files);
        filesChanged();

    }
    void setFiles(const QVariantList &a) {
        if (a != m_files) {
            m_files = a;
            emit filesChanged();
        }
    }
   QVariantList files() const {
        return m_files;
    }
signals:
    void filesChanged();



private:
    QVariantList m_files;
};
#endif // FILEMANAGER_H
