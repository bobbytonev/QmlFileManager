#ifndef MESSAGE_H
#define MESSAGE_H


#include <QObject>
#include <QVariantList>
#include <QSettings>
#include <QQuickStyle>
class ColorManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList colors READ colors WRITE setColors NOTIFY colorsChanged)





public:
    QVariantList reload(){

        QVariantList colorList;


            QSettings settings(QSettings::NativeFormat,QSettings::UserScope,QQuickStyle::name(), "Themes");
                settings.beginGroup("Themes");
                QStringList childKeys = settings.childKeys();
          foreach (const QString &childKey, childKeys){
          QVariant var(settings.value(childKey));
            colorList.append(var);
          }



               settings.endGroup();
               return colorList;

    }
    void setColors(const QVariantList &a) {
        if (a != m_colors) {
            m_colors = a;
            emit colorsChanged();
        }
    }
   QVariantList colors() const {
        return m_colors;
    }
signals:
    void colorsChanged();


public slots:
    void settings(const QString& str)
    {
        Q_UNUSED(str)
       setColors(reload());
    }
private:
    QVariantList m_colors;
};


#endif // MESSAGE_H
