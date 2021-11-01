#include "mapa.h"

Mapa::Mapa(){

    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->mapa = nullptr;
    this->lista_edificios = nullptr;
    this->usuario_inventario = nullptr;

}

void Mapa::ingreso_datos_mapa(){

    this->usuario_inventario = new Inventario;
    usuario_inventario->cargar_materiales();

    this->lista_edificios = new Caracteristicas_edificio;
    lista_edificios->cargar_edificios();

    procesar_archivo_mapa();
    procesar_archivo_ubicaciones();
}

void Mapa::procesar_archivo_mapa(){
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

void Mapa::procesar_archivo_ubicaciones(){

    ifstream archivo;
    archivo.open(ARCHIVO_UBICACIONES);

    string nombre, barra, fila, columna;

    while( archivo >> nombre ){
        getline(archivo, barra, ' ');
        getline(archivo, barra, '(');
        getline(archivo, fila, ',');
        getline(archivo, barra, ' ');
        getline(archivo, columna, ')');

        int madera, piedra, metal, maximo;

        for ( int i = 0; i < lista_edificios->obtener_cantidad_edificios(); i++){
            if ( lista_edificios->obtener_edificio(i)->obtener_nombre() == nombre){
                piedra = lista_edificios->obtener_edificio(i)-> obtener_cantidad_piedra();
                madera = lista_edificios->obtener_edificio(i)->obtener_cantidad_madera();
                metal = lista_edificios->obtener_edificio(i)->obtener_cantidad_metal();
                maximo = lista_edificios->obtener_edificio(i)->obtener_maximo_construir();

                mapa[stoi(fila) - 1][stoi(columna) - 1]->agregar_edificio(nombre, piedra, madera, metal, maximo);

                lista_edificios->obtener_edificio(i) ->sumar_cantidad();

            }
        }


    }

    archivo.close();

}

// ---------------------------------------------

// 1)
void Mapa::construir_edificio_nombre(){
    // tener la cantidad de materiales necesarios []
    string nombre_nuevo;
    cout << "\n -> Ingrese el nombre del nuevo edificio que desea construir : ";
    cin >> nombre_nuevo;
    
    bool existe_edificio = lista_edificios->existe_el_edificio(nombre_nuevo);
    bool supera_max = lista_edificios->supera_maximo(nombre_nuevo);

    if ( existe_edificio ){

        int pos_edificio = lista_edificios->obtener_posicion_edificio(nombre_nuevo);
        int piedra_necesaria, madera_necesaria, metal_necesario, maximo;

        piedra_necesaria = lista_edificios->obtener_edificio(pos_edificio)->obtener_cantidad_piedra();
        madera_necesaria = lista_edificios->obtener_edificio(pos_edificio)->obtener_cantidad_madera();
        metal_necesario = lista_edificios->obtener_edificio(pos_edificio)->obtener_cantidad_metal();
        maximo = lista_edificios->obtener_edificio(pos_edificio)->obtener_maximo_construir();

        if ( ! supera_max ){

            bool alcanzan_materiales = usuario_inventario->alcanzan_materiales(piedra_necesaria, madera_necesaria, metal_necesario);

            if ( alcanzan_materiales ){

                construir_edificio(nombre_nuevo, piedra_necesaria, madera_necesaria, metal_necesario, maximo);
                lista_edificios->obtener_edificio(pos_edificio)->sumar_cantidad();

            } else {
                cout << "\n No alcanzan los materiales necesarios para la construccion . " << endl;
            }

        } else {
            cout << "\n No se pueden construir mas " << nombre_nuevo << " ya que supera el maximo permitido. \n" << endl; 
        }

    } else {
        cout << "\n El edificio buscado NO existe . \n" << endl;
    }
}

void Mapa::construir_edificio(string nombre_nuevo, int piedra, int madera , int metal, int maximo){
    int fila , columna;
    cout << "\n Construccion del edificio \n" << endl;
    cout << " fila -> ";
    cin >> fila;
    cout << " columna -> ";
    cin >> columna;

    // No me agrega el edificio , error con memoria dinamica 
    mapa[fila - 1][columna - 1]->agregar_edificio(nombre_nuevo, piedra, madera, metal, maximo);

}

// 2)
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

// 3)
void Mapa::mostrar_todos_edificios(){
    lista_edificios->listar_todos_edificios();
}

// 4)
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

    string nombre_edificio = mapa[fila][columna]->obtener_nombre_edificio();

    if ( nombre_edificio != ""){

        obtengo_materiales_elimino_edificio(nombre_edificio, fila, columna);
        cout << "\n\t\t ###   El edificio : " << nombre_edificio << ", ha sido DEMOLIDO exitosamente !   ###\n" << endl;

    } else {
        cout << "\n En la coordenada ingresada no existe ningun edificio ...\n" << endl;
    }


}

