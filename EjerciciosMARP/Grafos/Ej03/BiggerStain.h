#ifndef BIGGERSTAIN_H_
#define BIGGERSTAIN_H_

#include <vector>
#include "Grafo.h"

class BiggerStain {
public:
	BiggerStain(Grafo const& g) : visited(g.V(), false), maximum(0) {
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