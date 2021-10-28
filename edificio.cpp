#include "edificio.h"

Edificio::Edificio(){
    this->nombre = "nada";
    this->cantidad_piedra = 0;
    this->canitdad_madera = 0;
    this->cantidad_metal = 0;
    this->maximo_construir = 0;
}

Edificio::Edificio(std::string nombre , int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir){
    this-> nombre = nombre;
    this-> cantidad_piedra = cantidad_piedra;
    this-> canitdad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> maximo_construir = maximo_construir;

} 

string Edificio::mostrar_nombre(){
    return nombre;
}

int Edificio::mostrar_cantidad_piedra(){
    return cantidad_piedra;
}
int Edificio::mostrar_canitdad_madera(){
    return canitdad_madera;
}
int Edificio::mostrar_cantidad_metal(){
    return cantidad_metal;
}
int Edificio::mostrar_maximo_construir(){
    return maximo_construir;
}


