#include <QQmlApplicationEngine>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QQuickStyle>
#include <QDebug>
#include <QDir>
#include <QObject>
#include <QQuickWindow>
#include <QQmlContext>
#include "FileManager.h"
#include "colormanager.h"
#include "StartWith.h"
#include "imageprovider.h"


class QQmlDynamicApplicationEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList theme READ theme WRITE setTheme NOTIFY themeChanged)



	const QString  THEME_FORLDER = "/usr/share/themes";

public:

bool firstLoad=true;



QFileSystemWatcher themeConfigWatcher;
QFileSystemWatcher watcher ;
ColorManager msg;
StartWith startWith;
FileManager fileManager;




//
void reloadEngine(QString style){
        const QUrl url(QStringLiteral("qrc:/main.qml"));
        if(engine==NULL){
            engine= new QQmlApplicationEngine();

        }

        QObject* pRootObject = engine->rootObjects().first();
         QQuickWindow* pMainWindow = qobject_cast<QQuickWindow*>(pRootObject);
		 bool visible =  pMainWindow->isVisible();
		 
		 pMainWindow->setVisible(false);
         pMainWindow->close();
		 
		 engine->clearComponentCache();
          qmlClearTypeRegistrations();
           QQuickStyle::setStyle(style);
           engine =new QQmlApplicationEngine();
         
			load(url,-1,NULL);
			
			if(!visible){
					qDebug()<<"HEREVISIBLE";
			pRootObject = engine->rootObjects().first();
			pMainWindow = qobject_cast<QQuickWindow*>(pRootObject);
			pMainWindow->setVisible(false);
			
			}
			
			

    }

    void load(QUrl url,int argc, char *argv[]){
        if(engine==NULL){
            engine= new QQmlApplicationEngine();

        }
		if(firstLoad){
        registerTypes(argc,argv);
		}else
			registerIt(argc,argv);
      
        engine->load(url);

    }
	
	void registerIt(int argc, char *argv[]){
		 engine->rootContext()->setContextProperty("startWith", &startWith);
		engine->addImageProvider("icons", new ImageProvider());
		engine->rootContext()->setContextProperty("msg", &msg);
		 engine->rootContext()->setContextProperty("fileManager", &fileManager);
		  engine->rootContext()->setContextProperty("tcm", this);
	}
	
	 void registerTypes(int argc, char *argv[]){
		
		QQuickStyle::setStyle("/media/sf_DIPLOMNA/DarkNeon");
		QSettings settings(QSettings::NativeFormat,QSettings::UserScope,QQuickStyle::name(), "Themes");
    
		QString config_dir = QFileInfo(settings.fileName()).absolutePath() + "/";
    
       
        watcher.addPath(config_dir);
		engine->rootContext()->setContextProperty("msg", &msg);
        msg.setColors(msg.reload());
		QObject::connect(&watcher,SIGNAL(directoryChanged(QString)),&msg,SLOT(settings(QString)));
		engine->rootContext()->setContextProperty("fileManager", &fileManager);



	//theme watcher
	QSettings themeConfigSettings(QSettings::NativeFormat,QSettings::UserScope,"theme-config", "Theme");
	QString theme_config_dir = QFileInfo(themeConfigSettings.fileName()).absolutePath() + "/";
	themeConfigWatcher.addPath(theme_config_dir);
	
	
	
    engine->rootContext()->setContextProperty("tcm", this);
    setTheme(reload());  
	QObject::connect(&themeConfigWatcher,SIGNAL(directoryChanged(QString)),this,SLOT(settings(QString)));
 
  //end

 engine->rootContext()->setContextProperty("startWith", &startWith);

	engine->addImageProvider("icons", new ImageProvider());
       

}
//


    QVariantList reload(){

        QVariantList themeConfig;


          QSettings settings(QSettings::NativeFormat,QSettings::UserScope,"theme-config", "Theme");
		  // QSettings settings(QSettings::NativeFormat,"/home/bobby",QQuickStyle::name(), "Themes");
                settings.beginGroup("Theme");
                QStringList childKeys = settings.childKeys();
          foreach (const QString &childKey, childKeys){
          QVariant var(settings.value(childKey));
		 
            themeConfig.append(var);
          }
		 
			
	
			if(!firstLoad){
				
				reloadEngine("Material");
				
					
			}
			

               settings.endGroup();
			   firstLoad=false;
               return themeConfig;

    }
	
	
	
	Q_INVOKABLE QString getThemeName(){
		return QQuickStyle::name();
		
		
	}
    void setTheme(const QVariantList &a) {
        if (a != m_theme) {
            m_theme = a;
            emit themeChanged();
        }
    }
   QVariantList theme() const {
        return m_theme;
    }
signals:
    void themeChanged();


public slots:
    void settings(const QString& str)
    {
        Q_UNUSED(str)
       setTheme(reload());
	   qDebug()<<"HELLO";
	  
    }
private:
    QVariantList m_theme;
	 QQmlApplicationEngine* engine=NULL;

};



