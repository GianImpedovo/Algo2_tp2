#include "escuela.h"

Escuela::Escuela(int piedra, int madera, int metal, int maximo) : Edificio(nombre, piedra, madera, metal, maximo){
    this->nombre = "escuela";
    this->diminutivo = "E";
    this->brinda = 0;
}

int Escuela::obtener_material_brinda(){
    return brinda;
}

void Escuela::mostrar_mensaje(){
    cout << "Soy una " << nombre << "no brindo materiales y me encuentro en el casillero consultado . " << endl;
}