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

int succesfulDefenses(vector<int> invTeams, vector<int> defTeams) {
	int j = 0, count = 0;

	for (size_t i = 0; i < defTeams.size(); i++) {
		if (defTeams[i] >= invTeams[j]) {
			count++;
			j++;
		}
	}

	return count;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> invTeams(n), defTeams(n);
	for (size_t i = 0; i < n; i++)
		cin >> invTeams[i];
	for (size_t i = 0; i < n; i++)
		cin >> defTeams[i];

	sort(invTeams.begin(), invTeams.end());
	sort(defTeams.begin(), defTeams.end());

	// resolver el caso posiblemente llamando a otras funciones
	cout << succesfulDefenses(invTeams, defTeams) << "\n";

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
