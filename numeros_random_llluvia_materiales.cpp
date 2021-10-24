#include <iostream>
#include "lluvia_recursos.h"
#include <ctime>

#include <cstdlib>


using namespace std;


int generar_numero_random(int min, int max){
    int range = max + 1  - min;   // sumo 1 porque rand() no incluye al ultimo num del range
    return min + ( rand() % range);

}

//PRE: Recibe los enteros "cant_gen_piedras", "cant_gen_maderas" y "cant_gen_metales" y el string
//elemento_a_colocar
//POST: Modifica por parametro elemento a colocar y las cantidades de piedra y madera restantes
void consultar_elemento_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, 
string &elemenento_a_colocar){
    if (cant_gen_piedras){
        elemenento_a_colocar = "S";
        cant_gen_piedras --;
    } else if (cant_gen_maderas){
        elemenento_a_colocar = "W";
        cant_gen_maderas --;
    } else{
        elemenento_a_colocar = "I";
        cant_gen_metales --;
    }
}



int main(){

    srand( time(NULL) );
    //srand( (unsigned)time(0) );

    int cant_gen_piedras = generar_numero_random(1,3); 
    int cant_gen_maderas = generar_numero_random(0,1);
    int cant_gen_metales = generar_numero_random(2,4);
    
    int max_fila = 10; // mapa.botener_numero_filas
    int max_col = 10; 
    
    int tot_materiales_gen = cant_gen_piedras + cant_gen_maderas + cant_gen_metales;
    string elemenento_a_colocar = "";
    cout << "Se han cargado en el mapa" <<endl
    <<cant_gen_piedras <<" unidades de metal"<<endl
    <<cant_gen_maderas <<" unidades de madera" <<endl
    <<cant_gen_metales <<" unidades de metal " <<endl
    <<"en las siguientes posiciones respectivamente: "<< endl;
    for (int i = 0; i < tot_materiales_gen; i++){
        consultar_elemento_a_colocar(cant_gen_piedras, cant_gen_maderas, cant_gen_metales, elemenento_a_colocar);
       
        int fila = generar_numero_random(1,max_fila);
        int columna = generar_numero_random(1, max_col);

        //COMENTARIOS SOBRE POSIBLE IMPLEMENTACION Y CREACION DEL MAPA

        //mapa tendra un metodo que lo recorrera la matriz de casilleros y devolvera el casillero
        // de cordenada fila, columna preguntando elemento por elemento del vector casilleros
        //si la coordenada coincide o no. El mapa solo contiene casilleros, es un array de casilleros
        // pero no sabe nada de cada uno. Por eso le tiene q preguntar a cada uno q carajo tiene, es
        // o puede tener
        
        //int casillero = mapa.obtener_pos_casillero(fila, columna) //en el array de casilleros
        //if mapa.casillero[casillero].obtener_tipo_terreno = "camino"
        //sino...
        //if (mapa.casillero[casillero].transitable == true){
            //if (mapa.casillero[casillero].ocupado == false ){
                //Metodo que aun no existe que recibira 2 enteros correspondientes a una col y una fila
                //y un string con el identificador del elemento. La funcion en terminos generales,
                //recorrera el mapa y colocara en la pos indicada en algun lado el identificador
                //de q cosa hay
                //mapa.colocar_elemento(fila, columna, elemento_a_colocar)
    //         }
    //     }
        
    // }
    cout << "("<< fila <<","<< columna <<")"<<endl; 
    }
    return 0;
}