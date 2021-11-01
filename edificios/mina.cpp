#include "mina.h"

Mina::Mina(int piedra, int madera, int metal, int maximo) : Edificio(nombre, piedra, madera, metal, maximo){
    this->nombre = "mina";
    this->diminutivo = "M";
    this->brinda = 15;
}

int Mina::obtener_material_brinda(){
    return brinda;
}

void Mina::mostrar_mensaje(){
    cout << "Soy una " << nombre << " brindo : " << brinda << " de piedra y me encuentro en el casillero consultado . " << endl;
}