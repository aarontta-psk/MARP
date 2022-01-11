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
struct Caja {
	int id;
	int time;
};

struct Comparator {
	bool operator()(Caja a, Caja b) {
		return b.time < a.time || (b.time == a.time && b.id < a.id);
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int N, C; cin >> N >> C;
	if (!N && !C)
		return false;

	queue<int> clients;
	for (size_t i = 0; i < C; i++) {
		int client; cin >> client;
		clients.push(client);
	}

	priority_queue<Caja, vector<Caja>, Comparator> cajas;
	// only used if not enough clients before main cycle
	int freeCaja = clients.size() + 1; 
	for (size_t i = 0; !clients.empty() && i < N; i++) {
		Caja c = { i + 1, clients.front() }; clients.pop();
		cajas.push(c);
	}

	while (cajas.size() == N) {
		Caja firstClient = cajas.top(); cajas.pop();
		if (!clients.empty()) {
			Caja newClient = { firstClient.id, firstClient.time + clients.front() }; clients.pop();
			cajas.push(newClient);
		}
		else freeCaja = firstClient.id;
	}

	// escribir la solución
	cout << freeCaja << "\n";

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