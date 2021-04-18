#ifndef TABLERO_HPP_
#define TABLERO_HPP_
#include "listaenla.hpp"
#include "hormigas.hpp"
#include "camino.hpp"
#include <vector>
#include <ctime>
#include <algorithm>
#include <limits>
#include <iostream>
#include <iomanip>
template <typename T> 
class Tablero
{
public:
  /**********************************************************
   *					ATRIBUTOS DE PuBLICOS				*
   **********************************************************/
  float FEROMONAS[100][100];//Representacion de las feromonas. 
  	//Puesto que no vamos a tener un mapa con mas de 100 vertices 
  	//asigno 100 para que cuando reasigne memoria la matriz este alineada.
  const float APRENDIZAJE = 1.;
  const float COSTE_EVAPORACION = 0.01;
  /*Actualizacion de feromonas
    PRECONDICIoN: las feromonas han sido inicializadas
    POSTCONDICIoN: actualiza las feromonas utilizando 
    	la formula de actualizacion de feromonas
  */
  void actualizar_feromonas();
  void evaporar_feromonas();
  /**************************************************************
   *					DECLARACIoN DE SUBTIPOS					*
   **************************************************************/
  typedef T tCoste; 
  //Tipo de coste de las aristas
  typedef typename std::size_t vertice; 
  //Vertices del grafo(nodos)
  static const tCoste INFINITO; 
  //Coste infinito entre dos nodos(no hay camino directo entre ellos)
  /*ESTRUCTURA DE CONEXIoN ENTRE DOS NODOS*/
  struct conexion{
    vertice i, j; //Vertices que forman la arista
    tCoste coste; //El coste entre los dos vertices
    /*OPERADOR == para comprobar si dos aristas son iguales.
      PRECONDICIoN: -
      POSTCONDICIoN: devuelve true si el parametro formal es 
      	la misma arista que la de la clase miembro.*/
    bool operator == (const conexion& c) const{return i == c.i && j == c.j;}
  };
  /***************************************************************
   *						OPERACIONES DEL TAD TABLERO			 *
   ***************************************************************/
  /*CONSTRUCTOR sobrecargado para crear el tablero
    PRECONDICIoN: el parametro formal N debe ser > 0
    POSTCONDICIoN: crea un tablero nuevo, asigna el tamaño a las 
   		feromonas e inicializa la lista de hormigas.
  */
  explicit Tablero(std::size_t N, vertice inicial, vertice objetivo);
  /*OBSERVADOR para saber el numero de vertices del grafo o tablero
    PRECONDICIoN: -
    POSTCONDICIoN: devuelve el numero de nodos
  */
  size_t numeroNodos() const{ return adyacentes.size();}
  /*OPERADOR [] OBSERVADOR y MODIFICADOR
    PRECONDICIoN: -
    POSTCONDICIoN: devuelve el elemento en dicha posicion
  */
  const std::vector<tCoste>& operator[](vertice v)const{
  	return adyacentes[v];
  }
  std::vector<tCoste>& operator[](vertice v){return adyacentes[v];}
  /*OBSERVADOR para saber cuantas hormigas hay en el tablero
    PRECONDICIoN: -
    POSTCONDICIoN: devuelve el numero de hormigas que recorren el tablero
  */
  size_t numeroHormigas() const {return hormigas.size();}
  /*Metodo para hacer avanzar una hormiga de un nodo al siguiente utilizando 
  la forumla de la probabilidad sobre la cual se elige uno arbitrareamente 
  y condicionado segun su probabilidad. 
    PRECONDICIoN: el nodo pasado por parametro tiene al menos un adyacente. 
    	El nodo no es el nodo objetivo. La hormiga h esta 
    	recorriendo el tablero.
    POSTCONDICIoN: devuelve el siguiente nodo por el que pasara la hormiga
  */
  vertice siguienteNodo(vertice x, Hormiga<tCoste>* h);
  /*Metodo para saber la distancia de un punto x a otro y, se utiliza 
  la formula de la distancia
    PRECONDICIoN: ambos parametros son adyacentes entre si, puesto 
    	que el grafo es no dirigido, con el que el primer parametro sea 
    	adyacente al segundo nos vale
    POSTCONDICION: devuelve la distancia entre dos puntos
  */
  float distancia(vertice x, vertice y);
  /*Metodo para saber si una hormiga especifica ha salido del 
  hormiguero en busca de comida
    PRECONDICIoN: -
    POSTCONDICIoN: devuelve verdadero si la hormiga existe en el 
    	tablero o falso en caso contrario*/
  bool hormigaBuscaComida(const Hormiga<tCoste>* h) const{
    return hormigas.buscar(h) != hormigas.fin();
  }
  /*Metodo par mandar a una nueva hormiga a buscar comida
    PRECONDICIoN: -
    POSTCONDICIoN: añade una hormiga nueva al Tablero y marca 
    	como visitado el nodo de inicio
  */
  void nuevaHormiga(Hormiga<tCoste>* h){
    hormigas.insertar(h, hormigas.fin());
    h->verticesVisitados().nuevoNodo(inicial_, 0.0);
  }
  /*Metodo para saber si hemos alcanzado el objetivo
  	 PRECONDICIoN: -
  	 POSTCONDICIoN: devuelve true si hemos alcanzado el objetivo, 
  	 	false en caso contrario
  */
  bool esObjetivo(vertice i) const{
  	 return i == objetivo_;
  }
  /*Metodo observador del nodo inicial
  	PRECONDICIoN: -
  	POSTCONDICIoN: devuelve el vertice inicial
  */
  vertice inicial(){
  	 return inicial_;
  }
  /*Metodo para saber cual es el mejor camino en un instante 
  de tiempo t
  	PRECONDICIoN: -
  	POSTCONDICIoN: devuelve un camino recorrido hasta el instante 
  		de tiempo en que se llama a la funcion	y su coste
  */
  Camino<tCoste> mejorCaminoActual();
  /*****************OPERADOR DE INSERCIoN EN FLUJO********************/
  template <class U> friend std::ostream& operator << 
  	(std::ostream& os, const Tablero<U>& tab);
private:
  /**************************************************************
   *						DECLARACIoN DE TIPOS PRIVADOS		*
   **************************************************************/
  std::vector< std::vector<tCoste> >adyacentes;
  Lista<const Hormiga<tCoste> *> hormigas;
  vertice inicial_;
  vertice objetivo_;
};
#endif
/****************************INFINITO********************************/
template <typename T> const T Tablero<T>::INFINITO = 
		std::numeric_limits<T>::max();
