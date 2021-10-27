#ifndef METAL_H_INCLUDED
#define METAL_H_INCLUDED

#include <iostream>
#include <string>
#include "material.h"

using namespace std;

class Metal : public Material {

private:


public:
    //Constructor de metal con dos parametros
    //PRE:-
    //POST: Construye una piedra con 2 parametros
    Metal(string, int);

    //metal saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();

};


#endif // METAL_H_INCLUDED