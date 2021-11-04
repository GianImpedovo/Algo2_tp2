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
    // Constructor
    // PRE: - 
    // POS: Inicializo los valores en con los valores de fila y columna correspondientes,
    //      y nombre vacio.
    Casillero(int fila, int columna);
    
    // Constructor
    // PRE: - 
    // POS: Inicializo los valores en 0 fila y columna, y "A" al nombre.
    Casillero();

    // PRE: - 
    // POS: Implementada en los casilleros_construibles, creara un nuevo edificio en el casillero.
    virtual void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo) = 0;

    // PRE: -
    // POS: - 
    virtual void agregar_material(string nombre, int cantidad) = 0;

    // PRE: -
    // POS: Muestra el nombre del casillero siendo estos = T,C,L.
    virtual void mostrar_casillero() = 0;

    // PRE: -
    // POS: Se obtiene el nombre del casillero solicitado siendo estos = T,C,L.
    virtual string obtener_nombre() = 0;

    // PRE: -
    // POS: En el casillero_construible, podremos obtener el nombre del
    //      edificio consultado en caso que exista.
    virtual string obtener_nombre_edificio() = 0;

    // PRE: -
    // POS: En el casillero_construible, nos devolvera en caso de existir edificio, su 
    //      su diminutivo, diminutivo = 'La primer palabra del nombre del edificio'.
    virtual string obtener_diminutivo_edificio() = 0;

    // PRE: -
    // POS: - 
    virtual string obtener_diminutivo_material() = 0;

    // PRE: -
    // POS: En el casillero_construible, en caso de existir edificio , lo elimina.
    virtual void eliminar_edificio() = 0;

    // PRE: -
    // POS: En el casillero_construible, obtendremos verdadero o falso , si existe retorna verdadero.
    virtual bool existe_edificio() = 0;

    // PRE: -
    // POS: - 
    virtual bool existe_material() = 0;
    
    // PRE: -
    // POS: En el casillero_construible, podremos visualizar por pantalla las coordenadas del casillero donde
    //      se encuentra el edificio, en caso que este exista.
    virtual void mostrar_coordenadas_edificio(string nombre) = 0;

    // Destructor
    // PRE: -
    // POS: - 
    virtual ~Casillero();
    


};


#endif // CASILLERO_H