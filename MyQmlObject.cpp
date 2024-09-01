#include "MyQmlObject.h"

MyQmlObject::MyQmlObject(QObject *parent)
    : QObject{parent}
{}
MyQmlObject::MyQmlObject(QString _id, int _x, int _y, QColor _clr, QString _dataSrc, QObject *parent)
    : QObject{parent}
    , m_id(_id)
    , m_x(_x)
    , m_y(_y)
    , m_clr(_clr)
    , m_dataSource(_dataSrc)
{}
