#ifndef FREEGRAPH_H_
#define FREEGRAPH_H_

#include <vector>
#include "Grafo.h"

class FreeGraph {
public:
	FreeGraph(Grafo const& g, int og) : visited(g.V()), previous(g.V()), origin(og) {
		dfs(g, og);
		isAciclic = (g.A() == g.V() - 1);
	}

	bool isFree() {
		for (bool vis : visited)
			if (!vis) return false;

		return isAciclic;
	}

private:
	std::vector<bool> visited;
	std::vector<int> previous;
	int origin;

	bool isAciclic = false;

	void dfs(Grafo const& g, int vert) {
		visited[vert] = true;

		for (int ady : g.ady(vert)) {
			if (!visited[ady]) {
				previous[ady] = vert;
				dfs(g, ady);
			}
		}
	}
};

#endif