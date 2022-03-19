#include "CuaEncadenada.h"
#include <iostream>
#include <vector>

using namespace std;

void casProva1(){
    CuaEncadenada<int> cua;
    try{
        cua.enqueue(10);
        cua.enqueue(20);
        cua.enqueue(30);
        cua.enqueue(40);
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
    cua.print();
    try{
        cua.dequeue();
        cua.enqueue(50);
        cua.print();
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
}

void casProva2(){
    CuaEncadenada<int> cua;
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
        cua.dequeue();
        cout << cua.getFront() << endl;
        cua.dequeue();
        cua.dequeue();
        cua.dequeue();
    }catch(out_of_range &e){
        cerr<< e.what() << endl;
    }
    cua.print();
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
    CuaEncadenada<int> cua;
    int opcio = 0;
    vector<string> opcions = { "Inserir element a la cua", "Treure element de la cua", "Consultar el primer element", "Imprimir tot el contingut de la CuaEstatica", "Sortir"};
    while(opcio != 5){
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
        }
    }
    casProva1();
    casProva2();
}