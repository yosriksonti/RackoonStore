#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include "panier.h"
class PieChart : public QWidget
{
    Q_OBJECT
public:
    explicit PieChart(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
private:
    panier p;
};

#endif // PIECHART_H
