#include "vector_ints.h"
#include <iostream>

using namespace std;


// Constructor sin parametros
Vector_ints :: Vector_ints( ) {
	longitud = 0;
	numeros = 0;
}

// obtener
int Vector_ints :: obtener_numero ( int pos) {
	return numeros[pos];
}

int Vector_ints :: obtener_longitud(){
    return longitud;
}


// redimensionar
void Vector_ints :: agregar_numero (int num, int tam, int pos ) {

    int* aux = new int[tam];

    for (int i = 0; i<pos; i++){
        aux[i] = numeros[i];
    }

    aux [pos] = num;

    if (longitud > 0){
        delete [] numeros;
        }
    longitud = tam;
    numeros = aux;
}


// Destructor
Vector_ints :: ~Vector_ints ( ) {

    if (longitud > 0){
		delete [] numeros;
        numeros = nullptr;

        longitud = 0;
    }
}
