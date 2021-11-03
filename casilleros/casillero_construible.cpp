#include "casillero_construible.h"

Casillero_construible::Casillero_construible(int fila, int columna): Casillero(fila, columna){
    this->nombre = "T";
    this->edificio_construido = 0;
}

string Casillero_construible::obtener_nombre(){
    return nombre;
}

void Casillero_construible::mostrar_casillero(){
    if ( ! edificio_construido ){
        cout << " Soy un casillero construible y me encuentro vacio" << endl;
    }
    else{
        cout << " Soy un casillero construible y no me encuentro vacio" << endl;
        edificio_construido->mostrar_mensaje();
    }
}

void Casillero_construible::agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo){
    if ( ! edificio_construido ){
        if (nombre == "aserradero"){

            this->edificio_construido = new Aserradero(piedra, madera, metal, maximo);

        }
        else if ( nombre == "escuela"){ 

            this->edificio_construido = new Escuela( piedra, madera, metal, maximo);

        }
        else if ( nombre == "fabrica"){

            this->edificio_construido = new Fabrica( piedra, madera, metal, maximo);

        }
        else if ( nombre == "mina"){

            this->edificio_construido = new Mina( piedra, madera, metal, maximo);

        }
        else if ( nombre == "obelisco"){

            this->edificio_construido = new Obelisco( piedra, madera, metal, maximo);

        }
        else if ( nombre == "planta electrica"){

            this->edificio_construido = new Planta_electrica( piedra, madera, metal, maximo);

        }
    } else {
        cout << "\n El casillero ya esta ocupado. \n" << endl;
    }

}


void Casillero_construible::agregar_material(string nombre, int cantidad){
    cout << "\nEste es un casillero construible, si salio esto, se rompio algo\n" << endl;
}

string Casillero_construible::obtener_nombre_edificio(){

    string nombre_edificio = "";
    if ( edificio_construido ){
        nombre_edificio = edificio_construido->obtener_nombre();
    }
    return nombre_edificio;

}

string Casillero_construible::obtener_diminutivo_edificio(){

    string diminutivo = "";
    if ( edificio_construido ){
        diminutivo = edificio_construido->obtener_diminutivo() ;
    }
    return diminutivo;
}

string Casillero_construible::obtener_diminutivo_material(){
    return "";
}

void Casillero_construible::eliminar_edificio(){
    delete edificio_construido;
    edificio_construido = 0;

}

bool Casillero_construible::existe_edificio(){
    bool existe = false;
    if ( edificio_construido ){
        existe = true;
    }
    return existe;
}

bool Casillero_construible::existe_material(){
    return true;
}

void Casillero_construible::mostrar_coordenadas_edificio(string nombre){

    if ( edificio_construido ){

        if ( nombre == edificio_construido->obtener_nombre()){

            cout << " - (" << fila + 1 << "," << columna + 1 << ") " << endl;

        }

    }
}

Casillero_construible::~Casillero_construible(){
    if ( edificio_construido ){
        delete edificio_construido;
        cout << "corriendo destructor de casillero construible" << endl;
    }
    edificio_construido = 0;
}
