#include <iostream>
#include "menu.h"
#include "caracteristicas_edificios.h"
#include "mapa.h"
#include "edificio.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;
    mapa->ingreso_datos_mapa();

    cout << "\n ¡ BIENVENIDOS A ANDYPOLIS ! \n" << endl;

    mostrar_menu();
    int opcion = elegir_opcion();

    while ( opcion != GUARDAR_SALIR ){

        procesar_opcion(opcion, mapa);
        mostrar_menu();
        opcion = elegir_opcion();
    }

    delete mapa;

    cout << "\n Muchas gracias por visitar la ciudad , nos vemos pronto ! \n" << endl; 

    return 0;
}