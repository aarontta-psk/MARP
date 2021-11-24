
/*@ <answer>
 *
 * Nicolas Rosa Caballero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
using namespace std;

//Nota: Escribo la definicion de patindromo para usarla de base, no es parte de la definicion, solo son anotaciones
/*
 casos recursivos (i < j):

 patindromo(i,j)| patindromo(i+1,j-1) +2 si letra[i] == letra[j]
				| max( patindromo(i+1, j),                          Quitamos el primero
				|      patindromo(i ,j-1)) si letra[i] != letra[j]  Quitamos el ultimo
				|

 casos basicos:
	patindromo(i,i) = 1           Tenemos solo una letra, por tanto es palindromo
	patindromo(i,j) = 0 si i > j  No tenemos ninguna letra, el mejor palindromo es la palabra vacia

 Llamada inicial patrindromo(0, n-1) si las letras estan en rango [0, n)
*/

/*@ <answer>

 Implementada version descendente siguiendo el video de tiro al patindromo, la version
 ascendente la voy a subir tambien pero necesito mas tiempo para pensarla, las versiones ascendentes me cuesta mas verlas

 Definicion matematica

 casos recursivos (i < j):

 formaPal(i,j)  | min(formaPal(i+1,j), formaPal(i, j-1)) +1 si  letra[i] != letra[j], hay que ver si añadimos menos por la izquierda o por la derecha,
				|                                                                         sumamos 1 a la palabras a añadir porque 1 de las 2 no son iguales,
				|                                                                         y por tanto al menos se añadira 1 letra
				|
				| formaPal(i+1, j-1) si letra[i] == letra[j], no hace falta añadir nada, hay que acotar el rango
				|
				|

 casos basicos:
	formaPal(i,i) = 0           Tenemos solo una letra, por tanto es palindromo
	formaPal(i,j) = 0 si i > j  No tenemos ninguna letra, el mejor palindromo es la palabra vacia

 Llamada inicial patrindromo(0, n-1) si las letras estan en rango [0, n)


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int formaPalindromo_rec(string const& palabra, int i, int j, Matriz<int>& tabla) //O(n^2) donde n -> numero caracteres
{
	int& res = tabla[i][j];
	if (res == -1)
	{
		if (i >= j) res = 0; //O nos hemos pasado o ya es palindromo, no se pone letra en ninguno de ambos casos
		else if (palabra[i] != palabra[j])
			//Nos quedamos con la que menos letras añada por la izquierda o por la derecha
			//Sumamos 1 porque una de las letras no coincide y habra que añadirla
			res = min(formaPalindromo_rec(palabra, i + 1, j, tabla), formaPalindromo_rec(palabra, i, j - 1, tabla)) + 1;
		else
			res = formaPalindromo_rec(palabra, i + 1, j - 1, tabla); //Si son iguales no hace falta añadir nada por ahora
	}

	return res;
}

//No tenemos la palabra palindroma, pero tenemos informacion en la tabla para saber a partir de donde duplicar en espejo
void reconstruir_rec(string const& palabra, Matriz<int> const& tabla, int i, int j, string& sol) //O(n)
{
	if (i > j) return;
	if (i == j) sol.push_back(palabra[i]);

	//Coinciden, entonces no hace falta hacer nada
	else if (palabra[i] == palabra[j])
	{
		sol.push_back(palabra[i]);
		reconstruir_rec(palabra, tabla, i + 1, j - 1, sol);
		sol.push_back(palabra[j]);
	}

	//Ahora bien si no coinciden, podemos duplicar por la izquierda o por la dercha
	//Para esto miramos la tabla para ver que nos conviene mas

	//Duplicar letra de la izquierda
	else if (tabla[i + 1][j] < tabla[i][j - 1])
	{
		sol.push_back(palabra[i]);
		reconstruir_rec(palabra, tabla, i + 1, j, sol);
		sol.push_back(palabra[i]);
	}

	//Duplicar letra de la derecha
	else
	{
		sol.push_back(palabra[j]);
		reconstruir_rec(palabra, tabla, i, j - 1, sol);
		sol.push_back(palabra[j]);
	}
}

bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	int numChars = palabra.length();

	if (!std::cin)  // fin de la entrada
		return false;

	Matriz<int> tabla(numChars, numChars, -1);
	cout << formaPalindromo_rec(palabra, 0, numChars - 1, tabla) << ' ';

	string solucion;
	reconstruir_rec(palabra, tabla, 0, numChars - 1, solucion);
	cout << solucion << '\n';

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
