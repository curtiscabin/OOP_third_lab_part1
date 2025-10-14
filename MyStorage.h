#ifndef MYSTORAGE_H
#define MYSTORAGE_H

#endif // MYSTORAGE_H

#include "CCircle.h"

class MyStorage {
    CCircle *circle;
    MyStorage *next;

public:
    MyStorage() : next(nullptr) {}

    void add(CCircle *circ){
        MyStorage*node = new MyStorage;
        node->circle = circ;
        if (!next){
            next = node;
            node->next = nullptr;
            return;
        }
        node->next = next;
        next = node;
    }
};
