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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int palin(string const& word, unsigned int i, unsigned int j, Matriz<int>& palindrome) {
	int& res = palindrome[i][j];
	if (res == -1) {
		if (i >= j) palindrome[i][j] = 0;
		else if (word[i] == word[j])
			palindrome[i][j] = palin(word, i + 1, j - 1, palindrome);
		else
			palindrome[i][j] = min(palin(word, i + 1, j, palindrome),
				palin(word, i, j - 1, palindrome)) + 1;
	}
	return res;
}

void reconstruir(string const& word, Matriz<int>& palindrome, unsigned int i, unsigned int j, string& sol) {
	if (i > j) return;
	else if (i == j) sol.push_back(word[i]);
	else if (word[i] == word[j]) {
		sol.push_back(word[i]);
		reconstruir(word, palindrome, i + 1, j - 1, sol);
		sol.push_back(word[j]);
	}
	else if (palindrome[i + 1][j] < palindrome[i][j - 1]) {
		sol.push_back(word[i]);
		reconstruir(word, palindrome, i + 1, j, sol);
		sol.push_back(word[i]);
	}
	else
	{
		sol.push_back(word[j]);
		reconstruir(word, palindrome, i, j - 1, sol);
		sol.push_back(word[j]);
	}
}

bool resuelveCaso() {

	// leer los datos de la entrada
	string word;
	cin >> word;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	Matriz<int> palindrome(word.size(), word.size(), -1);
	cout << palin(word, 0, word.size() - 1, palindrome) << " ";

	string sol;
	reconstruir(word, palindrome, 0, word.size() - 1, sol);
	cout << sol << "\n";

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
