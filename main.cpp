#include <iostream>
#include "menu.h"
#include "mapa.h"
#include "lista_edificio.h"
#include "edificio.h"

using namespace std;




int main(){

    
    Lista_edificio l_edificios;
    l_edificios.procesar_arhivo();

    Menu menu;
    menu.mostrar_menu();
    menu.elegir_opcion();

    while ( menu.mostrar_opcion() != GUARDAR_SALIR ){

        menu.procesar_opcion(l_edificios);

        menu.mostrar_menu();
        menu.elegir_opcion();

    }


    // Prueba de la lista de edificio:
    //l_edificios.procesar_arhivo();
    //l_edificios.listar_todos_edificios();

    //Mapa andy;
    //andy.mostrar_filas();
    //andy.mostrar_columnas();
    //andy.mostrar_mapa();

    return 0;
}