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

int Edificio::obtener_cantidad_piedra(){
    return cantidad_piedra;
}
int Edificio::obtener_canitdad_madera(){
    return canitdad_madera;
}
int Edificio::obtener_cantidad_metal(){
    return cantidad_metal;
}
int Edificio::obtener_maximo_construir(){
    return maximo_construir;
}

int Edificio::obtener_mitad_madera(){
    return canitdad_madera/2;
}

int Edificio::obtener_mitad_piedra(){
    return cantidad_piedra/2;
}

int Edificio::obtener_mitad_metal(){
    return cantidad_metal/2;
}

