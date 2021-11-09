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
int numPoints(vector<int> points, vector<int> bPoints) {
	int acc = 0;

	for (size_t i = 0; i < points.size(); i++)
		if (bPoints[i] > points[i])
			acc += bPoints[i] - points[i];

	return acc;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!n)
		return false;

	vector<int> points(n), bPoints(n);
	for (size_t i = 0; i < n; i++)
		cin >> points[i];
	for (size_t i = 0; i < n; i++)
		cin >> bPoints[i];

	sort(points.begin(), points.end());
	sort(bPoints.begin(), bPoints.end(), greater<int>());

	// resolver el caso posiblemente llamando a otras funciones
	// escribir la solución
	cout << numPoints(points, bPoints) << "\n";

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
