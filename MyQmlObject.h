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
    Q_PROPERTY(unsigned int val MEMBER m_val NOTIFY valChanged)
public:
    explicit MyQmlObject(QObject * = nullptr);
    MyQmlObject(QString, int, int, QColor, QString, QObject * = nullptr);

public slots:
    void onValChanged(unsigned int);

signals:
    void idChanged(QString);
    void xChanged(int);
    void yChanged(int);
    void clrChanged(QColor);
    void valChanged(unsigned int);

private:
    QString m_id, m_dataSource;
    unsigned int m_val{0};
    int m_x, m_y;
    QColor m_clr;
};

#endif // MYQMLOBJECT_H
