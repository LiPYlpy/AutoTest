#ifndef DRAWFORM_H
#define DRAWFORM_H

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <QWidget>
#include <QTimer>

namespace Ui {
class DrawForm;
}

class DrawForm : public QWidget
{
    Q_OBJECT

public:
    explicit DrawForm(QWidget *parent = nullptr);
    ~DrawForm();
     void updata_plot(QList<float> chosenValueF, QStringList chosenList);
private:
     Ui::DrawForm *ui;

     //绘图定时器
     QTimer *timer_plot;

     //曲线
     QSplineSeries* line_1;
     QSplineSeries* line_2;
     QSplineSeries* line_3;
     QSplineSeries* line_4;
     QSplineSeries* line_5;

//     QSplineSeries* line;

     //曲线点的最大数量
     int line_max = 100;

     //绘图变量和坐标
     QChart* chart;
     QValueAxis *axisX;
     QValueAxis *axisY;

};

#endif // DRAWFORM_H
