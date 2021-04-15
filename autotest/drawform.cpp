#include "drawform.h"
#include "ui_drawform.h"

DrawForm::DrawForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawForm)
{
    ui->setupUi(this);
    this->setWindowTitle("实时数据");
//    QPixmap pix = QPixmap(102, 102);
//    pix .fill(QColor(255, 255, 255));
//    QPainter painter;
//    painter.begin(&pix );
//    painter.setBrush(QColor(255, 200, 200));
//    painter.drawRect(1, 1, 100, 100);
//    painter.end();
//    ui->label->resize(100,200);
//    ui->label->setPixmap(pix);

    timer_plot = new QTimer(this);
//    connect(timer_plot,SIGNAL(timeout()),this,SLOT(updata_plot()));
//    connect(timer_plot,&QTimer::timeout,this,&DrawForm::updata_plot);


    line_1 = new QSplineSeries(this);
    line_2 = new QSplineSeries(this);
    line_3 = new QSplineSeries(this);
    line_4 = new QSplineSeries(this);
    line_5 = new QSplineSeries(this);

//    line = new QSplineSeries(this);

    chart = new QChart();

    chart->addSeries(line_1);
    chart->addSeries(line_2);
    chart->addSeries(line_3);
    chart->addSeries(line_4);
    chart->addSeries(line_5);
//    chart->addSeries(line);

    axisX = new QValueAxis(this);
    axisY = new QValueAxis(this);

    connect(ui->clearBtn,&QPushButton::clicked,[=](){
        QVector<QPointF> points;
        line_1->replace(points);
        line_2->replace(points);
        line_3->replace(points);
        line_4->replace(points);
        line_5->replace(points);
    });

//    connect(ui->startBtn,&QPushButton::clicked,[=](){
//        timer_plot->start(50);//启动定时器
//    });


//    connect(ui->finishBtn,&QPushButton::clicked,[=](){
//        timer_plot->stop();//启动定时器
//    });
}

DrawForm::~DrawForm()
{
    delete ui;
}

