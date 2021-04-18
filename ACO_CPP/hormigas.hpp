#ifndef HORMIGA_HPP_
#define HORMIGA_HPP_
#include <iostream>
#include "listaenla.hpp"
#include "camino.hpp"
template <typename T>
class Hormiga{
	public:
	/*************************************************************
   *					DECLARACIoN DE SUBTIPOS					 *
   **************************************************************/
		typedef typename std::size_t vertice;
		typedef T tCoste;
	/**************************************************************
   *						OPERACIONES DEL TAD HORMIGA			  *
   ***************************************************************/
		/*CONSTRUCTOR sobrecargado pasandole un identificador 
			unico en un tablero
		 PRECONDICIoN: -
		 POSTCONDICIoN: se crea una nueva hormiga
		*/
		explicit Hormiga(size_t i):id(i), visitados(){}
		/*OBSERVADOR del identificador de la hormiga
		PRECONDICIoN: -
		POSTCONDICIoN: devuelve el identificador de esta hormiga
		*/
		size_t identificador()const{return id;}
		/*OBSERVADOR Y MODIFICADOR de la lista de nodos visitados*/
		const Camino<tCoste>& verticesVisitados()const{
			return visitados;
		}	
		Camino<tCoste>& verticesVisitados() {return visitados;}
	/**********************************************************
	*		      MeTODOS WRAPPED DEL TAD CAMINO			  *
	**********************************************************/
		/*Una hormiga visita un vertice nuevo
			PRECONDICIoN: -
			POSTCONDICIoN: agrega un nuevo nodo visitado con 
				el coste de ir del anterior a este
		*/
		void nuevoNodoVisitado(vertice n, tCoste c){
			visitados.nuevoNodo(n, c);
		}
		/*La hormiga vuelve al hormiguero
			PRECONDICIoN: -
			POSTCONDICIoN: vacia la lista de nodos visitados dejando 
				solo el primero que es el hormiguero, y deja 
				el coste a 0
		*/
		void volver(){visitados.volver();}
		/*Metodo para saber si un nodo ya ha sido visitado
		 	PRECONDICIoN: -
		 	POSTCONDICIoN: devuelve verdadero si el camino 
		 		ha sido visitado, falso si no lo ha sido
	  */
		bool haVisitado(vertice i) const{
			return visitados.haVisitado(i);
		}
		/*Metodo para saber en que nodo se encuentra nuestra hormiga
			PRECONDICIoN: hay una hormiga asignada a un tablero(lo 
				sabemos si hemos inicializado el vertice inicial)
			POSTCONDICIoN: devuelve el vertice en el que se encuentra 
				la hormiga
		*/
		const vertice& actual(){
			return visitados.actual();
		}
	/***************OPERADOR DE INSERCIoN EN FLUJO***************/
		template <class U>
		friend std::ostream& operator <<
			(std::ostream& os, const Hormiga<U>& h);
	private:
		size_t id;
		Camino<tCoste> visitados;
};
/*******************OPERADORES == y !=***************************/
template<typename T>
bool operator ==(const Hormiga<T>& h1, const Hormiga<T>& h2){
	return h1.identificador() == h2.identificador();
}
template<typename T>
bool operator != (const Hormiga<T>& h1, const Hormiga<T>& h2){
	return !(h1 == h2);
}
/*****************OPERADOR DE INSERCIoN EN FLUJO********************/
template<typename T>
std::ostream& operator <<(std::ostream& os, const Hormiga<T>& h){
	os << "***************HORMIGA " << h.id << "***************\n";	
	os << h.visitados ;
	return os;
}
#endif
