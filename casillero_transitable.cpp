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
    cout << "Soy un casillero transitable y me encuentro vacio" << endl;
}

void Casillero_transitable::agregar_edificio(){
    cout << "no hace nada" << endl;
}