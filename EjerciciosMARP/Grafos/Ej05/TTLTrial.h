#ifndef TTLTRIAL_H_
#define TTLTRIAL_H_

#include <vector>
#include <queue>
#include "Grafo.h"

class TTLTrial {
public:
	TTLTrial(Grafo const& g, int og, int ttlTime) : visited(g.V(), false), distances(g.V()),
		origin(og), ttl(ttlTime), nodesNotChecked(0) {
		dfs(g);
	}

	int const notCheckedNodes() {
		return nodesNotChecked;
	}

private:
	std::vector<bool> visited;
	std::vector<int> distances;
	int origin, ttl, nodesNotChecked;

	void dfs(Grafo const& g) {
		std::queue<int> q;
		distances[origin] = 0; visited[origin] = true;
		q.push(origin);

		int numNodos = 1;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			
			if (distances[v] < ttl) {
				for (int w : g.ady(v)) {
					if (!visited[w]) {
						distances[w] = distances[v] + 1; visited[w] = true;
						q.push(w);
						numNodos++;
					}
				}
			}
		}

		nodesNotChecked = g.V() - numNodos;
	}
};

#endif