#ifndef BIGGERSTAIN_H_
#define BIGGERSTAIN_H_

#include <vector>
#include <string>

using namespace std;

using Mapa = vector<string>;

class BiggerStain {
public:
	BiggerStain(Mapa const& map) : rows_(map.size()), cols_(map[0].size()),
		visited(map.size(), vector<bool>(map[0].size(), false)), numStains(0), maximum(0) {
		for (size_t i = 0; i < rows_; i++) {
			for (size_t j = 0; j < cols_; j++) {
				if (!visited[i][j] && map[i][j] == '#') {
					numStains++;
					int maxi = dfs(map, i, j);
					maximum = max(maximum, maxi);
				}
			}
		}
	}

	int stains() {
		return numStains;
	}

	int biggerStain() {
		return maximum;
	}

private:
	vector<vector<bool>> visited;
	int rows_, cols_, numStains, maximum;
	const vector<pair<int, int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1} };

	bool outOfBounds(int const& i, int const& j) const {
		return !(0 <= i && i < rows_&& 0 <= j && j < cols_);
	}

	int dfs(Mapa const& map, int i, int j) {
		visited[i][j] = true;
		int tam = 1;

		for (auto dir : dirs) {
			int ni = i + dir.first; int nj = j + dir.second;
			if (!outOfBounds(ni, nj) && map[ni][nj] == '#' && !visited[ni][nj]) {
				tam += dfs(map, ni, nj);
			}
		}

		return tam;
	}
};

#endif