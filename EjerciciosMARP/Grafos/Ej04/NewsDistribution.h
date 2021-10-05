#ifndef NEWSDISTRIBUTION_H_
#define NEWSDISTRIBUTION_H_

#include <vector>
#include <stack>
#include "Grafo.h"

class NewsDistribution {
public:
	NewsDistribution(Grafo const& g) : visited(g.V(), false), connections(g.V(), 1) {
		std::stack<int> caminoCompleto;
		for (int vert = 0; vert < g.V(); vert++) {
			if (!visited[vert]) {
				dfs(g, vert, caminoCompleto);
				int distCamino = caminoCompleto.size();
				while (!caminoCompleto.empty()) {
					connections[caminoCompleto.top()] = distCamino;
					caminoCompleto.pop();
				}
			}
		}
	}

	std::vector<int> const& numConnections() {
		return connections;
	}

private:
	std::vector<bool> visited;
	std::vector<int> connections;

	void dfs(Grafo const& g, int vert, std::stack<int>& caminoCompleto) {
		visited[vert] = true;
		caminoCompleto.push(vert);

		for (int ady : g.ady(vert)) {
			if (!visited[ady])
				dfs(g, ady, caminoCompleto);
		}
	}
};

#endif