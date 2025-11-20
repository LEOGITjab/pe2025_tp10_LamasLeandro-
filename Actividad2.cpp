#include <iostream>
#include <string>
using namespace std;

struct Paciente {
	string nombre;
	string especie;
	int edad;
	int id; // identificador único del paciente
};

const int MAX_PACIENTES = 50;

void agregarPaciente(Paciente pacientes[], int &cantidad) {
	if (cantidad < MAX_PACIENTES) {
		Paciente p;
		cout << "Ingrese nombre del paciente: ";
		cin.ignore();
		getline(cin, p.nombre);
		cout << "Ingrese especie (perro, gato, etc.): ";
		getline(cin, p.especie);
		cout << "Ingrese edad: ";
		cin >> p.edad;
		cout << "Ingrese ID: ";
		cin >> p.id;
		
		pacientes[cantidad] = p;
		cantidad++;
		
		cout << "Paciente agregado correctamente.\n";
	} else {
		cout << "No se pueden agregar más pacientes.\n";
	}
}

void mostrarPacientes(Paciente pacientes[], int cantidad) {
	if (cantidad == 0) {
		cout << "No hay pacientes registrados.\n";
		return;
	}
	
	cout << "\n--- LISTA DE PACIENTES ---\n";
	for (int i = 0; i < cantidad; i++) {
		cout << "Paciente " << i + 1 << ":\n";
		cout << "  Nombre: " << pacientes[i].nombre << endl;
		cout << "  Especie: " << pacientes[i].especie << endl;
		cout << "  Edad: " << pacientes[i].edad << endl;
		cout << "  ID: " << pacientes[i].id << endl;
		cout << "--------------------------\n";
	}
}

void eliminarPaciente(Paciente pacientes[], int &cantidad, int id) {
	bool encontrado = false;
	for (int i = 0; i < cantidad; i++) {
		if (pacientes[i].id == id) {
			for (int j = i; j < cantidad - 1; j++) {
				pacientes[j] = pacientes[j + 1];
			}
			cantidad--;
			encontrado = true;
			cout << "Paciente eliminado correctamente.\n";
			break;
		}
	}
	if (!encontrado)
		cout << "No se encontró un paciente con ese ID.\n";
}

void ordenarPorEdad(Paciente pacientes[], int cantidad) {
	for (int i = 0; i < cantidad - 1; i++) {
		for (int j = 0; j < cantidad - i - 1; j++) {
			if (pacientes[j].edad > pacientes[j + 1].edad) {
				Paciente temp = pacientes[j];
				pacientes[j] = pacientes[j + 1];
				pacientes[j + 1] = temp;
			}
		}
	}
	cout << "Pacientes ordenados por edad.\n";
}

void ordenarPorNombre(Paciente pacientes[], int cantidad) {
	for (int i = 0; i < cantidad - 1; i++) {
		for (int j = 0; j < cantidad - i - 1; j++) {
			if (pacientes[j].nombre > pacientes[j + 1].nombre) {
				Paciente temp = pacientes[j];
				pacientes[j] = pacientes[j + 1];
				pacientes[j + 1] = temp;
			}
		}
	}
	cout << "Pacientes ordenados por nombre.\n";
}

int main() {
	Paciente pacientes[MAX_PACIENTES];
	int cantidad = 0;
	int opcion;
	
	do {
		cout << "\n===== VETERINARIA =====\n";
		cout << "1. Agregar paciente\n";
		cout << "2. Mostrar pacientes\n";
		cout << "3. Eliminar paciente\n";
		cout << "4. Ordenar por edad\n";
		cout << "5. Ordenar por nombre\n";
		cout << "0. Salir\n";
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		if (opcion == 1) {
			agregarPaciente(pacientes, cantidad);
		} else if (opcion == 2) {
			mostrarPacientes(pacientes, cantidad);
		} else if (opcion == 3) {
			int id;
			cout << "Ingrese el ID del paciente a eliminar: ";
			cin >> id;
			eliminarPaciente(pacientes, cantidad, id);
		} else if (opcion == 4) {
			ordenarPorEdad(pacientes, cantidad);
		} else if (opcion == 5) {
			ordenarPorNombre(pacientes, cantidad);
		}
		
	} while (opcion != 0);
	
	cout << "Programa finalizado.\n";
	return 0;
}
