#include "tablero.hpp"
#include "hormigas.hpp"
#include <iostream>
using namespace std;
int main(){
	size_t n = 6;
	typedef typename Tablero<float>::tCoste tCoste;
	typedef typename Tablero<tCoste>::vertice  vertice;
	Hormiga<tCoste> h1(1),h2(2),h3(3),h4(4)
		,h5(5),h6(6),h7(7),h8(8);
	vertice inicial = 0;
	vertice objetivo = 3;
	Tablero<tCoste> tab(n, inicial, objetivo);
	vertice actual = tab.inicial();
	tab[0][1] = tab[1][0] = 4;
	tab[0][2] = tab[2][0] = 1;
	tab[0][4] = tab[4][0] = 3;
	tab[1][5] = tab[5][1] = 4;
	tab[1][2] = tab[2][1] = 2;
	tab[2][5] = tab[5][2] = 6;
	tab[2][4] = tab[4][2] = 1;
	tab[3][4] = tab[4][3] = 1;
	tab[3][5] = tab[5][3] = 9;
	tab.nuevaHormiga(&h1);
	tab.nuevaHormiga(&h2);
	tab.nuevaHormiga(&h3);
	tab.nuevaHormiga(&h4);
	tab.nuevaHormiga(&h5);
	tab.nuevaHormiga(&h6);
	/*tab.nuevaHormiga(&h7);
	tab.nuevaHormiga(&h8);*/
	tab.hormigaBuscaComida(&h3);
	tab.hormigaBuscaComida(&h1);
	for(size_t i = 0; i < 10000; i++){
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h1);
		actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h2);
		actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h3);
		actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h4);
		actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h5);
		actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h6);
		/*actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h7);
		actual = tab.inicial();
		while(!tab.esObjetivo(actual))
			actual = tab.siguienteNodo(actual, &h8);*/
		tab.actualizar_feromonas();
		h1.volver();
		h2.volver();
		h3.volver();
		h4.volver();
		h5.volver();
		h6.volver();
		/*h7.volver();
		h8.volver();*/
		/*h1.volver();
		tab.actualizar_feromonas();*/
		//cout << tab << endl;
	}
	cout << tab << endl;
	cout << tab.mejorCaminoActual() << endl;
}
