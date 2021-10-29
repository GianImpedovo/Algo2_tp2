#include <iostream>
#include "menu.h"
#include "caracteristicas_edificios.h"
#include "mapa.h"
#include "edificio.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;
    Caracteristicas_edificio * caracteristicas = new Caracteristicas_edificio;
    caracteristicas->procesar_arhivo();

    mapa->procesar_archivo_ubicaciones();

    //mostrar_menu();
    //int opcion = elegir_opcion();
//
    //while ( opcion != GUARDAR_SALIR ){
//
    //    procesar_opcion(opcion, mapa, caracteristicas);
    //    mostrar_menu();
    //    opcion = elegir_opcion();
    //}
//
    delete mapa;
    //delete caracteristicas;
//
    return 0;
}