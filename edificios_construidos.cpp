#include "edificios_construidos.h"

Edificios_construidos::Edificios_construidos(){
    this->cantidad_edificios_construidos = 0;
    this->edificios_construidos = nullptr;
}

void Edificios_construidos::procesar_archivo(){
    ifstream archivo;
    archivo.open(ARCHIVO_UBICACION);

    string nombre;
    int fila;
    int columna;

    while ( archivo >> nombre ){
        cout << nombre << endl;
    }

    archivo.close();
    
}