#ifndef CCIRCLE_H
#define CCIRCLE_H

#endif // CCIRCLE_H
#pragma once

#include <QPoint>

class CCircle {
    int x;
    int y;
    int rad = 5;

public:
    CCircle(const QPoint p) : x(p.x()), y(p.y()){}

    void paint_circle(){

    }
};
