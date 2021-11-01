#pragma once

#include <limits>

#include "IndexPQ.h"
#include "DigrafoValorado.h"

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int origen) : size(g.V()), dist(g.V(), INF), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	Valor reachingPageCost() const { return dist[size - 1]; }

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	int size;
	std::vector<Valor> dist;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}
};
