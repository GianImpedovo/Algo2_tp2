#include "mapa.h"

Mapa::Mapa(){

    this->lista_edificios = new Caracteristicas_edificio;
    lista_edificios->procesar_arhivo();

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

void Mapa::mostrar_mapa(){
    lista_edificios->listar_todos_edificios();
}

void Mapa::procesar_archivo_ubicaciones(){

    ifstream archivo;
    archivo.open(ARCHIVO_UBICACIONES);

    string nombre;
    string barra;
    string fila;
    string columna;

    while( archivo >> nombre ){
        getline(archivo, barra, ' ');
        getline(archivo, barra, '(');
        getline(archivo, fila, ',');
        getline(archivo, barra, ' ');
        getline(archivo, columna, ')');

        // mapa[stoi(fila)][stoi(columna)]
        if ( mapa[stoi(fila)][stoi(columna)]->mostrar_nombre() == "T"){
            mapa[stoi(fila)][stoi(columna)]->agregar_edificio();
        }


    }

    archivo.close();

}

void Mapa::mostrar_filas(){
    cout << cantidad_filas << endl;
}

void Mapa::mostrar_columnas(){
    cout << cantidad_columnas << endl;
}

void Mapa::buscar_coordenada(){
    int fila = 0;
    int columna = 0;

    cout << "\nIngrese la fila -> ";
    cin >> fila;
    cout << "Ingrese la columna -> ";
    cin >> columna;
    cout << "\n";
    mapa[fila][columna]->mostrar_casillero() ;
    cout << "\n";
}

Mapa::~Mapa(){
    for ( int i = 0; i < cantidad_filas; i++){
        delete [] mapa[i];
    }
    delete [] mapa;
    this->mapa = nullptr;
    cout << "ejecutando destructor" << endl;
}