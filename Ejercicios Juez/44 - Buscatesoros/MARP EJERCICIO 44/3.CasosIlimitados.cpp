
/*@ <answer>
 *
 * Nicolas Rosa Caballero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Matriz.h"
using namespace std;

/*@ <answer>

 Este problema es practicamente igual al de la mochila pero con lo del oxigeno en vez de paso.
 La version ascendente la subire mas tarde, quiero intentar hacerla sin mirar el video

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Cofre
{
	int profundidad, oro;

	friend istream& operator >>(istream& is, Cofre& cofre)
	{
		return is >> cofre.profundidad >> cofre.oro;
	}

	friend ostream& operator <<(ostream& os, const Cofre& cofre)
	{
		//Ese / 3 no deberia ir ahi, pero es mas comodo
		return os << cofre.profundidad / 3 << ' ' << cofre.oro << '\n';
	}
};

float Teosoro_rec(vector<Cofre>& cofres, int i, int j, Matriz<float>& matriz)
{
	if (matriz[i][j] == -1) 
	{
		if (i == 0 || j == 0) matriz[i][j] = 0;
		else if (cofres[i - 1].profundidad > j)
			matriz[i][j] = Teosoro_rec(cofres, i - 1, j, matriz);
		else 
			matriz[i][j] = max(Teosoro_rec(cofres, i - 1, j, matriz),
					      	   Teosoro_rec(cofres, i - 1, j - cofres[i - 1].profundidad, matriz) + cofres[i - 1].oro);
		
	}
	return matriz[i][j];
}

float Tesoro(vector<Cofre>& cofres, int oxigeno, list<Cofre>& reconstruccionSol)
{
	int numCofres = cofres.size();
	Matriz<float> matriz(numCofres + 1, oxigeno +1, -1);
	float oroRecuperado = Teosoro_rec(cofres, numCofres, oxigeno, matriz);

	//calculo de los objetos, uso una lista para meterlos al reves
	int i = numCofres, j = oxigeno;
	while (i > 0 && j > 0) {
		if (matriz[i][j] > matriz[i - 1][j]) {
			reconstruccionSol.push_front(cofres[i - 1]);
			j -= cofres[i - 1].profundidad;
		}
		--i;
	}

	return oroRecuperado;
}

bool resuelveCaso() {

	int tSegundos, numCofres;
	cin >> tSegundos >> numCofres;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<Cofre> cofres(numCofres);

	for (Cofre& cofre : cofres)
	{
		cin >> cofre;
		cofre.profundidad *= 3; //Por cada objeto gasto t + 2t de oxigeno, y cada s de oxigeno equivalte a 1 p de profundidad
	}
	
	list<Cofre> re;
	auto sol = Tesoro(cofres, tSegundos, re);

	cout << sol << '\n';
	cout << re.size() << '\n';

	for (Cofre& tesoro : re)
		cout << tesoro;

	cout << "---\n";

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
