#include "caracteristicas_edificios.h"

// Constructor
Caracteristicas_edificio::Caracteristicas_edificio(){
    this->cantidad_edificios = 0;
    this->edificios_posibles = 0;
}

// Guardo las caracteristicas de los edificios al procesar el archivo
void Caracteristicas_edificio::cargar_edificios(){
ifstream nuevo_archivo;
    nuevo_archivo.open(ARCHIVO_EDIFICIO);

    string nombre_edificio, segundo_nombre, cantidad_piedra, cantidad_madera, cantidad_metal, maximo;

    int piedra, madera, metal, maximo_construir;

    Edificio * nuevo_edificio;

    while (nuevo_archivo >> nombre_edificio){
        if ( nombre_edificio == "planta"){
            nuevo_archivo >> segundo_nombre;
            nuevo_archivo >> cantidad_piedra;
            nuevo_archivo >> cantidad_madera;
            nuevo_archivo >> cantidad_metal;
            nuevo_archivo >> maximo;

            nombre_edificio += " " + segundo_nombre;

        } else {
            nuevo_archivo >> cantidad_piedra;
            nuevo_archivo >> cantidad_madera;
            nuevo_archivo >> cantidad_metal;
            nuevo_archivo >> maximo;

        }

        piedra = stoi(cantidad_piedra);
        madera = stoi(cantidad_madera);
        metal = stoi(cantidad_metal);
        maximo_construir = stoi(maximo);

        if (nombre_edificio == ASERRADERO){

            nuevo_edificio = new Aserradero(piedra, madera, metal, maximo_construir);

        }
        else if ( nombre_edificio == ESCUELA){

            nuevo_edificio = new Escuela( piedra, madera, metal, maximo_construir);

        }
        else if ( nombre_edificio == FABRICA){

            nuevo_edificio = new Fabrica( piedra, madera, metal, maximo_construir);

        }
        else if ( nombre_edificio == MINA){

            nuevo_edificio = new Mina( piedra, madera, metal, maximo_construir);

        }
        else if ( nombre_edificio == OBELISCO){

            nuevo_edificio = new Obelisco( piedra, madera, metal, maximo_construir);

        }
        else if ( nombre_edificio == PLANTA_ELECTRICA){

            nuevo_edificio = new Planta_electrica( piedra, madera, metal, maximo_construir);

        }
        agregar_edificio(nuevo_edificio);

    }

    nuevo_archivo.close();
}

// Agrego el edificio nuevo a la lista de edificios
void Caracteristicas_edificio::agregar_edificio(Edificio * nuevo_edificio){
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

// Obtengo la cantidad de edificios
int Caracteristicas_edificio::obtener_cantidad_edificios(){
    return cantidad_edificios;
}

// Obtener posicion del edificio en el vector
int Caracteristicas_edificio::obtener_posicion_edificio(string nombre){
    int pos;
    for ( int i = 0; i < cantidad_edificios ; i++){
        if ( nombre == edificios_posibles[i]->obtener_nombre()){
            pos = i;
        }
    }return pos;
}

// Obtengo el edificio requerido  
Edificio * Caracteristicas_edificio::obtener_edificio(int posicion){
    return edificios_posibles[posicion];
}

// Lista todos los edificios
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

// Existe edificio 
bool Caracteristicas_edificio::existe_el_edificio(string nombre){
    bool existe = false;
    for (int i = 0; i < cantidad_edificios; i++){
        string nombre_buscado = edificios_posibles[i]->obtener_nombre();
        if ( nombre_buscado == nombre ){
            existe = true;
        }
    }

    return existe;
}

// Spuera maximo
bool Caracteristicas_edificio::supera_maximo(string nombre){
    bool supera_max = true;
    int maximo , construidos, restantes;
    for ( int i = 0; i < cantidad_edificios ; i++){

        Edificio * edificio_buscado = obtener_edificio(i);
        string nombre_edificio = edificio_buscado->obtener_nombre();

        if ( nombre_edificio == nombre ){

            maximo = edificio_buscado->obtener_maximo_construir();
            construidos = edificio_buscado->obtener_cantidad_construidos();

            restantes = maximo - construidos;

            if ( restantes > 0 ){
                supera_max = false;
            } 
        }
        
    }

    return supera_max;
}

// Destructor 
Caracteristicas_edificio::~Caracteristicas_edificio(){

    int total = cantidad_edificios;
    for ( int i = 0; i < total; i++){

        delete edificios_posibles[i];
        cantidad_edificios--;
    }
    delete [] edificios_posibles;
    edificios_posibles = nullptr;

}