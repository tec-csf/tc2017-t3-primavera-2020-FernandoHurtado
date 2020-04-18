# Tarea 3. Técnicas de diseño de algoritmos

---

*Fernando Hurtado Chaurand* - *A01026025* - *Campus Santa Fe*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

### 2.1 Gato
Gato es un juego con dos jugadores, X y O, que toman turnos marcando los espacios en una cuadricula 3x3. El jugador que logra colocar tres de sus marcadores en horizontal, vertical, o diagonal es el ganador. 

Para ago la solucion optima es usar backtracking. Especificamente, encontre que el tipo de algoritmo backtracking mas efectivo para este tipo de juego es MinMax. MinMax es un tipo de algoritmo backtracking que involucra una prediccion de los movimientos posibles en un juego de turnos para encontrar el mejor resultado para el jugador.

La implementacion es relativamente simple, en pseudocodigo:
```
funcion minmax(posicion, profundidad, max)
	limite de profundidad = 4
	if la profundidad es igual al limite de profundidad
		regresar evaluacion de la posicion
	
	if max
		evaluacionmax = -1000
		por cada hijo de posicion:
			evaluacion = minmax (hijo, profundidad + 1, falso)
			maxevaluacion = max(maxevaluacion, evaluacion)
		regresar maxevaluacion

	else
		evaluacionmin = -1000
		por cada hijo de posicion:
			evaluacion = minmax (hijo, profundidad + 1, falso)
			minevaluacion = min(maxevaluacion, evaluacion)
		regresar minevaluacion

```
estoy limitando la profundidad a 4.
la complejidad en el peor de los casos es n, ya que la recursividad tiene una condicion de parar y cada nivel de recursion baja geometricamente a las condiciones de parar. 
	
 
## 3. Referencias

1. https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
2. https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/


