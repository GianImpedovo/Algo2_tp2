#ifndef ANDYPOLIS_UTILES_H
#define ANDYPOLIS_UTILES_H

#include <iostream>
#include <string>

using namespace std;

template <typename Casillero>
class Mapa{
private:
    int filas;
    int columnas;
    Casillero ** mapa;

public:
    Mapa (int filas, int columnas){
        
        this -> filas = filas;
        this -> columnas = columnas;
        
        mapa = new Casillero*[filas];
        for (int i = 0; i < filas; i++){
            mapa[i] = new Casillero[columnas]
        }
    } 

    ~Mapa(){
        for (int i = 0; i < filas; i++){
            delete [] matrix[i];
        }
        delete []
    } 
    


    bool es_coordenada_valida(int fila, int columna){
        bool es_valida = true;
        if (fila < 0 || fila > filas){
            es_valida = false;
        }
        if (columna <0 || columna > columnas){
            es_valida = false
        }
        return es_valida

    }

    //obtener casillero
    //POST: Devueleve un objeto de tipo casillero que se encuentra
    //en la posicion fila columna.
    Casillero obtener_casillero (int fila, int columna){
        if (es_coordenada_valida(fila, columna)){
            return mapa[i];
        }
        //Mostrar por panatalla que no fue valida en el main?
    }

    //Coloca en el casillero de coordenadas fila columna el objeto 
    //casillero enviado por parametro
    void colocar_casillero(int fila, int columna, Casillero casillero){
        if (es_coordenada_valida()){
            mapa[fila][columna] = casillero;
        }
    }

    int obtener_filas(){
        return filas;
    }
    
    int obtener_columnas(){
        return columnas;
    }
};

int main(){
}


#endif //ANDYPOLIS_UTILES_H