void Mapa::obtengo_materiales_elimino_edificio(string nombre_edificio, int fila, int columna){

    int mitad_piedra, mitad_madera, mitad_metal;

    for (int i = 0; i < lista_edificios->obtener_cantidad_edificios(); i++){

        string edificio_en_lista = lista_edificios->obtener_edificio(i)->obtener_nombre();

        if (edificio_en_lista == nombre_edificio){
            lista_edificios->obtener_edificio(i)->restar_cantidad();

            mitad_piedra = lista_edificios->obtener_edificio(i)->obtener_mitad_piedra();
            mitad_madera = lista_edificios->obtener_edificio(i)->obtener_mitad_madera();
            mitad_metal = lista_edificios->obtener_edificio(i)->obtener_mitad_metal();

        }

    }

    devolver_materiales(mitad_piedra, mitad_madera, mitad_metal);

    mapa[fila][columna]->eliminar_edificio();
}

void Mapa::devolver_materiales(int piedra, int madera, int metal){

    cout << "\n------------------------------\n" << endl;
    cout << "\nMateriales obtenidos \n" << endl;
    cout << "Piedra : " << piedra << endl;
    cout << "Madera : " << madera << endl;
    cout << "Metal : " << metal << endl;
    cout << "\n------------------------------\n" << endl;

    usuario_inventario->devolver_materiales(piedra, madera, metal);

}

// 5)
void Mapa::mostrar_mapa(){
    cout << "\n";
    for (int i = 0; i < cantidad_filas ; i++){
        for ( int j = 0; j < cantidad_columnas; j++){
           cout << mapa[i][j]->obtener_nombre()
                << mapa[i][j]->obtener_diminutivo_edificio()
                << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// 6)
void Mapa::consultar_coordenada(){
    int fila , columna;

    cout << "\nIngrese la fila -> ";
    cin >> fila;
    cout << "Ingrese la columna -> ";
    cin >> columna;
    cout << "\n";
    mapa[fila - 1][columna - 1]->mostrar_casillero() ;
    cout << "\n";
}

// 7)
void Mapa::mostrar_inv(){
    usuario_inventario->mostrar_inventario();
}

// 8) 
void Mapa::recolectar_recursos_producidos(){
    int piedra = 0;
    int madera = 0;
    int metal = 0;
    int cantidad_edificios, total_brindado , cantidad_construidos, cantidad_a_brindar;
    string nombre_edificio;

    cantidad_edificios = lista_edificios->obtener_cantidad_edificios();

    cout << "estoy en recolectar recursos" << endl;

    for ( int i = 0; i < cantidad_edificios; i++){

        Edificio * edificio_solicitado = lista_edificios->obtener_edificio(i); 

        nombre_edificio = edificio_solicitado->obtener_nombre();
        cantidad_construidos = edificio_solicitado->obtener_cantidad_construidos();
        cantidad_a_brindar = edificio_solicitado->obtener_cantidad_brindada();

        total_brindado = cantidad_construidos * cantidad_a_brindar;

        if ( nombre_edificio == "mina"){

            piedra += total_brindado;

        } else if ( nombre_edificio == "aserradero"){
            
            madera += total_brindado;

        } else if ( nombre_edificio == "fabrica"){

            metal += total_brindado;
        }
    }

    devolver_materiales(piedra, madera, metal);
}

// Destructor
Mapa::~Mapa(){
    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0; j < cantidad_columnas ; j++){
            mapa[i][j]->~Casillero();
            delete mapa[i][j];
        }
        delete mapa[i];
    }
    delete [] mapa;
    this->mapa = nullptr;

    this->lista_edificios->~Caracteristicas_edificio();
    this->usuario_inventario->~Inventario();

}