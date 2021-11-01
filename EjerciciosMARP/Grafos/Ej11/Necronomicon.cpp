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
using namespace std;

#include "Digrafo.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 - Para resolver el problema, guardamos el un grafo los saltos representados por las aristas.
   En caso de ser A, conecta con el siguiente; J, conecta con el salto; C, conecta tanto con el siguiente como con el salto.
 - Tras ello, hacemos un recorrido en profundidad a lo largo del grafo, comprobando que haya ciclo.
 - En caso de que se visite el final del programa (visited[prSize], siendo prSize = L + 1), y haya ciclo, se imprime "A VECES".
   En caso de que se visite el final del programa y no haya ciclo, se imprime "SIEMPRE". En caso de que no se visite el final del programa,
   se imprime "NUNCA"

 * Lectura: O(L), siendo L el tamaño del programa.
 * Escritura: O(L + 2L) [O(L)], siendo la primera L el número de instrucciones del programa; y 2L el número máximo de aristas,
 * en este caso 2L que sería el caso en el que todo el programa sea saltos condicionales.
 * Conclusion: el algoritmo tiene coste del orden O(L)

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
enum class HasFinished { NO, YES, MAYBE };

class ProgramFinish {
public:
	ProgramFinish(Digrafo const& graph) : visited(graph.V(), false), piledUp(graph.V(), false), prSize(graph.V()- 1), hasCycle(false) {
		dfs(graph, 0);
	};

	HasFinished hasEnded() { 
		if (visited[prSize])
			if (hasCycle)
				return HasFinished::MAYBE;
			else
				return HasFinished::YES;

		return HasFinished::NO; 
	};

private:
	vector<bool> visited;
	vector<bool> piledUp;
	int prSize;
	bool hasCycle;

	void dfs(Digrafo const& graph, int node) {
		visited[node] = true;
		piledUp[node] = true;

		for (int ady : graph.ady(node)) {
			if (!visited[ady])
				dfs(graph, ady);
			else if (piledUp[ady])
				hasCycle = true;
		}

		piledUp[node] = false;
	}
};


bool resuelveCaso() {

	// leemos la entrada
	int L;
	cin >> L;
	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	Digrafo graph(L + 1);
	for (size_t i = 0; i < L; i++) {
		char op; cin >> op;

		if (op != 'J')
			graph.ponArista(i, i + 1);
		if (op != 'A') {
			int nextArista;
			cin >> nextArista;
			graph.ponArista(i, --nextArista);
		}
	}

	ProgramFinish sol(graph);

	switch (sol.hasEnded()) {
	case HasFinished::NO: cout << "NUNCA"; break;
	case HasFinished::YES: cout << "SIEMPRE"; break;
	case HasFinished::MAYBE: cout << "A VECES"; break;
	}

	cout << "\n";

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
