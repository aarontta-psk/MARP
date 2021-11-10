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
		return bg < h.bg;
	}
};

istream& operator>>(istream& in, Works& h) {
	in >> h.bg >> h.end;
	return in;
}

int numWorks(vector<Works> works, int c, int f) {
	Works timeCovered = { c, c };
	int num = 1; int bgIdx = 0;

	while (bgIdx < works.size()) {
		if (works[bgIdx].bg > timeCovered.bg && works[bgIdx].bg > timeCovered.end)
			return -1;

		if (works[bgIdx].bg <= timeCovered.bg)
			timeCovered.end = max(timeCovered.end, works[bgIdx].end);
		else {
			timeCovered.bg = max(timeCovered.end, works[bgIdx].bg);
			timeCovered.end = max(timeCovered.end, works[bgIdx].end);
			num++;
		}

		++bgIdx;

		if (timeCovered.end >= f)
			break;
	}

	if (timeCovered.end < f)
		return -1;

	return num;
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
