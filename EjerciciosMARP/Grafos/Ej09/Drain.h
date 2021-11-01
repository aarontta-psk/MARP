#ifndef DRAIN_H_
#define DRAIN_H_

#include <climits>
#include <vector>
#include "Digrafo.h"

using namespace std;

class Drain {
public:
	Drain(Digrafo const& g) : dr(-1) {
		int candidato = 0;
		for (size_t vert = 1; vert < g.V(); vert++) 
			if (g.hayArista(candidato, vert))
				candidato = vert;

		int vrt = 0;
		while (vrt < g.V() && (candidato == vrt || (g.hayArista(vrt, candidato) && !g.hayArista(candidato, vrt))))
			vrt++;

		if (vrt == g.V())
			dr = candidato;
	}

	int const& drain() {
		return dr;
	}

private:
	int dr;
};

#endif