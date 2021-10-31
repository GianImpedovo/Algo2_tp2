#include <iostream>
#include "menu.h"
#include "caracteristicas_edificios.h"
#include "mapa.h"
#include "edificio.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;
    mapa->procesar_archivo_ubicaciones();


    mostrar_menu();
    int opcion = elegir_opcion();

    while ( opcion != GUARDAR_SALIR ){

        procesar_opcion(opcion, mapa);
        mostrar_menu();
        opcion = elegir_opcion();
    }   

    delete mapa;

    return 0;
}