/****************************CONSTRUCTOR*****************************/
template <typename T>
Tablero<T>::Tablero(std::size_t N, vertice inicial, vertice objetivo)
  :adyacentes(N, std::vector<tCoste>(N,INFINITO)), 
  hormigas(), 
  inicial_ (inicial), 
  objetivo_(objetivo)
{
  //  FEROMONAS[N][N]; 
  //Inicializamos las feromonas con una Tasa de Feromonas del 1% (aleatoria)
  for(size_t i = 0; i < N; i++)
    for(size_t j = 0; j < N; j++)
      FEROMONAS[i][j] = 0.1; 
}
/**********IMPLEMENTACIoN DEL RESTO DE MeTODOS DECLARADOS************/
template <typename T>
typename Tablero<T>::vertice Tablero<T>::siguienteNodo(vertice x,  Hormiga<tCoste>* h)
{
  size_t n = adyacentes[x].size(); 
  //Adyacentes de x
  assert(n != 0 && x != objetivo_ && hormigas.buscar(h) != hormigas.fin());	
  vertice siguiente = x; 
  //El siguiente nodo por el que pasara, valor de retorno de la funcion
  float Stn = 0; 
  //Sumatorio de feromonas y distancias
  float caminosIndividuales[n];
  //Numerador de la formula 1, producto de la feromona y la distancia desde 
  //el vertice x a uno de sus adyacentes, almacenados secuencialmente en un 
  //vector para calcular sobre ellos la probabilidad
  std::srand(unsigned(time(0))); //semilla aleatoria para generar un numero
  for(vertice i = adyacentes[x].front(); i < adyacentes[x].size(); i++)
    if(adyacentes[x][i] != INFINITO && !(h->haVisitado(i))){
      caminosIndividuales[i] = (1/adyacentes[x][i])*FEROMONAS[x][i];
      Stn += caminosIndividuales[i];
    }
	std::vector<vertice> anterior; 
	//Conjunto de vertices adyacentes que no fueron INFINITO
	int ultimoValorAlmacenado = 0; 
	//Para posteriormente se termine este bloque saber hasta que numero 
	//aleatorio generar a la hora de elegir camino
  /*Definir rangos con su porcentaje, 
  por ejemplo: 0----16.987%----56.654%----100% correspondientes a sus vertices*/
  for(vertice i = adyacentes[x].front(); i < adyacentes[x].size(); i++)
    if(adyacentes[x][i] != INFINITO && !(h->haVisitado(i))){
    	caminosIndividuales[i] = (caminosIndividuales[i] / Stn) * 100;
    	if(!anterior.empty())
    		for(size_t j = 0; j < anterior.size(); j++)
    			caminosIndividuales[i] += caminosIndividuales[anterior[j]];	
    	anterior.push_back(i);
    	ultimoValorAlmacenado = caminosIndividuales[i];    
    }
    //CALLEJoN SIN SALIDA: el nodo en el que estamos tiene todos 
    //sus adyacentes ya marcados y no es la solucion
    if(anterior.size() == 0){
    	//Cogemos el vertice anterior por el que hemos pasado
    	vertice antesDelCallejonSinSalida = 
    		h->verticesVisitados().
    			caminoRecorrido().elemento(
			 		h->verticesVisitados()
			 			.caminoRecorrido()
				 			.anterior(
				 				h->verticesVisitados()
				 					.caminoRecorrido()
				 						.buscar(h->actual()
				 			)
				 	)
    			);
    	//Se agrega el nodo anterior de nuevo ya que hay que saber el 
    	//camino real que ha tomado la hormiga
    	h->nuevoNodoVisitado(
    		antesDelCallejonSinSalida,
    		adyacentes[x][antesDelCallejonSinSalida]
    	);	
    	siguiente = siguienteNodo(antesDelCallejonSinSalida, h);
    }
	//Si hay solo un elemento no hay rangos y si utilizaramos el caso 
	//general saltaria una excepcion al intentar asignar el 
	//valor a la variable iBefore
	if (anterior.size() == 1){
				siguiente = anterior.front();
				h->nuevoNodoVisitado(
					anterior.front(),
					adyacentes[x][siguiente]
				);
	}else if (anterior.size() > 1){
		/*Generamos numero aleatorio y sacamos, segun el rango, 
		el vertice al que corresponde el numero aleatorio generado*/
	  float numeroAzar = rand() % (0 + ultimoValorAlmacenado);
	  //Para coger el ultimo elemento y su elemento anterior(para elegir un rango)
	  vertice iAux, iBeforeAux; 
		for(vertice i = anterior.back(); i != anterior.front(); i--){
			iAux = i;
			anterior.pop_back();
			iBeforeAux = anterior.back();
			if(adyacentes[x][iAux] != INFINITO){
				if(numeroAzar >= 
					caminosIndividuales[iBeforeAux] && 
					numeroAzar <= caminosIndividuales[iAux]){
					siguiente = iAux;
					h->nuevoNodoVisitado(
						iAux, 
						adyacentes[x][siguiente]
					);
				}
			}
		}
  }
	return siguiente;	
}
template <typename T>
float Tablero<T>::distancia(vertice x, vertice y){
	assert(adyacentes[x][y] == INFINITO);
	return 0;
}
template <typename T>
void Tablero<T>::actualizar_feromonas(){
	//float sigmaXY = 0.0;
	Lista<
		typename Hormiga
			<typename Tablero<T>::tCoste>
			::vertice> camino; 
			//Lista de caminos recorridos para cada hormiga
	vertice x, y; 
	//Variables auxiliares para saber que feromonas actualizar	
	evaporar_feromonas();
	for(typename Lista
			<const Hormiga<T> *>::posicion itH = hormigas.primera();
		 itH != hormigas.fin(); itH = hormigas.siguiente(itH)
	){
		camino = hormigas[itH]->
						verticesVisitados()
							.caminoRecorrido();
		for(Lista<vertice>::posicion itV = camino.primera(); 
			camino.siguiente(itV) != camino.fin(); 
			itV = camino.siguiente(itV)){
			x = camino[itV];
			y = camino[camino.siguiente(itV)];
			//valores iniciales de las feromonas del camino(la suma de 
			//la inversa del coste del camino de cada hormiga en un tiempo t)
			FEROMONAS[x][y] += (1/hormigas[itH]->
							verticesVisitados()
							.costeCamino()
									);
			FEROMONAS[y][x] = FEROMONAS[x][y];
		}
	}
}
template <typename T>
void Tablero<T>::evaporar_feromonas(){
	for(size_t i = 0; i < adyacentes.size(); i++)
		for(size_t j = 0; j < adyacentes.size(); j++){
			FEROMONAS[i][j] *= (1 - COSTE_EVAPORACION);
			FEROMONAS[j][i] = FEROMONAS[i][j];
		}
}
template <typename T>
Camino<T> Tablero<T>::mejorCaminoActual(){
	Camino<T> mejorCamino;
	vertice maxVerticeEnTiempot; 
	//El vertice adyacente candidato a ser el siguiente mejor
	vertice VerticeEnTiempot; 
	//El vertice actual que añadiremos al camino
	T costeEnTiempot; 
	//coste actual de la feromona que estamos viendo
	T costeMax; 
	//para coger el mayor coste y posteriormente guardar el 
	//vertice anteriormente declarado
	T c; 
	//coste a asignar cuando se elija un vertice	
	//Añadimos el vertice inicial a la lista del mejor camino
	mejorCamino.nuevoNodo(inicial_, 0);
	bool visitado[adyacentes.size()];
	for(size_t i = 0; i < adyacentes.size(); i++)
		visitado[i] = false;
	//Puesto que el mejor vertice inicialmente es el inicial, es
	// al que inicializamos la variable maxVerticeEnTiempot
	VerticeEnTiempot = inicial_;
	visitado[inicial_] = true;
	while(VerticeEnTiempot != objetivo_){
		costeMax = -1;
		for(Tablero<T>::vertice v = 0; v < adyacentes.size(); v++){			
			if(adyacentes[VerticeEnTiempot][v] != INFINITO &&
			 !visitado[v]){
				costeEnTiempot = FEROMONAS[VerticeEnTiempot][v];
				if(costeMax < costeEnTiempot){
					costeMax = costeEnTiempot;
					maxVerticeEnTiempot = v;
				}
			}
		}
		c = adyacentes[VerticeEnTiempot][maxVerticeEnTiempot];
		VerticeEnTiempot = maxVerticeEnTiempot;
		mejorCamino.nuevoNodo(
			VerticeEnTiempot, 
			c
		);	
		visitado[VerticeEnTiempot] = true;
	}
	return mejorCamino;
}
/*****************OPERADOR DE INSERCIoN EN FLUJO********************/
template <typename T>
std::ostream& operator << (std::ostream& os, const Tablero<T>& tab)
{
  size_t n = tab.adyacentes.size(); //numero de vertices
  /*MOSTRAR EL GRAFO*/
  os << "*********************GRAFO*********************\n";
  for(size_t i = 0; i < n; i++) {
  	 if (i == 0) os << std::setfill(' ') << std::setw(15);
  	 os << std::setfill(' ') << std::setw(8) << i;
  }
  os << std::endl;
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
    	if(j == 0) os << i;
      if (tab[i][j] == Tablero<T>::INFINITO) 
      	os << std::setfill(' ') << std::setw(8) << "INFI";
      else  
      	os << std::setfill(' ') << std::setw(8) << 
      		std::fixed << std::setprecision(2) << tab[i][j];
    }
    os << "\n";
  }
  /*MOSTRAR FEROMONAS*/
  os << "\n**************************FEROMONAS*********************\n";
  for(size_t i = 0; i < n; i++) {
  	 if (i == 0) os << std::setfill(' ') << std::setw(15);
  	 os << std::setfill(' ') << std::setw(9) << i;
  }
  os << std::endl;
  for(size_t i = 0; i < n; i++){
    for(size_t j = 0; j < n; j++){
      if(j == 0) os << i;
      os << std::setfill(' ') << std::setw(9) << std::fixed <<
      	 std::setprecision(3) << tab.FEROMONAS[i][j];
    }
    os << "\n";
  }
  /*MOSTRAR HORMIGAS*/
  //os << "\n**************************HORMIGAS*********************\n";
  /*for(typename Lista
  			<const Hormiga<T> *>::posicion it = tab.hormigas.primera(); 
  		it != tab.hormigas.fin(); it = tab.hormigas.siguiente(it))
  			os << *(tab.hormigas[it]);*/
  return os;
}
