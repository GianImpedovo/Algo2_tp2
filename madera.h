#ifndef MADERA_H
#define MADERA_H

#include <iostream>
#include <string>
#include "material.h"

using namespace std;

class Madera : public Material {

private:


public:
    //Constructor de piedra con dos parametros
    //PRE:-
    //POST: Construye una piedra con 2 parametros
    Madera(string, int);

    //Piedra saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // MADERA_H_INCLUDED