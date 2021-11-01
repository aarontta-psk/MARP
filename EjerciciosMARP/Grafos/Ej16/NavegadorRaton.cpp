/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

#include "DigrafoValorado.h"
#include "Dijkstra.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

	// leer los datos de la entrada
	int n; cin >> n;
	if (!n)
		return false;

	vector<int> loadTimes;

	for (int i = 0; i < n; ++i) {
		int load; cin >> load;
		loadTimes.push_back(load);
	}

	DigrafoValorado<int> graph(n);
	int a; cin >> a;
	for (int j = 0; j < a; ++j) {
		int og, dst, value; cin >> og >> dst >> value;
		graph.ponArista({ --og, --dst, value + loadTimes[dst] });
	}

	// resolver el caso posiblemente llamando a otras funciones
	Dijkstra<int> sol(graph, 0);

	// escribir la solución
	if (sol.reachingPageCost() == std::numeric_limits<int>::max())
		cout << "IMPOSIBLE\n";
	else cout << sol.reachingPageCost() + loadTimes[0] << "\n";

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

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
