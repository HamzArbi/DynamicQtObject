#ifndef MYQMLOBJECT_H
#define MYQMLOBJECT_H

#include <QColor>
#include <QObject>

class MyQmlObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id MEMBER m_id NOTIFY idChanged)
    Q_PROPERTY(int x MEMBER m_x NOTIFY xChanged)
    Q_PROPERTY(int y MEMBER m_y NOTIFY yChanged)
    Q_PROPERTY(QColor clr MEMBER m_clr NOTIFY clrChanged)
public:
    explicit MyQmlObject(QObject * = nullptr);
    MyQmlObject(QString, int, int, QColor, QString, QObject * = nullptr);

signals:
    void idChanged(QString);
    void xChanged(int);
    void yChanged(int);
    void clrChanged(QColor);

private:
    QString m_id, m_dataSource;
    int m_x, m_y;
    QColor m_clr;
};

#endif // MYQMLOBJECT_H
