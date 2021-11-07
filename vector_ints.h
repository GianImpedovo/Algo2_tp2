#ifndef VECTOR_INTS_H
#define VECTOR_INTS_H

class Vector_ints { 
	private:
	// atributos
	int longitud;
	int* numeros;

	public:
    
	//métodos (interfaz)
	// Constructor sin parametros
	// PRE: - 
	// POS: construye un vector vacio
	Vector_ints();

    int obtener_numero ( int pos);

    int obtener_longitud();

    // redimensionar
	// PRE: tam > 0
	// POS: redimensiona el vector, si tam es mayor que la longitud inicial, deja los datos anteriores y completa con vacios, si es menor, corta los datos que exceden
	void agregar_numero ( int num, int tam, int pos );

	void sacar_numero(int pos);

	void swap_num(int posicion_1, int posicion_2);

    ~Vector_ints( );



};

#endif // VECTOR_INTS_H

//cargar materiales