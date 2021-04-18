#ifndef MAP_HPP_
#define MAP_HPP_
#include "Arduino.h"
#include "COMMON_TYPES.hpp"
#include "RATIONAL.hpp"
class Map {
    public:
         /*************************************************************
        *					ATRIBUTOS DE PÚBLICOS					  *
        **************************************************************/     
        /*const size_t alpha = 1;
        const size_t beta = 1;
        const float LEARNING = 1.;
        const float EVAPORATION = 0.01;*/
        static const unsigned int n_ = 6;
        Rational_number PHEROMONES[n_][n_];
        bool VISITED[n_];
        uint8_t map_[n_][n_] = 
        {
          {0,4,1,INF,3,INF},
          {4,0,2,INF,INF,4},
          {1,2,0,INF,1,6},
          {INF,INF,INF,0,1,9},
          {3,INF,1,1,0,INF},
          {INF,4,6,9,INF,0}
        };
        uint8_t grades[n_][n_] = 
        {
          {0,1,0,INF,3,INF},
          {2,0,3,INF,INF,0},
          {2,1,0,INF,3,0},
          {INF,INF,INF,0,2,0},
          {2,INF,1,0,0,INF},
          {INF,2,3,0,INF,0}
        };
        uint8_t stragihten_grades[n_][n_] = 
        {
          {0,0,0,INF,0,INF},
          {1,0,1,INF,INF,0},
          {2,3,0,INF,1,3},
          {INF,INF,INF,0,2,2},
          {3,INF,3,0,0,INF},
          {INF,2,2,2,INF,0}
        };        
//        static const unsigned int n_ = 6;
//
//        uint8_t map_[n_][n_] = 
//        {
//          {0,4,1,INF,3,INF},
//          {4,0,2,INF,INF,4},
//          {1,2,0,INF,1,6},
//          {INF,INF,INF,0,7,5},
//          {3,INF,1,7,0,INF},
//          {INF,4,6,5,INF,0}
//        };
//
//        uint8_t grades[n_][n_] = 
//        {
//          {0,1,0,INF,3,INF},
//          {2,0,3,INF,INF,0},
//          {2,1,0,INF,3,0},
//          {INF,INF,INF,0,3,1},
//          {2,INF,1,0,0,INF},
//          {INF,2,3,0,INF,0}
//        };
//
//        uint8_t stragihten_grades[n_][n_] = 
//        {
//          {INF,0,0,INF,0,INF},
//          {1,0,1,INF,INF,0},
//          {2,3,0,INF,1,3},
//          {INF,INF,INF,0,2,2},
//          {3,INF,3,3,0,INF},
//          {INF,2,2,1,INF,0}
//        };
//        static const unsigned int n_ = 7;
//        uint8_t map_[n_][n_] =
//        {
//            {0,4,2,INF,INF,5,INF},
//            {4,0,2,INF,INF,INF,3},
//            {2,2,0,INF,INF,2,7},
//            {INF,INF,INF,0,6,INF,5},
//            {INF,INF,INF,6,0,3,INF},
//            {5,INF,2,INF,3,0,INF},
//            {INF,3,7,5,INF,INF,0}
//        };
//        uint8_t grades[n_][n_] = 
//        {
//            {0,1,0,INF,INF,3,INF},
//            {2,0,3,INF,INF,INF,0},
//            {2,1,0,INF,INF,3,0},
//            {INF,INF,INF,0,3,INF,1},
//            {INF,INF,INF,0,0,2,INF},
//            {2,INF,1,INF,0,0,INF},
//            {INF,2,3,0,INF,INF,0}
//        };
//        uint8_t stragihten_grades[n_][n_] = 
//        {
//          {0,0,0,INF,INF,0,INF},
//          {1,0,1,INF,INF,INF,0},
//          {2,3,0,INF,INF,1,3},
//          {INF,INF,INF,0,2,INF,2},
//          {INF,INF,INF,3,0,2,INF},
//          {3,INF,3,INF,0,0,INF},
//          {INF,2,2,1,INF,INF,0}
//        };               
        /*Actualización de feromonas
            PRECONDICIÓN: las feromonas han sido inicializadas
            POSTCONDICIÓN: actualiza las feromonas utilizando 
              la fórmula de actualización de feromonas
        */
        void grades_toogle_conversion();
        void modify_pheromones_from_str(String str);
        /**************************************************************
        *					DECLARACIÓN DE SUBTIPOS								 *
        **************************************************************/
        typedef uint8_t summit; 
        //Vértices del grafo(nodos)        
        static const uint8_t INF; 
        //Coste infinito entre dos nodos(no hay camino directo entre ellos)
        /***************************************************************
        *						OPERACIONES DEL TAD TABLERO					  *
        ***************************************************************/        
        /*CONSTRUCTOR sobrecargado para crear el tablero
            PRECONDICIÓN: el parámetro formal N debe ser > 0
            POSTCONDICIÓN: crea un tablero nuevo, asigna el tamaño a las feromonas
              e inicializa la lista de hormigas.
        */
        explicit Map(summit initial);                
        /*Método para hacer avanzar una hormiga de un nodo al siguiente utilizando 
         *  la fórumla de la probabilidad sobre la cuál se elige uno arbitráreamente 
         *  y condicionado según su probabilidad. 
            PRECONDICIÓN: el nodo pasado por parámetro tiene al menos un adyacente. 
              El nodo no es el nodo objetivo. La hormiga h está recorriendo el tablero.
            POSTCONDICIÓN: devuelve el siguiente nodo por el que pasará la hormiga
        */
        summit next_node(summit x);       
        /*Método para saber la distancia de un punto x a otro y, 
         *  se utiliza la formula de la distancia
            PRECONDICIÓN: ambos parámetros son adyacentes entre sí, 
              puesto que el grafo es no dirigido, con el que el primer
              parámetro sea adyacente al segundo nos vale
            POSTCONDICION: devuelve la distancia entre dos puntos
        */
        uint8_t distance(uint8_t x, uint8_t y);       
        /*Método observador del nodo inicial
            PRECONDICIÓN: -
            POSTCONDICIÓN: devuelve el vertice inicial
        */
        summit initial(){
            return initial_;
        }
        /*Método observador del nodo actual
            PRECONDICIÓN: -
            POSTCONDICIÓN: devuelve el vertice actual
        */
        summit actual(){
            return actual_node_;
        }

        /*Método modificador del nodo inicial
            PRECONDICIÓN: -
            POSTCONDICIÓN: devuelve el vertice actual
        */
        void actual(summit actual){
            actual_node_ = actual;
        }
        /*Método observador del nodo actual
            PRECONDICIÓN: -
            POSTCONDICIÓN: devuelve el vertice actual
        */
        summit previous(){
            return previous_node_;
        }
        //String print_adjacent_list() const;
        void restart_visited();
        int number_of_adjacents() const;
        private:
        /**************************************************************
        *						DECLARACIÓN DE TIPOS PRIVADOS		  *
        **************************************************************/
        int adjacent_[4];
        summit actual_node_, previous_node_;
        summit initial_;
        /**************************************************************
        *						DECLARACIÓN DE METODOS PRIVADOS		  *
        **************************************************************/
        void adjacent_list(summit x);
};
#endif
