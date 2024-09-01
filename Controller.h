#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
 * Controller is a singleton object which will be 
 * the brain of the application and can be used in both
 * C++ and QML we'll see how we can use it
 **/

#include <QObject>
#include <QVariantList>

#include "MyObject.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList dataList MEMBER m_qmlData NOTIFY dataListChanged)
public:
    static Controller *i();

    void readFile();

signals:
    void dataListChanged();

private:
    explicit Controller(QObject *parent = nullptr);

    QVariantList m_qmlData;
    QList<MyObject *> m_cppData;
};

#endif // CONTROLLER_H
