/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"
#include "EnterosInf.h"

using namespace std;

/*@ <answer>

	valido (i, l): pregunta si existe alguna forma de que se alcance la longitud 'l'
				   en base a las cuerdas a partir de 'i'

				  / valido(i - 1, l)							si li > l
	valido (i, j) |
				  \ valido(i - 1, l - li) ó valido(i - 1, l)    si li <= l

				  cb : i == 0 && l != 0 --> false
					   l == 0 --> true

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Cord {
	int length;
	int cost;
};

istream& operator >> (istream& in, Cord& s) {
	in >> s.length >> s.cost;
	return in;
}

bool valido(vector<Cord> const& cordeles, int index, int length, vector<bool>& sol) {
	/*if (sol[length])
		return sol[length];

	if (length == 0)
		return true;
	if (index == 0 && length != 0)
		return false;

	if (cordeles[index].length > length)
		sol[length] = valido(cordeles, index - 1, length, sol);
	else
		sol[length] = valido(cordeles, index - 1, length - cordeles[index].length, sol)
		|| valido(cordeles, index - 1, length, sol);*/


	sol[0] = true;

	for (size_t i = 1; i <= index; i++)
		for (int j = length; j >= cordeles[i].length; j--)
			sol[j] = sol[j - cordeles[i].length] || sol[j];

	return sol[length];
}

int64_t posibles(vector<Cord> const& cordeles, int index, int length, vector<int64_t>& sol) {
	/*if (length == 0)
		return 1;
	if (index == 0 && length != 0)
		return 0;

	if (sol[index][length] != -1)
		return sol[index][length];

	if (cordeles[index].length > length)
		sol[index][length] = posibles(cordeles, index - 1, length, sol);
	else {
		EntInf including = posibles(cordeles, index - 1, length - cordeles[index].length, sol),
			excluding = posibles(cordeles, index - 1, length, sol);
		sol[index][length] = including + excluding;
	}*/

	sol[0] = 1;

	for (size_t i = 1; i <= index; i++)
		for (int j = length; j >= cordeles[i].length; j--)
			sol[j] = sol[j - cordeles[i].length] + sol[j];

	return sol[length];
}

EntInf minimo(vector<Cord> const& cordeles, int index, int length, vector<EntInf>& sol) {
	/*if (sol[length] != Infinito)
		return sol[length];

	if (length == 0)
		return 0;
	if (index == 0 && length != 0)
		return Infinito;

	if (cordeles[index].length > length)
		sol[length] = minimo(cordeles, index - 1, length, sol);
	else {
		EntInf including = minimo(cordeles, index - 1, length - cordeles[index].length, sol) + 1,
			excluding = minimo(cordeles, index - 1, length, sol);
		sol[length] = min(including, excluding);
	}*/

	sol[0] = 0;

	for (int i = 1; i <= index; i++)
		for (size_t j = length; j >= cordeles[i].length; j--)
			sol[j] = min(sol[j - cordeles[i].length] + 1, sol[j]);

	return sol[length];
}

EntInf minCoste(vector<Cord> const& cordeles, int index, int length, vector<EntInf>& sol) {
	/*if (sol[length] != Infinito)
		return sol[length];

	if (length == 0)
		return 0;
	if (index == 0 && length != 0)
		return Infinito;

	if (cordeles[index].length > length)
		sol[length] = minCoste(cordeles, index - 1, length, sol);
	else {
		EntInf including = minCoste(cordeles, index - 1, length - cordeles[index].length, sol) + cordeles[index].cost,
			excluding = minCoste(cordeles, index - 1, length, sol);
		sol[length] = min(including, excluding);
	}*/

	sol[0] = 0;

	for (int i = 1; i <= index; i++)
		for (size_t j = length; j >= cordeles[i].length; j--)
			sol[j] = min(sol[j - cordeles[i].length] + cordeles[i].cost, sol[j]);

	return sol[length];
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, l;
	cin >> n >> l;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	vector<Cord> cordeles(n + 1);
	for (size_t i = 1; i <= n; i++)
		cin >> cordeles[i];

	// escribir la solución
	vector<bool> solV(l + 1, false);
	if (valido(cordeles, n, l, solV)) {
		cout << "SI";
		vector<int64_t> solP(l + 1, 0);
		cout << " " << posibles(cordeles, n, l, solP);
		vector<EntInf> solM(l + 1, Infinito);
		cout << " " << minimo(cordeles, n, l, solM);
		vector<EntInf> solC(l + 1, Infinito);
		cout << " " << minCoste(cordeles, n, l, solC);
	}
	else
		cout << "NO";

	cout << "\n";
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
