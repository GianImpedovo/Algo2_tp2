#include "casillero_transitable.h"

Casillero_transitable::Casillero_transitable(int fila, int columna): Casillero(fila, columna){
    this->nombre = "C";
}

string Casillero_transitable::obtener_nombre(){
    return nombre;
}

void Casillero_transitable::mostrar_casillero(){
    cout << "Soy un casillero transitable y me encuentro vacio" << endl;
}

void Casillero_transitable::agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un casillero transitable no se podran construir edificios en el. \n" << endl;
}

void Casillero_transitable::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Casillero_transitable::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Casillero_transitable::obtener_nombre_edificio(){
    return "";
}

string Casillero_transitable::obtener_diminutivo_edificio(){
    return "";
}

