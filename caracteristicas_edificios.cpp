#include "caracteristicas_edificios.h"


Caracteristicas_edificio::Caracteristicas_edificio(){
    this->cantidad_edificios = 0;
    this->edificios_posibles = nullptr;
}

int Caracteristicas_edificio::obtener_cantidad_edificios(){
    return cantidad_edificios;
}

Edificio * Caracteristicas_edificio::obtener_edificio(int posicion){
    return edificios_posibles[posicion];
}

void Caracteristicas_edificio::procesar_arhivo(){
ifstream nuevo_archivo;
    nuevo_archivo.open(ARCHIVO_EDIFICIO);

    string nombre_edificio;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maximo;

    Edificio * nuevo_edificio;

    while (nuevo_archivo >> nombre_edificio){
        nuevo_archivo >> cantidad_piedra;
        nuevo_archivo >> cantidad_madera;
        nuevo_archivo >> cantidad_metal;
        nuevo_archivo >> maximo;

        if (nombre_edificio == "aserradero"){

            nuevo_edificio = new Aserradero(cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        }
        else if ( nombre_edificio == "escuela"){

            nuevo_edificio = new Escuela( cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        }
        else if ( nombre_edificio == "fabrica"){

            nuevo_edificio = new Fabrica( cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        }
        else if ( nombre_edificio == "mina"){

            nuevo_edificio = new Mina( cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        }
        else if ( nombre_edificio == "obelisco"){

            nuevo_edificio = new Obelisco( cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        }
        else if ( nombre_edificio == "planta electrica"){

            nuevo_edificio = new Planta_electrica( cantidad_piedra, cantidad_madera, cantidad_metal, maximo);

        }


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

void Caracteristicas_edificio::listar_todos_edificios(){
    cout << "\n";
    cout << "\t\t###   Listado de todos los edificios :   ###" << endl;
    cout << "\nOrden de los elementos :  " << endl;
    cout << "\n -> nombre / piedra / madera / metal / cuantos puedo construir " << endl;
    cout << "_________________________________________________________________" << endl;
    for ( int i = 0; i < cantidad_edificios; i++){
        cout << "\n";
        cout << " -> " << edificios_posibles[i]->obtener_nombre() << " "
        << edificios_posibles[i]->obtener_cantidad_piedra() << " "
        << edificios_posibles[i]->obtener_cantidad_madera() << " "
        << edificios_posibles[i]->obtener_cantidad_metal() << " "
        << edificios_posibles[i]->obtener_cuantos_puedo_construir() << endl;
        cout << "\n";
        cout << "_________________________________________________________________" << endl;
    }
    cout << "\n";
}


// destructor
void Caracteristicas_edificio::guardar_datos(){
    ofstream archivo;
    archivo.open(ARCHIVO_EDIFICIO);

    for (int i = 0; i < cantidad_edificios; i++){
        archivo << edificios_posibles[i] ->obtener_nombre() << ' '
                << edificios_posibles[i] ->obtener_cantidad_piedra() << ' '
                << edificios_posibles[i] ->obtener_cantidad_madera() << ' '
                << edificios_posibles[i] ->obtener_cantidad_metal() << ' '
                << edificios_posibles[i] ->obtener_maximo_construir() << '\n';
    }

    archivo.close();

}

Caracteristicas_edificio::~Caracteristicas_edificio(){
    for ( int i = 0; i < cantidad_edificios; i++){
        delete edificios_posibles[i];
        cantidad_edificios--;
    }
    delete [] edificios_posibles;
    edificios_posibles = nullptr;
    cout << "Ejecutando destructor" << endl;

}