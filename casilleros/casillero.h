#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>

using namespace std;

class Casillero
{
protected:
    int fila;
    int columna;
    string nombre;

public:
    Casillero(int fila, int columna);

    Casillero();

    virtual void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo) = 0;

    virtual void agregar_material(string nombre, int cantidad) = 0;

    virtual void mostrar_casillero() = 0;

    virtual string obtener_nombre() = 0;

    virtual string obtener_nombre_edificio() = 0;

    virtual string obtener_diminutivo_edificio() = 0;

    virtual void eliminar_edificio() = 0;

    virtual bool existe_edificio() = 0;

    virtual bool existe_material() = 0;

    int mostrar_fila();

    int mostrar_columna();

    virtual void mostrar_coordenadas_edificio(string nombre) = 0;

    virtual ~Casillero();
    


};


#endif // CASILLERO_H