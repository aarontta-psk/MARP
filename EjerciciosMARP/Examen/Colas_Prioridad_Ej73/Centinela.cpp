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
struct Battery {
	int quantity;
	int end;
	int id;
};

struct Comparator {
	bool operator()(Battery a, Battery b) {
		return b.end < a.end || (b.end == a.end && b.id < a.id);
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int N; cin >> N;
	if (!cin)
		return false;

	priority_queue<Battery, vector<Battery>, Comparator> batteries;
	for (size_t i = 0; i < N; i++) {
		int bat; cin >> bat; Battery b = { bat, bat, i };
		batteries.push(b);
	}

	int R; cin >> R;
	queue<Battery> reserve;
	for (size_t i = 0; i < R; i++) {
		int bat; cin >> bat; Battery b = { bat, bat, i + N };
		reserve.push(b);
	}

	int Z; cin >> Z; int T; cin >> T;

	// resolver el caso posiblemente llamando a otras funciones
	int time = 0;
	while (!batteries.empty()) {
		time = batteries.top().end;
		if (time > T)
			break;

		auto b = batteries.top(); batteries.pop();

		b.quantity -= Z;
		b.end += b.quantity;
		if (b.quantity <= 0) {
			if (reserve.empty())
				continue;
			Battery auxB = { reserve.front().quantity, b.end - b.quantity + reserve.front().quantity, 
				reserve.front().id };
			reserve.pop(); batteries.push(auxB);
		}
		else
			batteries.push(b);
	}

	// escribir la solución
	if (time > T) {
		if(batteries.size() < N)
			cout << "FALLO EN EL SISTEMA\n";
		else
			cout << "CORRECTO\n";

		while(!batteries.empty()) {
			auto b = batteries.top(); batteries.pop();
			cout << b.id + 1 << " " << b.end << "\n";
		}
	}
	else
		cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";

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
