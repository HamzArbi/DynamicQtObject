#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int val READ val WRITE setVal NOTIFY valChanged)
public:
    explicit MyObject(QObject * = nullptr);
    explicit MyObject(QString, int, unsigned int, unsigned int, QObject * = nullptr);

    // Val getter and setter
    unsigned int val() const;
    void setVal(unsigned int);
    // This function will be triggered every "m_sec" seconds
    void updateValue();

signals:
    void valChanged(unsigned int);

private:
    QString m_id;
    unsigned int m_val{0}, m_minVal, m_maxVal;
    int m_sec;
};

#endif // MYOBJECT_H
