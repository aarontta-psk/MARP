/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"

/*@ <answer>

	El algoritmo para resolver el problema primero encuentra la longitud de la mayor 
	subsecuencia comun entre las palabras 'X' e 'Y', y luego reconstruye dicha subsecuencia.
	Para ambos cálculos, partimos desde el último carácter de cada palabra.

	FUNCION:
	subsecuencia(i, j): obtiene la longitud de la mayor subsecuencia posible entre la 
	palabra 'X' (con caracteres de 0 hasta 'i'), y la palabra 'Y' (con caracteres de 0 hasta 'j')

	                      /
	                     |  subsecuencia(i - 1, j - 1) + 1					      si X[i] == Y[j]
	subsecuencia(i, j) - |
			    	     |  max(subsecuencia(i - 1, j), subsecuencia(i, j - 1))   si X[i] != Y[j]
						  \

	Casos base:
		* subsecuencia (0, j) = 0      0 caracteres en X, única subsecuencia común el conjunto vacío
		* subsecuencia (i, 0) = 0      0 caracteres en Y, única subsecuencia común el conjunto vacío

	Llamada inicial: subsecuencia(sizeX, sizeY), siendo sizeX y sizeY los tamaños de las palabras 
	'X' e 'Y' respectivamente.

	En cuanto a la complejidad del algoritmo, es del orden O(sizeX * sizeY) tanto para el tiempo
	como para el espacio, siendo sizeX y sizeY los tamaños de las palabras 'X' e 'Y' respectivamente.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int subsequence(string const& wordX, string const& wordY, int i, int j, Matriz<int>& checker) {
	int& res = checker[i][j];

	if (res == -1) {
		int indexX = i - 1, indexY = j - 1;
		if (i == 0 || j == 0) checker[i][j] = 0;
		else if (wordX[indexX] == wordY[indexY])
			checker[i][j] = subsequence(wordX,  wordY, i - 1, j - 1, checker) + 1;
		else
			checker[i][j] = max(subsequence(wordX, wordY, i - 1, j, checker),
				subsequence(wordX, wordY, i, j - 1, checker));
	}

	return res;
}

void rebuild(string const& wordX, string const& wordY, Matriz<int>& checker, int i, int j, string& sol) {
	int indexX = i - 1, indexY = j - 1;

	if (indexX < 0 || indexY < 0) return;
	
	else if (wordX[indexX] == wordY[indexY]) {
		rebuild(wordX, wordY, checker, i - 1, j - 1, sol);
		sol.push_back(wordX[indexX]);
	}
	else if (checker[i - 1][j] < checker[i][j - 1]) 
		rebuild(wordX, wordY, checker, i, j - 1, sol);
	else
		rebuild(wordX, wordY, checker, i - 1, j, sol);
}

bool resuelveCaso() {

	// leemos la entrada
	string X, Y;
	cin >> X >> Y;

	if (!cin)
		return false;

	unsigned int sizeX = X.size(), sizeY = Y.size();

	// resolver el caso
	Matriz<int> checker(sizeX + 1, sizeY + 1, -1);
	//cout << subsequence(X, Y, sizeX, sizeY, checker);
	if (subsequence(X, Y, sizeX, sizeY, checker)) {
		string sol;
		rebuild(X, Y, checker, sizeX, sizeY, sol);
		cout << sol;
	}

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

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
