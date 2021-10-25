#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>

using namespace std;

class Casillero
{
private:
    int fila;
    int columna;
    string nombre;
public:
    Casillero(int fila, int columna , string nombre);
    Casillero();
    string mostrar_nombre();
    void establecer_valores(string nombre, int i , int j);
    int mostrar_fila();
    int mostrar_columna();

};


#endif // CASILLERO_H