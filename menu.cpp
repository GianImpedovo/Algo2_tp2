#include "menu.h"

Menu::Menu(){

    this->opcion = 1;

}

int Menu::mostrar_opcion(){
    return opcion;
}

void Menu::mostrar_menu(){
    cout << "1. Construir edificio por nombre. " << endl;
    cout << "2. Listar los edificios construidos." << endl;
    cout << "3. Listar todos los edificios." << endl;
    cout << "4. Demoler un edificio por coordenada." << endl;
    cout << "5. Mostrar mapa." << endl;
    cout << "6. Consultar coordenada." << endl;
    cout << "7. Mostrar inventario." << endl;
    cout << "8. Recolectar recursos producidos." << endl;
    cout << "9. Lluvia de recursos." << endl;
    cout << "10. Guardar y salir." << endl;



}

bool Menu::opcion_valida(){
    if ( opcion <= 0 || opcion > 10){
        return false;
    }else {
        return true;
    }
}

void Menu::elegir_opcion(){
    // validar la opcion elegida por el usuario: 
    int opcion;

    cout << " -> ";
    cin >> opcion;

    while (!opcion_valida()){
        cout << "Ingrese una opcion valida : ";
        cin >> opcion;
    }

    this->opcion = opcion;

}

void Menu::procesar_opcion(Lista_edificio l_edificios){
    int edificio_elegido;
    string nombre_edificio;

    switch (opcion)
    {
    case CONSTRUIR_EDIFICIO:
        cout << "1" << endl;
        break;

    case LISTAR_EDIFICIOS_CONSTRUIDOS:
        cout << "2" << endl;
        break;

    case LISTAR_TODOS_EDIFICIOS:
        // 3)
        l_edificios.listar_todos_edificios();
        break;

    case DEMOLER_EDIFICIO_COORDENADA:
        cout << "4" << endl;
        break;

    case MOSTRAR_MAPA:
        cout << "5" << endl;
        break;

    case CONSULTAR_COORDENADA:
        cout << "6" << endl;
        break;

    case MOSTRAR_INVENTARIO:
        cout << "7" << endl;
        break;

    case RECOLECTAR_RECURSOS_PRODUCIDOS:
        cout << "8" << endl;
        break;

    case LLUVIAR_RECURSOS:
        cout << "9" << endl;
        break;



    
    }
}
