#ifndef MYSTORAGE_H
#define MYSTORAGE_H

#endif // MYSTORAGE_H

#include "CCircle.h"

class Node{

    Node *next;
    CCircle *circle;

    Node():next(nullptr),circle(nullptr){}

    ~Node(){
        delete circle;
    }

    friend class MyStorage;


};

class MyStorage {
    Node *head;
    Node *tail;
    Node *current;

public:
    MyStorage() : head(nullptr),tail(nullptr),current(nullptr) {}

    ~MyStorage(){
        while (head){
            current = head;
            head = current->next;
            delete current;

        }
        current = nullptr;
        tail = nullptr;
    }

    void add(CCircle *circ){

        Node* node = new Node;
        node->circle = circ;
        node->next = head;
        head = node;
        current = node;
        if (!tail) tail = node;

    }

    void first(){
        current = head;
    }

    void next(){
        if (current) current = current->next ;
    }

    bool eol(){
        return current == nullptr;
    }


    CCircle *getObject(){
        return current ? current->circle : nullptr;
    }

    int get_size(){
        int count =0;
        for(this->first();!this->eol();this->next()) count++;
        return count;
    }
};
