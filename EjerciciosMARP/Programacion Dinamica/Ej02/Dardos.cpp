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
vector<EntInf> resolver(vector<int>& secciones, int value) {
	vector<EntInf> secc(value + 1, Infinito);
	secc[0] = 0;

	for (size_t i = 0; i < secciones.size(); i++)
		for (size_t j = secciones[i]; j < secc.size(); j++)
			secc[j] = min(secc[j], secc[j - secciones[i]] + 1);

	vector<EntInf> sol;
	if (secc[value] != Infinito) {
		int i = secciones.size() - 1, j = value;
		while (j > 0) {
			if (secciones[i] <= j && secc[j] == secc[j - secciones[i]] + 1) {
				sol.push_back(secciones[i]);
				j -= secciones[i];
			}
			else i--;
		}
	}

	return sol;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int v, s;
	cin >> v >> s;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<int> secciones(s);
	for (size_t i = 0; i < s; i++)
		cin >> secciones[i];

	vector<EntInf> sol = resolver(secciones, v);

	// escribir la solución
	if (!sol.size())
		cout << "Imposible\n";
	else {
		cout << sol.size() << ":";
		for (size_t i = 0; i < sol.size(); i++)
			cout << " " << sol[i];
		cout << "\n";
	}

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
