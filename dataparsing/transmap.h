#ifndef TRANSMAP_H
#define TRANSMAP_H

#include <QObject>
#include <QVariant>

class TransMap : public QObject
{
    Q_OBJECT
public:
    explicit TransMap(QObject *parent = nullptr);

    //slot
    void GetMap(QVariant map);

signals:

};

#endif // TRANSMAP_H
