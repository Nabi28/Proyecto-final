#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
	string Nombre;
	string Cedula;
	string Semestre;
	vector<float> calificaciones;
	float promedio;
	string estado;
};
//mi parte guarda el promedio y tamb clasifica si esta aprobado o reprobado
Estudiante capturarEstudiante() {
	Estudiante e;
	int cantidadNotas;
	
	cout << "Ingrese el Nombre completo: ";
	getline(cin, e.Nombre);
	
	cout << "Ingrese la Cédula: ";
	getline(cin, e.Cedula);
	
	cout << "Ingrese el Semestre: ";
	getline(cin, e.Semestre);
	
	cout << "¿Cuántas notas desea calcular?: ";
	cin >> cantidadNotas;
	
	e.calificaciones.resize(cantidadNotas);
	
	for (int i = 0; i < cantidadNotas; ++i) {
		float nota;
		do {
			cout << "Nota " << i + 1 << " (0 a 100): ";
			cin >> nota;
		} while (nota < 0 || nota > 100);
		
		e.calificaciones[i] = nota;
	}
	
	float suma = 0;
	
	
	for (float nota : e.calificaciones) {
		suma += nota;
	}
	
	
	
	e.promedio = suma / cantidadNotas;
	//en esta parte se suman y se dividen las notas
	

	if (e.promedio >= 70) {
		e.estado = "Aprobado";
	} else {
		e.estado = "Reprobado";
	}
	// y esto se usa para aprobar o desaprobar
	
	cin.ignore(); //a lo que entendí de Fere esq esto ayuda a que las cosas no se dañen
	return e;
}

void mostrarEstudiantes(const vector<Estudiante>& lista) {
	cout << "\n?? Listado de estudiantes: \n";
	for (size_t i = 0; i < lista.size(); ++i) {
		cout << "\nEstudiante #" << i + 1 << endl;
		cout << "Nombre: " << lista[i].Nombre << endl;
		cout << "Cédula: " << lista[i].Cedula << endl;
		cout << "Semestre: " << lista[i].Semestre << endl;
		cout << "Calificaciones: ";
		for (float nota : lista[i].calificaciones) {
			cout << nota << " ";
		}
		cout << "\nPromedio: " << lista[i].promedio << endl;
		cout << "Estado: " << lista[i].estado << endl;
	}
}

int main() {
	int cantidadEstudiantes;
	vector<Estudiante> listaEstudiantes;
	
	cout << "Ingrese el número de estudiantes: ";
	cin >> cantidadEstudiantes;
	cin.ignore();
	
	for (int i = 0; i < cantidadEstudiantes; ++i) {
		cout << "\n?? Capturando datos del estudiante #" << i + 1 << endl;
		Estudiante nuevo = capturarEstudiante();
		listaEstudiantes.push_back(nuevo);
	}
	
	mostrarEstudiantes(listaEstudiantes);
	
	return 0;
}
