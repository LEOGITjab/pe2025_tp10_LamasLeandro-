#include <iostream>
#include <string>
using namespace std;

struct Alumno {
	string nombre;
	int edad;
	int legajo;
};

struct Materia {
	string nombre;
	Alumno alumnos[50];
	int cantidad;
};

void insertarAlumno(Materia &m, Alumno a) {
	if (m.cantidad < 50) {
		m.alumnos[m.cantidad] = a;
		m.cantidad++;
		cout << "Alumno agregado correctamente.\n";
	} else {
		cout << "No se pueden agregar más alumnos.\n";
	}
}

void eliminarAlumno(Materia &m, int legajo) {
	bool encontrado = false;
	for (int i = 0; i < m.cantidad; i++) {
		if (m.alumnos[i].legajo == legajo) {
			for (int j = i; j < m.cantidad - 1; j++) {
				m.alumnos[j] = m.alumnos[j + 1];
			}
			m.cantidad--;
			encontrado = true;
			cout << "Alumno eliminado correctamente.\n";
			break;
		}
	}
	if (!encontrado) {
		cout << "No se encontró un alumno con ese legajo.\n";
	}
}

void mostrarAlumnosRecursivo(Materia &m, int i = 0) {
	if (i < m.cantidad) {
		cout << "Alumno " << i + 1 << ":\n";
		cout << "  Nombre: " << m.alumnos[i].nombre << endl;
		cout << "  Edad: " << m.alumnos[i].edad << endl;
		cout << "  Legajo: " << m.alumnos[i].legajo << endl;
		cout << "------------------------\n";
		mostrarAlumnosRecursivo(m, i + 1);
	}
}

int main() {
	Materia materia;
	materia.nombre = "Programación";
	materia.cantidad = 0;
	
	Alumno a1 = {"Juan", 17, 1001};
	Alumno a2 = {"Lucía", 16, 1002};
	Alumno a3 = {"Martín", 18, 1003};
	
	insertarAlumno(materia, a1);
	insertarAlumno(materia, a2);
	insertarAlumno(materia, a3);
	
	cout << "\n--- Lista de alumnos ---\n";
	mostrarAlumnosRecursivo(materia);
	
	cout << "\nEliminando alumno con legajo 1002...\n";
	eliminarAlumno(materia, 1002);
	
	cout << "\n--- Lista actualizada ---\n";
	mostrarAlumnosRecursivo(materia);
	
	return 0;
}

