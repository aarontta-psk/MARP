/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
struct House {
	int west, east;

	bool operator < (const House& h) const {
		return east < h.east;
	}
};

istream& operator>>(istream& in, House& h) {
	in >> h.west >> h.east;
	return in;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n; cin >> n;
	if (!n)
		return false;

	vector<House> houses(n);
	for (size_t i = 0; i < n; i++)
		cin >> houses[i];

	sort(houses.begin(), houses.end());

	// resolver el caso posiblemente llamando a otras funciones
	int lastEnd = 0, numCaves = 0;
	for (size_t i = 0; i < n; i++)
		if (houses[i].west >= lastEnd) {
			numCaves++;
			lastEnd = houses[i].east;
		}

	// escribir la solución
	cout << numCaves << "\n";

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
