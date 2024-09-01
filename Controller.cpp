#include "Controller.h"
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include "MyQmlObject.h"

Controller *Controller::i()
{
    static Controller *_instance = new Controller();
    return _instance;
}

void Controller::readFile()
{
    QFile _dataFile(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                    + "/Samples/sample_5data.json");
    if (!_dataFile.open(QIODevice::ReadOnly)) {
        qInfo() << "can't open the file";
        return;
    }

    m_cppData.clear();
    m_qmlData.clear();

    QJsonDocument _doc = QJsonDocument::fromJson(_dataFile.readAll());
    _dataFile.close();

    QJsonObject jsonObject = _doc.object();

    QJsonArray cppArray = jsonObject["cpp_data"].toArray();
    for (const QJsonValue &value : cppArray) {
        QJsonObject obj = value.toObject();

        QString _id = obj["id"].toString();
        int _sec = obj["sec"].toInt();
        int _min = obj["min"].toInt();
        int _max = obj["max"].toInt();
        m_cppData.append(new MyObject(_id, _sec, _min, _max));
    }

    // Extract qml_data
    QJsonArray qmlArray = jsonObject["qml_data"].toArray();
    for (const QJsonValue &value : qmlArray) {
        QJsonObject obj = value.toObject();

        QString _id = obj["id"].toString();
        int _x = obj["x"].toInt();
        int _y = obj["y"].toInt();
        QColor _color = obj["color"].toString();
        QString _dataSource = obj["dataSource"].toString();
        // You may have a warning here about memory leak, after some analysis there's none
        m_qmlData.append(QVariant::fromValue(new MyQmlObject(_id, _x, _y, _color, _dataSource)));
    }

    qInfo() << QString("%1 data found !").arg(m_qmlData.size()) << Qt::endl;

    emit dataListChanged();
}

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    readFile();
}
