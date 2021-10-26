#include "material.h"
#include <iostream>


//constructor de material sin parametros
Material :: Material(){
}

//Obtener nombre
string Material :: obtener_nombre(){
  
  return nombre;
}


//Obtener cantidad
int Material :: obtener_cantidad_disponible(){
  
  return cantidad;
}

//cargar material
void Material :: asignar_valores(string nombre, int cantidad){
  
  this -> nombre = nombre;
  this -> cantidad = cantidad;

}

//mostrar nombre
void Material :: mostrar_nombre(){
  
  cout << nombre;
}

//mostrar cantidad
void Material :: mostrar_cantidad(){
  
  cout << cantidad;
}