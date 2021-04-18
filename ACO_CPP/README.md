# Algoritmo de Colonias de Hormigas en C++.

_Código en C++ para la ejecución completa del Algoritmo de Colonias de Hormigas, este código es independiente del robot, se puede ejecutar para la comprobación de resultados._

## Descripción de archivos del directorio

_Descripción de los archivos disponibles en este directorio:_

* 'camino.hpp': Contiene todo lo referente a los caminos que tome la hormiga así como de crear el mapa (Grafo).
* 'hormigas.hpp': Contiene las operaciones y atributos que definen una hormiga.
* 'listaenla.hpp': Se utiliza el ##Tipo Abstracto de Datos## Lista con la implementación de nodos enlazados para guardar el recorrido que ha tomado una hormiga para así derivar posteriormente, su costo.
* 'Makefile': Script para compilar el código descrito en este directorio ejecutando el comando 'make' se generará automáticamente el archivo ejecutable. Se utiliza el compilador 'Clang++'.
* 'pt.cpp': La iniciales del archivo 'pt' significan 'prueba tablero', hace referencia al código principal de ejecución.
* 'tablero.hpp': Este archivo es el más importante ya que enlaza casi todas las clases implementadas con la principal 'pt.cpp'.

Todo lo mencionado en este apartado lo podemos encontrar en la Sección 3.2.3.


### Pre-requisitos 

_Que cosas necesitas para instalar el software:_

* Compilador clang++ para ejecución del código en C++. 
* Ejecutar el archivo 'Makefile' sobre una terminal Linux.

### Instalación 

_Posicionado con una terminal en Linux sobre este directorio ejecutamos el comando:_

```
make
```

## Ejecutando las pruebas 

_Para la ejecución del código en C++ después de completar la ##Instalación## se generará el archivo 'test-tablero' el cual será ejecutable_

```
./test-tablero
```

## Construido con 

_Herramientas utilizadas para el proyecto_

* [Clang](https://clang.llvm.org/) - Usado para compilar el Programa en C++


---
Realizado por [juanmaGHutchison](https://github.com/juanmaGHutchison)