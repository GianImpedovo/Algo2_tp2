#include "inventario.h"
#include <iostream>

int main (){

    Inventario *inventario = new Inventario;
    inventario -> cargar_materiales();
    for (int i = 0; i < inventario->obtener_cantidad_de_materiales(); i++ ){
        
        cout << inventario -> obtener_material_de_lista_materiales(i) -> obtener_nombre()<< " "
        <<inventario -> obtener_material_de_lista_materiales(i) -> obtener_cantidad_disponible()<<endl;
        }

    delete inventario;

    return 0;
}