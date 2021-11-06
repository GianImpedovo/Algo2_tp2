#include "mapa.h"
#include "vector_ints.h"

Mapa::Mapa(){

    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    for ( int i = 0; i < cantidad_filas; i++){
        for (int j = 0; j < cantidad_columnas; j++){
            mapa[i][j] = 0;
        }
    }
    this->lista_edificios = 0;
    this->usuario_inventario = 0;

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

    string filas, columnas;
    for ( int i = 0 ; i < 1 ; i++){
        arch >> filas; 
        arch >> columnas;

        cantidad_filas = stoi(filas);
        cantidad_columnas = stoi(columnas);
    }
    string nombre;

    generar_matriz();

    for ( int i = 0; i < cantidad_filas; i++){
        for (int j = 0; j < cantidad_columnas; j++){
            arch >> nombre ;
            if ( nombre == "T") {
                this->mapa[i][j] = new Casillero_construible(i, j);
            } 
            if (nombre == "C") {
                this->mapa[i][j] = new Casillero_transitable(i,j);
            }
            if (nombre == "L") {
                this->mapa[i][j] = new Casillero_inaccesible(i,j);
            }
        }
    }
    arch.close();
}

void Mapa::generar_matriz(){
    this->mapa = new Casillero ** [ cantidad_filas ];
    for ( int i = 0; i < cantidad_filas; i++){
        mapa[i] = new Casillero * [ cantidad_columnas ];
    }

}

void Mapa::procesar_archivo_ubicaciones(){

    ifstream archivo;
    archivo.open(ARCHIVO_UBICACIONES);

    string nombre,segundo_nombre, barra, fila, columna;

    while( archivo >> nombre ){
        if ( nombre == "planta"){
            archivo >> segundo_nombre;
            getline(archivo, barra, '(');
            getline(archivo, fila, ',');
            getline(archivo, barra, ' ');
            getline(archivo, columna, ')');

            nombre += " " + segundo_nombre;
        } else {
            getline(archivo, barra, '(');
            getline(archivo, fila, ',');
            getline(archivo, barra, ' ');
            getline(archivo, columna, ')');
        }

        if (nombre == "piedra" || nombre == "madera" || nombre == "metal"){
            mapa[stoi(fila)][stoi(columna)]->agregar_material(nombre,1);
        }

        int madera, piedra, metal, maximo;

        for ( int i = 0; i < lista_edificios->obtener_cantidad_edificios(); i++){
            if ( lista_edificios->obtener_edificio(i)->obtener_nombre() == nombre){
                piedra = lista_edificios->obtener_edificio(i)-> obtener_cantidad_piedra();
                madera = lista_edificios->obtener_edificio(i)->obtener_cantidad_madera();
                metal = lista_edificios->obtener_edificio(i)->obtener_cantidad_metal();
                maximo = lista_edificios->obtener_edificio(i)->obtener_maximo_construir();
                cout<<nombre<<endl;
                mapa[stoi(fila)][stoi(columna)]->agregar_edificio(nombre, piedra, madera, metal, maximo);

                lista_edificios->obtener_edificio(i) ->sumar_cantidad();

            }
        }


    }

    archivo.close();

}

void Mapa::validar_coordenada(int &fila, int &columna){
    cout << "\n Ingrese las coordenadas : \n" << endl;
    cout << "\n - Ingrese la fila -> ";
    cin >> fila;
    cout << " - Ingrese la columna -> ";
    cin >> columna;
    cout << "\n";

    while ( fila > cantidad_filas || columna > cantidad_columnas ){
        cout << "\n### Se ingresaron coordenadas fuera del limite : ";
        cout << "filas <= " << cantidad_filas << " - columnas <= " << cantidad_columnas << "###\n" << endl;

        cout << "\n Ingrese la fila -> ";
        cin >> fila;
        cout << " Ingrese la columna -> ";
        cin >> columna;
        cout << "\n";
    }
}

bool Mapa::aceptar_condiciones(){
    bool acepto = false;
    char opcion;
    cout << "\n Desea realizar la operacion ? ( s/n ) : ";
    cin >> opcion;
    cout << "\n";

    if ( opcion == 's'){
        acepto = true;
    }

    return acepto;
}

// -------------- DIVISION PUNTO POR PUNTO : MENU -------------------------------

// 1)
void Mapa::construir_edificio_nombre(){

    string nombre_nuevo;
    cout << "\n -> Ingrese el nombre del nuevo edificio que desea construir : ";
    cin.ignore();
    getline(cin , nombre_nuevo);

    bool existe_edificio = lista_edificios->existe_el_edificio(nombre_nuevo);

    if ( existe_edificio ){

        realizar_construccion(nombre_nuevo);

    } else {
        cout << "\n El edificio buscado NO existe . \n" << endl;
    }
}

