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
struct Profile {
	int next_message; // next message scheduled
	int id; // personal id
	int message_period; // receiving message threshold
};

bool operator<(Profile const& a, Profile const& b) {
	return b.next_message < a.next_message || (b.next_message == a.next_message && b.id < a.id);
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0)
		return false;

	priority_queue<Profile> registry;
	int threshold, identf;
	for (int i = 0; i < n; i++) {
		cin >> identf >> threshold ;
		registry.push({ threshold, identf, threshold });
	}

	// resolver el caso posiblemente llamando a otras funciones
	// escribir la solución
	int send;
	cin >> send;
	while (send) {
		Profile p = registry.top(); registry.pop();
		cout << p.id << "\n";
		p.next_message += p.message_period;
		registry.push(p);
		send--;
	}

	cout << "---" << "\n";

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
