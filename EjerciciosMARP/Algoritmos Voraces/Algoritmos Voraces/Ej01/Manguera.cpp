/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

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

int numPatches(vector<int> lengths, int patchLength) {
	int accLength = 0, count = 1;

	for (size_t i = 1; i < lengths.size(); i++) {
		if (accLength + (lengths[i] - lengths[i - 1]) <= patchLength)
			accLength += lengths[i] - lengths[i - 1];
		else {
			accLength = 0;
			count++;
		}
	}

	return count;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, l;
	cin >> n >> l;
	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> lengths(n);
	for (size_t i = 0; i < n; i++)
		cin >> lengths[i];

	// resolver el caso posiblemente llamando a otras funciones
	cout << numPatches(lengths, l) << "\n";

	// escribir la solución

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
