#include <iostream>
#include "mapa.h"


//solo xa probarlo!!
int main(){

    Casillero casillero;
    //Mapa <int> mapa (10,15);
    Mapa *mapa = new Mapa(3,3);
    for (int i=0; i< mapa -> obtener_filas() ; i++){
        for (int j =0;  j < mapa -> obtener_columnas(); j++) {
            mapa->colocar_casillero(i, j, casillero); //depsues sera un objeto casillero

        }
    } 
    
    for( int i = 0; i < mapa -> obtener_filas(); i++){
        for (int j = 0; j < mapa -> obtener_columnas (); j++){
            cout <<"(" << mapa -> obtener_casillero(i,j).obtener_fila() <<","
            << mapa -> obtener_casillero(i,j).obtener_columna() <<") ";
            }
        cout << endl;
        }
    delete mapa;
    return 0;
}
