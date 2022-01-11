/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

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
struct comparator {
	bool operator()(int a, int b) {
		return b < a;
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int n; cin >> n;
	if (!n)
		return false;

	priority_queue<int, vector<int>, comparator> addQueue;

	for (size_t i = 0; i < n; i++) {
		int value; cin >> value;
		addQueue.push(value);
	}

	// resolver el caso posiblemente llamando a otras funciones
	int cost = 0;
	while (addQueue.size() != 1) {
		int minV = addQueue.top(); addQueue.pop();
		minV += addQueue.top(); addQueue.pop();
		cost += minV;
		addQueue.push(minV);
	}

	// escribir la solución
	cout << cost << "\n";

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
