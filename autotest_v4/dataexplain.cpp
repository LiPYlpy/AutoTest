#include "dataexplain.h"

QStringList testList;

QStringList DetectResult()
{
    return testList;
}

//R19表
QVariantList R19_Value(QByteArray dataArea)
{
    for(int i = 0; i < 896; i++)
    {
        testList<<"true";
    }
    QVariantList valueList;
    int text;
    QString temp;
    //1-6
    temp = dataArea.mid(0,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    //1-4
    valueList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1);
    //5
    text = temp.mid(4,2).toInt(nullptr,2);
    switch (text) {
    case 0:valueList<<"USBA";break;
    case 1:valueList<<"DSS";break;
    case 2:valueList<<"DTU";break;
    case 3:valueList<<"USBB";break;
    default:break;
    }
    //6
    valueList<<"0";
    //7
    valueList<<"0";
    //8
    temp = dataArea.mid(3,1).toHex();
    text = temp.toInt(nullptr,16);
    float pa = 3*text*3.3/255;
    temp = QString("%1").arg(pa);
    valueList << temp;
    //9
    temp = dataArea.mid(4,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 3*text*3.3/255;
    temp = QString("%1").arg(pa);
    if(pa<3.5 || pa>4)
        testList[8]="false";
    valueList << temp;
    //10
    temp = dataArea.mid(5,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = text*3.3/255/(100*0.047/3);
    temp = QString("%1").arg(pa);
    if(pa<0 || pa>0.7)
        testList[9]="false";
    valueList << temp;
    //11
    temp = dataArea.mid(6,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 3*text*3.3/255;
    temp = QString("%1").arg(pa);
    if(pa<3.5 || pa>4)
        testList[10]="false";
    valueList << temp;
    //12
    temp = dataArea.mid(7,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = text*3.3/255/(100*0.047/3);
    temp = QString("%1").arg(pa);
    if(pa<0 || pa>0.9)
        testList[11]="false";
    valueList << temp;
    //13
    temp = dataArea.mid(8,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp;
    //14
    temp = dataArea.mid(9,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp;
    //15
    temp = dataArea.mid(10,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //16
    temp = dataArea.mid(11,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp;
    //17
    temp = dataArea.mid(12,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //18
    temp = dataArea.mid(13,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //19
    temp = dataArea.mid(14,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    if( text < 0 || text >255)
        testList[18] = "false";
    valueList << temp;
    //20
    temp = dataArea.mid(15,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //21
    temp = dataArea.mid(16,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //22
    temp = dataArea.mid(17,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0')).mid(4,4);
    valueList << temp;
    //23
    temp = dataArea.mid(18,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //24-31
    temp = dataArea.mid(19,1);
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp.mid(0,1) << temp.mid(1,1) << temp.mid(2,1) << temp.mid(3,1);
    valueList << temp.mid(4,1) << temp.mid(5,1) << temp.mid(6,1) << temp.mid(7,1);
    //32
    temp = dataArea.mid(20,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //33
    temp = dataArea.mid(21,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //34
    temp = dataArea.mid(22,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //35
    temp = dataArea.mid(24,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //36
    temp = dataArea.mid(25,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //37
    temp = dataArea.mid(26,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //38
    temp = dataArea.mid(27,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //39
    temp = dataArea.mid(28,2).toHex();
    valueList << temp;
    //40
    temp = dataArea.mid(30,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //41
    temp = dataArea.mid(31,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //42
    temp = dataArea.mid(32,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //43
    temp = dataArea.mid(33,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //44
    temp = dataArea.mid(34,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //45
    temp = dataArea.mid(35,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //46
    temp = dataArea.mid(36,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //47
    temp = dataArea.mid(37,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //48-55
    temp = dataArea.mid(38,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 16, 2, QChar('0'));
    valueList << temp.mid(0,2) << temp.mid(2,2) << temp.mid(4,2) << temp.mid(6,2);
    valueList << temp.mid(8,2) << temp.mid(10,2) << temp.mid(12,2) << temp.mid(14,2);


    return valueList;
}

QVariantList R19_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    QString temp;
    int text;
    //1-6
    temp = dataArea.mid(0,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    //1-4
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1);
    //5
    hexList << temp.mid(4,2);
    //6
    hexList << temp.mid(6,2);
    //7
    temp = dataArea.mid(1,2).toHex();
    hexList << temp;
    //8
    temp = dataArea.mid(3,1).toHex();
    hexList << temp;
    //9
    temp = dataArea.mid(4,1).toHex();
    hexList << temp;
    //10
    temp = dataArea.mid(5,1).toHex();
    hexList << temp;
    //11
    temp = dataArea.mid(6,1).toHex();
    hexList << temp;
    //12
    temp = dataArea.mid(7,1).toHex();
    hexList << temp;
    //13
    temp = dataArea.mid(8,1).toHex();
    hexList << temp;
    //14
    temp = dataArea.mid(9,1).toHex();
    hexList << temp;
    //15
    temp = dataArea.mid(10,1).toHex();
    hexList << temp;
    //16
    temp = dataArea.mid(11,1).toHex();
    hexList << temp;
    //17
    temp = dataArea.mid(12,1).toHex();
    hexList << temp;
    //18
    temp = dataArea.mid(13,1).toHex();
    hexList << temp;
    //19
    temp = dataArea.mid(14,1).toHex();
    hexList << temp;
    //20
    temp = dataArea.mid(15,1).toHex();
    hexList << temp;
    //21
    temp = dataArea.mid(16,1).toHex();
    hexList << temp;
    //22
    temp = dataArea.mid(17,1).toHex();
    hexList << temp;
    //23
    temp = dataArea.mid(18,1).toHex();
    hexList << temp;
    //24-31
    temp = dataArea.mid(19,1);
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1) << temp.mid(1,1) << temp.mid(2,1) << temp.mid(3,1);
    hexList << temp.mid(4,1) << temp.mid(5,1) << temp.mid(6,1) << temp.mid(7,1);
    //32
    temp = dataArea.mid(20,1).toHex();
    hexList << temp;
    //33
    temp = dataArea.mid(21,1).toHex();
    hexList << temp;
    //34
    temp = dataArea.mid(22,2).toHex();
    hexList << temp;
    //35
    temp = dataArea.mid(24,1).toHex();
    hexList << temp;
    //36
    temp = dataArea.mid(25,1).toHex();
    hexList << temp;
    //37
    temp = dataArea.mid(26,1).toHex();
    hexList << temp;
    //38
    temp = dataArea.mid(27,1).toHex();
    hexList << temp;
    //39
    temp = dataArea.mid(28,2).toHex();
    hexList << temp;
    //40
    temp = dataArea.mid(30,1).toHex();
    hexList << temp;
    //41
    temp = dataArea.mid(31,1).toHex();
    hexList << temp;
    //42
    temp = dataArea.mid(32,1).toHex();
    hexList << temp;
    //43
    temp = dataArea.mid(33,1).toHex();
    hexList << temp;
    //44
    temp = dataArea.mid(34,1).toHex();
    hexList << temp;
    //45
    temp = dataArea.mid(35,1).toHex();
    hexList << temp;
    //46
    temp = dataArea.mid(36,1).toHex();
    hexList << temp;
    //47
    temp = dataArea.mid(37,1).toHex();
    hexList << temp;
    //48-55
    temp = dataArea.mid(38,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 16, 2, QChar('0'));
    hexList << temp.mid(0,2) << temp.mid(2,2) << temp.mid(4,2) << temp.mid(6,2);
    hexList << temp.mid(8,2) << temp.mid(10,2) << temp.mid(12,2) << temp.mid(14,2);
    return hexList;
}

//R20表
QVariantList R20_Value(QByteArray dataArea)
{
    QVariantList valueList;
    int text;
    QString temp;
//    bool flag = true;
    //1-6
    temp = dataArea.mid(0,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    //1-4
    valueList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1);
    //5
    text = temp.mid(4,2).toInt(nullptr,2);
    switch (text) {
    case 0:valueList<<"USBA";break;
    case 1:valueList<<"DSS";break;
    case 2:valueList<<"DTU";break;
    case 3:valueList<<"USBB";break;
    default:break;
    }
    //6
    valueList<<"0";
    //7
    valueList<<"0";
    //8
    temp = dataArea.mid(3,1).toHex();
    text = temp.toInt(nullptr,16);
    float pa = 3*text*3.3/255;
    temp = QString("%1").arg(pa);
    valueList << temp;
    //9
    temp = dataArea.mid(4,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 3*text*3.3/255;
    temp = QString("%1").arg(pa);
    if(pa<3.5 || pa>4)
        testList[55+8] = "false";
    valueList << temp;
    //10
    temp = dataArea.mid(5,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = text*3.3/255/(100*0.047/3);
    temp = QString("%1").arg(pa);
    if(pa<0 || pa>0.7)
        testList[55+9] = "false";
    valueList << temp;
    //11
    temp = dataArea.mid(6,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 3*text*3.3/255;
    temp = QString("%1").arg(pa);
    if(pa<3.5 || pa>4)
        testList[55+10] = "false";
    valueList << temp;
    //12
    temp = dataArea.mid(7,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = text*3.3/255/(100*0.047/3);
    temp = QString("%1").arg(pa);
    if(pa<0 || pa>0.9)
        testList[55+11] = "false";
    valueList << temp;
    //13
    temp = dataArea.mid(8,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp;
    //14
    temp = dataArea.mid(9,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp;
    //15
    temp = dataArea.mid(10,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //16
    temp = dataArea.mid(11,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp;
    //17
    temp = dataArea.mid(12,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //18
    temp = dataArea.mid(13,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //19
    temp = dataArea.mid(14,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    if( text < 0 || text >255)
        testList[55+18] = "false";
    valueList << temp;
    //20
    temp = dataArea.mid(15,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //21
    temp = dataArea.mid(16,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //22
    temp = dataArea.mid(17,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0')).mid(4,4);
    valueList << temp;
    //23
    temp = dataArea.mid(18,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //24-31
    temp = dataArea.mid(19,1);
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    valueList << temp.mid(0,1) << temp.mid(1,1) << temp.mid(2,1) << temp.mid(3,1);
    valueList << temp.mid(4,1) << temp.mid(5,1) << temp.mid(6,1) << temp.mid(7,1);
    //32
    temp = dataArea.mid(20,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //33
    temp = dataArea.mid(21,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //34
    temp = dataArea.mid(22,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //35
    temp = dataArea.mid(24,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //36
    temp = dataArea.mid(25,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //37
    temp = dataArea.mid(26,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //38
    temp = dataArea.mid(27,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text);
    valueList << temp;
    //39
    temp = dataArea.mid(28,2).toHex();
    valueList << temp;
    //40
    temp = dataArea.mid(30,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //41
    temp = dataArea.mid(31,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //42
    temp = dataArea.mid(32,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //43
    temp = dataArea.mid(33,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //44
    temp = dataArea.mid(34,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //45
    temp = dataArea.mid(35,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //46
    temp = dataArea.mid(36,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //47
    temp = dataArea.mid(37,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text*20);
    valueList << temp;
    //48-55
    temp = dataArea.mid(38,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 16, 2, QChar('0'));
    valueList << temp.mid(0,2) << temp.mid(2,2) << temp.mid(4,2) << temp.mid(6,2);
    valueList << temp.mid(8,2) << temp.mid(10,2) << temp.mid(12,2) << temp.mid(14,2);
    return valueList;
}

QVariantList R20_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    QString temp;
    int text;
    //1-6
    temp = dataArea.mid(0,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    //1-4
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1);
    //5
    hexList << temp.mid(4,2);
    //6
    hexList << temp.mid(6,2);
    //7
    temp = dataArea.mid(1,2).toHex();
    hexList << temp;
    //8
    temp = dataArea.mid(3,1).toHex();
    hexList << temp;
    //9
    temp = dataArea.mid(4,1).toHex();
    hexList << temp;
    //10
    temp = dataArea.mid(5,1).toHex();
    hexList << temp;
    //11
    temp = dataArea.mid(6,1).toHex();
    hexList << temp;
    //12
    temp = dataArea.mid(7,1).toHex();
    hexList << temp;
    //13
    temp = dataArea.mid(8,1).toHex();
    hexList << temp;
    //14
    temp = dataArea.mid(9,1).toHex();
    hexList << temp;
    //15
    temp = dataArea.mid(10,1).toHex();
    hexList << temp;
    //16
    temp = dataArea.mid(11,1).toHex();
    hexList << temp;
    //17
    temp = dataArea.mid(12,1).toHex();
    hexList << temp;
    //18
    temp = dataArea.mid(13,1).toHex();
    hexList << temp;
    //19
    temp = dataArea.mid(14,1).toHex();
    hexList << temp;
    //20
    temp = dataArea.mid(15,1).toHex();
    hexList << temp;
    //21
    temp = dataArea.mid(16,1).toHex();
    hexList << temp;
    //22
    temp = dataArea.mid(17,1).toHex();
    hexList << temp;
    //23
    temp = dataArea.mid(18,1).toHex();
    hexList << temp;
    //24-31
    temp = dataArea.mid(19,1);
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1) << temp.mid(1,1) << temp.mid(2,1) << temp.mid(3,1);
    hexList << temp.mid(4,1) << temp.mid(5,1) << temp.mid(6,1) << temp.mid(7,1);
    //32
    temp = dataArea.mid(20,1).toHex();
    hexList << temp;
    //33
    temp = dataArea.mid(21,1).toHex();
    hexList << temp;
    //34
    temp = dataArea.mid(22,2).toHex();
    hexList << temp;
    //35
    temp = dataArea.mid(24,1).toHex();
    hexList << temp;
    //36
    temp = dataArea.mid(25,1).toHex();
    hexList << temp;
    //37
    temp = dataArea.mid(26,1).toHex();
    hexList << temp;
    //38
    temp = dataArea.mid(27,1).toHex();
    hexList << temp;
    //39
    temp = dataArea.mid(28,2).toHex();
    hexList << temp;
    //40
    temp = dataArea.mid(30,1).toHex();
    hexList << temp;
    //41
    temp = dataArea.mid(31,1).toHex();
    hexList << temp;
    //42
    temp = dataArea.mid(32,1).toHex();
    hexList << temp;
    //43
    temp = dataArea.mid(33,1).toHex();
    hexList << temp;
    //44
    temp = dataArea.mid(34,1).toHex();
    hexList << temp;
    //45
    temp = dataArea.mid(35,1).toHex();
    hexList << temp;
    //46
    temp = dataArea.mid(36,1).toHex();
    hexList << temp;
    //47
    temp = dataArea.mid(37,1).toHex();
    hexList << temp;
    //48-55
    temp = dataArea.mid(38,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 16, 2, QChar('0'));
    hexList << temp.mid(0,2) << temp.mid(2,2) << temp.mid(4,2) << temp.mid(6,2);
    hexList << temp.mid(8,2) << temp.mid(10,2) << temp.mid(12,2) << temp.mid(14,2);
    return hexList;
}

//R21表
QVariantList R21_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    QString temp;
    int text;
    //1-8
    temp = dataArea.mid(0,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //9-16
    temp = dataArea.mid(1,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //17-22
    temp = dataArea.mid(2,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,3);
    //23-30
    temp = dataArea.mid(3,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //31-32
    temp = dataArea.mid(4,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,7);
    //33-40
    temp = dataArea.mid(5,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //41-48
    temp = dataArea.mid(6,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,1)<<temp.mid(2,1)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //49
    temp = dataArea.mid(7,2).toHex();
    hexList << temp;
    //50
    temp = dataArea.mid(9,2).toHex();
    hexList << temp;
    //51
    temp = dataArea.mid(11,1).toHex();
    hexList << temp;
    //52
    temp = dataArea.mid(12,1).toHex();
    hexList << temp;
    //53
    temp = dataArea.mid(13,1).toHex();
    hexList << temp;
    //54
    temp = dataArea.mid(14,1).toHex();
    hexList << temp;
    //55
    temp = dataArea.mid(15,1).toHex();
    hexList << temp;
    //56
    temp = dataArea.mid(16,1).toHex();
    hexList << temp;
    //57
    temp = dataArea.mid(17,1).toHex();
    hexList << temp;
    //58
    temp = dataArea.mid(18,1).toHex();
    hexList << temp;
    //59
    temp = dataArea.mid(19,1).toHex();
    hexList << temp;
    //60
    temp = dataArea.mid(20,1).toHex();
    hexList << temp;
    //61
    temp = dataArea.mid(21,1).toHex();
    hexList << temp;
    //62
    temp = dataArea.mid(22,1).toHex();
    hexList << temp;
    //63
    temp = dataArea.mid(23,1).toHex();
    hexList << temp;
    return hexList;
}

QVariantList R21_Value(QByteArray dataArea)
{
    QVariantList valueList;
    QString temp;
    int text;
    float pa;
    //1-8
    temp = dataArea.mid(0,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i < 2; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"打开";
        else
            valueList<<"关闭";
    }
    for(int i = 2; i < 5; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"准许";
        else
            valueList<<"禁止";
    }
    if(temp.at(5)=='1')
        valueList<<"开始";
    else
        valueList<<"结束";

    if(temp.at(6)=='1')
        valueList<<"自主";
    else
        valueList<<"星地";

    if(temp.at(7)=='1')
        valueList<<"开始";
    else
        valueList<<"结束";
    //9-16
    temp = dataArea.mid(1,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i < 2; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"打开";
        else
            valueList<<"关闭";
    }
    for(int i = 2; i < 8; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"采用";
        else
            valueList<<"不采用";
    }
    //17-22
    temp = dataArea.mid(2,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i < 4; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"采用";
        else
            valueList<<"不采用";
    }
    if(temp.at(4)=='1')
        valueList<<"存储";
    else
        valueList<<"不存储";
    valueList<<"预留";
    //23-30
    temp = dataArea.mid(3,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i < 8; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"开启";
        else
            valueList<<"关闭";
    }
    //31-32
    temp = dataArea.mid(4,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    if(temp.at(0)=='1')
        valueList<<"开启";
    else
        valueList<<"关闭";
    valueList<<"预留";
    //33-40
    temp = dataArea.mid(5,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i < 8; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"错误";
        else
            valueList<<"正确";
    }
    //41-48
    temp = dataArea.mid(6,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i < 8; i++)
    {
        if(temp.at(i)=='1')
            valueList<<"错误";
        else
            valueList<<"正确";
    }
    //49
    temp = dataArea.mid(7,2).toHex();
    text = temp.toInt(nullptr,16);
    pa = text/4095*2.5*3/45;
    if(text<0x0000 || text>0x0bb8)
        testList[110+48] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //50
    temp = dataArea.mid(9,2).toHex();
    text = temp.toInt(nullptr,16);
    pa = text/4095*2.5*3/45;
    if(text<0x0000 || text>0x0bb8)
        testList[110+49] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //51
    temp = dataArea.mid(11,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+50] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //52
    temp = dataArea.mid(12,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+51] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //53
    temp = dataArea.mid(13,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+52] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //54
    temp = dataArea.mid(14,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+53] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //55
    temp = dataArea.mid(15,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+54] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //56
    temp = dataArea.mid(16,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+55] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //57
    temp = dataArea.mid(17,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+56] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //58
    temp = dataArea.mid(18,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+57] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //59
    temp = dataArea.mid(19,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 8*text/1024*2.4/20/0.17;
    if(text<0x00 || text>0xff)
        testList[110+58] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //60
    temp = dataArea.mid(20,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 0.2559*(6800/(1-(4*text/1024*2.4-1.25)/5/6-1000/7800)-6800)-255.2;
    if(text<0x13 || text>0xf0)
        testList[110+59] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //61
    temp = dataArea.mid(21,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 0.2559*(6800/(1-(4*text/1024*2.4-1.25)/5/6-1000/7800)-6800)-255.2;
    if(text<0x13 || text>0xf0)
        testList[110+60] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //62
    temp = dataArea.mid(22,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 0.2559*(6800/(1-(4*text/1024*2.4-1.25)/5/6-1000/7800)-6800)-255.2;
    if(text<0x13 || text>0xf0)
        testList[110+61] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    //63
    temp = dataArea.mid(23,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 0.2559*(6800/(1-(4*text/1024*2.4-1.25)/5/6-1000/7800)-6800)-255.2;
    if(text<0x13 || text>0xf0)
        testList[110+62] = "false";
    temp = QString("%1").arg(pa);
    valueList << temp;
    return valueList;
}

//R22表
QVariantList R22_Value(QByteArray dataArea)
{
    QVariantList valueList;
    QString temp;
    int text;
    float pa;
    //1
    temp = dataArea.mid(0,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //2
    temp = dataArea.mid(2,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //3
    temp = dataArea.mid(4,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //4
    temp = dataArea.mid(6,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //5
    temp = dataArea.mid(8,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //6
    temp = dataArea.mid(10,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //7
    temp = dataArea.mid(12,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<< temp;
    //8
    temp = dataArea.mid(13,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<< temp;
    //9
    temp = dataArea.mid(14,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<< temp;
    //10
    temp = dataArea.mid(15,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<< temp;
    //11
    temp = dataArea.mid(16,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<< temp;
    //12
    temp = dataArea.mid(17,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<< temp;
    //13
    temp = dataArea.mid(18,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //14
    temp = dataArea.mid(20,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //15
    temp = dataArea.mid(22,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //16
    temp = dataArea.mid(24,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //17
    temp = dataArea.mid(26,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //18
    temp = dataArea.mid(28,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //19
    temp = dataArea.mid(30,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //20
    temp = dataArea.mid(32,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList<< temp;
    //21-28
    temp = dataArea.mid(34,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0;i<8;i++)
    {
        if(temp.mid(i,1)=="1")
            valueList<<"可用";
        else
            valueList<<"不可用";
    }
    //29-34
    temp = dataArea.mid(35,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    if(temp.mid(0,1)=="1")
        valueList<<"备磁";
    else
        valueList<<"主磁";
    text = temp.mid(1,3).toInt(nullptr,2);
    switch (text) {
    case 0:valueList<<"数字太敏1";break;
    case 1:valueList<<"模拟太敏1";break;
    case 2:valueList<<"模拟太敏2";break;
    case 3:valueList<<"模拟太敏3";break;
    case 4:valueList<<"模拟太敏4";break;
    case 5:valueList<<"模拟太敏5";break;
    case 6:valueList<<"数字太敏2";break;
    default:valueList<<" ";break;
    }
    if(temp.mid(4,1)=="1")
        valueList<<"备陀螺";
    else
        valueList<<"主陀螺";
    if(temp.mid(5,1)=="1")
        valueList<<"不使用";
    else
        valueList<<"使用";
    if(temp.mid(6,1)=="1")
        valueList<<"数值递推";
    else
        valueList<<"J2递推";
    if(temp.mid(7,1)=="1")
        valueList<<"半实物测试";
    else
        valueList<<"正常工作";
    //35-41
    temp = dataArea.mid(36,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    if(temp.mid(0,1)=="0")
        valueList<<"拍照模式";
    else
        valueList<<"敏感器模式";
    if(temp.mid(1,2)=="00")
    {
        valueList<<"单拍模式";
    }
    else if(temp.mid(1,2)=="01")
    {
        valueList<<"连拍模式";
    }
    else
    {
        valueList<<"敏感器模式";
    }
    if(temp.mid(3,1)=="0")
        valueList<<"禁止";
    else
        valueList<<"准许";
    if(temp.mid(4,1)=="0")
        valueList<<"滤波补偿";
    else
        valueList<<"静动补偿";
    if(temp.mid(5,1)=="0")
        valueList<<"未采用";
    else
        valueList<<"采用";
    if(temp.mid(6,1)=="0")
        valueList<<"未采用";
    else
        valueList<<"采用";
    if(temp.mid(7,1)=="0")
        valueList<<"禁止";
    else
        valueList<<"准许";

    //42-45
    temp = dataArea.mid(37,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    switch (temp.mid(0,5).toInt(nullptr,2)) {
    case 1:valueList<<"TRIAD1";break;
    case 2:valueList<<"TRIAD2";break;
    case 3:valueList<<"TRIAD3";break;
    case 4:valueList<<"TRIAD4";break;
    case 5:valueList<<"TRIAD5";break;
    case 6:valueList<<"EKF1";break;
    case 7:valueList<<"EKF2";break;
    case 8:valueList<<"EKF3";break;
    case 9:valueList<<"EKF4";break;
    case 10:valueList<<"EKF5";break;
    case 11:valueList<<"EKF6";break;
    case 12:valueList<<"EKF7";break;
    case 13:valueList<<"EKF8";break;
    case 14:valueList<<"EKF9";break;
    case 15:valueList<<"EKF10";break;
    case 16:valueList<<"EKF11";break;
    case 17:valueList<<"UKF1";break;
    case 18:valueList<<"UKF2";break;
    case 19:valueList<<"UKF3";break;
    case 20:valueList<<"UKF4";break;
    case 21:valueList<<"UKF5";break;
    case 22:valueList<<"UKF6";break;
    case 23:valueList<<"UKF7";break;
    case 24:valueList<<"UKF8";break;
    case 25:valueList<<"UKF9";break;
    case 26:valueList<<"UKF10";break;
    case 27:valueList<<"UKF11";break;
    case 28:valueList<<"QUEST1";break;
    case 29:valueList<<"QUEST";break;
    case 30:valueList<<"REQUEST1";break;
    case 31:valueList<<"REQUEST2";break;
    default:valueList<<"ERROE";break;
    }
    if(temp.mid(5,1)=="0")
        valueList<<"关闭";
    else
        valueList<<"开启";
    if(temp.mid(6,1)=="0")
        valueList<<"关闭";
    else
        valueList<<"开启";
    valueList<<"预留";
    //46-49
    temp = dataArea.mid(38,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    switch (temp.mid(0,5).toInt(nullptr,2)) {
    case 0:valueList<<"AUTOADS";break;
    case 1:valueList<<"TRIAD1";break;
    case 2:valueList<<"TRIAD2";break;
    case 3:valueList<<"TRIAD3";break;
    case 4:valueList<<"TRIAD4";break;
    case 5:valueList<<"TRIAD5";break;
    case 6:valueList<<"EKF1";break;
    case 7:valueList<<"EKF2";break;
    case 8:valueList<<"EKF3";break;
    case 9:valueList<<"EKF4";break;
    case 10:valueList<<"EKF5";break;
    case 11:valueList<<"EKF6";break;
    case 12:valueList<<"EKF7";break;
    case 13:valueList<<"EKF8";break;
    case 14:valueList<<"EKF9";break;
    case 15:valueList<<"EKF10";break;
    case 16:valueList<<"EKF11";break;
    case 17:valueList<<"UKF1";break;
    case 18:valueList<<"UKF2";break;
    case 19:valueList<<"UKF3";break;
    case 20:valueList<<"UKF4";break;
    case 21:valueList<<"UKF5";break;
    case 22:valueList<<"UKF6";break;
    case 23:valueList<<"UKF7";break;
    case 24:valueList<<"UKF8";break;
    case 25:valueList<<"UKF9";break;
    case 26:valueList<<"UKF10";break;
    case 27:valueList<<"UKF11";break;
    case 28:valueList<<"QUEST1";break;
    case 29:valueList<<"QUEST";break;
    case 30:valueList<<"REQUEST1";break;
    case 31:valueList<<"REQUEST2";break;
    default:valueList<<"ERROE";break;
    }
    if(temp.mid(5,1)=="0")
        valueList<<"主磁";
    else
        valueList<<"备磁";
    if(temp.mid(6,1)=="0")
        valueList<<"模拟";
    else
        valueList<<"数字";
    if(temp.mid(7,1)=="0")
        valueList<<"主陀螺";
    else
        valueList<<"备陀螺";
    //50-57
    temp = dataArea.mid(39,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 16, 2, QChar('0'));
    switch (temp.mid(0,5).toInt(nullptr,2)) {
    case 1:valueList<<"NOCTRL";break;
    case 2:valueList<<"DAMP_ALLON";break;
    case 3:valueList<<"DAMP_BDOT";break;
    case 4:valueList<<"DAMP_RATE";break;
    case 5:valueList<<"STABLE_REA";break;
    case 6:valueList<<"STABLE_MOM";break;
    case 7:valueList<<"INERTIA_DIR";break;
    case 8:valueList<<"STATION_BIAS";break;
    case 9:valueList<<"AIM-POINT";break;
    case 10:valueList<<"YAW_ACTIVE";break;
    case 11:valueList<<"AUTOROTATE";break;
    default:valueList<<"ERROR";break;
    }
    switch (temp.mid(5,5).toInt(nullptr,2)) {
    case 0:valueList<<"AUTOCTRL";break;
    case 1:valueList<<"NOCTRL";break;
    case 2:valueList<<"DAMP_ALLON";break;
    case 3:valueList<<"DAMP_BDOT";break;
    case 4:valueList<<"DAMP_RATE";break;
    case 5:valueList<<"STABLE";break;
    case 7:valueList<<"INERTIA_DIR";break;
    case 8:valueList<<"STATION_BIAS";break;
    case 9:valueList<<"AIM-POINT";break;
    case 10:valueList<<"YAW_ACTIVE";break;
    case 11:valueList<<"AUTOROTATE";break;
    default:valueList<<"ERROR";break;
    }
    if(temp.mid(10,1)=="0")
        valueList<<"反作用轮";
    else
        valueList<<"偏置轮";
    for(int i = 0;i<4;i++)
    {
        if(temp.mid(11+i,1)=="0")
            valueList<<"未锁定";
        else
            valueList<<"锁定";
    }
    if(temp.mid(15,1)=="0")
        valueList<<"单倍";
    else
        valueList<<"双倍";
    //58-65
    temp = dataArea.mid(41,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    if(temp.mid(0,1)=="0")
        valueList<<"不忽略";
    else
        valueList<<"忽略";
    if(temp.mid(1,1)=="0")
        valueList<<"反作用轮";
    else
        valueList<<"偏置轮";
    for(int i = 0; i<4; i++)
    {
        if(temp.mid(2+i,1)=="0")
            valueList<<"未使用";
        else
            valueList<<"使用";
    }
    if(temp.mid(6,1)=="0")
        valueList<<"单倍";
    else
        valueList<<"双倍";
    valueList<<"预留";
    //66-73
    temp = dataArea.mid(42,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<7; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"未开";
        else
            valueList<<"开";
    }
    if(temp.mid(7,1)=="0")
        valueList<<"禁止";
    else
        valueList<<"准许";
    //74-81
    temp = dataArea.mid(43,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<7; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"未开";
        else
            valueList<<"开";
    }
    if(temp.mid(7,1)=="0")
        valueList<<"使用注数";
    else
        valueList<<"正常";
    //82-88
    temp = dataArea.mid(44,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<6; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"未开";
        else
            valueList<<"开";
    }
    valueList<<"预留";
    //89-93
    temp = dataArea.mid(45,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<4; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"未开";
        else
            valueList<<"开";
    }
    valueList<<"预留";
    //94-101
    temp = dataArea.mid(46,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<7; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"禁止";
        else
            valueList<<"准许";
    }
    valueList<<"预留";
    //102-109
    temp = dataArea.mid(47,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<7; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    valueList<<"预留";
    //110-115
    temp = dataArea.mid(48,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<5; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    valueList<<"预留";
    //116-123
    temp = dataArea.mid(49,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<7; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    valueList<<"预留";
    //124-131
    temp = dataArea.mid(50,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    //132-139
    temp = dataArea.mid(51,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<2; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    for(int i = 2; i<5; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"禁止";
        else
            valueList<<"准许";
    }
    for(int i = 5; i<8; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"备用";
        else
            valueList<<"查表";
    }
    //140
//    temp = dataArea.mid(52,6).toHex();
    int a = dataArea.mid(52,2).toHex().toInt(nullptr,16);
    int b = dataArea.mid(54,2).toHex().toInt(nullptr,16);
    int c = dataArea.mid(56,2).toHex().toInt(nullptr,16);
    temp = QString::number((int16_t)a) + "," +QString::number((int16_t)b) + ","+QString::number((int16_t)c) ;
    valueList <<temp;
    //141
    temp = dataArea.mid(58,15).toHex();
    valueList <<temp;
    //142
    temp = dataArea.mid(73,8).toHex();
    valueList <<temp;
    //143
//    temp = dataArea.mid(81,10).toHex();
    int s1 = dataArea.mid(81,2).toHex().toInt(nullptr,16);
    int s2 = dataArea.mid(83,2).toHex().toInt(nullptr,16);
    int s3 = dataArea.mid(85,2).toHex().toInt(nullptr,16);
    int s4 = dataArea.mid(87,2).toHex().toInt(nullptr,16);
    int s5 = dataArea.mid(89,2).toHex().toInt(nullptr,16);
    temp = QString::number(s1) + "," +QString::number(s2) + ","+QString::number(s3)+","+ QString::number(s4)+ ","+QString::number(s5);
    valueList <<temp;
    //144
    temp = dataArea.mid(91,6).toHex();
    valueList <<temp;
    //145
    temp = dataArea.mid(97,6).toHex();
    valueList <<temp;
    //146
    temp = dataArea.mid(103,10).toHex();
    valueList <<temp;
    //147
    temp = dataArea.mid(113,10).toHex();
    valueList <<temp;
    //148
    int b1 = dataArea.mid(123,2).toHex().toInt(nullptr,16);
    int b2 = dataArea.mid(125,2).toHex().toInt(nullptr,16);
    int b3 = dataArea.mid(127,2).toHex().toInt(nullptr,16);
    int b4 = dataArea.mid(129,2).toHex().toInt(nullptr,16);
    int b5 = dataArea.mid(131,2).toHex().toInt(nullptr,16);
    int b6 = dataArea.mid(133,2).toHex().toInt(nullptr,16);
    temp = QString::number(b1)+","+QString::number(b2)+","+QString::number(b3)+","+QString::number(b4)+","+QString::number(b5)+","+QString::number(b6);
    valueList <<temp;
    //149
    temp = dataArea.mid(135,6).toHex();
    valueList <<temp;
    //150
    temp = dataArea.mid(141,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    temp = QString::number(text);
    valueList <<temp;
    //151
    temp = dataArea.mid(143,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    temp = QString::number(text);
    valueList <<temp;
    //152
    temp = dataArea.mid(145,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    temp = QString::number(text);
    valueList <<temp;
    //153
    temp = dataArea.mid(147,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    temp = QString::number(text);
    valueList <<temp;
    //154
    temp = dataArea.mid(149,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList <<temp;
    //155
    temp = dataArea.mid(151,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList <<temp;
    //156
    temp = dataArea.mid(153,2).toHex();
    text = temp.toInt(nullptr,16);
    text = (int16_t)text;
    pa = text/100;
    temp = QString("%1").arg(pa);
    valueList <<temp;
    //157-164
    temp = dataArea.mid(155,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    //165-172
    temp = dataArea.mid(156,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"错误";
        else
            valueList<<"正常";
    }
    //173
    temp = dataArea.mid(157,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList << temp;

//    for(int i =0 ;i<173;i++)
//        valueList<<"value";
    return valueList;
}

QVariantList R22_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    QString temp;
    int text;
    //1
    temp = dataArea.mid(0,2).toHex();
    hexList << temp;
    //2
    temp = dataArea.mid(2,2).toHex();
    hexList << temp;
    //3
    temp = dataArea.mid(4,2).toHex();
    hexList << temp;
    //4
    temp = dataArea.mid(6,2).toHex();
    hexList << temp;
    //5
    temp = dataArea.mid(8,2).toHex();
    hexList << temp;
    //6
    temp = dataArea.mid(10,2).toHex();
    hexList << temp;
    //7
    temp = dataArea.mid(12,1).toHex();
    hexList << temp;
    //8
    temp = dataArea.mid(13,1).toHex();
    hexList << temp;
    //9
    temp = dataArea.mid(14,1).toHex();
    hexList << temp;
    //10
    temp = dataArea.mid(15,1).toHex();
    hexList << temp;
    //11
    temp = dataArea.mid(16,1).toHex();
    hexList << temp;
    //12
    temp = dataArea.mid(17,1).toHex();
    hexList << temp;
    //13
    temp = dataArea.mid(18,2).toHex();
    hexList << temp;
    //14
    temp = dataArea.mid(20,2).toHex();
    hexList << temp;
    //15
    temp = dataArea.mid(22,2).toHex();
    hexList << temp;
    //16
    temp = dataArea.mid(24,2).toHex();
    hexList << temp;
    //17
    temp = dataArea.mid(26,2).toHex();
    hexList << temp;
    //18
    temp = dataArea.mid(28,2).toHex();
    hexList << temp;
    //19
    temp = dataArea.mid(30,2).toHex();
    hexList << temp;
    //20
    temp = dataArea.mid(32,2).toHex();
    hexList << temp;
    //21-28
    temp = dataArea.mid(34,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0;i<8;i++)
    {
        hexList<<temp.mid(i,1);
    }
    //29-34
    temp = dataArea.mid(35,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList<<temp.mid(0,1)<<temp.mid(1,3)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //35-41
    temp = dataArea.mid(36,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,1)<<temp.mid(1,2)<<temp.mid(3,1)<<temp.mid(4,1)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //42-45
    temp = dataArea.mid(37,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,5)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //46-49
    temp = dataArea.mid(38,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    hexList << temp.mid(0,5)<<temp.mid(5,1)<<temp.mid(6,1)<<temp.mid(7,1);
    //50-57
    temp = dataArea.mid(39,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 16, 2, QChar('0'));
    hexList << temp.mid(0,5)<<temp.mid(5,5)<<temp.mid(10,1)<<temp.mid(11,1)<<temp.mid(12,1)<<temp.mid(13,1)<<temp.mid(14,1);
    hexList<<temp.mid(15,1);

    //58-65
    temp = dataArea.mid(41,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //66-73
    temp = dataArea.mid(42,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }

    //74-81
    temp = dataArea.mid(43,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }

    //82-88
    temp = dataArea.mid(44,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<6; i++)
    {
        hexList<<temp.mid(i,1);
    }
    hexList<<temp.mid(6,2);
    //89-93
    temp = dataArea.mid(45,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<4; i++)
    {
        hexList<<temp.mid(i,1);
    }
    hexList<<temp.mid(4,4);
    //94-101
    temp = dataArea.mid(46,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //102-109
    temp = dataArea.mid(47,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //110-115
    temp = dataArea.mid(48,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<5; i++)
    {
        hexList<<temp.mid(i,1);
    }
    hexList<<temp.mid(5,3);
    //116-123
    temp = dataArea.mid(49,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //124-131
    temp = dataArea.mid(50,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //132-139
    temp = dataArea.mid(51,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //140
    temp = dataArea.mid(52,6).toHex();
    hexList <<temp;
    //141
    temp = dataArea.mid(58,15).toHex();
    hexList <<temp;
    //142
    temp = dataArea.mid(73,8).toHex();
    hexList <<temp;
    //143
    temp = dataArea.mid(81,10).toHex();
    hexList <<temp;
    //144
    temp = dataArea.mid(91,6).toHex();
    hexList <<temp;
    //145
    temp = dataArea.mid(97,6).toHex();
    hexList <<temp;
    //146
    temp = dataArea.mid(103,10).toHex();
    hexList <<temp;
    //147
    temp = dataArea.mid(113,10).toHex();
    hexList <<temp;
    //148
    temp = dataArea.mid(123,12).toHex();
    hexList <<temp;
    //149
    temp = dataArea.mid(135,6).toHex();
    hexList <<temp;
    //150
    temp = dataArea.mid(141,2).toHex();
    hexList <<temp;
    //151
    temp = dataArea.mid(143,2).toHex();
    hexList <<temp;
    //152
    temp = dataArea.mid(145,2).toHex();
    hexList <<temp;
    //153
    temp = dataArea.mid(147,2).toHex();
    hexList <<temp;
    //154
    temp = dataArea.mid(149,2).toHex();
    hexList <<temp;
    //155
    temp = dataArea.mid(151,2).toHex();
    hexList <<temp;
    //156
    temp = dataArea.mid(153,2).toHex();
    hexList <<temp;
    //157-164
    temp = dataArea.mid(155,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //165-172
    temp = dataArea.mid(156,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0; i<8; i++)
    {
        hexList<<temp.mid(i,1);
    }
    //173
    temp = dataArea.mid(157,1).toHex();
    hexList << temp;
    return hexList;
}

//R23表
QVariantList R23_Value(QByteArray dataArea)
{
    QVariantList valueList;
    for(int i = 0; i < 91; i++)
        valueList<<"value";

    QString temp;
    int text;
    float pa;
    //92
    temp = dataArea.mid(130,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = 3*text/102;
    if(pa< 0 || pa>5.5)
        testList[346+91]="false";
    temp = QString("%1").arg(pa);
    valueList << temp;

    for(int i = 92; i < 141; i++)
        valueList<<"value";
    return valueList;
}

QVariantList R23_Hex(QByteArray dataArea)
{
//    QVariantList hexList;
//    for(int i = 0; i < 141; i++)
//        hexList<<"ff";

//    QString temp;
//    int text;
//    //92
//    temp = dataArea.mid(130,1).toHex();
//    text = temp.toInt(nullptr,16);
//    temp = QString("%1").arg(text, 8, 2, QChar('0'));
//    hexList[346+91] = temp;

    QVariantList hexList;
    for(int i = 0; i < 91; i++)
        hexList<<"ff";

    QString temp;
    //92
    temp = dataArea.mid(130,1).toHex();
    hexList << temp;

    for(int i = 92; i < 141; i++)
        hexList<<"ff";
    return hexList;
}

//R24表
QVariantList R24_Value(QByteArray dataArea)
{
    QVariantList valueList;
    for(int i = 0; i < 66; i++)
        valueList<<"value";
    return valueList;
}

QVariantList R24_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    for(int i = 0; i < 66; i++)
        hexList<<"ff";
    return hexList;
}

//R25表
QVariantList R25_Value(QByteArray dataArea)
{
    QVariantList valueList;
    for(int i = 0; i < 101; i++)
        valueList<<"value";
    return valueList;
}

QVariantList R25_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    for(int i = 0; i < 101; i++)
        hexList<<"ff";
    return hexList;
}

//R26表
QVariantList R26_Value(QByteArray dataArea)
{
    QVariantList valueList;
    for(int i = 0; i < 11; i++)  //236
        valueList<<"value";

    QString temp;
    int text;
    float pa;

    //12-26
    temp = dataArea.mid(17,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 16, 2, QChar('0'));
    //12
    valueList << temp.mid(0,1) << temp.mid(1,1)<< temp.mid(2,2) << temp.mid(4,1)<< temp.mid(5,1);
    //17
    valueList << temp.mid(6,1)<< temp.mid(7,1)<< temp.mid(8,1)<< temp.mid(9,1)<<temp.mid(10,1);
    //22
    valueList <<temp.mid(11,1)<< temp.mid(12,1)<<temp.mid(13,1)<<temp.mid(14,1)<<temp.mid(15,1);

    //27-34
    temp = dataArea.mid(19,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0;i<8;i++)
    {
        valueList << temp.mid(i,1);
    }

    //35-41
    temp = dataArea.mid(20,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0;i<3;i++)
    {
        if(temp.mid(i,1)=="0")
            valueList<<"异常";
        else
            valueList<<"正常";
    }
    valueList << "预留";
    valueList << "预留";
    if(temp.mid(5,1)=="0")
        valueList<<"未完成";
    else
        valueList<<"完成";
    if(temp.mid(6,2)=="00")
        valueList<<"无操作";
    else if(temp.mid(6,2)=="01")
        valueList<<"更新";
    else
        valueList<<"回滚";
    //42
    valueList<<"预留";
    //43
    temp = dataArea.mid(22,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text);
    valueList<<temp;
    //44
    temp = dataArea.mid(23,2).toHex();
    valueList <<temp;
    //45
    temp = dataArea.mid(25,2).toHex();
    valueList << temp;
    //46
    temp = dataArea.mid(27,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%65536);
    valueList << temp;
    //47
    temp = dataArea.mid(29,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%65536);
    valueList << temp;
    //48
    temp = dataArea.mid(31,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%256);
    valueList << temp;
    //49
    temp = dataArea.mid(32,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%256);
    valueList << temp;
    //50
    temp = dataArea.mid(33,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%65536);
    valueList << temp;
    //51
    temp = dataArea.mid(35,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%65536);
    valueList << temp;
    //52
    temp = dataArea.mid(37,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString::number(text%256);
    valueList << temp;

    for(int i = 52; i<96;i++)
        valueList<<"ff";

    //99
    temp = dataArea.mid(119,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = (text<<4)/819;
    if(pa<0 || pa>3.3 )
        testList[654+98-2]="false";
    temp = QString("%1").arg(pa);
    valueList << temp;

    for(int i = 97; i < 102; i++)  //236
        valueList<<"value";

    //105
    temp = dataArea.mid(125,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = (text<<4)/819;
    if(pa<0 || pa>3.3 )
        testList[654+104-2]="false";
    temp = QString("%1").arg(pa);
    valueList << temp;

    for(int i = 103; i < 108; i++)  //236
        valueList<<"value";


    //111
    temp = dataArea.mid(131,1).toHex();
    text = temp.toInt(nullptr,16);
    pa = (text<<4)/819;
    if(pa<0 || pa>3.3 )
        testList[654+110-2]="false";
    temp = QString("%1").arg(pa);
    valueList << temp;

    for(int i = 109; i < 236; i++)  //236
        valueList<<"value";


    return valueList;
}

QVariantList R26_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    for(int i = 0; i < 11; i++) //236
        hexList<<"ff";

    QString temp;
    int text;

    //12-26
    temp = dataArea.mid(17,2).toHex();
    text = temp.toInt(nullptr,16);
    temp = temp = QString("%1").arg(text, 16, 2, QChar('0'));
    //12
    hexList << temp.mid(0,1)<<temp.mid(1,1)<< temp.mid(2,2)<<temp.mid(4,1)<< temp.mid(5,1);
    //17
    hexList << temp.mid(6,1)<< temp.mid(7,1)<< temp.mid(8,1)<< temp.mid(9,1)<< temp.mid(10,1);
    //22
    hexList << temp.mid(11,1)<<temp.mid(12,1)<<temp.mid(13,1)<< temp.mid(14,1)<< temp.mid(15,1);

    //27-34
    temp = dataArea.mid(19,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0;i<8;i++)
    {
        hexList << temp.mid(i,1);
    }
    //35-41
    temp = dataArea.mid(20,1).toHex();
    text = temp.toInt(nullptr,16);
    temp = QString("%1").arg(text, 8, 2, QChar('0'));
    for(int i = 0;i<6;i++)
    {
        hexList << temp.mid(i,1);
    }
    hexList<<temp.mid(6,2);
    //42
    temp = dataArea.mid(21,1).toHex();
    hexList<<temp;
    //43
    temp = dataArea.mid(22,1).toHex();
    hexList<<temp;
    //44
    temp = dataArea.mid(23,2).toHex();
    hexList <<temp;
    //45
    temp = dataArea.mid(25,2).toHex();
    hexList << temp;
    //46
    temp = dataArea.mid(27,2).toHex();
    hexList << temp;
    //47
    temp = dataArea.mid(29,2).toHex();
    hexList << temp;
    //48
    temp = dataArea.mid(31,1).toHex();
    hexList << temp;
    //49
    temp = dataArea.mid(32,1).toHex();
    hexList << temp;
    //50
    temp = dataArea.mid(33,2).toHex();
    hexList << temp;
    //51
    temp = dataArea.mid(35,2).toHex();
    hexList << temp;
    //52
    temp = dataArea.mid(37,1).toHex();
    hexList << temp;

    for(int i = 52; i<96;i++)
        hexList<<"ff";

    //99
    temp = dataArea.mid(119,1).toHex();
    hexList<<temp;

    for(int i = 97; i <102; i++) //236
        hexList<<"ff";

    //105
    temp = dataArea.mid(125,1).toHex();
    hexList << temp;

    for(int i = 103; i < 108; i++) //236
        hexList<<"ff";

    //111
    temp = dataArea.mid(131,1).toHex();
    hexList << temp;

    for(int i = 109; i < 236; i++) //236
        hexList<<"ff";
    return hexList;
}

//R27表
QVariantList R27_Value(QByteArray dataArea)
{
    QVariantList valueList;
    for(int i = 0; i < 6; i++)
        valueList<<"value";
    return valueList;
}

QVariantList R27_Hex(QByteArray dataArea)
{
    QVariantList hexList;
    for(int i = 0; i < 6; i++)
        hexList<<"ff";
    return hexList;
}
