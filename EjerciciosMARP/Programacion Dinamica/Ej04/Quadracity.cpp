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
int caminos(vector<vector<char>> const& table, unsigned int n, unsigned int m) {
	vector<int> check(m + 1, 0);

	/*for (size_t j = 0; j <= n + 1; j++)
		check[0][j] = 0;*/

	check[1] = 1;

	for (size_t i = 1; i <= n; i++)
		for (size_t j = 1; j <= m; j++) {
			if (table[i - 1][j - 1] != 'P')
				check[j] = check[j - 1] + check[j];
			else check[j] = 0;
		}

	// si depende de uno del mismo vector que tal si te acuerdas de hacerlo bien crack

	return check[m];
}

bool resuelveCaso() {

	// leer los datos de la entrada
	unsigned int n, m;
	cin >> n >> m;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<vector<char>> table(n, vector<char>(m));
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			cin >> table[i][j];

	// escribir la solución
	cout << caminos(table, n, m) << "\n";

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
