#include "piechart.h"
#include <QPainter>

PieChart::PieChart(QWidget *parent) : QWidget(parent)
{

}

void PieChart::paintEvent(QPaintEvent *)
{
    QString x1,x2;

    QPainter painter(this);
    QRectF size = QRectF(10,10,this->width()-100,this->width()-100);
    painter.setBrush(Qt::lightGray);
    p.stat(&x1,&x2);
    int y1 = (x1.toInt() * 360)/100;
    painter.drawPie(size, 0, y1 * 16);
    painter.setBrush(Qt::gray);
    painter.drawPie(size, y1 * 16, (360 - y1)*16);
}
