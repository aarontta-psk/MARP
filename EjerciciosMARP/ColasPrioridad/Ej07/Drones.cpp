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
struct Pila {
	string type;
	int energy;

	bool operator<(Pila const& a) const {
		return energy < a.energy;
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, a, b;
	cin >> n >> a >> b;
	if (!std::cin)
		return false;

	int aux;
	priority_queue<int> pilas9V, pilas15V;
	for (size_t i = 0; i < a; i++) {
		cin >> aux;
		pilas9V.push(aux);
	}
	for (size_t i = 0; i < b; i++) {
		cin >> aux;
		pilas15V.push(aux);
	}
	// resolver el caso posiblemente llamando a otras funciones

	priority_queue<Pila> used;
	while (!pilas9V.empty() && !pilas15V.empty()) {
		int hours = 0;

		for (size_t i = 0; i < n; i++) {
			if (pilas9V.empty() || pilas15V.empty())
				break;

			hours += pilas9V.top() > pilas15V.top() ? pilas15V.top() : pilas9V.top();

			if (pilas9V.top() - pilas15V.top() != 0) {
				Pila usedPower = { pilas9V.top() > pilas15V.top() ? "9V" : "1.5V",
					pilas9V.top() > pilas15V.top() ? pilas9V.top() - pilas15V.top() : pilas15V.top() - pilas9V.top() };
				used.push(usedPower);
			}

			pilas9V.pop(); pilas15V.pop();
		}

		while (!used.empty()) {
			Pila aux = used.top(); used.pop();
			if (aux.type == "9V")
				pilas9V.push(aux.energy);
			else
				pilas15V.push(aux.energy);
		}

		std::cout << hours << " ";
	}

	// escribir la solución
	std::cout << "\n";

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
