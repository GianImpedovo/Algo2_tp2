#include "fabrica.h"

Fabrica::Fabrica(int piedra, int madera, int metal, int maximo) : Edificio(nombre, piedra, madera, metal, maximo){
    this->nombre = "fabrica";
    this->diminutivo = "F";
    this->brinda = 40;
}

int Fabrica::obtener_material_brinda(){
    return brinda;
}

void Fabrica::mostrar_mensaje(){
    cout << "Soy una " << nombre << " brindo : " << brinda << " de metal y me encuentro en el casillero consultado . " << endl;
}