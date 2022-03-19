#ifndef CuaEncadenada_H
#define CuaEncadenada_H

#include "Node.h"
#include <iostream>

using namespace std;

template <typename T>
class CuaEncadenada {
    public:
        CuaEncadenada();
        CuaEncadenada(const CuaEncadenada<T>& q);
        ~CuaEncadenada();
        bool isEmpty();
        void print();
        void enqueue(const T key);
        void dequeue();
        const T getFront();
    
    private:
        Node<T>* _front;
        Node<T>* _rear;
};


template <typename T>
CuaEncadenada<T>::CuaEncadenada(){
    Node<T> sentinella(0);
    this->_front =  &sentinella;
    this->_rear = &sentinella;
}

template <typename T>
CuaEncadenada<T>::CuaEncadenada(const CuaEncadenada<T>& q){
    this->_front = q._front;
    this->_rear = q._rear;
}

template <typename T>
CuaEncadenada<T>::~CuaEncadenada(){
    delete _front;
    delete _rear;
}

template <typename T>
bool CuaEncadenada<T>::isEmpty(){
    return _front == _rear;
}

template <typename T>
void CuaEncadenada<T>::print(){
    Node<T>* aux = _front->getNext();
    cout << "[";
    while(aux != nullptr){
        cout << aux->getElement() <<", ";
        aux = aux->getNext();
    }
    cout << "]" <<endl;
}

template <typename T>
void CuaEncadenada<T>::enqueue(const T key){
    Node<T>* new_node = new Node(key);
    _rear->setNext(*new_node);
    _rear = _rear->getNext();
    cout << "Element " << key << " agregat" << endl;
}

template <typename T>
void CuaEncadenada<T>::dequeue(){
    Node<T>* aux = _front->getNext();
    _front = aux->getNext();
    cout << "Element " << aux->getElement() << " eliminat" << endl;
    delete aux;
}

template <typename T>
const T CuaEncadenada<T>::getFront(){
    if (isEmpty()) throw new out_of_range("EXEPTION: L'estructura esta buida");
    else return _front->getNext()->getElement();
}

#endif