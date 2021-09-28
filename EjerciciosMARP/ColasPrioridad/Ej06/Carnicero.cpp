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
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	int caso;
	priority_queue<int> colaMenores;
	priority_queue<int, vector<int>, greater<int>> colaMayores;

	for (int i = 0; i < n; i++) {
		cin >> caso;

		if (caso == 0) {
			if (colaMenores.empty())
				std::cout << "ECSA ";
			else {
				std::cout << colaMenores.top() << " ";

				colaMenores.pop();
				
				if (colaMenores.size() > colaMayores.size() + 1) {
					colaMayores.push(colaMenores.top());
					colaMenores.pop();
				}
				else if (colaMayores.size() > colaMenores.size()) {
					colaMenores.push(colaMayores.top());
					colaMayores.pop();
				}
			}
		}
		else {
			if (colaMenores.empty() || caso < colaMenores.top())
				colaMenores.push(caso);
			else
				colaMayores.push(caso);

			if (colaMenores.size() > colaMayores.size() + 1){
				colaMayores.push(colaMenores.top());
				colaMenores.pop();
			}
			else if (colaMayores.size() > colaMenores.size()) {
				colaMenores.push(colaMayores.top());
				colaMayores.pop();
			}
		}
	}

	std::cout << "\n";

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
