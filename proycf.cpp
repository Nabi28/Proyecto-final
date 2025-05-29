#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
	vector<float> calificaciones;
};

int main(){
	int numest;
	int est;
	
	do{
		cout<< "Ingresa la cantidad de alumnos que quieres evaluar: ";
		cin >> numest;
		
		if (numest <=0){
			cout<< "ERROR. Ingrese un numero mayor a 0. Intente de nuevo:  ";
			
		}
	}while (numest <=0);
	
	for (est = 1; est<= numest; est++){
		float Nota, suma=0, promedio;
		
		cout<< "Alumno #" << est << endl;
		//esto fue una recomendacion
		
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
		for (int i = 0; i < cantidadNotas; ++i) {
			suma += e.calificaciones[i];
		}
		
		float promedio = suma / cantidadNotas;
		
		cout << "Su promedio es: " << promedio << endl;
		
		if (promedio >= 70) {
			cout << "El alumno esta Aprobado" << endl;
		} else {
			cout << "El alumno esta Reprobado" << endl;
		}
	}
	
	return 0;
}
