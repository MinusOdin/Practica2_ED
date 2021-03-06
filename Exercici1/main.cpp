#include <iostream>
#include <vector>
#include "CuaEstatica.h"

using namespace std;

void casProva1(){
    CuaEstatica cua(3);
    try{
        cua.enqueue(10);
        cua.enqueue(20);
        cua.printFrontRear();
        cua.enqueue(30);
        cua.enqueue(40);
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
    cua.print();
    try{
        cua.printFrontRear();
        cua.dequeue();
        cua.enqueue(50);
        cua.print();
        cua.printFrontRear();
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
}

void casProva2(){
    CuaEstatica cua(3);
    try{
        cua.enqueue(10);
        cout << cua.getFront() << endl;
        cua.enqueue(20);
        cua.enqueue(30);
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
    cua.print();
    try{
        cua.printFrontRear();
        cua.dequeue();
        cout << cua.getFront() << endl;
        cua.dequeue();
        cua.printFrontRear();
        cua.dequeue();
        cua.dequeue();
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
    cua.print();
    cua.printFrontRear();
}

void imprimirOpcions(vector<string> opcions){
    for (int i = 1; i <= opcions.size(); i++){
        cout<< i << ". " << opcions[i-1] << endl;
    }
}

void demanarOpcio(int &opcio){
    cout<< "Tria una opcio: ";
    cin >> opcio;
}

int main(){
    CuaEstatica cua(3);
    int opcio = 0;
    vector<string> opcions = { "Inserir element a la cua", "Treure element de la cua", "Consultar el primer element", "Imprimir tot el contingut de la CuaEstatica", "Imprimir les posicions del front i el rear", "Sortir"};
    while(opcio != 6){
        imprimirOpcions(opcions);
        demanarOpcio(opcio);
        switch (opcio){
            case 1:
                int aux;
                cout<< "Que vols inserir?" << endl;
                cin >> aux;
                try{
                    cua.enqueue(aux);
                }catch(exception &e){
                    cerr << e.what() << endl;
                }
                break;
            case 2:
                try{
                    cua.dequeue();
                }catch(exception &e){
                    cerr << e.what() << endl;
                }
                break;
            case 3:
                try{
                    cout<< cua.getFront()<<endl;
                }catch(exception &e){
                    cerr << e.what() << endl;
                }
                break;
            case 4:
                cua.print();
                break;
            case 5:
                cua.printFrontRear();
                break;
        }
    }
    casProva1();
    casProva2();
}