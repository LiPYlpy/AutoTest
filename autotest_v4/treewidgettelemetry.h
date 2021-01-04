#ifndef TREEWIDGETTELEMETRY_H
#define TREEWIDGETTELEMETRY_H

#include <QWidget>
#include <QTreeWidgetItem>

class treeWidgetTelemetry : public QWidget
{
    Q_OBJECT
public:
    explicit treeWidgetTelemetry(QWidget *parent = nullptr);
    ~treeWidgetTelemetry();

    QTreeWidgetItem * buildTree();

signals:

};

#endif // TREEWIDGETTELEMETRY_H
