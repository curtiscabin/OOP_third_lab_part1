#ifndef MYSTORAGE_H
#define MYSTORAGE_H

#endif // MYSTORAGE_H

#include "CCircle.h"

class Node{

    Node():next(nullptr),circle(nullptr){}

    ~Node(){
        delete next;
        delete circle;
    }

    Node*next;
    CCircle *circle;
};

class MyStorage {
    MyStorage*head;
    MyStorage*tail;
    MyStorage*current;

public:
    MyStorage() :head(nullptr),tail(nullptr) {}

    void add(CCircle *circ){
        Node*node = new Node;
        node->circle = circ;
        if (!head){
            head = node;
            tail = node;
            node->next = nullptr;
            return;
        }
        node->next = head;
        head = node;
    }

    void first(){
        current = head;
    }

    void next(){
        // current = current;
    }

    CCircle *getObject(){
        return current->circle;
    }

    // CCircle *next(){
    //     return
    // }
};
