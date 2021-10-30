#include "casillero_inaccesible.h"


Casillero_inaccesible::Casillero_inaccesible(int fila, int columna): Casillero( fila, columna , nombre){
    this->nombre = "L";
    this->fila = fila;
    this->columna = columna;
}

string Casillero_inaccesible::obtener_nombre(){
    return nombre;
}

void Casillero_inaccesible::mostrar_casillero(){
    cout << "Este es un casillero inaccesible" << endl;
}

void Casillero_inaccesible::agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un casillero inaccesible , no se podran construir edificios en el. \n" << endl;
}

void Casillero_inaccesible::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}
