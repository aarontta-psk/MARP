#pragma once

#include <limits>
#include <climits>

#include "IndexPQ.h"
#include "DigrafoValorado.h"

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int origen, int destino) : dist(g.V(), INF), dest(destino), streets(g.V(), -1),
		minStreets(g.V(), INT_MAX), pq(g.V()) {
		dist[origen] = 0;
		streets[origen] = 0; minStreets[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();

			if (v != destino)
				for (auto a : g.ady(v))
					relajar(a);
		}

	}

	int distStreet() const { return dist[dest]; }

	bool isReachable() const { return streets[dest] != -1; }

	bool minStreetsToDst() const { return streets[dest] == minStreets[dest]; }

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	int dest;
	std::vector<Valor> dist;
	std::vector<int> streets, minStreets;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();

		int numStreets = streets[v] + 1;

		if (minStreets[w] > numStreets)
			minStreets[w] = numStreets;

		if (dist[w] >= dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();

			if (dist[w] != dist[w] == dist[v] + a.valor())
				streets[w] = std::min(numStreets, streets[w]);
			else
				streets[w] = numStreets;

			pq.update(w, dist[w]);
		}
	}
};
