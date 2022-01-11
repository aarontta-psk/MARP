#pragma once

#include <vector>
#include <limits>
#include <string>

using namespace std;

//template <typename Valor>
class Ovejas {
public:
	Ovejas(vector<string> const& graph, int Fil, int Col) : visit(Fil, vector<bool>(Col, false)), F(Fil), C(Col), ovejasBlancas(0) {
		dfs(graph, 0, 0);

		for (size_t i = 0; i < Fil; i++) {
			for (size_t j = 0; j < Col; j++) {
				if (!visit[i][j] && graph[i][j] == 'X') {
					bool white = false;
					dfs2(graph, i, j, white);
					if (white) ovejasBlancas++;
				}
			}
		}
	}

	int ovejas() { return ovejasBlancas; };

private:
	std::vector<vector<bool>> visit;
	int ovejasBlancas;
	int F, C;

	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

	bool outOfBounds(int f, int c) {
		return !(f >= 0 && f < F&& c >= 0 && c < C);
	}

	void dfs(vector<string> const& G, int f, int c) {
		visit[f][c] = true;
		for (auto d : dirs) {
			int nf = f + d.first, nc = c + d.second;
			if (!outOfBounds(nf, nc) && G[nf][nc] == '.' && !visit[nf][nc]) {
				dfs(G, nf, nc);
			}
		}
	}

	void dfs2(vector<string> const& G, int f, int c, bool& white) {
		visit[f][c] = true;
		for (auto d : dirs) {
			int nf = f + d.first, nc = c + d.second;
			if (!outOfBounds(nf, nc) && !visit[nf][nc]) {
				if (G[nf][nc] == '.')
					white = true;

				dfs2(G, nf, nc, white);
			}
		}
	}
};