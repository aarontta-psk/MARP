#ifndef MAXNUMFRIENDS_H_
#define MAXNUMFRIENDS_H_

#include <vector>
#include "Grafo.h"

class MaxNumFriends {
public:
	MaxNumFriends(Grafo const& g, int og) : visited(g.V(), false), maximum(0) {
		for (int vert = 0; vert < g.V(); vert++) {
			if (!visited[vert]) {
				int maxi = dfs(g, vert);
				maximum = std::max(maximum, maxi);
			}
		}
	}

	int maxFriends() {
		return maximum;
	}

private:
	std::vector<bool> visited;
	int maximum;

	int dfs(Grafo const& g, int vert) {
		visited[vert] = true;
		int tam = 1;
		for (int ady : g.ady(vert)) {
			if (!visited[ady]) {
				tam += dfs(g, ady);
			}
		}

		return tam;
	}
};

#endif