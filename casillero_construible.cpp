#include "casillero_construible.h"


Casillero_construible::Casillero_construible(int fila, int columna): Casillero( fila, columna , nombre){
    this->edificio_construido = nullptr;
    this->nombre = "T";
    this->fila = fila;
    this->columna = columna;
}

string Casillero_construible::mostrar_nombre(){
    return nombre;
}

void Casillero_construible::mostrar_casillero(){
    if ( edificio_construido == nullptr ){
        cout << "Soy un casillero construible y me encuentro vacio" << endl;
    } else {
        cout << "Soy un casillero construible y no me encuentro vacio" << endl;
        //cout << edificio_construido->mostrar_edifico() << endl;
    }
}

