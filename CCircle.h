#ifndef CCIRCLE_H
#define CCIRCLE_H

#endif // CCIRCLE_H
#pragma once

#include <QPoint>
#include <QWidget>
#include<QPainter>
#include<QDebug>


class CCircle : public QWidget {
    Q_OBJECT
    int x;
    int y;
    int rad = 5;

public:
    CCircle(const QPoint p) : x(p.x()), y(p.y()){}

    void paint_circle(){
        qDebug()<<"paint_circle\n";
        update();
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        painter.drawEllipse(x,y,2*rad,2*rad);
        painter.end();
    }
};
