# Algoritmo de Colonias de Hormigas en C++.

_C�digo en C++ para la ejecuci�n completa del Algoritmo de Colonias de Hormigas, este c�digo es independiente del robot, se puede ejecutar para la comprobaci�n de resultados._

## Descripci�n de archivos del directorio

_Descripci�n de los archivos disponibles en este directorio:_

* 'camino.hpp': Contiene todo lo referente a los caminos que tome la hormiga as� como de crear el mapa (Grafo).
* 'hormigas.hpp': Contiene las operaciones y atributos que definen una hormiga.
* 'listaenla.hpp': Se utiliza el ##Tipo Abstracto de Datos## Lista con la implementaci�n de nodos enlazados para guardar el recorrido que ha tomado una hormiga para as� derivar posteriormente, su costo.
* 'Makefile': Script para compilar el c�digo descrito en este directorio ejecutando el comando 'make' se generar� autom�ticamente el archivo ejecutable. Se utiliza el compilador 'Clang++'.
* 'pt.cpp': La iniciales del archivo 'pt' significan 'prueba tablero', hace referencia al c�digo principal de ejecuci�n.
* 'tablero.hpp': Este archivo es el m�s importante ya que enlaza casi todas las clases implementadas con la principal 'pt.cpp'.

Todo lo mencionado en este apartado lo podemos encontrar en la Secci�n 3.2.3.


### Pre-requisitos 

_Que cosas necesitas para instalar el software:_

* Compilador clang++ para ejecuci�n del c�digo en C++. 
* Ejecutar el archivo 'Makefile' sobre una terminal Linux.

### Instalaci�n 

_Posicionado con una terminal en Linux sobre este directorio ejecutamos el comando:_

```
make
```

## Ejecutando las pruebas 

_Para la ejecuci�n del c�digo en C++ despu�s de completar la ##Instalaci�n## se generar� el archivo 'test-tablero' el cual ser� ejecutable_

```
./test-tablero
```

## Construido con 

_Herramientas utilizadas para el proyecto_

* [Clang](https://clang.llvm.org/) - Usado para compilar el Programa en C++


---
Realizado por [juanmaGHutchison](https://github.com/juanmaGHutchison)