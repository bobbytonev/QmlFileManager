#include <QObject>
#include <QVariantList>
#include <QSettings>
#include <QQuickStyle>
#include <QDebug>
class ThemeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList theme READ theme WRITE setTheme NOTIFY themeChanged)





public:
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

			

               settings.endGroup();
               return themeConfig;

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
};



