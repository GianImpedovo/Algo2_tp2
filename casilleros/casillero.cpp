#include "casillero.h"

Casillero::Casillero(){
    this->fila = 0;
    this->columna = 0;
    this->nombre = "A";
}

Casillero::Casillero(int fila, int columna){
    this->fila = fila;
    this->columna = columna;
    this->nombre = "";
}

string Casillero::obtener_nombre(){
    return nombre;
}

Casillero::~Casillero(){}