void Mapa::realizar_construccion(string nombre_nuevo){

        int pos_edificio = lista_edificios->obtener_posicion_edificio(nombre_nuevo);

        int piedra_necesaria = lista_edificios->obtener_edificio(pos_edificio)->obtener_cantidad_piedra();
        int madera_necesaria = lista_edificios->obtener_edificio(pos_edificio)->obtener_cantidad_madera();
        int metal_necesario = lista_edificios->obtener_edificio(pos_edificio)->obtener_cantidad_metal();
        int maximo = lista_edificios->obtener_edificio(pos_edificio)->obtener_maximo_construir();

        bool supera_max = lista_edificios->supera_maximo(nombre_nuevo);
        bool alcanzan_materiales = usuario_inventario->alcanzan_materiales(piedra_necesaria, madera_necesaria, metal_necesario);

        if ( ! supera_max && alcanzan_materiales ){

            if ( aceptar_condiciones() ){

                int fila , columna;
                cout << "\n ### En esta seccion podra CONSTRUIR un EDIFICIO : ###\n" << endl;
                validar_coordenada( fila, columna);
                bool existe_edificio_construido = mapa[fila][columna]->existe_edificio();

                if ( ! existe_edificio_construido ){
                    mapa[fila][columna]->agregar_edificio(nombre_nuevo, piedra_necesaria, madera_necesaria, metal_necesario, maximo);
                    lista_edificios->obtener_edificio(pos_edificio)->sumar_cantidad();
                    usuario_inventario->utilizar_materiales(piedra_necesaria, madera_necesaria, metal_necesario);

                    cout << "\n ¡ FELICITACIONES : El edificio " << nombre_nuevo << " fue creado exitosamente ! \n" << endl;
                } else {
                    cout << "\n El casillero ya contiene un edificio .\n" << endl;
                }
            }
        } else {
            cout << "\n No se pueden construir mas " << nombre_nuevo << " ya que supera el maximo permitido. \n" << endl; 
        }

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

    cout << "\n\t\t ###   En esta seccion podra DEMOLER un EDIFICIO :   ###" << endl;
    
    cout << "\n";
    int fila, columna;
    cout << " Ingrese las coordenadas del edificio a demoler : \n" << endl;

    validar_coordenada( fila, columna);

    string nombre_edificio = mapa[fila][columna]->obtener_nombre_edificio();

    if ( nombre_edificio != ""){

        if ( aceptar_condiciones() ){

            obtengo_materiales_elimino_edificio(nombre_edificio, fila, columna);
            cout << "\n\t\t ###   El edificio : " << nombre_edificio << ", ha sido DEMOLIDO exitosamente !   ###\n" << endl;

        }

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

void Mapa::devolver_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida){

    cout << "\n------------------------------\n" << endl;
    cout << "\nMateriales obtenidos \n" << endl;
    cout << PIEDRA << " : " << piedra_obtenida << endl;
    cout << MADERA <<" : " << madera_obtenida << endl;
    cout << METAL << " : " << metal_obtenida << endl;
    cout << "\n------------------------------\n" << endl;

    usuario_inventario->devolver_materiales(piedra_obtenida, madera_obtenida, metal_obtenida);

}

// 5)
void Mapa::mostrar_mapa(){
    cout << "\n";
    for (int i = 0; i < cantidad_filas ; i++){
        for ( int j = 0; j < cantidad_columnas; j++){
           cout << mapa[i][j]->obtener_nombre()
                << mapa[i][j]->obtener_diminutivo_edificio()
                << mapa[i][j]->obtener_diminutivo_material()
                << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

// 6)
void Mapa::consultar_coordenada(){
    int fila , columna;

    validar_coordenada( fila, columna);

    mapa[fila][columna]->mostrar_casillero() ;
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

    for ( int i = 0; i < cantidad_edificios; i++){

        Edificio * edificio_solicitado = lista_edificios->obtener_edificio(i); 

        nombre_edificio = edificio_solicitado->obtener_nombre();
        cantidad_construidos = edificio_solicitado->obtener_cantidad_construidos();
        cantidad_a_brindar = edificio_solicitado->obtener_cantidad_brindada();

        total_brindado = cantidad_construidos * cantidad_a_brindar;

        if ( nombre_edificio == MINA){

            piedra += total_brindado;

        } else if ( nombre_edificio == ASERRADERO){
            
            madera += total_brindado;

        } else if ( nombre_edificio == FABRICA){

            metal += total_brindado;
        }
    }

    devolver_materiales(piedra, madera, metal);
}


void Mapa :: lluvia_recursos(){

    srand( (unsigned)time(0) );

    int cant_gen_piedras = generar_numero_random(1,3); 
    int cant_gen_maderas = generar_numero_random(0,1);
    int cant_gen_metales = generar_numero_random(2,4);
    
    int tot_materiales_gen = cant_gen_piedras + cant_gen_maderas + cant_gen_metales;
    
        
    cout << "Han llovido en el mapa " << tot_materiales_gen << " unidades de materiales: " <<endl
    <<cant_gen_piedras <<" unidades de piedra"<<endl
    <<cant_gen_maderas <<" unidades de madera" <<endl
    <<cant_gen_metales <<" unidades de metal " <<endl<<endl;
    // <<"`Presione 5 para ver el mapa y ver cuales cayeron en casilleros habilitados"<< endl<<endl;

    ejecutar_lluvia(tot_materiales_gen,cant_gen_piedras, cant_gen_maderas, cant_gen_metales);
}


int Mapa::generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);

}


void Mapa::consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, 
string &material_a_colocar ){
    if (cant_gen_piedras){
        material_a_colocar = "piedra";
        cant_gen_piedras --;

    } else if (cant_gen_maderas){
        material_a_colocar = "madera";
        cant_gen_maderas --;

    } else{
        material_a_colocar = "metal";
        cant_gen_metales --;
    }
}


void Mapa::ejecutar_lluvia(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales){
    
    Vector_ints *vector_filas = new Vector_ints;
    
    Vector_ints *vector_columnas = new Vector_ints;

    int pos = 0;
    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0; j < cantidad_columnas ; j++){
            if (mapa[i][j] -> obtener_nombre() =="C" && !( mapa[i][j] -> existe_material() ) ){    

                vector_filas->agregar_numero(i,pos+1, pos);
                vector_columnas->agregar_numero(j,pos+1, pos);
                
                pos+=1;
            }
        }
    }
    for( int i = 0; i < vector_filas->obtener_longitud(); i++){
        cout <<"(" <<vector_filas->obtener_numero(i) <<", ";
        cout << vector_columnas->obtener_numero(i) <<" )";
    }
    cout <<endl;
    cout << vector_filas ->obtener_longitud() <<" "<< vector_columnas->obtener_longitud() <<" ";
    
    
    string material_a_colocar = "";

    for (int i = 0; i < tot_materiales_gen; i++){
        
        consultar_material_a_colocar(cant_gen_piedras, cant_gen_maderas, cant_gen_metales, material_a_colocar);
        if ( vector_filas->obtener_longitud() < 0 ){
            int pos_coordenada =  generar_numero_random( 0, vector_filas->obtener_longitud() - 1);
            //Es la misma para ambos vectores pues hay tantas filas como columnaas ya q pos iguales corresponden
            //a la misma coordenada
        
            int fila = vector_filas -> obtener_numero(pos_coordenada);
            int columna = vector_columnas -> obtener_numero(pos_coordenada);
            
            mapa[fila][columna] -> agregar_material(material_a_colocar, 1);

            //CODIGO CON METODOS PARA ACHICAR Y QUITAR ELEMENTOS DE LOS VECTORES FILAS Y COLUMNAS

            // vector_filas -> o
        }

        else{
            //MODULARIZAR EN OTRA FUNC MOSTRAR_ALERTA
            cout <<"No se pudieron colocar los siguientes materiales porque los casilleros transitables ya estan todos ocupados";
            if (cant_gen_piedras > 0){
                cout<<cant_gen_piedras <<" unidades de piedra"<<endl;
            }
            if (cant_gen_piedras > 0){
                cout<<cant_gen_maderas <<" unidades de madera" <<endl;
            }
            if (cant_gen_piedras > 0){
                cout<<cant_gen_metales <<" unidades de metal " <<endl;
            }
        }
        
    }

    delete vector_filas;
    delete vector_columnas;

}

// -------------- FINALIZA PUNTOS DEL MENU -------------------------------


// Destructor
Mapa::~Mapa(){

    ofstream archivo_ubicaciones(ARCHIVO_UBICACIONES);

    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0; j < cantidad_columnas ; j++){
            if (mapa[i][j] ->existe_edificio() ){
                archivo_ubicaciones << mapa[i][j] ->obtener_nombre_edificio() << " ("
                << i << ", " << j << ")" << endl;
            }
            if ( mapa[i][j] -> existe_material() ){ 
                archivo_ubicaciones << mapa[i][j] -> obtener_nombre_material() <<" ("
                << i << ", " << j << ")" << endl;
            }

            delete mapa[i][j];
        }
        delete [] mapa[i];
    }
    delete [] mapa;
    this->mapa = 0;

    delete lista_edificios;
    lista_edificios = 0;
    delete usuario_inventario;
    usuario_inventario = 0;


}