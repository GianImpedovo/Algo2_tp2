#ifndef PIEDRA_H_INCLUDED
#define PIEDRA_H_INCLUDED

#include <iostream>
#include <string>
#include "material.h"

using namespace std;

class Piedra : public Material {

private:


public:
    //Constructor de piedra con dos parametros
    //PRE:-
    //POST: Construye una piedra con 2 parametros
    Piedra(string, int);

    //Piedra saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // PIEDRA_H_INCLUDED