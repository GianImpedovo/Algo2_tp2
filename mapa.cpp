#include "mapa.h"

Mapa::Mapa(){
    ifstream arch;
    arch.open(ARCHIVO_MAPA);

    for ( int i = 0 ; i < 1 ; i++){
        arch >> cantidad_filas; 
        arch >> cantidad_columnas;
    }
    string nombre;

    generar_matriz();

    for ( int i = 0; i < cantidad_filas; i++){
        for (int j = 0; j < cantidad_columnas; j++){
            arch >> nombre ;

            if ( nombre == "T") {
                mapa[i][j] = new Casillero_construible(i, j);
            } 
            if (nombre == "C") {
                mapa[i][j] = new Casillero_transitable(i,j);
            }
            if (nombre == "L") {
                mapa[i][j] = new Casillero_inaccesible(i,j);
            }

        }
    }

    arch.close();
}

void Mapa::generar_matriz(){
    this->mapa = new Casillero ** [ cantidad_filas ];
    for ( int i = 0; i < cantidad_filas; i++){
        mapa[i] = new Casillero * [cantidad_columnas];
    }

}


void Mapa::mostrar_filas(){
    cout << cantidad_filas << endl;
}

void Mapa::mostrar_columnas(){
    cout << cantidad_columnas << endl;
}

void Mapa::mostrar_mapa(){
    for (int i = 0 ; i < cantidad_filas; i++){
        for (int j = 0; j < cantidad_columnas; j++){
            cout << mapa[i][j]->mostrar_nombre() << " ";
        }
        cout << "\n";
    }
}

void Mapa::buscar_coordenada(int fila, int columna){
    mapa[fila][columna]->mostrar_casillero() ;
}

Mapa::~Mapa(){
    for ( int i = 0; i < cantidad_filas; i++){
        delete [] mapa[i];
    }
    delete [] mapa;
    this->mapa = nullptr;
    cout << "ejecutando destructor" << endl;
}