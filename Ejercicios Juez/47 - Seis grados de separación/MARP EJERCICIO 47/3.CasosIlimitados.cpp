
/*@ <answer>
 *
 * Nicolas Rosa Caballero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "EnterosInf.h"
#include <unordered_map>

using namespace std;

/*@ <answer>

 Uso el algoritmo de floid para encontrar las distancias minimas entre
 todos los vertices, luego los recorro para quedarme con la mayor de las
 distancias minimas.

 Coste: 
	En tiempo: O(P^3) donde P -> numero de personas
	En espacio: O(1) por la matriz auxiliar para guardar las distancias la necesitaria cualquier algoritmo

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void Floyd(Matriz<EntInf> const& grafo, Matriz<EntInf>& distancias) {
	int numPersonas = grafo.numfils();
	//Para no sobreescribir el grafo, porque dijiste en clase
	//que los datos que recibimos podrian ser usados para otra cosa
	distancias = grafo;

	for (int k = 0; k < numPersonas; ++k) {
		for (int i = 0; i < numPersonas; ++i) {
			for (int j = 0; j < numPersonas; ++j) {
				EntInf temp = distancias[i][k] + distancias[k][j];
				if (temp < distancias[i][j]) { // es mejor pasar por k
					distancias[i][j] = temp;
				}
			}
		}
	}
}

Matriz<EntInf> LeeEntrada(const int& pPersonas, const int& numRelaciones)
{
	Matriz<EntInf> personas(pPersonas, pPersonas, Infinito);

	//Uso un mapa para asociar facilmente cada persona a un numero al leer
	//Uso un mapa desordenado porque me da igual como se guarden el mapa
	unordered_map<string, int> mapaPersonas;

	//Leemos de la entrada, la insertamos en el mapa con el offset actual,
	//Si la insercion devuelve true, es que es una persona nueva y hay que aumentar el offset para la siguiente
	//Nos guardamos su posicion obteniendo la segunda componente que devuelve el iterador
	//Finalmente guardamos que la distancia entre p1 y p2, asi como p2 y p1 es 1
	int offset = 0;
	for (int i = 0; i < numRelaciones; i++)
	{
		string nombre;

		cin >> nombre;
		auto a = mapaPersonas.insert({ nombre, offset });
		if (a.second) 
			offset++;
		int persona1 = a.first->second;

		cin >> nombre;
		a = mapaPersonas.insert({ nombre, offset });
		if (a.second)
			offset++;
		int persona2 = a.first->second;

		personas[persona1][persona2] = personas[persona2][persona1] = 1;
	}

	return personas;
}

EntInf GradoSeparacion(const Matriz<EntInf>& personas)
{
	int numPersonas = personas.numfils();
	Matriz<EntInf> distancias; //Parametro de salida de floyd
	Floyd(personas, distancias);

	// El grado de la red es la mayor separacion que haya entre todos los pares de vertices
	EntInf maxDistancia = 0;
	for (int i = 0; i < numPersonas; i++)
		for (int j = 0; j < i; j++) //Solo se recorrer una diagonal porque la otra es simetrica en resultados, i,j == j,i
			maxDistancia = max(distancias[i][j], maxDistancia);

	return maxDistancia;
}

bool resuelveCaso() {

	int pPersonas, rRelaciones;

	cin >> pPersonas >> rRelaciones;

	if (!std::cin)  // fin de la entrada
		return false;

	//Asumo que el compilador es inteligente y no hará copia de la matriz
	//Esta matriz contiene en la posicion i,j las relaciones directas entre i y j, que será o 1
	//Si existe o Infinito si no
	Matriz<EntInf> personas = LeeEntrada(pPersonas, rRelaciones);

	EntInf maxDist = GradoSeparacion(personas);

	if (maxDist == Infinito) cout << "DESCONECTADA\n";
	else cout << maxDist << '\n';

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
