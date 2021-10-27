#include "casillero_transitable.h"


Casillero_transitable::Casillero_transitable(int fila, int columna): Casillero( fila, columna , nombre){
    this->nombre = "C";
    this->fila = fila;
    this->columna = columna;
}

string Casillero_transitable::mostrar_nombre(){
    return nombre;
}

void Casillero_transitable::mostrar_casillero(){
    cout << "Este es un casillero transitable" << endl;
}