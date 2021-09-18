/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

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

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0)
		return false;

	priority_queue<int64_t, vector<int64_t>, greater<int64_t>> sumQueue;
	int readNum;
	for (int i = 0; i < n; i++) {
		cin >> readNum;
		sumQueue.push(readNum);
	}
	
	// resolver el caso posiblemente llamando a otras funciones
	int64_t sum = 0;
	while (sumQueue.size() != 1) {
		int64_t prioSum = sumQueue.top(); sumQueue.pop(); // first element
		prioSum += sumQueue.top(); sumQueue.pop();    // first + second element
		sum += prioSum;								  // accumulated addition
		sumQueue.push(prioSum);
	}
	
	// escribir la solución
	cout << sum << "\n";

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
