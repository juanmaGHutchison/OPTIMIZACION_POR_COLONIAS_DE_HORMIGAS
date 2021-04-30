# Proyecto Final de Carrera: Diseño y Fabricación de Robots basados en Arduino para realizar el Algoritmo de Colonias de Hormigas.

_El proyecto permite realizar una ejecución real del Algoritmo de Colonias de Hormigas en un robot diseñado y fabricado en Arduino, diseño del robot disponible en el mismo proyecto._

Podemos encontrar una breve explicación además de una ejecución del robot finalizado en el siguiente enlace:
* [Ejecución ACO en Arduino](https://www.youtube.com/watch?v=iJVlAWncoFY&t=352s) - Video explicativo con posterior ejecución del Algoritmo de Colonias de Hormigas.

Y tenemos otro video en el cual se detalla el montaje de dicho robot en Arduino:
* [Montaje robot ACO](https://www.youtube.com/watch?v=88lnHN8jg98) - Video explicativo del montaje del robot en Arduino.

## Descripcion de directorios y archivos

_Descripción de los directorios y archivos disponibles en el proyecto:_

* 'ACO_CPP': En este directorio se encuentran los archivos necesarios para ejecutar el Algoritmo de Colonias de Hormigas en el lenguaje C++. De este programa se ha realizado gran parte de la experimentación del archivo 'Gomez-Hutchison-JuanManuel_TFG' Capítulo 4.
* 'ACOv2_robot': En este directorio se encuentra el proyecto final realizado en Arduino el cual se cargará físicamente al Robot.
* 'ACOv2_servidor': En este directorio se encuentra la parte del servidor, el cual se encargará, entre otras funciones de comunicar a las hormigas y actualizar las feromonas del mapa.
* 'BLUETOOTH_PRUEBA': En este directorio se encuentra un código simple para testear la comunicación Bluetooth entre el Robot y el servidor.
* 'CNYboardV2.0': Directorio donde se almacena el proyecto de diseño de la PCB al que irán conectados los sensores CNY70. Podemos encontrar la información en la documentación del archivo 'Gomez-Hutchison-JuanManuel_TFG', Sección 3.3.4.1.
* 'TEST_PIEZAS_HORMIGAS': Directorio que contiene código en Arduino para el testeo de piezas individuales del Robot, sensores, actuadores... así como de algunas pruebas de integración de éstos. 
* 'shieldV2.0.1': Directorio donde se almacena el proyecto de diseño de la PCB al que irán interconectados todos los componentes electrónicos. Podemos encontrar la información en la documentación del archivo 'Gomez-Hutchison-JuanManuel_TFG', Sección 3.3.4.2.
* 'Diseño_soporte3D': Directorio que contiene el diseño del soporte de la batería de nuestro robot.
* 'Mapa': Directorior que contiene el diseño del mapa así como las imágenes listas para imprimir.
* 'Gomez-Hutchison-JuanManuel_TFG': Archivo que contiene la documentación completa del proyecto, para cualquier tipo de duda referente al proyecto, acceder a este archivo.


### Pre-requisitos 

_Que cosas necesitas para instalar el software:_

* Arduino IDE en su última versión.
* Qt creator v4.4.10 o superior.
* Opcional: Compilador clang++ para ejecución del código en C++. Compilado con Makefile.

### Instalación 

_Simplemente tendremos que cargar el código en Arduino en el robot una vez fabricado, imprimir el mapa sobre el que se lanzará al Robot, y en un PC el código del servidor creado en Qt._

## Ejecutando las pruebas 

_Para la obtención de resultados iniciamos el servidor en Qt, lanzamos el Robot en el mapa y seguimos los pasos descritos en el documento 'Gomez-Hutchison-Juanmanuel_TFG' en la Sección 3.10_

### Analice las pruebas end-to-end 

_Los resultados de las pruebas realizadas y contrastadas a la vez que justificadas las encontramos en el documento 'Gomez-Hutchison-Juanmanuel_TFG' en el Capítulo 4_

## Construido con 

_Herramientas utilizadas para el proyecto_

* [Qt creator](https://www.qt.io/product/development-tools) - Usado para hacer el programa servidor.
* [Arduino IDE](https://www.arduino.cc/) - Usado para hacer el programa del Robot en Arduino 
* [Clang](https://clang.llvm.org/) - Usado para compilar el Programa en C++
* [GnuPlot](http://www.gnuplot.info/) - Usado para generar Gráficas
* [Eagle](https://www.autodesk.com/products/eagle/overview?plc=F360&term=1-YEAR&support=ADVANCED&quantity=1) - Usado para realizar el diseño de las PCB
* [Fusion 360](https://www.autodesk.es/products/fusion-360/overview?term=1-YEAR) - Usado para realizar el diseño 3D
* [InkScape](https://inkscape.org/es/) - Usado para el diseño del mapa
* [Latex](https://es.overleaf.com) - Usado para escribir la documentación.

## Autores 

_Ayudas ofrecidas_

* **Arturo Morgado Estévez** - *Estructuración del proyecto y electrónica*
* **Abel García Otero** - *Electrónica*
* **Ignacio Díaz Cano** - *Documentación y codificación* - [ignaciodc](https://github.com/ignaciodc)


---
Realizado por [juanmaGHutchison](https://github.com/juanmaGHutchison)