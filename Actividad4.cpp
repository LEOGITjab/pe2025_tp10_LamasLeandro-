#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Personaje {
	string nombre;
	string elemento;
	string clase;
	int vidaMaxima;
	int danio;
	string descripcion;
	bool desbloqueado;
};

const int MAX_PERSONAJES = 100;
Personaje personajes[MAX_PERSONAJES];
int cantidad = 0;

void insertarPersonaje() {
	if (cantidad >= MAX_PERSONAJES) {
		cout << "No se pueden agregar más personajes.\n";
		return;
	}
	
	Personaje nuevo;
	cout << "\n=== Registrar nuevo personaje ===\n";
	cout << "Nombre: ";
	cin.ignore();
	getline(cin, nuevo.nombre);
	cout << "Elemento: ";
	getline(cin, nuevo.elemento);
	cout << "Clase: ";
	getline(cin, nuevo.clase);
	cout << "Vida máxima: ";
	cin >> nuevo.vidaMaxima;
	cout << "Daño: ";
	cin >> nuevo.danio;
	cin.ignore();
	cout << "Descripción: ";
	getline(cin, nuevo.descripcion);
	cout << "¿Está desbloqueado? (1 = Sí, 0 = No): ";
	cin >> nuevo.desbloqueado;
	
	int i = cantidad - 1;
	while (i >= 0 && personajes[i].nombre > nuevo.nombre) {
		personajes[i + 1] = personajes[i];
		i--;
	}
	personajes[i + 1] = nuevo;
	cantidad++;
	
	cout << "\nPersonaje agregado correctamente.\n";
}

void buscarPersonaje() {
	if (cantidad == 0) {
		cout << "No hay personajes registrados.\n";
		return;
	}
	
	string nombreBuscado;
	cout << "\nIngrese el nombre del personaje a buscar: ";
	cin.ignore();
	getline(cin, nombreBuscado);
	
	bool encontrado = false;
	for (int i = 0; i < cantidad; i++) {
		if (personajes[i].nombre == nombreBuscado) {
			encontrado = true;
			cout << "\n=== Personaje encontrado ===\n";
			cout << "Nombre: " << personajes[i].nombre << endl;
			cout << "Elemento: " << personajes[i].elemento << endl;
			cout << "Clase: " << personajes[i].clase << endl;
			cout << "Vida Máxima: " << personajes[i].vidaMaxima << endl;
			cout << "Daño: " << personajes[i].danio << endl;
			cout << "Descripción: " << personajes[i].descripcion << endl;
			cout << "Desbloqueado: " << (personajes[i].desbloqueado ? "Sí" : "No") << endl;
			break;
		}
	}
	
	if (!encontrado)
		cout << "No se encontró el personaje con ese nombre.\n";
}

void eliminarPersonaje() {
	if (cantidad == 0) {
		cout << "No hay personajes registrados.\n";
		return;
	}
	
	string nombreEliminar;
	cout << "\nIngrese el nombre del personaje a eliminar: ";
	cin.ignore();
	getline(cin, nombreEliminar);
	
	bool encontrado = false;
	for (int i = 0; i < cantidad; i++) {
		if (personajes[i].nombre == nombreEliminar) {
			encontrado = true;
			for (int j = i; j < cantidad - 1; j++) {
				personajes[j] = personajes[j + 1];
			}
			cantidad--;
			cout << "Personaje eliminado correctamente.\n";
			break;
		}
	}
	
	if (!encontrado)
		cout << "No se encontró el personaje con ese nombre.\n";
}

int main() {
	int opcion;
	
	do {
		cout << "\n===== MENU PRINCIPAL =====\n";
		cout << "1. Insertar nuevo personaje\n";
		cout << "2. Buscar personaje por nombre\n";
		cout << "3. Eliminar personaje\n";
		cout << "4. Salir\n";
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: insertarPersonaje(); break;
		case 2: buscarPersonaje(); break;
		case 3: eliminarPersonaje(); break;
		case 4: cout << "Saliendo del programa...\n"; break;
		default: cout << "Opción no válida.\n"; break;
		}
	} while (opcion != 4);
	
	return 0;
}

