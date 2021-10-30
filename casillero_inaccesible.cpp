#include "casillero_inaccesible.h"


Casillero_inaccesible::Casillero_inaccesible(int fila, int columna): Casillero( fila, columna , nombre){
    this->nombre = "L";
    this->fila = fila;
    this->columna = columna;
}

string Casillero_inaccesible::mostrar_nombre(){
    return nombre;
}

void Casillero_inaccesible::mostrar_casillero(){
    cout << "Este es un casillero inaccesible" << endl;
}

void Casillero_inaccesible::agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo){
    cout << "no hace nada" << endl;
}