#include <iostream>
#include "CuaEstatica.h"

using namespace std;

CuaEstatica::CuaEstatica(const int max_size){
    this->_data = new int[max_size];
    this->_size = 0;
    this->_front = 0;
    this->_rear = 0;
    this->_max_size = max_size;
}

CuaEstatica::~CuaEstatica(){
    delete _data;
}

void CuaEstatica::enqueue(const int key){
    if(isFull()) throw out_of_range("EXCEPTION: L'estructura esta plena");
    else{
        _data[_rear] = key;
        _rear ++;
        if(_rear == _max_size ) _rear = 0;
        _size++;
        cout << "Element " << key << " agregat" << endl;
    }
}

void CuaEstatica::dequeue(){
    if(isEmpty()) throw out_of_range("EXCEPTION: L'estructura esta buida");
    else{
        cout << "Element " << _data[_front] << " eliminat" << endl;
        _front++;
        if (_front == _max_size ) _front = 0;
        _size--;
    }
}

bool CuaEstatica::isFull(){
    return _size == _max_size;
}

bool CuaEstatica::isEmpty(){
    return _size == 0;
}

void CuaEstatica::print(){
    cout<< "[";
    int aux = _front;
    for (int i = 0; i < _size; i++){
        if ( i == _size - 1) cout<<_data[aux % _size];
        else cout<< _data[aux % _size] << ", ";
        aux++;
    }
    cout <<"]" << endl;
}

const int CuaEstatica::getFront(){
    if (isEmpty()) throw new out_of_range("EXCEPTION: L'estructura esta buida");
    else return _data[_front];
}

void CuaEstatica::printFrontRear(){
    if (isEmpty()) cout<< "Front: " << 0 <<", Rear: " << 0 <<endl;
    else cout<< "Front: " << _front <<", Rear: " << _rear <<endl;
}