#include "inventario.h"
#include <iostream>
#include <fstream>

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
                        
            material = new Material;
            
            material -> asignar_valores(nombre, stoi(cantidad));

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
