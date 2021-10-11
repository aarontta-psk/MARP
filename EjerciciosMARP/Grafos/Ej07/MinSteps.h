#ifndef MINSTEPS_H_
#define MINSTEPS_H_

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class MinSteps {
public:
	MinSteps(int origin, int destination) {
		steps = bfs(origin, destination);
	}

	int minSteps() {
		return steps;
	}

private:
	int steps, max = 10000;

	int adyacente(int const& num, int const& calc) const {
		switch (calc) {
		case 0:
			return (num + 1) % 10000;
		case 1: 
			return (num * 2) % 10000;
		case 2: 
			return num / 3;
		}
	}

	int bfs(int og, int dst) {
		if (og == dst)
			return 0;

		vector<int> distHolder(max, INT_MAX);
		distHolder[og] = 0;

		queue<int> checkQueue;
		checkQueue.push(og);

		while (!checkQueue.empty()) {
			int step = checkQueue.front(); checkQueue.pop();

			for (int i = 0; i < 3; i++) {
				int newNum = adyacente(step, i);
				if (distHolder[newNum] == INT_MAX) {
					distHolder[newNum] = distHolder[step] + 1;

					if (newNum == dst)
						return distHolder[newNum];
					else checkQueue.push(newNum);
				}
			}
		}
	}
};

#endif