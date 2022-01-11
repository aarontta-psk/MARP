#pragma once

#include <vector>
#include <limits>

#include "IndexPQ.h"
#include "DigrafoValorado.h"

using namespace std;

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& graph, int salida, int t) : dist(graph.V(), INF), time(t), mice(0), pq(graph.V()) {
		DigrafoValorado<Valor> g = graph.inverso();

		dist[salida] = 0;
		pq.push(salida, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}

		for (size_t i = 0; i < dist.size(); i++) {
			if (i != salida && dist[i] <= time)
				mice++;
		}
	}

	int numMice() { return mice; };

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	int time, mice;
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