#include "casillero_construible.h"


Casillero_construible::Casillero_construible(int fila, int columna): Casillero( fila, columna , nombre){
    this->edificio_construido = nullptr;
    this->nombre = "T";
}

string Casillero_construible::mostrar_nombre(){
    return nombre;
}

void Casillero_construible::mostrar_casillero(){

    cout << "Soy un casillero construible y me encuentro vacio" << endl;
}

void Casillero_construible::agregar_edificio(){
    cout << "agrego edificio" << endl;
}
