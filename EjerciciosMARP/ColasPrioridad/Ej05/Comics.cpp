/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 - struct Comic que guarda su valor y su cola
 - Guardo los valores en un vector de colas y me guardo el valor menor
 - Guardo las cimas en la queue para ir comparando el mas pequeño de las colas
 - Cuando la quito, si no es el menor, coloco la nueva cima de la cola (si hay)

 Entrada: Complejidad O(n*k) siendo 'n' el numero de colas, y 'k' la longitud mayor de las colas

 Resolucion: Complejidad O(m*log(p)), siendo 'm' el numero total de los comics en todas las colas,
 y 'p' el numero de cimas (por tanto, numero de colas)

 @ </answer> */

 // =======================================================================
 // Escribe el código completo de tu solución aquí debajo, tras la etiqueta
 // =======================================================================
 //@ <answer>
struct Comic {
	int value;
	int queue;
};

bool operator < (Comic const& a, Comic const& b) {
	return b.value < a.value;
}

bool resuelveCaso() {

	// leemos la entrada
	int n;
	cin >> n;
	if (!cin) return false;

	// leer el resto del caso y resolverlo
	vector<stack<int>> comic_queues;
	priority_queue<Comic> topComics;
	int majorValue = -1;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		comic_queues.push_back(stack<int>());

		int t;
		for (int j = 0; j < k; ++j) {
			cin >> t;
			if (majorValue == -1 || majorValue > t)
				majorValue = t;
			comic_queues[i].push(t);
		}

		topComics.push({ t, i });
		comic_queues[i].pop();
	}

	int place = 1;

	while (!topComics.empty()) {
		auto com = topComics.top(); topComics.pop();

		if (com.value == majorValue)
			break;

		if (!comic_queues[com.queue].empty()) {
			auto top = comic_queues[com.queue].top();
			comic_queues[com.queue].pop();
			topComics.push({ top, com.queue });
		}

		place++;
	}

	cout << place << "\n";

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

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
