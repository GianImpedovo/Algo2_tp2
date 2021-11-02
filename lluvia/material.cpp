#include "material.h"
#include <iostream>


//Constructor de material con 2 parametros
Material :: Material(string nombre, int cantidad){
  this-> nombre = nombre;
  this-> cantidad = cantidad;
}

Material :: ~Material(){
      //cout <<"destructor material"
       // cout << "Material (padre) Destructor called\n";
    }

//Obtener nombre
string Material :: obtener_nombre(){ 
  
  return nombre;
}


//Obtener cantidad
int Material :: obtener_cantidad_disponible(){
  
  return cantidad;
}


//Restar material
void Material :: restar_material(int cantidad_material_nec){
  cantidad =  cantidad - cantidad_material_nec;
    
}

//Sumar mitad material
void Material :: sumar_mitad_material(int cantidad_material_nec){
    
  cantidad =  cantidad + cantidad_material_nec/2;   //truncado (redondeo hacia abajo)
                       
}


//Sumar material
void Material :: sumar_material(int cantidad_material_recolectado){
    
  cantidad =  cantidad + cantidad_material_recolectado;   //truncado (redondeo hacia abajo)
                       
}

//Mostrar nombre
void Material :: mostrar_nombre(){
  
  cout << nombre;
}

//Mostrar cantidad
void Material :: mostrar_cantidad(){
  
  cout << cantidad;
}

void Material :: saludar(){
  cout<<"Hola, me llamaron? ";
  cout << "Soy un/a "<< nombre << " de clase base material y estoy en un casillero transitable" <<endl;
}