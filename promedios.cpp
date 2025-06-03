#include <iostream>
#include <string>
#include <vector>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

// Estructura para guardar los datos de cada estudiante
struct Estudiante
{
	string nombre;
	string cedula;
	string semestre;
	vector<float> calificaciones;
	float promedio;
	string estado;
};

// Función para validar la cédula
bool validarCedula(const string& cedula)
	{
    if (cedula.length() != 9) {
        cout << "Error: La cédula debe tener exactamente 9 dígitos.\n";
        return false;
    }
    for (char c : cedula) {
        if (!isdigit(c)) {
            cout << "Error: La cédula solo debe contener números.\n";
            return false;
        }
    }
    return true;
}
// Función para capturar los datos de un estudiante
Estudiante capturarEstudiante()
{
	cout << "\033[2J\033[H";
	Estudiante e;

	cout << BLUE << "\n =====================================";
	cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
	cout << BLUE << " =====================================" << RESET << endl;

	cout << "Ingrese el nombre completo: ";
	getline(cin, e.nombre);

	do{
		cout << "Ingrese la cedula: ";
		getline(cin, e.cedula);
	} while (!validarCedula(e.cedula));

	cout << "Ingrese el ciclo: ";
	getline(cin, e.semestre);

		cout << "Ingrese las 5 notas: ";
	e.calificaciones.resize(5);

	float suma = 0;
	for (int i = 0; i < 5; ++i)
	{
		float nota;
		do
		{
			cout << "Nota " << i + 1 << " (0 a 100): ";
			cin >> nota;
			if (nota < 0 || nota > 100)
				cout << RED << " Error: Nota fuera de rango.\n"
					 << RESET;
		} while (nota < 0 || nota > 100);
		e.calificaciones[i] = nota;
		suma += nota;
	}

	e.promedio = suma / 5;
	e.estado = (e.promedio >= 70) ? "Aprobado" : "Reprobado";

	cin.ignore(); // Limpia el buffer
	return e;
}

// Función para mostrar los datos de todos los estudiantes
void mostrarEstudiantes(const vector<Estudiante> &lista)
{
	cout << "\033[2J\033[H";
	cout << BLUE << "\n =====================================";
	cout << RED << "\n     RESULTADOS DE LOS ESTUDIANTES   \n";
	cout << BLUE << " =====================================" << RESET << endl;

	for (size_t i = 0; i < lista.size(); ++i)
	{
		cout << "\nEstudiante #" << i + 1 << endl;
		cout << "Nombre: " << lista[i].nombre << endl;
		cout << "Cedula: " << lista[i].cedula << endl;
		cout << "Semestre: " << lista[i].semestre << endl;
		cout << "Calificaciones: ";
		for (float nota : lista[i].calificaciones)
		{
			cout << nota << " ";
		}
		cout << "\nPromedio: " << lista[i].promedio;
		cout << "\nEstado: ";

		if (lista[i].estado == "Aprobado")
			cout << GREEN << lista[i].estado << RESET << endl;
		else
			cout << RED << lista[i].estado << RESET << endl;
	}
}

// Función principal
int main()
{
	cout << "\033[2J\033[H";

	int cantidadEstudiantes;
	vector<Estudiante> listaEstudiantes;

	cout << BLUE << "\n =====================================";
	cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
	cout << BLUE << " =====================================" << RESET << endl;

	cout << "Ingrese el numero de estudiantes: ";
	cin >> cantidadEstudiantes;
	cin.ignore(); // Limpiar buffer antes de getline()

	for (int i = 0; i < cantidadEstudiantes; ++i)
	{
		cout << "\n Capturando datos del estudiante #" << i + 1 << endl;
		Estudiante nuevo = capturarEstudiante();
		listaEstudiantes.push_back(nuevo);
	}

	mostrarEstudiantes(listaEstudiantes);
	return 0;
}
