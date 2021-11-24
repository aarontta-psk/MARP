
/*@ <answer>
 *
 * Nicolas Rosa Caballero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>

 Forma iterativa compleja vista en clase

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


int Comer(vector<int>& cubos, const int& numCubos)
{
	vector<int> vacas(numCubos, 0);

	// casos basicos
	// si N es impar, la diagonal principal, un solo cubo
	// si N es par, la diagonal enicma de la principal, dos cubos

	if (numCubos % 2 == 1)
	{
		for (int j = 0; j < numCubos; j++)
			vacas[j] = cubos[j];
	}
	else
		for (int j = 1; j < numCubos; j++)
			vacas[j] = max(cubos[j - 1], cubos[j]);

	// recorriendo de abajo a arriba y de izquierda a derecha (de 2 en 2)
	for (int i = ((numCubos % 2 == 0) ? numCubos - 4 : numCubos - 3); i >= 0; i--)
	{
		for (int j = ((numCubos % 2 == 0) ? i + 3 : i + 2); j < numCubos; j += 2)
		{
			int come_i, come_j;

			//come i
			if (cubos[i + 1] > cubos[j])
				come_i = cubos[i] + vacas[j];
			else
				come_i = cubos[i] + vacas[j - 1];

			//come j
			if (cubos[i] > cubos[j - 1])
				come_j = cubos[j] + vacas[j - 1];
			else
				come_j = cubos[j] + vacas[j - 2];

			vacas[j] = max(come_i, come_j);
		}
	}

	return vacas[numCubos - 1];
}

bool resuelveCaso() {

	int numCubos = 0;
	cin >> numCubos;

	if (!std::cin || numCubos == 0)  // fin de la entrada
		return false;

	vector<int> cubos(numCubos);

	for (int& cubo : cubos)
		cin >> cubo;

	cout << Comer(cubos, numCubos) << '\n';

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
