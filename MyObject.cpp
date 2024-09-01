#include "MyObject.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QTimer>

MyObject::MyObject(QObject *parent)
    : QObject{parent}
{}

MyObject::MyObject(QString _id, int _sec, unsigned int _min, unsigned int _max, QObject *parent)
    : QObject{parent}
    , m_id(_id)
    , m_minVal(_min)
    , m_maxVal(_max)
    , m_sec(_sec)
{
    // Setup timer to trigger every "m_sec" seconds
    QTimer *_timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MyObject::updateValue);
    _timer->start(m_sec * 1000); // Convert it to milliseconds
}

unsigned int MyObject::val() const
{
    return m_val;
}

void MyObject::setVal(unsigned int p_newVal)
{
    // Set and emit a new val
    if (m_val == p_newVal)
        return;
    m_val = p_newVal;
    // print the message :: the QString::number was necessary beacause if it stays int
    // it will have a different behavior since it will use another function
    qInfo() << QString("%1 value changed to %2").arg(m_id, QString::number(p_newVal));
    emit valChanged(m_val);
}

void MyObject::updateValue()
{
    unsigned int newVal = QRandomGenerator::global()->bounded(m_minVal, m_maxVal + 1);
    setVal(newVal);
}
