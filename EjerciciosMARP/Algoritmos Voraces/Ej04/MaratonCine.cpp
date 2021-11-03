/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
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
struct MovieTime {
	int movieStart;
	int movieEnd;

	bool operator < (const MovieTime& movie) const {
		return movieEnd < movie.movieEnd;
	}
};

istream& operator>>(istream& in, MovieTime& movie) {
	int h, m, run; char c;
	in >> h >> c >> m >> run;
	movie.movieStart = h * 60 + m;
	movie.movieEnd = movie.movieStart + run + 10;
	return in;
}

int numMovies(vector<MovieTime> movies) {
	int count = 0, lastTime = 0;

	for (size_t i = 0; i < movies.size(); i++) {
		if (lastTime <= movies[i].movieStart) {
			lastTime = movies[i].movieEnd;
			count++;
		}
	}

	return count;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!n)
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<MovieTime> movies(n);
	for (size_t i = 0; i < n; i++)
		cin >> movies[i];

	sort(movies.begin(), movies.end());

	// escribir la solución
	cout << numMovies(movies) << "\n";

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
