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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
vector<int> maxPunts(vector<vector<int>>& table, unsigned int n) {
	Matriz<int> check(n + 1, n + 2, 0);

	/*for (size_t j = 0; j <= n + 1; j++)
		check[0][j] = 0;*/

	for (size_t i = 1; i <= n; i++) {
		//check[i][0] = 0; check[i][n + 1] = 0;
		for (size_t j = 1; j <= n; j++) {
			check[i][j] = max(check[i - 1][j - 1], check[i - 1][j]);
			check[i][j] = max(check[i][j], check[i - 1][j + 1]) + table[i - 1][j - 1];
		}
	}
	return check[n];
}

bool resuelveCaso() {

	// leer los datos de la entrada
	unsigned int n;
	cin >> n;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<vector<int>> table(n, vector<int>(n));
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			cin >> table[i][j];

	auto sol = maxPunts(table, n);
	int solNum = -1, index = 0;
	for (size_t t = 1; t <= n; t++) {
		int auxSol = solNum;
		solNum = max(solNum, sol[t]);
		if (solNum > auxSol) index = t;
	}

	// escribir la solución
	cout << solNum << " " << index << "\n";

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
