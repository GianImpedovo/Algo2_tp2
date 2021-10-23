#include "inventario.h"
#include <iostream>
#include <fstream>

using namespace std;


const string PATH_MATERIALES = "materiales.txt";

//Constructor de inventario sin parametros
Inventario :: Inventario(){
    
    Material** lista_materiales = 0;
    cantidad_de_materiales = 0;
}


void Inventario :: cargar_materiales(){
    
    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(archivo_materiales.is_open()){

        string nombre;
        string cantidad;

        Material *material;

        while(archivo_materiales >> nombre){
            archivo_materiales >> cantidad;
                        
            //Material material(nombre,stoi(cantidad)) = new Material;

            material = new Material;
            //Material* aterial(nombre, cantidad);
            
            material.asignar_valores(nombre,cantidad)

            agregar_material(material);
        }

        archivo_materiales.close();
    }
    else{
        lista_materiales -> cantidad_de_materiales = ERROR;    //para chequear si se abrio o no el archivo
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

    lista_materiales = nuevo_vector_materiales; //llama al constructor de copia???
    cantidad_de_materiales++;
}


//copiar datos
void Inventario :: copiar_datos(Material** lista_nueva, int tamanio) {
	for (int i = 0; i<tamanio; i++){
		lista_nueva[i] = lista_materiales[i];
	};
}


//Constructor de copia
Inventario :: Inventario ( const Inventario & nuevo_inventario ) {
	this -> cantidad_de_materiales = nuevo_inventario.cantidad_de_materiales;
	if (cantidad_de_materiales > 0) {
		*lista_materiales = new Material[ cantidad_de_materiales ];
		copiar_datos (nuevo_inventario.lista_materiales, cantidad_de_materiales);
		// Se copian los valores a esa nueva porcion de memoria	
	}
    
	else *lista_materiales = 0;
}
