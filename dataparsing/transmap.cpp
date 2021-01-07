#include "transmap.h"
#include <QMap>
#include <QDebug>



TransMap::TransMap(QObject *parent) : QObject(parent)
{

}

void TransMap::GetMap(QVariant map)
{
    QMap<QString,QString> tableMap = map.value<QMap<QString,QString>>();
    qDebug()<<tableMap.value("TM-RCES-236");
}


