#include "lista_edificio.h"


Lista_edificio::Lista_edificio(string archivo){
    ifstream nuevo_archivo;
    nuevo_archivo.open(archivo);

    int cantidad_edificios = 0;

    string nombre_edificio;
    float cantidad_piedra;
    float cantidad_madera;
    float cantidad_metal;
    int maximo;

    while (nuevo_archivo >> nombre_edificio){
        nuevo_archivo >> cantidad_piedra;
        nuevo_archivo >> cantidad_madera;
        nuevo_archivo >> cantidad_metal;
        nuevo_archivo >> maximo;

        Edificio * nuevo_edificio;

        nuevo_edificio = new Edificio(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        Edificio ** vector_edificio = new Edificio * [ cantidad_edificios + 1]; 

        if ( cantidad_edificios == 0){
            vector_edificio[ cantidad_edificios ] = nuevo_edificio;
            this->edificios_posibles = vector_edificio;
        } else {
            for ( int i = 0; i < cantidad_edificios; i++){
                vector_edificio[i] = edificios_posibles[i];
            }
            vector_edificio[ cantidad_edificios ] = nuevo_edificio;
            delete [] edificios_posibles;
            this->edificios_posibles = vector_edificio;
        }
        cantidad_edificios++;
    }
    this->cantidad_edificios = cantidad_edificios;

    nuevo_archivo.close();
}

void Lista_edificio::mostrar_edificios(){
    for ( int i = 0; i < cantidad_edificios; i++){
        cout << edificios_posibles[i]->mostrar_nombre() << endl;
    }
}