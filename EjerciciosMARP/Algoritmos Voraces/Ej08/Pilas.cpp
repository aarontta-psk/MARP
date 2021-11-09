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

	

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {

	// leer los datos de la entrada
	int n, v;
	cin >> n >> v;

	vector<int> voltage(n);
	for (size_t i = 0; i < n; i++)
		cin >> voltage[i];

	sort(voltage.begin(), voltage.end());

	// resolver el caso posiblemente llamando a otras funciones
	int bg = 0, end = voltage.size() - 1;
	int numCars = 0;
	while (bg < end) {
		if (voltage[bg] + voltage[end] >= v) { // if minVolt and maxVolt is possible, +1 on number of cars usable
			numCars++; bg++; end--;
		}
		else // else, we discard the lowest voltage available
			bg++;
	}

	// escribir la solución
	cout << numCars << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
