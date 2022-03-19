#ifndef Node_H
#define Node_H

#include <iostream>

using namespace std;

template<typename T>
class Node{
    public:
        Node(T element);
        Node(const Node<T>& q);
        ~Node();
        const T getElement() const;
        Node<T>* getNext() const;
        void setNext(Node<T> node);
    private:
        T element;
        Node<T>* next;
};



template<typename T>
Node<T>::Node(T element){
    this->element = element;
    this->next = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& q){
    this->element = q.element;
    this->next = q.getNext();
}

template<typename T>
Node<T>::~Node(){
}

template<typename T>
const T Node<T>::getElement() const{
    return element;
}

template<typename T>
Node<T>* Node<T>::getNext() const{
    return next;
}

template<typename T>
void Node<T>::setNext(Node<T> node){
    this->next = &node;
}

#endif