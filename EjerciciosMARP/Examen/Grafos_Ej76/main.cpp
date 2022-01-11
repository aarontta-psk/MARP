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
#include <string>
#include <vector>
#include <limits>

#include "Ovejas.h"

using namespace std;

/*@ <answer>

	- A la hora de resolver la solcuión, primero construimos el grafo dirigido. Luego, utilizando el algoritmo de Dijkstra,
	  obtenemos las distancias de ida (de O a P); y, para obtener las distancias de vuelta, volevemos a aplicar Dijkstra,
	  pero en este caso comprobamos las distancias utilizando la inversa del grafo dirigido (para así obtener distancia de P a O,
	  sin tener que alterar el algoritmo ni hacerlo por cada casa). Tras ello, leemos las casas a revisar su distancia con minimo esfuerzo,
	  e imprimimos su valor en caso de que haya conexion con todas ellas (en caso contrario, imprimimos "Imposible").

	* Coste algoritmo: O(C * log(N) + P), siendo C * log(N) el coste del algoritmo de Dijkstra (se dan C vueltas a lo
	  sumo, costando cada vuelta como mucho O(log(N)) por el .update() de la cola de prioridad variable);
	  más P vueltas para imprimir la solucion (siendo P el numero de casa a repartir)

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
bool resuelveCaso() {

	// leemos la entrada
	int F, C;
	cin >> C >> F;
	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	vector<string> pictures;
	for (size_t i = 0; i < F; i++) {
		string line; cin >> line;
		pictures.push_back(line);
	}

	Ovejas sol(pictures, F, C);

	cout << sol.ovejas() << "\n";

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
