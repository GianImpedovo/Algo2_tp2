#include "material.h"
#include <iostream>


//Constructor de material sin parametros
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

//Asignar valores al material
void Material :: asignar_valores(string nombre, int cantidad){
  
  this -> nombre = nombre;
  this -> cantidad = cantidad;

}

//Restar material
void Material :: restar_material(int cantidad_material_nec){
    
    cantidad =  cantidad - cantidad_material_nec;
    
}

//Sumar material
void Material :: sumar_material(int cantidad_material_nec){
    
  cantidad =  cantidad + cantidad_material_nec/2;   //truncado (redondeo hacia abajo)
                       
}

//Mostrar nombre
void Material :: mostrar_nombre(){
  
  cout << nombre;
}

//Mostrar cantidad
void Material :: mostrar_cantidad(){
  
  cout << cantidad;
}