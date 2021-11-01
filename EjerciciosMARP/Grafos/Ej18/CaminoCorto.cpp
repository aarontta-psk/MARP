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
	if (!std::cin)
		return false;

	DigrafoValorado<int> graph(n);
	int c; cin >> c;
	for (int j = 0; j < c; ++j) {
		int og, dst, value; cin >> og >> dst >> value;
		graph.ponArista({ --og, --dst, value });
		graph.ponArista({ dst, og, value });
	}

	// resolver el caso posiblemente llamando a otras funciones
	int k; cin >> k;
	for (size_t i = 0; i < k; i++) {
		int og, dst; cin >> og >> dst;
		Dijkstra<int> sol(graph, --og, --dst);

		// escribir la solución
		if (!sol.isReachable())
			cout << "SIN CAMINO\n";
		else
			cout << sol.distStreet() << " " << (sol.minStreetsToDst() ? "SI" : "NO") << "\n";
	}

	cout << "\n";

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
