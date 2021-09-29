#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FileManager.h"
#include "colormanager.h"
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QSettings>
#include <QFileSystemWatcher>

#include "ThemeManager.h"
#include "StartWith.h"
#include "imageprovider.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);



	
	//theme watcher
	QSettings themeConfigSettings(QSettings::NativeFormat,QSettings::UserScope,"theme-config", "Theme");
	QString theme_config_dir = QFileInfo(themeConfigSettings.fileName()).absolutePath() + "/";
	QFileSystemWatcher themeConfigWatcher;
	themeConfigWatcher.addPath(theme_config_dir);
	
	ThemeManager themeManager;
	
    engine.rootContext()->setContextProperty("tcm", &themeManager);
    themeManager.setTheme(themeManager.reload());  
	QObject::connect(&themeConfigWatcher,SIGNAL(directoryChanged(QString)),&themeManager,SLOT(settings(QString)));
 
  //end


		QQuickStyle::setStyle("/usr/share/themes/"+themeManager.theme()[2].toString());
        //QQuickStyle::setStyle("Material");
    
         QSettings settings(QSettings::NativeFormat,QSettings::UserScope,QQuickStyle::name(), "Themes");
    
		QString config_dir = QFileInfo(settings.fileName()).absolutePath() + "/";
    
        QFileSystemWatcher watcher;
        watcher.addPath(config_dir);
    
    
		 ColorManager msg;
         engine.rootContext()->setContextProperty("msg", &msg);
         msg.setColors(msg.reload());
    
         QObject::connect(&watcher,SIGNAL(directoryChanged(QString)),&msg,SLOT(settings(QString)));

         FileManager fileManager;
         engine.rootContext()->setContextProperty("fileManager", &fileManager);



 StartWith startWith;
 engine.rootContext()->setContextProperty("startWith", &startWith);

	engine.addImageProvider("icons", new ImageProvider());
       



    engine.load(url);

    return app.exec();
}
