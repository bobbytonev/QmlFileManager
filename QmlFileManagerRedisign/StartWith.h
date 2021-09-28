


#include <QObject>
#include <QVariantList>
#include <QSettings>
#include <QQuickStyle>
#include <QDebug>
#include <QMimeDatabase>
#include <QDirIterator>
#include <QFileInfo>
#include <QString>
class StartWith : public QObject
{
    Q_OBJECT
   
	Q_PROPERTY(QVariantList apps READ apps WRITE setApps NOTIFY appsChanged)

const QString  SYSTEM_APPLICATIONS = "/usr/share/applications";



	struct Info{
        QString name,icon{"application"},path,mimetype,category;
    }info;

public:


Q_INVOKABLE void load(QString filePath){
	
	QMimeDatabase db;
    QMimeType type = db.mimeTypeForFile(filePath);
  
	QString mimeType =type.name();
	
	
	 QDirIterator it(SYSTEM_APPLICATIONS, {"*.desktop"}, QDir::NoFilter, QDirIterator::Subdirectories);
          
m_apps.clear();
           while (it.hasNext()) {
               QString filename = it.next();
			   
			   
			  
			  
                QSettings desktopFile(filename, QSettings::IniFormat);
                desktopFile.beginGroup("Desktop Entry");
				 QString config_dir = QFileInfo(desktopFile.fileName()).fileName();
              info.path = desktopFile.value("Exec").toString().split(" ")[0];
              info.icon = desktopFile.value("Icon", "application").toString();
              info.name = desktopFile.value("Name").toString();
			 
			
		if(getMimeType(filename,mimeType)){
			m_apps.append(QStringList{info.name, info.icon, info.path});
		}

             
                desktopFile.endGroup();

               }
		   
               emit appsChanged();
	
}
 bool getMimeType(QString fileName,QString mimeType){
	QString type;
	 QFile inputFile(fileName);
		if (inputFile.open(QIODevice::ReadOnly))
		{
		QTextStream in(&inputFile);
		while (!in.atEnd())
		{
		QString line = in.readLine();
		if(line.startsWith("MimeType=")){
			type=line;
			break;
		}
		
      
		}
   inputFile.close();
}
	return type.contains(mimeType,Qt::CaseInsensitive);
}
 
 
 
 
 
    
	
	void setApps(const QVariantList &a) {
        if (a != m_apps) {
            m_apps = a;
            emit appsChanged();
        }
    }
   QVariantList apps() const {
        return m_apps;
    }
signals:
   
	 void appsChanged();

private:
	QVariantList m_apps;
	
};


