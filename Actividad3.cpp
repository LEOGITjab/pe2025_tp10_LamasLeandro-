#include <iostream>
#include <string>
using namespace std;

const int MAX = 500;

struct Pelicula {
	string idPelicula;
	string titulo;
	bool disponible;
	float duracion;
	int anioEstreno;
};

typedef Pelicula tvector[MAX];

void agregarPelicula(tvector peliculas, int &n) {
	if (n >= MAX) {
		cout << "No se pueden agregar más películas.\n";
		return;
	}
	cout << "\n=== Agregar Película ===\n";
	cout << "ID: ";
	cin >> peliculas[n].idPelicula;
	cin.ignore();
	cout << "Título: ";
	getline(cin, peliculas[n].titulo);
	cout << "Disponible (1=Sí, 0=No): ";
	cin >> peliculas[n].disponible;
	cout << "Duración (min): ";
	cin >> peliculas[n].duracion;
	cout << "Año de estreno: ";
	cin >> peliculas[n].anioEstreno;
	n++;
}

int buscarPorID(tvector peliculas, int n, string id, int i = 0) {
	if (i >= n) return -1; // No encontrado
	if (peliculas[i].idPelicula == id) return i;
	return buscarPorID(peliculas, n, id, i + 1);
}

int mayorDuracion(tvector peliculas, int n, int i = 0, int posMayor = 0) {
	if (i == n) return posMayor;
	if (peliculas[i].duracion > peliculas[posMayor].duracion)
		posMayor = i;
	return mayorDuracion(peliculas, n, i + 1, posMayor);
}

void mostrarPeliculas(tvector peliculas, int n, int i = 0) {
	if (i >= n) return;
	cout << "\nPelícula " << i + 1 << ":\n";
	cout << "ID: " << peliculas[i].idPelicula << endl;
	cout << "Título: " << peliculas[i].titulo << endl;
	cout << "Disponible: " << (peliculas[i].disponible ? "Sí" : "No") << endl;
	cout << "Duración: " << peliculas[i].duracion << " min\n";
	cout << "Año de Estreno: " << peliculas[i].anioEstreno << endl;
	mostrarPeliculas(peliculas, n, i + 1);
}

int main() {
	tvector peliculas;
	int n = 0;
	int opcion;
	
	do {
		cout << "\n===== MENU=====\n";
		cout << "1. Agregar película\n";
		cout << "2. Buscar película por ID\n";
		cout << "3. Mostrar película con mayor duración\n";
		cout << "4. Mostrar todas las películas\n";
		cout << "0. Salir\n";
		cout << "Opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			agregarPelicula(peliculas, n);
			break;
		case 2: {
			string id;
			cout << "Ingrese ID a buscar: ";
			cin >> id;
			int pos = buscarPorID(peliculas, n, id);
			if (pos == -1)
				cout << "No se encontró la película.\n";
			else {
				cout << "Película encontrada:\n";
				cout << "Título: " << peliculas[pos].titulo << endl;
			}
			break;
		}
		case 3: {
			if (n == 0)
				cout << "No hay películas cargadas.\n";
			else {
				int pos = mayorDuracion(peliculas, n);
				cout << "La película con mayor duración es: " << peliculas[pos].titulo
					<< " (" << peliculas[pos].duracion << " min)\n";
			}
			break;
		}
		case 4:
			if (n == 0)
				cout << "No hay películas cargadas.\n";
			else
				mostrarPeliculas(peliculas, n);
			break;
		case 0:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opción inválida.\n";
		}
	} while (opcion != 0);
	
	return 0;
}
