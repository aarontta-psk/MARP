/*@ <answer>
 *
 * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

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
struct Paciente {
	int64_t urgency;
	int waitTime;
	string name;
};

bool operator>(Paciente const& a, Paciente const& b) {
	return b.urgency > a.urgency || (b.urgency == a.urgency && b.waitTime < a.waitTime);
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!n)
		return false;

	priority_queue<Paciente, vector<Paciente>, greater<Paciente>> patients;
	vector<string> attended;
	char type;

	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < n; i++) {
		cin >> type;
		if (type == 'I') {
			string pName; int64_t damage;
			cin >> pName >> damage;
			patients.push({ damage, i, pName });
		}
		else {
			Paciente p = patients.top();
			patients.pop();
			attended.push_back(p.name);
		}
	}
	// escribir la solución

	for (int i = 0; i < attended.size(); i++)
		cout << attended[i] << "\n";

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
