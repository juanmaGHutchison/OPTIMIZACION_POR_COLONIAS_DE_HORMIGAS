#ifndef CAMINO_HPP_
#define CAMINO_HPP_
#include "listaenla.hpp"
#include "hormigas.hpp"
template <typename T>
class Camino{
	public:
		typedef typename std::size_t vertice;
		typedef T tCoste;		
		/*Metodo para agregar un nodo a la lista de vertices 
			recorridos junto al coste de ir del anterior al actual
		 PRECONDICIoN: el nodo n no ha sido visitado aun
		 POSTCONDICIoN: agrega un nuevo nodo a la lista de visitados 
		 	y añade el coste
	  */
		void nuevoNodo(vertice n, tCoste c);
		/*Metodo para volver al inicio
			PRECONDICIoN: -
			POSTCONDICIoN: deja el camino vacio(solo vertice inicial)
				 y el coste a 0
		*/
		void volver();
		/*Metodo para saber en que nodo se encuentra nuestra hormiga
			PRECONDICIoN: hay una hormiga asignada a un tablero(lo 
				sabemos si hemos inicializado el vertice inicial)
			POSTCONDICIoN: devuelve el vertice en el que se encuentra
				 la hormiga
		*/
		const vertice& actual();
		/*Metodo para saber si un nodo ya ha sido visitado
		 PRECONDICIoN: -
		 POSTCONDICIoN: devuelve verdadero si el camino ha sido 
		 	visitado, falso si no lo ha sido
	  */
		bool haVisitado(vertice i) const{
			return camino.buscar(i) != camino.fin();
		}
		/*Metodo para obtener el coste del camino recorrido
			PRECONDICIoN: -
			POSTCONDICIoN: devuelve el coste del camino recorrido
		*/
		const float& costeCamino()const{
			return coste;
		}
		/*Metodo para saber los nodos recorridos de un camino
			PRECONDICIoN: -
			POSTCONDICIoN: devuelve una lista de vertices recorridos
		*/
		const Lista<vertice>& caminoRecorrido() const{
			return camino;
		}
		/***************OPERADOR DE INSERCIoN EN FLUJO**************/
		template <class U> 
		friend std::ostream& operator << 
			(std::ostream& os, const Camino<U>& cam);
	private:
	/************************************************************
   *						DECLARACIoN DE TIPOS PRIVADOS		*
   *************************************************************/
		Lista<vertice> camino;
		tCoste coste;
};
template<typename U>
std::ostream& operator <<(std::ostream& os, const Camino<U>& cam){
	os << "Camino recorrido: ";
	bool primera = false;
	for(typename Lista<typename Camino<U>::vertice>::posicion it = 
		cam.camino.primera(); it != cam.camino.fin(); 
			it = cam.camino.siguiente(it)){
		os << ((primera)? " -> ": "") << cam.camino[it];
		primera = true;
	}
	os << "\nCoste del camino: " << cam.coste << "\n";
	return os;
}
/***************IMPLEMENTACIoN DE MeTODOS********************/
template <typename T>
void Camino<T>::nuevoNodo
	(Camino<T>::vertice n, Camino<T>::tCoste c){
	coste += c;
	camino.insertar(n, camino.fin());
}
template <typename T>
void Camino<T>::volver(){
	for(Lista<vertice>::posicion it = camino.anterior(camino.fin()); 
		it != camino.primera(); it = camino.anterior(it))
		camino.eliminar(it);
	coste = 0.0;
}
template <typename T>
const typename Camino<T>::vertice& Camino<T>::actual(){
	return camino[
		camino.anterior(
			camino.fin()
			)
		];
}
#endif
