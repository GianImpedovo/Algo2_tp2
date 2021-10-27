#include <iostream>
#include "caracteristicas_edificios.h"
#include "mapa.h"
#include "edificio.h"

using namespace std;




int main(){

    Mapa mapa;
    Caracteristicas_edificio * lista_edificios = new Caracteristicas_edificio;

    lista_edificios->procesar_arhivo();

    mapa.procesar_archivo_ubicaciones(lista_edificios);


    return 0;
}