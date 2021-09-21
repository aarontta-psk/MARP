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
struct Task {
	int init;
	int end;
	int period;
};

bool operator<(Task const& a, Task const& b) {
	return b.init < a.init;
}

bool hayConflicto(priority_queue<Task>& cal, int time) {
	int occupied = 0;
	while (!cal.empty() && cal.top().init < time) {
		Task t = cal.top(); cal.pop();
		if (t.init < occupied)
			return true;

		if (t.period != -1)
			cal.push({ t.init + t.period, t.end + t.period, t.period });
	
		occupied = t.end;
	}

	return false;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, m, t;
	cin >> n >> m >> t;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	priority_queue<Task> calendar;

	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		calendar.push({ start, end, -1 });
	}

	int period;
	for (int j = 0; j < m; j++) {
		cin >> start >> end >> period;
		calendar.push({ start, end, period});
	}

	// escribir la solución
	if (hayConflicto(calendar, t)) cout << "SI\n";
	else cout << "NO\n";

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
