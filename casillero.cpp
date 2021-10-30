#include "casillero.h"

Casillero::Casillero(){
    this->fila = 0;
    this->columna = 0;
    this->nombre = "A";
}

Casillero::Casillero(int fila, int columna , string nombre){
    this->fila = fila;
    this->columna = columna;
    this->nombre = nombre;
}

string Casillero::obtener_nombre(){
    return nombre;
}

int Casillero::mostrar_fila(){
    return fila;
}

int Casillero::mostrar_columna(){
    return columna;
}
