#include "lista_edificio.h"


Lista_edificio::Lista_edificio(){
    this->cantidad_edificios = 0;
    this->edificios_posibles = nullptr;
}

void Lista_edificio::procesar_arhivo(){
ifstream nuevo_archivo;
    nuevo_archivo.open(ARCHIVO_EDIFICIO);

    string nombre_edificio;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maximo;

    while (nuevo_archivo >> nombre_edificio){
        nuevo_archivo >> cantidad_piedra;
        nuevo_archivo >> cantidad_madera;
        nuevo_archivo >> cantidad_metal;
        nuevo_archivo >> maximo;

        Edificio * nuevo_edificio;

        nuevo_edificio = new Edificio(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo);


        int cantidad_vieja = cantidad_edificios;
        Edificio ** vector_edificio = new Edificio * [ cantidad_vieja + 1]; 

        for ( int i = 0; i < cantidad_edificios; i++){
            vector_edificio[i] = edificios_posibles[i];
        }
        vector_edificio[ cantidad_vieja ] = nuevo_edificio;

        if ( cantidad_edificios != 0){
            delete [] edificios_posibles; 
        }
        edificios_posibles = vector_edificio;
        cantidad_edificios++;
    }

    nuevo_archivo.close();
}

void Lista_edificio::mostrar_cantidad_edificios(){
    cout << cantidad_edificios << endl;
}

void Lista_edificio::listar_todos_edificios(){
    for ( int i = 0; i < cantidad_edificios; i++){
        cout << edificios_posibles[i]->mostrar_nombre() << " "
        << edificios_posibles[i]->mostrar_cantidad_piedra() << " "
        << edificios_posibles[i]->mostrar_canitdad_madera() << " "
        << edificios_posibles[i]->mostrar_cantidad_metal() << " "
        << edificios_posibles[i]->mostrar_maximo_construir() << " " << endl;

    }
}

void Lista_edificio::guardar_datos(){
    ofstream archivo;
    archivo.open(ARCHIVO_EDIFICIO);

    for (int i = 0; i < cantidad_edificios; i++){
        archivo << edificios_posibles[i] ->mostrar_nombre() << ' '
                << edificios_posibles[i] ->mostrar_cantidad_piedra() << ' '
                << edificios_posibles[i] ->mostrar_canitdad_madera() << ' '
                << edificios_posibles[i] ->mostrar_cantidad_metal() << ' '
                << edificios_posibles[i] ->mostrar_maximo_construir() << '\n';
    }

    archivo.close();

}

Lista_edificio::~Lista_edificio(){
    for ( int i = 0; i < cantidad_edificios; i++){
        delete edificios_posibles[i];
    }
    delete [] edificios_posibles;
    cantidad_edificios = 0;
    cout << "Ejecutando destructor" << endl;

}