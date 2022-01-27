#pragma once

#include <vector>
#include <queue>
#include <limits>

#include "Grafo.h"

using namespace std;

template <typename Valor>
class Guards {
public:
	Guards(Grafo const& graph) : visit(graph.V(), false), guard(graph.V(), false), notViable(false), numG(0), numGN(0) {
		for (size_t i = 0; i < graph.V(); i++) {
			if (notViable)
				break;

			if (!visit[i])
				bfs(graph, i);
		}
	}

	bool isViable() { return !notViable; };

	int numGuards() { return min(numG, numGN); };

private:
	const Valor INF = std::numeric_limits<Valor>::max();

	std::vector<bool> visit, guard;
	bool notViable; int numG, numGN;

	void bfs(Grafo const& g, int s) {
		std::queue<int> q;
		visit[s] = true; guard[s] = true;
		numG++;
		q.push(s);
		while (!q.empty()) {
			if (notViable)
				break;

			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					visit[w] = true; guard[w] = !guard[v];
					q.push(w);

					if (guard[w]) numG++;
					else numGN++;
				}
				if (guard[v] == guard[w]) {
					notViable = true;
					break;
				}
			}
		}
	}
};