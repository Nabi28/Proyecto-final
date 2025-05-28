#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Estudiante
{
    string Nombre;
    string Cedula;
    string Semestre;
    vector<float> calificaciones;
};

Estudiante capturarEstudiante()
{
    Estudiante e;
    int cantidadNotas;

    cout << "Ingrese el Nombre completo: ";
    getline(cin, e.Nombre);

    cout << "Ingrese la Cedula: ";
    getline(cin, e.Cedula);

    cout << "Ingrese Semestre";
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
        e.calificaciones[1] = nota;
    }
    cin.ignore();
    return e;
}

void mostrarEstudiantes(const vector<Estudiante> &lista)
{
    cout << "\nListado de estudiantes: \n";
    for (size_t i = 0; i < lista.size(); ++i)
    {
        cout << "\nEstudiantes #" << i + 1 << endl;
        cout << "Nombre: " << lista[i].Nombre << endl;
        cout << "Cedula: " << lista[i].Cedula << endl;
        cout << "Semstre: " << lista[i].Semestre << endl;
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
    int cantidadEstudiantes;
    vector<Estudiante> listaEstudiantes;

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