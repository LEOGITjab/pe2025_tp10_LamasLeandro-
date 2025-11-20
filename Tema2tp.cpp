#include <iostream>
using namespace std;

// Declaraciones de funciones
void establecerSaldo(double &saldo, bool &saldoInicializado);
void realizarDeposito(double &saldo, bool saldoInicializado);
void realizarExtraccion(double &saldo, bool saldoInicializado);
void consultarSaldo(double saldo, bool saldoInicializado);

int main() {
	double saldo = 0.0;
	bool saldoInicializado = false;
	int opcion;
	
	do {
		cout << "\n************ Simulador de ATM ************" << endl;
		cout << "1- Establecer saldo inicial" << endl;
		cout << "2- Realizar un deposito" << endl;
		cout << "3- Realizar una extraccion" << endl;
		cout << "4- Consultar saldo" << endl;
		cout << "5- Salir" << endl;
		cout << "------------------------------------------" << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			establecerSaldo(saldo, saldoInicializado);
			break;
		case 2:
			realizarDeposito(saldo, saldoInicializado);
			break;
		case 3:
			realizarExtraccion(saldo, saldoInicializado);
			break;
		case 4:
			consultarSaldo(saldo, saldoInicializado);
			break;
		case 5:
			cout << "Fin de operaciones." << endl;
			break;
		default:
			cout << "OPCION INCORRECTA, intente de nuevo." << endl;
			break;
		}
		
	} while (opcion != 5);
	
	return 0;
}

// Función para establecer el saldo inicial
void establecerSaldo(double &saldo, bool &saldoInicializado) {
	double monto;
	cout << "Ingrese el saldo inicial: ";
	cin >> monto;
	
	if (monto >= 0) {
		saldo = monto;
		saldoInicializado = true;
		cout << "Saldo inicial establecido correctamente." << endl;
	} else {
		cout << "El saldo inicial no puede ser negativo." << endl;
	}
}

// Funcioon para realizar un deposito
void realizarDeposito(double &saldo, bool saldoInicializado) {
	if (!saldoInicializado) {
		cout << "Debe establecer el saldo inicial primero." << endl;
		return;
	}
	
	double monto;
	cout << "Ingrese el monto a depositar: ";
	cin >> monto;
	
	if (monto > 0) {
		saldo += monto;
		cout << "Deposito realizado con exito. Nuevo saldo: $" << saldo << endl;
	} else {
		cout << "El monto a depositar debe ser positivo." << endl;
	}
}

// Función para realizar una extracción
void realizarExtraccion(double &saldo, bool saldoInicializado) {
	if (!saldoInicializado) {
		cout << "Debe establecer el saldo inicial primero." << endl;
		return;
	}
	
	double monto;
	cout << "Ingrese el monto a extraer: ";
	cin >> monto;
	
	if (monto > 0) {
		if (monto <= saldo) {
			saldo -= monto;
			cout << "Extraccion realizada con exito. Nuevo saldo: $" << saldo << endl;
		} else {
			cout << "FONDOS INSUFICIENTES." << endl;
		}
	} else {
		cout << "El monto a extraer debe ser positivo." << endl;
	}
}

// Función para consultar saldo
void consultarSaldo(double saldo, bool saldoInicializado) {
	if (!saldoInicializado) {
		cout << "Debe establecer el saldo inicial primero." << endl;
		return;
	}
	
	cout << "El saldo actual es: $" << saldo << endl;
}

