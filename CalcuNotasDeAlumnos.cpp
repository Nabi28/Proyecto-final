#include <string>
#include <iostream>
//espero estar haciendo esto bien T_T
ising namespace std;

int main (){
for (int i = 0; i < cantidadNotas; ++i) {
	float nota;
	do {
		cout << "Nota " << i + 1 << ": ";
		cin >> nota;
	} while (nota < 0 || nota > 100);
	e.calificaciones[i] = nota;
}

return e;
}