void DrawForm::updata_plot(QList<float> chosenValueF, QStringList chosenList)
{
    QVector<QPointF> list;
    QVector<QPointF> newlist;
    float data;

    qDebug()<<chosenList;
    qDebug()<<chosenValueF;

    if(chosenList.at(0)!=" ")
    {
        list = line_1->pointsVector();//获取现在图中列表
        if (list.size() < line_max)
        {
            //保持原来
            newlist = list;
        }
        else
        {
            newlist.clear();
            //错位移动
            for(int i = 1; i< list.size();i++)
            {
                newlist.append(QPointF(i-1,list.at(i).y()));
            }
        }
        data = chosenValueF.at(0);
    //    newlist.append(QPointF(newlist.size(),rand()));//最后补上新的数据
        newlist.append(QPointF(newlist.size(),data));//最后补上新的数据
        line_1->replace(newlist);//替换更新
    }


    if(chosenList.at(1)!=" ")
    {
        list = line_2->pointsVector();//获取现在图中列表
        if (list.size() < line_max)
        {
            //保持原来
            newlist = list;
        }
        else
        {
            newlist.clear();
            //错位移动
            for(int i =1 ; i< list.size();i++)
            {
                newlist.append(QPointF(i-1,list.at(i).y()));
            }
        }
        data = chosenValueF.at(1);
        newlist.append(QPointF(newlist.size(),data));//最后补上新的数据
        line_2->replace(newlist);//替换更新
    }


    if(chosenList.at(2)!=" ")
    {
        list = line_3->pointsVector();//获取现在图中列表
        if (list.size() < line_max)
        {
            //保持原来
            newlist = list;
        }
        else
        {
            newlist.clear();
            //错位移动
            for(int i =1 ; i< list.size();i++)
            {
                newlist.append(QPointF(i-1,list.at(i).y()));
            }
        }
        data = chosenValueF.at(2);
        newlist.append(QPointF(newlist.size(),data));//最后补上新的数据
        line_3->replace(newlist);//替换更新
    }


    if(chosenList.at(3)!=" ")
    {
        list = line_4->pointsVector();//获取现在图中列表
        if (list.size() < line_max)
        {
            //保持原来
            newlist = list;
        }
        else
        {
            newlist.clear();
            //错位移动
            for(int i =1 ; i< list.size();i++)
            {
                newlist.append(QPointF(i-1,list.at(i).y()));
            }
        }
        data = chosenValueF.at(3);
        newlist.append(QPointF(newlist.size(),data));//最后补上新的数据
        line_4->replace(newlist);//替换更新
    }


    if(chosenList.at(4)!=" ")
    {
        list = line_5->pointsVector();//获取现在图中列表
        if (list.size() < line_max)
        {
            //保持原来
            newlist = list;
        }
        else
        {
            newlist.clear();
            //错位移动
            for(int i =1 ; i< list.size();i++)
            {
                newlist.append(QPointF(i-1,list.at(i).y()));
            }
        }
        data = chosenValueF.at(4);
        newlist.append(QPointF(newlist.size(),data));//最后补上新的数据
        line_5->replace(newlist);//替换更新
    }


    line_1->setName(chosenList.at(0));//设置曲线名称
    line_1->setPen(QColor(255, 0, 0));//设置曲线颜色
    line_1->setUseOpenGL(true);//openGl 加速

    line_2->setName(chosenList.at(1));//设置曲线名称
    line_2->setPen(QColor(255, 0, 255));//设置曲线颜色
    line_2->setUseOpenGL(true);//openGl 加速

    line_3->setName(chosenList.at(2));//设置曲线名称
    line_3->setPen(QColor(0, 255, 255));//设置曲线颜色
    line_3->setUseOpenGL(true);//openGl 加速

    line_4->setName(chosenList.at(3));//设置曲线名称
    line_4->setPen(QColor(0, 255, 0));//设置曲线颜色
    line_4->setUseOpenGL(true);//openGl 加速

    line_5->setName(chosenList.at(4));//设置曲线名称
    line_5->setPen(QColor(0, 0, 255));//设置曲线颜色
    line_5->setUseOpenGL(true);//openGl 加速

    chart->setTitle("实时遥测显示");//设置图标标题

    chart->removeSeries(line_1);
    chart->addSeries(line_1);
    chart->removeSeries(line_2);
    chart->addSeries(line_2);
    chart->removeSeries(line_3);
    chart->addSeries(line_3);
    chart->removeSeries(line_4);
    chart->addSeries(line_4);
    chart->removeSeries(line_5);
    chart->addSeries(line_5);

//    for (int i = 0; i< 5; i++) {
//        switch (i) {
//        case 0:
//            if(chosenList.at(i)==" ")
//            {
//                chart->removeSeries(line_1);
//            }
//            continue;
//        case 1:
//            if(chosenList.at(i)==" ")
//            {
//                chart->removeSeries(line_2);
//            }
//            continue;
//        case 2:
//            if(chosenList.at(i)==" ")
//            {
//                chart->removeSeries(line_3);
//            }
//            continue;
//        case 3:
//            if(chosenList.at(i)==" ")
//            {
//                chart->removeSeries(line_4);
//            }
//            continue;
//        case 4:
//            if(chosenList.at(i)==" ")
//            {
//                chart->removeSeries(line_5);
//            }
//            continue;
//        default:
//            chart->removeSeries(line_1);
//            chart->addSeries(line_1);
//            chart->removeSeries(line_2);
//            chart->addSeries(line_2);
//            chart->removeSeries(line_3);
//            chart->addSeries(line_3);
//            chart->removeSeries(line_4);
//            chart->addSeries(line_4);
//            chart->removeSeries(line_5);
//            chart->addSeries(line_5);
//        }
//    }

    chart->createDefaultAxes();//设置坐标轴

//        axisX->setRange(0,line_max);//范围
//        axisX->setTitleText("times(secs)");//标题
//        axisX->setTickCount(10);//分隔个数
//        axisX->setLineVisible(true);//可视化
//        axisX->setLinePenColor(Qt::blue);//颜色

        axisY->setRange(-5,12);
//        axisY->setTitleText("value");
//        axisY->setTickCount(6);
//        axisY->setLineVisible(true);
//        axisY->setLinePenColor(Qt::blue);

//        chart->setAxisX(axisX,line);
//        chart->setAxisY(axisY,nullptr);


    /* 问题在于第一条线超限，线条太细，显示不清晰 */

    ui->widgetPlot->setChart(chart);
}

