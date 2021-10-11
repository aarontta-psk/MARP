#ifndef BESTSUPERMARKET_H_
#define BESTSUPERMARKET_H_

#include <climits>
#include <vector>
#include <stack>
#include "Grafo.h"

using namespace std;

class BestSupermarket {
public:
	BestSupermarket(Grafo const& g, vector<int> const& prices) : visited(g.V()), bestSups(g.V(), INT_MAX), bestSup(INT_MAX) {
		for (size_t vert = 0; vert < g.V(); vert++) {
			if (!visited[vert]) {
				stack<int> temp;
				dfs(g, prices, temp, vert);

				while (!temp.empty()) {
					int index = temp.top(); temp.pop();
					if (bestSup != INT_MAX) bestSups[index] = bestSup;
				}

				bestSup = INT_MAX;
			}
		}
	}

	int bestSupermarket(int bS) {
		return bestSups[bS];
	}

private:
	vector<bool> visited;
	vector<int> bestSups;
	int bestSup;

	void dfs(Grafo const& g, vector<int> const& prices, stack<int>& temp, int vert) {
		visited[vert] = true;
		temp.push(vert);

		if (bestSup > prices[vert])
			bestSup = prices[vert];

		for (int ady : g.ady(vert)) {
			if (!visited[ady]) {
				dfs(g, prices, temp, ady);
			}
		}
	}
};

#endif