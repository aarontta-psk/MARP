#ifndef TASKS_H_
#define TASKS_H_

#include <climits>
#include <vector>
#include <stack>
#include "Digrafo.h"

using namespace std;

class Tasks {
public:
	Tasks(Digrafo const& g) : visited(g.V(), false), piledUp(g.V(), false), cycle(false) {
		Digrafo inv = g.inverso();
		for (size_t vert = 0; vert < g.V(); vert++) {
			if (!cycle && !visited[vert]) {
				dfs(inv, vert);
			}
		}
	}

	deque<int> const& taskQueue() {
		return postOrder;
	}

private:
	vector<bool> visited;
	vector<bool> piledUp;
	deque<int> postOrder;
	bool cycle;

	void dfs(Digrafo const& g, int vert) {
		visited[vert] = true;
		piledUp[vert] = true;

		for (int ady : g.ady(vert)) {
			if (cycle)
				return;
			if (!visited[ady])
				dfs(g, ady);
			else if (piledUp[ady]) {
				cycle = true;
				while (!postOrder.empty())
					postOrder.pop_back();
			}
		}

		piledUp[vert] = false;

		if (!cycle)
			postOrder.push_back(vert);
	}
};

#endif