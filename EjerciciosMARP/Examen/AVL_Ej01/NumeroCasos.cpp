/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>

#include "bintree.h" // propios o los de las estructuras de datos de clase

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
int resuelve(bintree<int> arbol, bool& avl, int min, int max) {
	if (arbol.empty())
		return 0;

	if (avl)
		avl = !((max != -1 && max <= arbol.root()) ||
			(min != -1 && min >= arbol.root()));

	int heightL = resuelve(arbol.left(), avl, min, arbol.root());
	int heightR = resuelve(arbol.right(), avl, arbol.root(), max);

	if (avl)
		avl = abs(heightL - heightR) == 0 || abs(heightL - heightR) == 1;

	return std::max(heightL, heightR) + 1;
}

void resuelveCaso() {

	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);

	// resolver el caso posiblemente llamando a otras funciones
	// escribir la solución
	bool avl = true;
	resuelve(arbol, avl, -1, -1);

	cout << (avl ? "SI" : "NO") << "\n";

	return;
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
