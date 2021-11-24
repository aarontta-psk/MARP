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
struct LightBulb {
	int power;
	int cost;

	bool operator <(LightBulb const& l) const {
		return power < l.power;
	}
};

pair<int, EntInf> caminos(vector<LightBulb> const& bulbs, unsigned int n, unsigned int pMax, unsigned int pMin) {
	vector<EntInf> check(pMax + 1, Infinito);
	check[0] = 0;
	/*for (size_t j = 0; j <= n + 1; j++)
		check[0][j] = 0;*/

	for (size_t i = 1; i <= n; i++)
		for (size_t j = bulbs[i - 1].power; j <= pMax; j++)
			check[j] = min(check[j - bulbs[i - 1].power] + bulbs[i - 1].cost, check[j]);

	if (check[pMax] == Infinito)
		return { 0, check[pMax] };

	int k = pMin, power = -1;
	EntInf menor = Infinito;

	while (k <= pMax) {
		if (check[k] < menor) {
			menor = check[k];
			power = k;
		}
		k++;
	}

	return { power, menor };
}

bool resuelveCaso() {

	// leer los datos de la entrada
	unsigned int n, pMax, pMin;
	cin >> n >> pMax >> pMin;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<LightBulb> bulbs(n);
	for (size_t i = 0; i < n; i++)
		cin >> bulbs[i].power;
	for (size_t j = 0; j < n; j++)
		cin >> bulbs[j].cost;

	sort(bulbs.begin(), bulbs.end());

	// escribir la solución
	pair<int, EntInf> sol = caminos(bulbs, n, pMax, pMin);

	if (sol.second == Infinito) cout << "IMPOSIBLE\n";
	else cout << sol.second << " " << sol.first << "\n";

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
