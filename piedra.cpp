#include <iostream>
#include "piedra.h"

//Constructor de piedra don dos parametros
Piedra :: Piedra(string nombre, int cantidad) : Material(nombre, cantidad){
        nombre = nombre;
        cantidad = cantidad;
}


//Piedra saluda
void Piedra :: saludar(){
        cout << "Soy una piedra y me encuentro en el casillero consultado"<<endl;
}