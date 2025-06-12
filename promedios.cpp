#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <iomanip>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

struct Estudiante {
	string nombre;
	string cedula;
	string semestre;
	float calificaciones[5];
	float promedio;
	string estado;
	string mensajeFinal;
};

// Función de validación de cédula
bool validarCedula(const string &cedula) {
	if (cedula.length() != 9) {
		cout << RED << "Error: La cédula debe tener exactamente 9 dígitos numéricos.\n" << RESET;
		return false;
	}
	for (char c : cedula) {
		if (!isdigit(c)) {
			cout << RED << "Error: La cédula solo debe contener números.\n" << RESET;
			return false;
		}
	}
	return true;
}

// Captura de datos de estudiantes
Estudiante capturarEstudiante() {
	Estudiante e;
	
	cout << BLUE << "\n=====================================";
	cout << RED << "\n    SISTEMA DE REGISTRO ACADÉMICO    \n";
	cout << BLUE << "=====================================" << RESET << endl;
	
	do {
		cout << "Ingrese el nombre completo: ";
		getline(cin, e.nombre);
		if (e.nombre.empty())
			cout << RED << "Error: El nombre no puede estar vacío.\n" << RESET;
	} while (e.nombre.empty());
	
	do {
		cout << "Ingrese la cédula: ";
		getline(cin, e.cedula);
	} while (!validarCedula(e.cedula));
	
	cout << "Ingrese el ciclo: ";
	getline(cin, e.semestre);
	
	cout << "Ingrese las 5 notas:" << endl;
	float suma = 0;
	for (int i = 0; i < 5; ++i) {
		float nota;
		do {
			cout << "Nota " << i + 1 << " (0 a 100): ";
			cin >> nota;

			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << RED << "Error: Entrada inválida. Ingrese un número.\n" << RESET;


			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << RED << "Error: Entrada invalida. Ingrese un numero.\n"
					 << RESET;

				nota = -1;
				continue;
			}
			
			if (nota < 0 || nota > 100)
				cout << RED << " Error: Nota fuera de rango.\n" << RESET;
			
		} while (nota < 0 || nota > 100);
		e.calificaciones[i] = nota;
		suma += nota;
	}
	
	e.promedio = suma / 5;

	e.estado = (e.promedio >= 70) ? "Aprobado" : "Reprobado";
	

	if (e.promedio >= 70)
	{
		e.estado = "Aprobado";
		e.mensajeFinal = "¡Felicidades! Has aprobado el curso.";
	}
	else
	{
		e.estado = "Reprobado";
		e.mensajeFinal = "Mejor suerte para la próxima, insecto.";
	}


	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return e;
}


// Mostrar resultados en tabla alineada
void mostrarEstudiantes(const Estudiante lista[], int cantidad) {
	string aprobados[cantidad], reprobados[cantidad];
	int contA = 0, contR = 0;
	
	for (int i = 0; i < cantidad; ++i) {
		if (lista[i].estado == "Aprobado") {
			aprobados[contA++] = lista[i].nombre;
		} else {
			reprobados[contR++] = lista[i].nombre;
		}
	}
	
	cout << BLUE << "\n=====================================";
	cout << RED << "\n     RESULTADOS DE LOS ESTUDIANTES   \n";
	cout << BLUE << "=====================================" << RESET << endl;
	
	// Imprimir tabla alineada
	cout << left << setw(20) << "APROBADOS" << "| " << "REPROBADOS" << endl;
	cout << setw(20) << "--------------------" << "| " << "--------------------" << endl;
	
	int max = contA > contR ? contA : contR;
	for (int i = 0; i < max; i++) {
		string a = (i < contA) ? aprobados[i] : "";
		string r = (i < contR) ? reprobados[i] : "";
		cout << left << setw(20) << a << "| " << r << endl;
=======
void mostrarEstudiantes(const Estudiante lista[], int cantidad)
{
	cout << BLUE << "\n =====================================";
	cout << RED << "\n     RESULTADOS DE LOS ESTUDIANTES   \n";
	cout << BLUE << " =====================================" << RESET << endl;

	for (int i = 0; i < cantidad; ++i)
	{
		cout << "\n=== Estudiante #" << i + 1 << " ===\n";

		cout << "Nombre:     " << lista[i].nombre << "\n";
		cout << "Cédula:     " << lista[i].cedula << "\n";
		cout << "Semestre:   " << lista[i].semestre << "\n";

		cout << "Calificaciones: ";
		for (int j = 0; j < 5; ++j)
		{
			cout << lista[i].calificaciones[j];
			if (j < 4)
				cout << ", ";
		}
		cout << "\n";

		cout << "Promedio: " << fixed << setprecision(2) << lista[i].promedio << "\n";

		string marco = "+====================+\n";

		if (lista[i].estado == "Aprobado")
		{
			cout << GREEN;
			cout << marco;
			cout << "|   ✅  Aprobado     |\n";
			cout << marco;
			cout << RESET;
		}
		else
		{
			cout << RED;
			cout << marco;
			cout << "|   ❌  Reprobado      |\n";
			cout << marco;
			cout << RESET;
		}

		cout << "Mensaje: " << lista[i].mensajeFinal << "\n";

	}
}

int main() {
	cout << "\033[2J\033[H"; // Limpiar pantalla
	
	int cantidadEstudiantes;
	do {
		cout << BLUE << "\n=====================================";
		cout << RED << "\n    SISTEMA DE REGISTRO ACADÉMICO    \n";
		cout << BLUE << "=====================================" << RESET << endl;
		
		cout << "Ingrese el número de estudiantes: ";
		cin >> cantidadEstudiantes;
		if (cin.fail() || cantidadEstudiantes <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << RED << "Error: Debe ingresar un número entero positivo.\n" << RESET;
			cantidadEstudiantes = 0;
		}
	} while (cantidadEstudiantes <= 0);
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	Estudiante listaEstudiantes[cantidadEstudiantes];
	
	for (int i = 0; i < cantidadEstudiantes; ++i) {
		cout << "\nCapturando datos del estudiante #" << i + 1 << endl;
		listaEstudiantes[i] = capturarEstudiante();
	}
	
	mostrarEstudiantes(listaEstudiantes, cantidadEstudiantes);
	return 0;
}
