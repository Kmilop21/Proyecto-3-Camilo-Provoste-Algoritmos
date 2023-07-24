# Proyecto-3-Camilo-Provoste-Algoritmos

Este proyecto hace una ***carrera*** de algoritmos

Este archivo hace el uso de una serie de funciones para implementar 7 algoritmos de ordenamiento de datos, 3 de ellos haciendo uso de funciones adicionales que permitan recursividad. Luego estos son llamados en una funcion que toma el tiempo de inicio y de fin de cada uno de los algoritmos para calcular el tiempo demorado.

Por estos 7 algoritmos, pasan 3 sets de datos ordenados de 4 maneras diferentes, ordenado ascendentemente, ordenado descendentemente, ordenado aleatoriamente con repeticion y ordenado aleatoriamente sin repeticion, formando en total 12 sets de datos que pasan a travez de los 7 algoritmos para que estos compitan por ser el mas rapido.

Para la implementacion de estos 12 sets de datos, se hizo uso de una **clase** llamada ***Data*** que contiene los 3 sets de datos originales con sus rangos correspondientes (90.000 a 100.000, 50.000 a 70.000 y 500 a 1.000). Estos 3 sets de datos son parte de una **estructura incrustada** en la clase, llamada ***Set***, la cual contiene la informacion de el rango menor y el rango mayor, para luego sacar un numero aleatorio entre esos rangos, volviendose el maximo del set. Dentro de esta clase uncrustada hay **otra clase incrustada** llamada ***order*** que contiene un vector de numeros enteros (los datos del set), un vector de numeros flotantes (el tiempo para cada algoritmo) y un ultimo vector con el nombre de cada algoritmo.

En la clase data hay funciones que permiten generar los sets de datos en los 4 ordenes, conseguir informacion para ellos, hacer la carrera y calculcar y mostrar los resultados.

***LINK VIDEO: ***  https://youtu.be/tC1oJfz3Go8