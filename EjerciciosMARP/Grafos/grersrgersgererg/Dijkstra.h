#pragma once

#include <vector>
#include <limits>

#include "IndexPQ.h"
#include "DigrafoValorado.h"

using namespace std;

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