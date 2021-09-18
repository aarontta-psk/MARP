/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <stdlib.h> 

using namespace std;

#include "bintree.h"

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
	if (arbol.empty()) //si vacio, devolvemos altura 0
		return 0;

	//comprobacion de que es busqueda
	if (avl)
		avl = !((max != -1 && max <= arbol.root()) ||
			(min != -1 && min >= arbol.root()));

	//obtencion de alturas
	int heightL = resuelve(arbol.left(), avl, min, arbol.root());
	int heightR = resuelve(arbol.right(), avl, arbol.root(), max);

	//si aun no ha sido detectado que no es avl
	if (avl)
		avl = (abs(heightL - heightR) == 0 || abs(heightL - heightR) == 1);

	//retornamos la altura nueva
	return (std::max(heightL, heightR) + 1);
}

void resuelveCaso() {

	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);

	// resolver el caso posiblemente llamando a otras funciones
	bool avl = true;
	resuelve(arbol, avl, -1, -1);

	// escribir la solución
	cout << (avl ? "SI" : "NO") << endl;
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
