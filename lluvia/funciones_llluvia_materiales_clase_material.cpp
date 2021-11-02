#include <iostream>
#include <ctime>
#include <cstdlib>

#include "material.h"



using namespace std;

//Generar numero random
//PRE: Recibe los enteros "min" y "max" con los valores limites (inclusives) entre los cuales se desea generar
//el numero random 
//POST: Devuelve un valor random entre "min" y "max"
////int Mapa ::
int generar_numero_random(int min, int max){
    int range = max + 1  - min;   // sumo 1 porque rand() no incluye al ultimo num del range
    return min + ( rand() % range);

}

//Consultar material a colocar
//PRE: Recibe los enteros "cant_gen_piedras", "cant_gen_maderas" y "cant_gen_metales" y el string
//material_a_colocar
//POST: Modifica por parametro "material_a_colocar" y las cantidades de piedra y madera restantes
//void Mapa ::
void consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, 
string &material_a_colocar ){
    if (cant_gen_piedras){
        material_a_colocar = "S";
        cant_gen_piedras --;

    } else if (cant_gen_maderas){
        material_a_colocar = "W";
        cant_gen_maderas --;

    } else{
        material_a_colocar = "I";
        cant_gen_metales --;
    }
}



//Lluvia de recursos
//PRE: Recibe los eneteros "max_fila" y  "max_col" con los vaores de las maxima columna y la maxima fila que
//hay en el mapa
//POST: Coloca en el mapa 1 unidad de cada material generado. Si la posicion random en la que se lo colocaria
//resulta estar ocupada, no se coloca dicho material.
//void Mapa ::
int main(){

    srand( (unsigned)time(0) );

    int cant_gen_piedras = generar_numero_random(1,3); 
    int cant_gen_maderas = generar_numero_random(0,1);
    int cant_gen_metales = generar_numero_random(2,4);
    
    int max_fila = 10; // mapa.botener_numero_filas
    int max_col = 10; 
    
    int tot_materiales_gen = cant_gen_piedras + cant_gen_maderas + cant_gen_metales;
    
    string material_a_colocar = "";
        
    cout << "Han llovido en el mapa " << tot_materiales_gen << " unidades de materiales: " <<endl
    <<cant_gen_piedras <<" unidades de piedra"<<endl
    <<cant_gen_maderas <<" unidades de madera" <<endl
    <<cant_gen_metales <<" unidades de metal " <<endl
    <<"en las siguientes ubicaciones: "<< endl <<endl;

    Material * material;
    
    for (int i = 0; i < tot_materiales_gen; i++){
        
        consultar_material_a_colocar(cant_gen_piedras, cant_gen_maderas, cant_gen_metales, material_a_colocar);
        
        material = new Material(material_a_colocar, 1 );
        //cout <<"pido mem"<<endl;
        
        int fila = generar_numero_random(1,max_fila);
        int columna = generar_numero_random(1, max_col);
        
        //DESCOMENTAR LA SIGUIENTE LINEA AL AGEGAR A LA CLASE MAPA
        //mapa[stoi(fila)][stoi(columna)] -> agregar_material(material);
        
        cout << material -> obtener_cantidad_disponible() << " unidad de " << material -> obtener_nombre() << " en "
        << "("<< fila <<","<< columna <<")"<<endl;

    }

    return 0;
}