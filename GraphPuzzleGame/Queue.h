//
// Created by yk029484 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_SQV51_QUEUE_H
#define GRAPH_PUZZLE_GAME_SQV51_QUEUE_H


namespace std {

    template<typename T>
    class Queue {
    private:
        struct Node {
            T data;
            Node* next;
            Node(T data) : data(data), next(nullptr) {}
        };

        Node* rear;


    public:
        Queue();
        ~Queue();
        void push(T t);
        bool isEmpty() const;
        T getFront() const;
        void pop();

        Node* front;
    };

    template<typename T>
    void Queue<T>::pop() {
        if (front == nullptr) {
            return;
        }
        //pop the front node remembering the list is linked from front to rear
        Node* temp = front;
        front = front->next;
        delete temp;


    }


}


#endif //GRAPH_PUZZLE_GAME_SQV51_QUEUE_H