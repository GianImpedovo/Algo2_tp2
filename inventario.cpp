#include <iostream>
#include <fstream>
#include "inventario.h"

const int ERROR = -1;

using namespace std;


const string PATH_MATERIALES = "materiales.txt";

//Constructor de inventario sin parametros
Inventario :: Inventario(){
    
    lista_materiales = 0;
    cantidad_de_materiales = 0;
}

//Obtener material de lista_materiales
Material *Inventario :: obtener_material_de_lista_materiales(int pos){

    return lista_materiales[pos];
}

//Obtener cantidad de materiales en lista_materiales
int Inventario :: obtener_cantidad_de_materiales(){
    return cantidad_de_materiales;
}

//cargar materiales
void Inventario :: cargar_materiales(){
    
    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(archivo_materiales.is_open()){

        string nombre;
        string cantidad;

        Material *material;


        while(archivo_materiales >> nombre){
            archivo_materiales >> cantidad;
            
            material = new Material(nombre, stoi(cantidad));
            
            //material -> asignar_valores(nombre, stoi(cantidad));

            agregar_material(material);
        }

        archivo_materiales.close();
    }
    else{
        cantidad_de_materiales = ERROR; 
    }
} 


//agregar material a la lista de materiales
void Inventario :: agregar_material(Material* material){
    
    int tope_viejo = cantidad_de_materiales;

    Material** nuevo_vector_materiales = new Material*[tope_viejo + 1];

    for(int i = 0; i < cantidad_de_materiales; i++){
        nuevo_vector_materiales[i] = lista_materiales[i];
    }
    
    nuevo_vector_materiales[tope_viejo] = material;

    if(cantidad_de_materiales != 0){
        delete[] lista_materiales;
    }

    lista_materiales = nuevo_vector_materiales;
    cantidad_de_materiales++;
}


//Destructor de inventario
Inventario:: ~ Inventario(){
        
        ofstream archivo_materiales(PATH_MATERIALES);

        int cantidad_total = cantidad_de_materiales;

        for(int i = 0; i < cantidad_total; i++){
            
            archivo_materiales << lista_materiales[i]->obtener_nombre()<< ' '
            << lista_materiales[i] -> obtener_cantidad_disponible()<< '\n';
            

            delete lista_materiales[i];
            
            cantidad_de_materiales--;
        }

        delete [] lista_materiales;
        lista_materiales = nullptr;
};


//chequar si alcanza material en cuestion
void Inventario :: chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza){
    if (cantidad_disponible < cantidad_material_nec){
                alcanza = false;
    }
}


//Chequear si alcanzan materiales
bool Inventario :: alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec){

    bool alcanza = true;
    int i = 0;
    while (alcanza && i < cantidad_de_materiales){
        
        string material_a_chequear = lista_materiales[i]->obtener_nombre();

        int cantidad_disponible = lista_materiales[i]->obtener_cantidad_disponible();
        
        if (material_a_chequear == "piedra"){
            chequear_material(cantidad_disponible, cantidad_piedra_nec, alcanza);
        }
        if (material_a_chequear == "madera"){
            chequear_material(cantidad_disponible, cantidad_madera_nec, alcanza);
        } 
        if (material_a_chequear == "metal"){
            chequear_material(cantidad_disponible, cantidad_metal_nec, alcanza);
        }
        i++;
    }
    return alcanza;
}


//Mostrar inventario
void Inventario :: mostrar_inventario(){
    
    cout << setfill(' ') << setw(64)<<"MATERIALES DE CONSTRUCCION"<<"\n\n"
    << setfill(' ') << setw(45) <<"MATERIAL"<< setfill(' ')<<setw(21)<<"CANTIDAD DISPONIBLE"<<endl
    << setfill(' ') << setw(72)<<"__________________________________________" <<endl<<endl;
    
    for(int i = 0; i < cantidad_de_materiales; i++){
        cout<<setfill(' ') << setw(45) << lista_materiales[i] -> obtener_nombre()
        <<setfill(' ') << setw(12) << lista_materiales[i] -> obtener_cantidad_disponible() <<endl;
        }
    
    cout<<endl;   
}; 