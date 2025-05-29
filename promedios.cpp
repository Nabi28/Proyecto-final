#include <iostream>
#include <vector>
#include <string>

#define RED "\033[31m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
using namespace std;

struct Estudiante
{
    string Nombre;
    string Cedula;
    string Semestre;
    vector<float> calificaciones;
};
Estudiante
capturarEstudiante()
{
    Estudiante e;
    int cantidadNotas;

    cout << BLUE << "\n »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»";
    cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
    cout << BLUE << " »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»" << RESET << endl;

    cout << "Ingrese el Nombre completo: ";
    getline(cin, e.Nombre);

    cout << "Ingrese la Cedula: ";
    getline(cin, e.Cedula);

    cout << "Ingrese el Semestre";
    getline(cin, e.Semestre);

    cout << "¿Cauntas notas decea calcular?: ";
    cin >> cantidadNotas;
    e.calificaciones.resize(cantidadNotas);

    for (int i = 0; i < cantidadNotas; ++i)
    {
        float nota;
        do
        {
            cout << "Nota " << i + 1 << " (0 a 100): ";
            cin >> nota;
        } while (nota < 0 || nota > 100);
        e.calificaciones[i] = nota;
    }
    cin.ignore();
    return e;
}

void mostrarEstudiantes(const vector<Estudiante> &lista)
{
    cout << BLUE << "\n »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»";
    cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
    cout << BLUE << " »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»" << RESET << endl;

    for (size_t i = 0; i < lista.size(); ++i)
    {
        cout << "\nEstudiantes #" << i + 1 << endl;
        cout << "Nombre: " << lista[i].Nombre << endl;
        cout << "Cedula: " << lista[i].Cedula << endl;
        cout << "Semestre: " << lista[i].Semestre << endl;
        cout << "Calificaciones: ";
        for (float nota : lista[i].calificaciones)
        {
            cout << nota << " ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "\033[2J\033[H";
    int cantidadEstudiantes;
    vector<Estudiante> listaEstudiantes;

    cout << BLUE << "\n »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»";
    cout << RED << "\n    SISTEMA DE REGISTRO ACADEMICO    \n";
    cout << BLUE << " »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»" << RESET << endl;

    cout << "Ingrese el numero de estudiantes: ";
    cin >> cantidadEstudiantes;
    cin.ignore();

    for (int i = 0; i < cantidadEstudiantes; ++i)
    {
        cout << "\nCapturado datos del estudiante #" << i + 1 << endl;
        Estudiante nuevo = capturarEstudiante();
        listaEstudiantes.push_back(nuevo);
    }

    mostrarEstudiantes(listaEstudiantes);

    return 0;
}