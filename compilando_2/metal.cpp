#include <iostream>
#include "metal.h"

//Constructor de Metal don dos parametros
Metal :: Metal(string nombre, int cantidad) : Material(nombre, cantidad){
        nombre = nombre;
        cantidad = cantidad;
}


//metal saluda
void Metal :: saludar(){
        cout << "Soy un metal y me encuentro en el casillero consultado";
}