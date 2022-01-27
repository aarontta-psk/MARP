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
int patin_rec(string const& bizcocho, int i, int j, Matriz<int>& sol) {
	int& res = sol[i][j];
	if (res == -1) {
		if (i >= j) res = 1;
		else if (bizcocho[i] == bizcocho[i + 1]) 
			res = patin_rec(bizcocho, i + 1, j, sol);
		else if (bizcocho[j] == bizcocho[j - 1]) 
			res = patin_rec(bizcocho, i, j - 1, sol);
		else if (bizcocho[i] == bizcocho[j]) 
			res = patin_rec(bizcocho, i + 1, j - 1, sol) + 1;
		else 
			res = min(patin_rec(bizcocho, i + 1, j, sol), patin_rec(bizcocho, i, j - 1, sol)) + 1;
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
	string pancake;
	for (size_t i = 0; i < n; i++)
		cin >> pancake;

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
