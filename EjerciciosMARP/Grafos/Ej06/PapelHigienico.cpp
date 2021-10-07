/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <stack>

#include "Grafo.h"

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
class BestSupermarket {
public:
	BestSupermarket(Grafo const& g, vector<int> const& prices) : visited(g.V()), bestSups(g.V(), INT_MAX), bestSup(INT_MAX) {
		for (size_t vert = 0; vert < g.V(); vert++) {
			if (!visited[vert]) {
				stack<int> temp;
				dfs(g, prices, temp, vert);

				while (!temp.empty()) {
					int index = temp.top(); temp.pop();
					if (bestSup != INT_MAX) bestSups[index] = bestSup;
				}

				bestSup = INT_MAX;
			}
		}
	}

	int bestSupermarket(int bS) {
		return bestSups[bS];
	}

private:
	vector<bool> visited;
	vector<int> bestSups;
	int bestSup;

	void dfs(Grafo const& g, vector<int> const& prices, stack<int>& temp, int vert) {
		visited[vert] = true;
		temp.push(vert);

		if (bestSup > prices[vert])
			bestSup = prices[vert];

		for (int ady : g.ady(vert)) {
			if (!visited[ady]) {
				dfs(g, prices, temp, ady);
			}
		}
	}
};

bool resuelveCaso() {

	// leemos la entrada
	int N, C;
	cin >> N >> C;
	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	Grafo graph(N);
	int firstV, secondV;
	for (size_t i = 0; i < C; i++) {
		cin >> firstV >> secondV;
		graph.ponArista(--firstV, --secondV);
	}

	int S;
	cin >> S;

	vector<int> prices(N, INT_MAX);
	int index, price;
	for (size_t j = 0; j < S; j++) {
		cin >> index >> price;
		prices[--index] = price;
	}

	BestSupermarket sol(graph, prices);

	int K;
	cin >> K;
	int consulta;
	for (size_t l = 0; l < K; l++) {
		cin >> consulta;
		consulta--;
		cout << (sol.bestSupermarket(consulta) != INT_MAX ? to_string(sol.bestSupermarket(consulta)) : "MENUDO MARRON") << "\n";
	}

	cout << "---\n";
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
