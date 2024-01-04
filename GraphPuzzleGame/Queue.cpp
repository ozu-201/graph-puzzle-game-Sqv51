//
// Created by yk029484 on 12/21/2023.
//

#include "Queue.h"

namespace std {
    template<typename T>
    T Queue<T>::getFront() const {
        return front->data;
    }

    template<typename T>
    bool Queue<T>::isEmpty() const {
        return front == nullptr;
    }

    template<typename T>
    void Queue<T>::push(T t) {
        Node* newNode = new Node(t);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

    }

    template<typename T>
    Queue<T>::~Queue() {

    }

    template<typename T>
    Queue<T>::Queue() {
        front = nullptr;
        rear = nullptr;

    }

}