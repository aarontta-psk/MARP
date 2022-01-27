/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"
#include "EnterosInf.h"

using namespace std;

/*@ <answer>


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Concert {
	int groups;
	int cost;
};

istream& operator >> (istream& in, Concert& s) {
	in >> s.groups >> s.cost;
	return in;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int p, n;
	cin >> p >> n;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<Concert> concerts(n);
	for (size_t i = 0; i < n; i++)
		cin >> concerts[i];

	// escribir la solución
	vector<int> solV(p + 1, 0);
	for (size_t i = 1; i <= n; i++) {
		for (size_t j = p; j >= concerts[i - 1].cost; j--) {
			if (concerts[i - 1].cost > j)
				solV[j] = solV[j];
			else
				solV[j] = max(solV[j - concerts[i - 1].cost] + concerts[i - 1].groups, solV[j]);
		}
	}

	cout << solV[p] << "\n";
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
