#include "aserradero.h"

Aserradero::Aserradero(int piedra, int madera, int metal, int maximo) : Edificio(nombre, piedra, madera, metal, maximo){
    this->diminutivo = "A";
    this->brinda = 25;
}

int Aserradero::obtener_material_brinda(){
    return brinda;
}