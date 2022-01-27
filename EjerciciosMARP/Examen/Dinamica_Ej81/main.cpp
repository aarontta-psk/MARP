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
int patin_rec(vector<int> const& bizcocho, int i, int j, Matriz<int>& sol) {
	if (i < 0 || i >= bizcocho.size() || j < 0 || j >= bizcocho.size())
		return 0;

	int& res = sol[i][j];
	if (res == -1) {
		if (i >= j) res = 0;
		else if (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0) {
			res = max(patin_rec(bizcocho, i + 2, j, sol),
				patin_rec(bizcocho, i, j - 2, sol));
			res = max(res, patin_rec(bizcocho, i + 1, j - 1, sol) + 1);
		}
		else {
			res = max(patin_rec(bizcocho, i + 2, j, sol),
				patin_rec(bizcocho, i, j - 2, sol));
			res = max(res, patin_rec(bizcocho, i + 1, j - 1, sol));
		}
	}
	return res;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<int> pancake(n);
	for (size_t i = 0; i < n; i++)
		cin >> pancake[i];

	// escribir la solución
	Matriz<int> solV(n + 1, n + 1, -1);
	patin_rec(pancake, 0, n - 1, solV);

	cout << solV[0][n-1] << "\n";
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
