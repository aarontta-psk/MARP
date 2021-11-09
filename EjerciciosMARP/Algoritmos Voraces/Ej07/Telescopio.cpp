/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Works {
	int bg, end;

	bool operator < (const Works& h) const {
		return bg < h.bg || (bg == h.bg && end < h.end);
	}
};

istream& operator>>(istream& in, Works& h) {
	in >> h.bg >> h.end;
	return in;
}

int numWorks(vector<Works> works, int c, int f) {
	int bgIdx = 0;

	// first work that is on the threshold
	while (bgIdx < works.size() && (works[bgIdx].bg >= f || works[bgIdx].end <= c))
		bgIdx++;

	if (bgIdx == works.size() || works[bgIdx].bg > c) // if there's no work in the threshold, or the first one doesn't cover the bg
		return -1;

	vector<Works> tempWorks; tempWorks.push_back(works[bgIdx]);
	Works tempWork = { -1, -1 };
	bgIdx++;
	while (bgIdx < works.size() && tempWorks[tempWorks.size() - 1].end < f) {
		if (works[bgIdx].bg > tempWorks[tempWorks.size() - 1].end) {
			if (works[bgIdx].bg > tempWork.end)
				break;
			else {
				tempWorks.push_back(tempWork);
				tempWork = works[bgIdx];
			}
		}

		if (works[bgIdx].bg <= tempWorks[tempWorks.size() - 1].end &&
			works[bgIdx].end - tempWorks[tempWorks.size() - 1].end > tempWork.end - tempWorks[tempWorks.size() - 1].end) {
			tempWork = works[bgIdx];
		}
		++bgIdx;
	}

	if (bgIdx == works.size() && tempWorks[tempWorks.size() - 1].end < f &&
		tempWork.end > tempWorks[tempWorks.size() - 1].end)
		tempWorks.push_back(tempWork);

	if (tempWorks[tempWorks.size() - 1].end < f)
		return -1;

	return tempWorks.size();
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int c, f, n;
	cin >> c >> f >> n;
	if (!c && !f && !n)
		return false;

	vector<Works> works(n);
	for (size_t i = 0; i < n; i++)
		cin >> works[i];

	sort(works.begin(), works.end());
	// resolver el caso posiblemente llamando a otras funciones
	int workNum = numWorks(works, c, f);

	// escribir la solución
	if (workNum == -1)
		cout << "Imposible\n";
	else
		cout << workNum << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
