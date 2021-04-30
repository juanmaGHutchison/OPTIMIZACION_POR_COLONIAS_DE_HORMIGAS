# Proyecto Final de Carrera: Dise�o y Fabricaci�n de Robots basados en Arduino para realizar el Algoritmo de Colonias de Hormigas.

_El proyecto permite realizar una ejecuci�n real del Algoritmo de Colonias de Hormigas en un robot dise�ado y fabricado en Arduino, dise�o del robot disponible en el mismo proyecto._

Podemos encontrar una breve explicaci�n adem�s de una ejecuci�n del robot finalizado en el siguiente enlace:
* [Ejecuci�n ACO en Arduino](https://www.youtube.com/watch?v=iJVlAWncoFY&t=352s) - Video explicativo con posterior ejecuci�n del Algoritmo de Colonias de Hormigas.

Y tenemos otro video en el cual se detalla el montaje de dicho robot en Arduino:
* [Montaje robot ACO](https://www.youtube.com/watch?v=88lnHN8jg98) - Video explicativo del montaje del robot en Arduino.

## Descripcion de directorios y archivos

_Descripci�n de los directorios y archivos disponibles en el proyecto:_

* 'ACO_CPP': En este directorio se encuentran los archivos necesarios para ejecutar el Algoritmo de Colonias de Hormigas en el lenguaje C++. De este programa se ha realizado gran parte de la experimentaci�n del archivo 'Gomez-Hutchison-JuanManuel_TFG' Cap�tulo 4.
* 'ACOv2_robot': En este directorio se encuentra el proyecto final realizado en Arduino el cual se cargar� f�sicamente al Robot.
* 'ACOv2_servidor': En este directorio se encuentra la parte del servidor, el cual se encargar�, entre otras funciones de comunicar a las hormigas y actualizar las feromonas del mapa.
* 'BLUETOOTH_PRUEBA': En este directorio se encuentra un c�digo simple para testear la comunicaci�n Bluetooth entre el Robot y el servidor.
* 'CNYboardV2.0': Directorio donde se almacena el proyecto de dise�o de la PCB al que ir�n conectados los sensores CNY70. Podemos encontrar la informaci�n en la documentaci�n del archivo 'Gomez-Hutchison-JuanManuel_TFG', Secci�n 3.3.4.1.
* 'TEST_PIEZAS_HORMIGAS': Directorio que contiene c�digo en Arduino para el testeo de piezas individuales del Robot, sensores, actuadores... as� como de algunas pruebas de integraci�n de �stos. 
* 'shieldV2.0.1': Directorio donde se almacena el proyecto de dise�o de la PCB al que ir�n interconectados todos los componentes electr�nicos. Podemos encontrar la informaci�n en la documentaci�n del archivo 'Gomez-Hutchison-JuanManuel_TFG', Secci�n 3.3.4.2.
* 'Dise�o_soporte3D': Directorio que contiene el dise�o del soporte de la bater�a de nuestro robot.
* 'Mapa': Directorior que contiene el dise�o del mapa as� como las im�genes listas para imprimir.
* 'Gomez-Hutchison-JuanManuel_TFG': Archivo que contiene la documentaci�n completa del proyecto, para cualquier tipo de duda referente al proyecto, acceder a este archivo.


### Pre-requisitos 

_Que cosas necesitas para instalar el software:_

* Arduino IDE en su �ltima versi�n.
* Qt creator v4.4.10 o superior.
* Opcional: Compilador clang++ para ejecuci�n del c�digo en C++. Compilado con Makefile.

### Instalaci�n 

_Simplemente tendremos que cargar el c�digo en Arduino en el robot una vez fabricado, imprimir el mapa sobre el que se lanzar� al Robot, y en un PC el c�digo del servidor creado en Qt._

## Ejecutando las pruebas 

_Para la obtenci�n de resultados iniciamos el servidor en Qt, lanzamos el Robot en el mapa y seguimos los pasos descritos en el documento 'Gomez-Hutchison-Juanmanuel_TFG' en la Secci�n 3.10_

### Analice las pruebas end-to-end 

_Los resultados de las pruebas realizadas y contrastadas a la vez que justificadas las encontramos en el documento 'Gomez-Hutchison-Juanmanuel_TFG' en el Cap�tulo 4_

## Construido con 

_Herramientas utilizadas para el proyecto_

* [Qt creator](https://www.qt.io/product/development-tools) - Usado para hacer el programa servidor.
* [Arduino IDE](https://www.arduino.cc/) - Usado para hacer el programa del Robot en Arduino 
* [Clang](https://clang.llvm.org/) - Usado para compilar el Programa en C++
* [GnuPlot](http://www.gnuplot.info/) - Usado para generar Gr�ficas
* [Eagle](https://www.autodesk.com/products/eagle/overview?plc=F360&term=1-YEAR&support=ADVANCED&quantity=1) - Usado para realizar el dise�o de las PCB
* [Fusion 360](https://www.autodesk.es/products/fusion-360/overview?term=1-YEAR) - Usado para realizar el dise�o 3D
* [InkScape](https://inkscape.org/es/) - Usado para el dise�o del mapa
* [Latex](https://es.overleaf.com) - Usado para escribir la documentaci�n.

## Autores 

_Ayudas ofrecidas_

* **Arturo Morgado Est�vez** - *Estructuraci�n del proyecto y electr�nica*
* **Abel Garc�a Otero** - *Electr�nica*
* **Ignacio D�az Cano** - *Documentaci�n y codificaci�n* - [ignaciodc](https://github.com/ignaciodc)


---
Realizado por [juanmaGHutchison](https://github.com/juanmaGHutchison)