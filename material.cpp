#include "material.h"
#include <iostream>


//constructor de material sin parametros
Material :: Material() {
  
  nombre = "";
  cantidad = 0;
}


//constructor de material con 2 parametros
Material :: Material(string nombre, int cantidad){
  this -> nombre = nombre;
  this -> cantidad = cantidad;
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