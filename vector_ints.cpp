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

void Vector_ints::sacar_numero(int posicion_numero_a_sacar){
    
    if (longitud > 1) {

        //mando el q quiero elimnar a la ult pos y lo intercambio con ese
        swap_num(longitud - 1, posicion_numero_a_sacar);
        
        int *vector_aux_numeros = new int[longitud - 1];

        for(int i = 0; i < longitud - 1; i++){
            vector_aux_numeros[i] = numeros[i];
            //Como esta en la ult pos nunca lo copio!
        }

        delete[] numeros;

        numeros = vector_aux_numeros;

    }else{
        delete[] numeros;
    }

    //agenda -> cantidad_de_contactos--;
    longitud --;
}

void Vector_ints::swap_num(int posicion_1, int posicion_2){
    int aux = numeros[posicion_1];
    numeros[posicion_1] = numeros[posicion_2]; //mando al final (pos_1) el quiero eliminar(pos_2)
    numeros[posicion_2] = aux; //el ultimo lo pongo en donde estaba el que quiero eliminar
}