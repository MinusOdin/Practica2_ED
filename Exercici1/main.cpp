#include <iostream>
#include "CuaEstatica.h"

using namespace std;

int main(){
    CuaEstatica cua(3);
    cua.enqueue(10);
    cua.enqueue(20);
    cua.printFrontRear();
    cua.enqueue(30);
    cua.enqueue(40);
}