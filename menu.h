#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

int const CONSTRUIR_EDIFICIO = 1;
int const LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
int const LISTAR_TODOS_EDIFICIOS = 3;
int const DEMOLER_EDIFICIO_COORDENADA = 4;
int const MOSTRAR_MAPA = 5;
int const CONSULTAR_COORDENADA = 6;
int const MOSTRAR_INVENTARIO = 7;
int const RECOLECTAR_RECURSOS_PRODUCIDOS = 8;
int const LLUVIAR_RECURSOS = 9;
int const GUARDAR_SALIR = 10;




class Menu {
private:
    int opcion;

public:
    Menu();
    int mostrar_opcion();
    void elegir_opcion();
    void mostrar_menu();
    bool opcion_valida();
    void procesar_opcion();

};




#endif // MENU_H