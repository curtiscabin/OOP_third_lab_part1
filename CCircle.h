#ifndef CCIRCLE_H
#define CCIRCLE_H

#endif // CCIRCLE_H
#pragma once

#include <QPoint>
#include <QWidget>
#include<QPainter>
#include<QDebug>
#include <String>


class CCircle : public QWidget {
    Q_OBJECT
    int x;
    int y;
    int rad = 30;

public:
    CCircle(const QPoint &p, QWidget* parent/* = nullptr*/) : x(p.x()), y(p.y()), QWidget(parent){
        setFixedSize(2*rad, 2*rad);
        move(p.x() - rad, p.y() - rad);

    }

    void paint_circle(){
        qDebug()<<"paint_circle\n";
        qDebug()<<"x - "<<x<<" and y - "<<y<<Qt::endl;
        show();
    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(0,0,2*rad,2*rad);

    }

    // bool isCordOfCircle(const QPoint &p){

    // }
};
