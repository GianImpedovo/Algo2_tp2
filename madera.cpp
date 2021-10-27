#include <iostream>
#include "madera.h"

//Constructor de piedra don dos parametros
Madera :: Madera(string nombre, int cantidad) : Material(nombre, cantidad){

}

//Piedra saluda
void saludar(){
        cout << "Soy una madera y me encuentro en el casillero consultado";
}