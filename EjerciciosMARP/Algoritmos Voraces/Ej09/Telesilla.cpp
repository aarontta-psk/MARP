/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Aarón Nauzet Moreno Sosa
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


/*@ <answer>

	Estrategia voraz: Emparejar en cada silla a la persona de mayor peso con la de 
	menor peso (de entre las disponibles) si cumplen que su suma de pesos es soportable.
	En caso contrario, ponemos solo a la persona con mayor peso en la silla (ya que se garantiza
	que la silla siempre podrá soportar al menos a una persona)

	Para hacer eficiente el algoritmo, ordenoamos los pesos de menor a mayor en un vector, 
	y guardamos los índices de la persona con mayor y menor peso [vector.size() -1 y 0 al 
	principio]. Si la suma de ambos pesos es menor o igual que el peso permitido, avanzamos 
	los indices en sus respectivas direcciones [-- y ++ respectivamente], y en caso de que se
	sobrepasase el peso, solo avanzamos el indice del peso mayor, pues solo podrá usar una silla
	si está solo, ya que no puede con el minimo peso disponible. En cualquier caso, añadimos una 
	silla al contador.

	Coste: O(N*log(N)) [debido al uso del metodo sort() para oredenar el vector de menor a mayor],
	siendo N el numero de esquiadores

	Demostración:
	- Solución: Conjunto de parejas de esquiadores

	  Preparamos la solución, haciendo que en cada pareja (xi, yi) se cumpla que xi >= yi;
	  y luego ordenamos la secuencia de mayor a menor con respecto al esquiador xi [xi-1 >= xi >= xi+1].
	  así, sin cambiar las soluciones, reducimos diferencias triviales en la demostración.

	· Sol. voraz X:   (a1, b1) (a2, b2) ... | (ai, bi) ...
					      =        =        |    !=
	· Sol. optima Y:  (c1, d1) (c2, d2) ... | (ci, di) ...

	
	- Podemos asegurar que ai == ci, debido a que:
	· Si ai > ci, quiere decir que ai estaría a la derecha de la sucesión óptima, lo cual no
	  puede ocurrir ya que hemos ordenado la sucesión de mayor a menor con respecto al elemento xi,
	  y no se cumpliria que xi-1 >= xi >= xi+1 para cualquier i de la sucesion.
    · Si ci > ai, no se puede dar, porque si esto ocurriese, el algoritmo voraz hubiese seleccionado ci.

	- Partiendo de que ai == ci, miramos las posibles diferencias en el segundo esquiador del par:

		* En caso de que bi > 0 y di > 0 (es decir, ambos pares tienen una pareja de 
		  esquiadores cada uno)

		- bi > di: no puede ocurrir, porque el algoritmo voraz siempre empareja el mayor peso con el 
		  menor peso disponible, y si esto ocurriese, se hubiese seleccionado di y entonces di = bi.
		- di > bi: 
			· Sol. voraz X:   (a1, b1) (a2, b2) .... | (ai, bi) ...
							      =        =         |    !=
			· Sol. óptima Y:  (c1, d1) (c2, d2) .... | (ci, di)  ...  (cj, bi) ...

			- Tratamos de intercambiar bi con di:
				· ci + bi <= maxWeight, ya que ci + di <= maxWeight ^ bi < di
				· cj + di <= maxWeight, ya que ci + di <= maxWeight ^ cj < ci
			- Podemos intercambiar, y la solución sigue siendo óptima

		* En caso de que bi == 0 ó di == 0 (es decir, algun par no tiene una pareja de
		  esquiadores)

		- bi == 0: no puede ocurrir, porque el algoritmo voraz siempre empareja el mayor peso con el
		  menor peso disponible, y si esto ocurriese, se hubiese seleccionado, como mínimo, di.
		- di == 0: 
			· Sol. voraz X:   (a1, b1) (a2, b2) .... | (ai, bi) ...
	     					      =        =         |    !=
			· Sol. óptima Y:  (c1, d1) (c2, d2) .... | (ci, di)  ...  (cj, bi) ...

			- Tratamos de intercambiar bi con di:
				· ci + bi <= maxWeight, ya que ai + bi <= maxWeight ^ ai == ci
				· cj + di <= maxWeight, ya que cj + bi <= maxWeight ^ di == 0 < bi
			- Podemos intercambiar, y la solución sigue siendo óptima

		- También podemos asegurar que numParejasY == numParejasX, ya que si hubiesen mas parejas en la
		  solución óptima, la estrategia voraz la hubiese añadido a la solución; y si hubiesen más parejas
		  en la solución voraz, directamente la solución optima Y no sería ni solcuión, ya que eso implicaría que 
		  no todos los esquiadores viajan en la telesilla.

	Así podemos hacer que la solución voraz esté contenida en una solución óptima Y', por lo tanto 
	la solución voraz es óptima.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int numChairs(const vector<int>& skiers, const int maxWeight) {
	int minW = 0, maxW = skiers.size() - 1;
	int numChairs = 0;
	while (maxW >= 0 && minW <= maxW) {
		// if both the min and max fit, we add both min and max
		if (skiers[minW] + skiers[maxW] <= maxWeight)
			minW++;

		numChairs++; maxW--;
	}

	return numChairs;
}

bool resuelveCaso() {

	// leemos la entrada
	int maxWeight, N;
	cin >> maxWeight >> N;

	if (!cin)
		return false;

	vector<int> skiers(N);
	for (int& x : skiers)
		cin >> x;

	sort(skiers.begin(), skiers.end());

	// resolver el caso

	cout << numChairs(skiers, maxWeight) << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
