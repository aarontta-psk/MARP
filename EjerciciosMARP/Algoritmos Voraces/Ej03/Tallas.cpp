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
int numEquip(vector<int> plSizes, vector<int> availableSizes) {
	int equip = 0;

	int i = 0, j = 0;
	while (i < plSizes.size() && j < availableSizes.size()) {
		if (plSizes[i] > availableSizes[j])
			j++;
		else if (plSizes[i] == availableSizes[j] || plSizes[i] + 1 == availableSizes[j]) {
			i++; j++;
			equip++;
		}
		else 
			i++;
	}

	return plSizes.size() - equip;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, m;
	cin >> n >> m;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<int> plSizes(n), availableSizes(m);

	for (size_t i = 0; i < n; i++)
		cin >> plSizes[i];

	for (size_t j = 0; j < m; j++)
		cin >> availableSizes[j];

	sort(plSizes.begin(), plSizes.end());
	sort(availableSizes.begin(), availableSizes.end());

	// escribir la solución
	cout << numEquip(plSizes, availableSizes) << "\n";

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
