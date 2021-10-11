#ifndef DRAIN_H_
#define DRAIN_H_

#include <climits>
#include <vector>
#include "Digrafo.h"

using namespace std;

class Drain {
public:
	Drain(Digrafo const& g) : visited(g.V(), false), inAndOut(g.V(), { 0, 0 }), dr(-1) {
		for (size_t vert = 0; vert < g.V(); vert++) 
			if (!visited[vert])
				dfs(g, vert);

		int step = 0;
		while (step < g.V() && (inAndOut[step].first != g.V() - 1 || inAndOut[step].second != 0))
			step++;

		if (step != g.V())
			dr = step;
	}

	int const& drain() {
		return dr;
	}

private:
	vector<bool> visited;
	vector<pair<int, int>> inAndOut;
	int dr, step;

	void dfs(Digrafo const& g, int vert) {
		visited[vert] = true;
		inAndOut[vert].second = g.ady(vert).size();

		for (int ady : g.ady(vert)) {
			inAndOut[ady].first++;
			if (inAndOut[ady].first == g.V() - 1)
				step = ady;
			if (!visited[ady])
				dfs(g, ady);
		}
	}
};

#endif