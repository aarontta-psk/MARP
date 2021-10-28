/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Aarón Nauzet Moreno Sosa
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

/*@ <answer>

	- A la hora de resolver la solcuión, primero construimos el grafo dirigido. Luego, utilizando el algoritmo de Dijkstra,
	  obtenemos las distancias de ida (de O a P); y, para obtener las distancias de vuelta, volevemos a aplicar Dijkstra,
	  pero en este caso comprobamos las distancias utilizando la inversa del grafo dirigido (para así obtener distancia de P a O,
	  sin tener que alterar el algoritmo ni hacerlo por cada casa). Tras ello, leemos las casas a revisar su distancia con minimo esfuerzo,
	  e imprimimos su valor en caso de que haya conexion con todas ellas (en caso contrario, imprimimos "Imposible").

	* Coste algoritmo: O(C * log(N) + P), siendo C * log(N) el coste del algoritmo de Dijkstra (se dan C vueltas a lo
	  sumo, costando cada vuelta como mucho O(log(N)) por el .update() de la cola de prioridad variable); 
	  más P vueltas para imprimir la solucion (siendo P el numero de casa a repartir)

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int origen) : distTo(g.V(), INF), distFrom(g.V(), INF), pq(g.V()) {
		// Ida
		distTo[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajarIda(a);
		}

		// Vuelta
		DigrafoValorado<int> gInv = g.inverso();
		distFrom[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : gInv.ady(v))
				relajarVuelta(a);
		}
	}

	bool thereIsPath(int house) { return distTo[house] != INF && distFrom[house] != INF; };

	int effort(int house) { return distTo[house] + distFrom[house]; };

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	std::vector<Valor> distTo, distFrom;
	IndexPQ<Valor> pq;

	void relajarIda(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (distTo[w] > distTo[v] + a.valor()) {
			distTo[w] = distTo[v] + a.valor();
			pq.update(w, distTo[w]);
		}
	}

	void relajarVuelta(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (distFrom[w] > distFrom[v] + a.valor()) {
			distFrom[w] = distFrom[v] + a.valor();
			pq.update(w, distFrom[w]);
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
	DigrafoValorado<int> graph(N);
	for (size_t i = 0; i < C; i++) {
		int og, dst, effort; cin >> og >> dst >> effort;
		graph.ponArista({ --og, --dst, effort });
	}

	int O, P;
	cin >> O >> P;
	Dijkstra<int> sol(graph, --O);

	vector<int> casos(P);
	for (size_t j = 0; j < P; j++) 
		cin >> casos[j];

	int acc = 0;
	for (size_t k = 0; k < P; k++) {
		if (sol.thereIsPath(--casos[k]))
			acc += sol.effort(casos[k]);
		else {
			cout << "Imposible\n";
			return true;
		}
	}

	cout << acc << "\n";

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
