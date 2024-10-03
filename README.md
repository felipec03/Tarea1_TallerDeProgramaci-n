# Tarea 1 - Taller de Programación!
***
*Este repositorio contiene la tarea 1 del ramo de Taller de Programación, Ingeniería Civil en Informática de la USACH.*

> La tarea tiene por finalidad resolver el **problema de los n-bidones**, donde, dado un conjunto inicial de $n$ bidones, $A_1, \dots, A_{i-1}, A_i, A_{i+1}, \dots, A_n$, con una capacidad máxima determinada, llegar por medio de operaciones a un arreglo de igual tamaño con cierta cantidad de agua, considerando las limitaciones.

Las operaciones en cuestión son:
- Llenar bidón
- Vaciar bidón
- Trasvasijar un bidón a otro

**La finalidad del programa es encontrar el camino más corto de operaciones para llegar al arreglo objetivo de bidones.**

Esta tarea contiene uso de estructuras cómo la cola, cola de prioridad (heap) y árboles. Para el árbol se utilizará el algoritmo A*, lo que comprende el uso de funciones heurísticas.