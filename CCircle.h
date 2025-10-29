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
    bool isSelect_ = false;

public:
    CCircle(const QPoint &p, QWidget* parent) : x(p.x()), y(p.y()), QWidget(parent){
        setFixedSize(2*rad, 2*rad);
        move(p.x() - rad, p.y() - rad);

    }

    ~CCircle(){
        update();
    }

    void paint_circle(){
        qDebug()<<"paint_circle\n";
        qDebug()<<"x - "<<x<<" and y - "<<y<<Qt::endl;
        show();
    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        if (isSelect()) painter.setPen(QPen(Qt::cyan, 3));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(0,0,2*rad,2*rad);

    }

    bool isCordBelongCircle(const QPoint &p){
        int xp = p.x();
        int yp = p.y();

        if ( (x - xp)*(x-xp) + (y - yp)*(y-yp) <= rad*rad ){
            return true;
        }
        else return false;
    }

    void setSelection(){
        isSelect_ = true;
    }

    bool isSelect(){
        return isSelect_;
    }

};
