// Prueba
#include <iostream>
#include <string>
#include <limits>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

struct Estudiante 
{
	string nombre;
	string cedula;
	string semestre;
	float calificaciones[5];
	float promedio;
	string estado;
};

bool validarCedula(const string &cedula)
{
	if (cedula.length() != 9)
	{
		cout << RED << "Error: La cedula debe tener exactamente 9 digitos numericos.\n"
			 << RESET;
		return false;
	}
	for (char c : cedula)
	{
		if (!isdigit(c))
		{
			cout << RED << "Error: La cedula solo debe contener numeros.\n"
				 << RESET;
			return false;
		}
	}
	return true;
}

Estudiante capturarEstudiante()
{
	Estudiante e;

	cout << BLUE << "\n =====================================";
	cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
	cout << BLUE << " =====================================" << RESET << endl;

	do
	{
		cout << "Ingrese el nombre completo: ";
		getline(cin, e.nombre);
		if (e.nombre.empty())
			cout << RED << "Error: El nombre no puede estar vacio.\n"
				 << RESET;
	} while (e.nombre.empty());

	do
	{
		cout << "Ingrese la cedula: ";
		getline(cin, e.cedula);
	} while (!validarCedula(e.cedula));

	cout << "Ingrese el ciclo: ";
	getline(cin, e.semestre);

	cout << "Ingrese las 5 notas:" << endl;
	float suma = 0;
	for (int i = 0; i < 5; ++i)
	{
		float nota;
		do
		{
			cout << "Nota " << i + 1 << " (0 a 100): ";
			cin >> nota;

			if (cin.fail())
			{
				cin.clear(); // limpiar error
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << RED << "Error: Entrada invalida. Ingrese un numero.\n"
					 << RESET;
				nota = -1; // fuerza repetir el ciclo
				continue;
			}

			if (nota < 0 || nota > 100)
				cout << RED << " Error: Nota fuera de rango.\n"
					 << RESET;

		} while (nota < 0 || nota > 100);
		e.calificaciones[i] = nota;
		suma += nota;
	}

	e.promedio = suma / 5;
	e.estado = (e.promedio >= 70) ? "Aprobado" : "Reprobado";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return e;
}

void mostrarEstudiantes(const Estudiante lista[], int cantidad)
{
	cout << BLUE << "\n =====================================";
	cout << RED << "\n     RESULTADOS DE LOS ESTUDIANTES   \n";
	cout << BLUE << " =====================================" << RESET << endl;

	for (int i = 0; i < cantidad; ++i)
	{
		cout << "\nEstudiante #" << i + 1 << endl;
		cout << "Nombre: " << lista[i].nombre << endl;
		cout << "Cedula: " << lista[i].cedula << endl;
		cout << "Semestre: " << lista[i].semestre << endl;
		cout << "Calificaciones: ";
		for (int j = 0; j < 5; ++j)
		{
			cout << lista[i].calificaciones[j] << " ";
		}
		cout << "\nPromedio: " << lista[i].promedio;
		cout << "\nEstado: ";

		if (lista[i].estado == "Aprobado")
			cout << GREEN << lista[i].estado << RESET << endl;
		else
			cout << RED << lista[i].estado << RESET << endl;
	}
}

int main()
{
	cout << "\033[2J\033[H";

	int cantidadEstudiantes;

	do
	{
		cout << BLUE << "\n =====================================";
		cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
		cout << BLUE << " =====================================" << RESET << endl;

		cout << "Ingrese el numero de estudiantes: ";
		cin >> cantidadEstudiantes;
		if (cin.fail() || cantidadEstudiantes <= 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << RED << "Error: Debe ingresar un numero entero positivo.\n"
				 << RESET;
			cantidadEstudiantes = 0;
		}
	} while (cantidadEstudiantes <= 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Estudiante listaEstudiantes[cantidadEstudiantes];

	for (int i = 0; i < cantidadEstudiantes; ++i)
	{
		cout << "\nCapturando datos del estudiante #" << i + 1 << endl;
		listaEstudiantes[i] = capturarEstudiante();
	}

	mostrarEstudiantes(listaEstudiantes, cantidadEstudiantes);
	return 0;
}
