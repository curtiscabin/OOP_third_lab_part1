#ifndef MYSTORAGE_H
#define MYSTORAGE_H

#endif // MYSTORAGE_H

#include "CCircle.h"

class Node{

    Node *next;
    CCircle *circle;

    Node():next(nullptr),circle(nullptr){}

    ~Node(){
        if (circle!=nullptr)delete circle;
    }

    friend class MyStorage;


};

class MyStorage {
    Node *head;
    Node *tail;
    Node *current;

public:
    MyStorage() : head(nullptr),tail(nullptr),current(nullptr) {}

    void clear(){
        while (head){
            current = head;
            head = current->next;
            delete current;

        }
        current = nullptr;
        tail = nullptr;
    }

    ~MyStorage(){
        this->clear();
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

    void deleteSelect(MyStorage *select) {

        for (select->first();!select->eol();select->next()){
            current = head;
            if (head->circle == select->getObject()){
                head->circle = nullptr;
                Node *ptr = head;
                head = head->next;
                delete ptr;
                continue;
            }
            else if (tail->circle == select->getObject()){
                tail->circle = nullptr;
                Node *ptr = tail;
                while(current->next != tail){
                    this->next();
                }
                tail = current;
                tail->next = nullptr;
                delete ptr;
                continue;
            }

            while (current->next && current->next->circle != select->getObject()){
                this->next();
            }
            if (!current->next) continue;
            current->next->circle = nullptr;
            Node *ptr = current->next;
            current->next = current->next->next;
            if (ptr == tail) {
                tail = current;
            }
            delete ptr;


        }
        select->clear();
    }

    void clearSelectCircles(){
        while (head){
            current = head;
            head = current->next;
            current->circle->clearSelection();
            current->circle->update();
            current = nullptr;

        }
        current = nullptr;
        tail = nullptr;
    }

};
