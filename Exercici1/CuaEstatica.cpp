#include <iostream>
#include "CuaEstatica.h"

using namespace std;

CuaEstatica::CuaEstatica(const int max_size){
    int data[max_size];
    this->_data = data;
    this->_size = 0;
    this->_front = 0;
    this->_rear = -1;
    this->_max_size = max_size;
}

CuaEstatica::~CuaEstatica(){}

void CuaEstatica::enqueue(const int key){
    if(isFull()) throw out_of_range("EXCEPTION: L'estructura esta plena");
    else{
        _rear ++;
        _data[_rear] = key;
        _size++;
        cout << "Element " << key << "agregat" << endl;
    }
}

void CuaEstatica::dequeue(){
    if(isEmpty()) throw out_of_range("EXCEPTION: L'estructura esta buida");
    else{
        cout << "Element " << *(_data) << "eliminat" << endl;
        _front--;
        _size--;
        for(int i = 0; i <= size; i++){
            _data + i = *(_data + i)
        }
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
    for (int i = 0; i <= _size; i++){
        if (i == _size) cout<<_data[i];
        else cout<< _data[i] << ", ";
    }
    cout << endl;
}

const int CuaEstatica::getFront(){
    return _data[_front];
}

void CuaEstatica::printFrontRear(){
    if (isEmpty()) cout<< "Front: " << 0 <<", Rear: " << 0;
    else cout<< "Front: " << _data[_front] <<", Rear: " << _data[_rear];
}