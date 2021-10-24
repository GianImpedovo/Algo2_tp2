#ifndef ANDYPOLIS_UTILES_H
#define ANDYPOLIS_UTILES_H

#include <iostream>
#include <string>

using namespace std;

//template <typename Casillero>

class Casillero {
private:
    int fila;
    int columna;
    bool ocupado;    //true / false
    string tipo_terreno;    //Lago, Terreno, Camino
    string elemento_en_casillero; //Mina Stone Escuela etc

    //opcion 2
    //string elemento_en_casillero; // Mina Stone Escuel

public:
    Casillero(){
        fila = 4;
    }
    
    //getter
    int obtener_fila(){
        return fila;
    }


    int obtener_columna(){
        return columna;
    }

};

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
            mapa[i] = new Casillero[columnas];
        }
    } 

    ~Mapa(){
        for (int i = 0; i < filas; i++){
            delete [] mapa[i];
        }
        delete [] mapa;
        } 
    


    bool es_coordenada_valida(int fila, int columna){
        bool es_valida = true;
        if (fila < 0 || fila > filas){
            es_valida = false;
        };
        if (columna <0 || columna > columnas){
            es_valida = false;
        }
    return es_valida;

    }

    //obtener casillero
    //POST: Devueleve un objeto de tipo casillero que se encuentra
    //en la posicion fila columna.
    Casillero obtener_casillero (int fila, int columna){
        if (es_coordenada_valida(fila, columna)){       //OJO!!! LLAMAR ESTE METODO EN EL MAIN SINO DEVUELVE WRETURN ERRPR
            return mapa[fila][columna];             //XQ EN CASO DE SER FALSE NO DEVOLVERIA NADA
        };
        //Mostrar por panatalla que no fue valida en el main?
    }

    //Coloca en el casillero de coordenadas fila columna el objeto 
    //casillero enviado por parametro
    void colocar_casillero(int fila, int columna, Casillero casillero){
        if ( es_coordenada_valida(fila, columna) ){ 
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


#endif //ANDYPOLIS_UTILES_H
