/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Aaron Nauzet Moreno Sosa
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

/*@ <answer>

	Para resolver el ejercicio, guardamos los instrumentos en una cola de prioridad, dando mayor prioridad a aquel que
	tenga el grupo mas grande de musicos en la misma partitura mayor. Tras ello, vamos repartiendo las partituras,
	y tras actualizar el grupo mayor de dicho instrumento, lo volvemos a introducir en la cola de prioridad para futuras consultas.

	Para el comparador del struct Instrumento (que guarda el numero total de instrumentos, el grupo mas grande
	dentro de esos instrumentos por partitura, y el total de partituras repartidas), simplemente damos a prioridad a 'a'
	si su grupo mas grande es mayor que el del otro Instrumento.

	Lectura: O(N*log(N)), siendo 'N' el numero de instrumentos diferentes que componene la banda
	[N iteraciones, log(N) en el push() de la priority_queue de dichas iteraciones]

	Resolucion: O(M*log(N)), siendo 'M' la diferencia entre el numero de instrumentos diferentes y el
	numero de partituras a repartir (P - N); y siendo 'N' el numero de instrumentos diferentes
	(M iteraciones, log(N) tanto en el pop() como en el push() de la priority_queue dentro de 
	dichas iteraciones)

 @ </answer> */

 // =======================================================================
 // Escribe el código completo de tu solución aquí debajo, tras la etiqueta
 // =======================================================================
 //@ <answer>

struct Instrumento {
	int totalAmount;
	int numInstperPartMax;
	int numPart;

	bool operator<(Instrumento const& a) const {
		return a.numInstperPartMax > numInstperPartMax;
	}
};

bool resuelveCaso() {

	// leemos la entrada
	int P, N;
	cin >> P >> N;
	if (!cin) return false;

	// leer el resto del caso y resolverlo
	priority_queue<Instrumento> numInst;
	for (int i = 0; i < N; i++) {
		int newInst; cin >> newInst;
		numInst.push({ newInst, newInst, 1 });
	}

	for (int i = N; i < P; i++) {
		auto inst = numInst.top(); numInst.pop();
		inst.numPart++;
		inst.numInstperPartMax = (inst.totalAmount % inst.numPart == 0) ? inst.totalAmount / inst.numPart :
			inst.totalAmount / inst.numPart + 1;
		numInst.push(inst);
	}

	cout << numInst.top().numInstperPartMax << "\n";

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
