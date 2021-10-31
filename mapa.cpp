#include "mapa.h"

Mapa::Mapa(){

    this->usuario_inventario = new Inventario;
    usuario_inventario->cargar_materiales();

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

void Mapa::mostrar_inv(){
    usuario_inventario->mostrar_inventario();
}

void Mapa::generar_matriz(){
    this->mapa = new Casillero ** [ cantidad_filas ];
    for ( int i = 0; i < cantidad_filas; i++){
        mapa[i] = new Casillero * [cantidad_columnas];
    }

}

void Mapa::listar_edificios_construidos(){
    cout << "\n";
    cout << "\t\t###   Listado de los edificio construidos :   ### " << endl;
    cout << "\nOrden de los elemenots : " << endl;
    cout << " -> nombre : cantidad construidos " << endl;
    cout << " - coordenede \n - coordenada\n ..." << endl;
    cout << "\n" ;
    cout << "___________________________________________________" << endl;
    cout << "\n" ;
    for (int i = 0; i < lista_edificios->obtener_cantidad_edificios(); i++){

        int cantidad_constuidos = lista_edificios->obtener_edificio(i)->obtener_cantidad_construidos();
        string nombre_edificio = lista_edificios->obtener_edificio(i)->obtener_nombre();

        if ( cantidad_constuidos > 0 ){

            cout << " -> "<< nombre_edificio << " : " << cantidad_constuidos << endl;
            mostrar_coordenadas(nombre_edificio);

        }

    }
    cout << "\n" ;
    cout << "___________________________________________________" << endl;
    cout << "\n" ;
}

void Mapa::mostrar_coordenadas(string nombre){
    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0 ; j < cantidad_columnas; j++){
            
            bool es_construible = "T" == mapa[i][j]->obtener_nombre();
            if ( es_construible ){
                mapa[i][j]->mostrar_coordenadas_edificio(nombre);
            }
        }
    }
}

void Mapa::mostrar_todos_edificios(){
    lista_edificios->listar_todos_edificios();
}

void Mapa::demoler_edificio(){

    cout << "\n\t\t ###   En esta seccion podra demoler un EDIFICIO :   ###" << endl;
    
    cout << "\n";
    int fila, columna;
    cout << " Ingrese las coordenadas del edificio a demoler : \n" << endl;
    cout << " fila -> ";
    cin >> fila;
    cout << " columna -> ";
    cin >> columna;

    while ( fila > cantidad_filas || columna > cantidad_columnas ){
        cout << "\n Ingrese una vez mas los datos ya que estos superan los limites permitidos : " << endl;
        cout << "\n fila -> ";
        cin >> fila;
        cout << " columna -> ";
        cin >> columna;
    }

    int mitad_piedra, mitad_madera, mitad_metal;

    string nombre_edificio = mapa[fila][columna]->obtener_nombre_edificio();

    if ( nombre_edificio != ""){
        for (int i = 0; i < lista_edificios->obtener_cantidad_edificios(); i++){

            string edificio_en_lista = lista_edificios->obtener_edificio(i)->obtener_nombre();

            if (edificio_en_lista == nombre_edificio){
                lista_edificios->obtener_edificio(i)->restar_cantidad();

                mitad_piedra = lista_edificios->obtener_edificio(i)->obtener_mitad_piedra();
                mitad_madera = lista_edificios->obtener_edificio(i)->obtener_mitad_madera();
                mitad_metal = lista_edificios->obtener_edificio(i)->obtener_mitad_metal();

            }

        }
        cout << "\n------------------------------\n" << endl;
        cout << "\nMateriales obtenidos \n" << endl;
        cout << "Piedra : " << mitad_piedra << endl;
        cout << "Madera : " << mitad_madera << endl;
        cout << "Metal : " << mitad_metal << endl;
        cout << "\n------------------------------\n" << endl;

        usuario_inventario->devolver_materiales(mitad_piedra, mitad_madera, mitad_metal);

        mapa[fila][columna]->eliminar_edificio();

        cout << "\n\t\t ###   El edificio : " << nombre_edificio << ", ha sido DEMOLIDO exitosamente !   ###\n" << endl;

    } else {
        cout << "\n En la coordenada ingresada no existe ningun edificio ...\n" << endl;
    }


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

        int madera;
        int piedra; 
        int metal;
        int maximo;

        for ( int i = 0; i < lista_edificios->obtener_cantidad_edificios(); i++){
            if ( lista_edificios->obtener_edificio(i)->obtener_nombre() == nombre){
                piedra = lista_edificios->obtener_edificio(i)-> obtener_cantidad_piedra();
                madera = lista_edificios->obtener_edificio(i)->obtener_cantidad_madera();
                metal = lista_edificios->obtener_edificio(i)->obtener_cantidad_metal();
                maximo = lista_edificios->obtener_edificio(i)->obtener_maximo_construir();

                mapa[stoi(fila)][stoi(columna)]->agregar_edificio(nombre, piedra, madera, metal, maximo);

                lista_edificios->obtener_edificio(i) ->sumar_cantidad();

                //cout << lista_edificios->obtener_edificio(i)->obtener_nombre() << endl;
            }
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

void Mapa::mostrar_mapa(){
    cout << "\n";
    for (int i = 0; i < cantidad_filas ; i++){
        for ( int j = 0; j < cantidad_columnas; j++){
           cout << mapa[i][j]->obtener_nombre()
                << mapa[i][j]->obtener_nombre_edificio() 
                << " ";
        }
        cout << "\n";
    }
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