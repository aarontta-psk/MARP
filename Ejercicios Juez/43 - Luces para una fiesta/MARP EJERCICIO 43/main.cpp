/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Nicolas Rosa Caballero
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;


/*@ <answer>

 Coste: O(tiposBombillas * pMax) en tiempo y espacio

 Se resuelve como el de las monedas, pero en vez de ser un intervalo fijo a pagar, es un rango (potencia)
 y se quiere minimizar un coste

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Bombilla
{
	int potencia;
	EntInf coste;
};

Bombilla ColocarBombillas(vector<Bombilla>& bombillas, int pMax, int pMin, int tiposBombillas)
{
	int size = bombillas.size();
	Matriz<EntInf> matriz(tiposBombillas + 1, pMax + 1, Infinito);

	//Rellenar matriz (misma tecnica que caso de las monedas)
	//No es posible optimizar mas el espacios
	matriz[0][0] = 0;
	for (int i = 1; i <= size; ++i)
	{
		matriz[i][0] = 0;
		for (int j = 1; j <= pMax; ++j)
		{
			if (bombillas[i - 1].potencia <= j)         
			{
				EntInf anterior = matriz[i][j - bombillas[i - 1].potencia];
				matriz[i][j] = min(matriz[i - 1][j], anterior + bombillas[i - 1].coste); //Elegir la de menor coste
			}
			else matriz[i][j] = matriz[i - 1][j];             
		}
	}

	//Reconstruir solucion (solo nos importa la ultima fila, como con las dianas/monedas)
	EntInf minCoste = Infinito;
	int minPotencia = 0;
	for (int i = pMin; i <= pMax; i++) {
		EntInf resultado = matriz[size][i];
		if (resultado < minCoste) {
			minCoste = resultado;
			minPotencia = i;
		}
	}
	return { minPotencia , minCoste };
}

bool resuelveCaso() {

	// leemos la entrada
	int tiposBombilla, PMax, PMin;
	cin >> tiposBombilla >> PMax >> PMin;
	if (!cin)
		return false;

	// leemos las características de los tipos de bombillas
	vector<Bombilla> bombillas(tiposBombilla);
	for (Bombilla& x : bombillas)
		cin >> x.potencia;
	for (Bombilla& x : bombillas) //Todo en un solo vector, mas comodo asi
	{
		int aux;
		cin >> aux;
		x.coste = aux;
	}

	Bombilla sol = ColocarBombillas(bombillas, PMax, PMin, tiposBombilla);
	
	if (sol.coste == Infinito) cout << "IMPOSIBLE\n";
	else cout << sol.coste << " " << sol.potencia << '\n';

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
