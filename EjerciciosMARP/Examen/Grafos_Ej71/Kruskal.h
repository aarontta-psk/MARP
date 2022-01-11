#pragma once

#include <vector>
#include <limits>

#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

template <typename Valor>
class Kruskal {
public:
	Kruskal(GrafoValorado<Valor> const& graph) : vert(graph.V()), coste(0) {
		PriorityQueue<Arista<Valor>> pq(graph.aristas());
		ConjuntosDisjuntos cj(graph.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cj.unidos(v, w)) {
				cj.unir(v, w);
				ARM.push_back(a); coste += a.valor();
				if (ARM.size() == graph.V() - 1) {
					break;
				}
			}
		}
	}

	bool isViable() { return ARM.size() == vert - 1; };

	int costeARM() { return coste; };

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	int vert;
	int coste, n_cj;
	std::vector<Arista<Valor>> ARM;
};