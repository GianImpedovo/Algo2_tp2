#include <iostream>
#include "madera.h"

//Constructor de piedra don dos parametros
Madera :: Madera(string nombre, int cantidad) : Material(nombre, cantidad){
        nombre = nombre;
        cantidad = cantidad;
}

//Piedra saluda
void Madera :: saludar(){
        cout << "Soy una piedra y me encuentro en el casillero consultado";
}