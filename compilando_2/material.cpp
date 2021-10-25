#include "material.h"
#include <iostream>


//constructor de material sin parametros
Material :: Material(){
}


//setter de material
void Material :: asignar_contenido(string nombre, int cantidad){
  
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

//mostrar nombre
void Material :: mostrar_nombre(){
  
  cout << nombre;
}

//mostrar cantidad
void Material :: mostrar_cantidad(){
  
  cout << cantidad;
}


//Constructor de copia
Material :: Material ( const Material & nuevo_material ) {
  cout <<"constructor de copia de material";
  this -> nombre = nombre;
  this -> cantidad = cantidad;
}