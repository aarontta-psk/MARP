#pragma once

#include <limits>

#include "IndexPQ.h"
#include "DigrafoValorado.h"

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int origen) : dist(g.V(), INF), numPaths(g.V(), 0), pq(g.V()) {
		dist[origen] = 0;
		numPaths[0] = 1;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	int paths() const { return numPaths[numPaths.size() - 1]; }

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	std::vector<Valor> dist;
	std::vector<int> numPaths;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] >= dist[v] + a.valor()) {

			if (dist[w] == dist[v] + a.valor())
				numPaths[w] += numPaths[v];
			else
				numPaths[w] = numPaths[v];

			dist[w] = dist[v] + a.valor();

			pq.update(w, dist[w]);
		}
	}
};