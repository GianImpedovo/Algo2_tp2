#include "inventario.h"
#include <iostream>
#include <fstream>

const int ERROR = -1;

using namespace std;


const string PATH_MATERIALES = "materiales.txt";

//Constructor de inventario sin parametros
Inventario :: Inventario(){
    
    Material** lista_materiales;
    //lista_materiales = new Material*;
    cantidad_de_materiales = 0;
}

//Obtener material en lista_materiales
//PRE: Recibe la posicion del material en la lista
//POST: Devuelve un puntero a dicho material
Material *Inventario :: obtener_lista_materiales(int pos){
    return lista_materiales[pos];
}

int Inventario :: obtener_cantidad_de_materiales(){
    return cantidad_de_materiales;
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
            
            material -> asignar_valores(nombre, stoi(cantidad));

            agregar_material(material);
        }

        archivo_materiales.close();
    }
    else{
        cantidad_de_materiales = ERROR;    //para chequear si se abrio o no el archivo
    }
} 


//agregar material a la lista de materiales
void Inventario :: agregar_material(Material* material){
    
    int tope_viejo = cantidad_de_materiales;

    Material** nuevo_vector_materiales = new Material*[tope_viejo + 1];

    for(int i = 0; i < cantidad_de_materiales; i++){
        nuevo_vector_materiales[i] = lista_materiales[i];
    }
    
    nuevo_vector_materiales[tope_viejo] = material; //llama al constructor de copia???

    if(cantidad_de_materiales != 0){
        delete[] lista_materiales;
    }

    lista_materiales = nuevo_vector_materiales; //llama al constructor de copia???
    cantidad_de_materiales++;
}


//copiar datos
// void Inventario :: copiar_datos(Material** lista_nueva, int tamanio) {
// 	for (int i = 0; i<tamanio; i++){
// 		lista_nueva[i] = lista_materiales[i];
// 	};
// }


// //Constructor de copia
// Inventario :: Inventario ( const Inventario & nuevo_inventario ) {
// 	this -> cantidad_de_materiales = nuevo_inventario.cantidad_de_materiales;
// 	if (cantidad_de_materiales > 0) {
// 		*lista_materiales = new Material[ cantidad_de_materiales ];
// 		copiar_datos (nuevo_inventario.lista_materiales, cantidad_de_materiales);
// 		// Se copian los valores a esa nueva porcion de memoria	
// 	}
    
// 	else *lista_materiales = 0;
// }

Inventario:: ~ Inventario(){
        //int cant_mat = inventario -> obtener_cantidad_de_materiales();
        //int cant_mat = cantidad_de_materiales;
        
        for(int i = 0; i < cantidad_de_materiales; i++){

            //delete lista_materiales -> materiales[i];
            delete lista_materiales[i];
            
            //lista_materiales -> cantidad_de_materiales--;
            cantidad_de_materiales--;
        }

        //delete[] lista_materiales -> materiales;
        delete [] lista_materiales;
        lista_materiales = nullptr;
};


int main (){

    Inventario *inventario = new Inventario;
    inventario -> cargar_materiales();
    //inventario es un doble puntero -> devuelve el contenido de ese puntero (un puntero al elemento "pos" de la lista)
    //luego -> devuelve el contenido del puntero a la lista, es decir el material y a la vez llama al metodo obtener_nombre
    for (int i = 0; i < inventario->obtener_cantidad_de_materiales(); i++ ){
        cout << inventario -> obtener_lista_materiales(i) -> obtener_nombre()<< " "
        <<inventario -> obtener_lista_materiales(i) -> obtener_cantidad_disponible()<<endl;
        }

    delete inventario;
}