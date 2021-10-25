#include <iostream>
#include "menu.h"
#include "lista_edificio.h"
#include "edificio.h"

using namespace std;




int main(){

    /*
    Menu menu;
    menu.mostrar_menu();
    menu.elegir_opcion();

    while ( menu.mostrar_opcion() != GUARDAR_SALIR ){

        menu.mostrar_menu();
        menu.elegir_opcion();
    }
    */

    Lista_edificio l_edificios;


    l_edificios.mostrar_edificios();
    

    return 0;
}