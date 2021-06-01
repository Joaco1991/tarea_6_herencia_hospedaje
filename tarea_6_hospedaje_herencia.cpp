#include <iostream>
#include <stdlib.h>
using namespace std;
//*************Clase Padre*******************
class hospedaje {
public:
	hospedaje(float, string);
	void mostrarhospedaje();

private:
	float precio;
	string direccion;
};

//Constructor clase hospedaje
hospedaje::hospedaje(float _precio, string _direccion) {
	precio = _precio;
	direccion = _direccion;
}
void hospedaje::mostrarhospedaje() {
	cout << "El precio en dolares es: " << precio << endl;
	cout << "La direccion es:" << direccion << endl;
}

//**************************Clase Hoteles*****************************
class hoteles : public hospedaje {
public:
	hoteles(float, string, string);
	void mostrarhoteles();
private:
	string clasehotel;
};


//contructor clase hoteles
hoteles::hoteles(float _precio, string _direccion, string _clasehotel) : hospedaje (_precio, _direccion){
	clasehotel = _clasehotel;
}

void hoteles::mostrarhoteles() {
	mostrarhospedaje();
	cout << "La clase de hotes es: " << clasehotel << endl;
}

//*********************Clase habitaciones************************
class habitacion : public hoteles{
public:
	habitacion(float, string, string, int);
	void mostrarCamas();
private:
	int cantCamas;
};

habitacion::habitacion(float _precio, string _direccion, string _clasehotel, int _cantCamas) : hoteles(_precio, _direccion, _clasehotel){
	cantCamas = _cantCamas;
}

void habitacion::mostrarCamas() {
	mostrarhoteles();
	cout << "La cantidad de camas de la habitacion es: " << cantCamas << endl << endl;
}

//*********************Clase Apartamentos*******************************
class apartamentos :public hospedaje {
public:
	apartamentos(float, string, int, int, int);
	void mostrarapartamentos();
private:
	int cantcuartos;
	int cantbanos;
	int cantvehiculos;
};

//Asignandole los valores a contructor apartamentos
apartamentos::apartamentos(float _precio, string _direccion, int _cantcuartos, int _cantbanos, int _cantvehiculos) : hospedaje(_precio, _direccion) {
	cantcuartos = _cantcuartos;
	cantbanos = _cantbanos;
	cantvehiculos = _cantvehiculos;
}
void apartamentos :: mostrarapartamentos() {
	mostrarhospedaje();
	cout << "La cantidad de cuartos es: " << cantcuartos << endl;
	cout << "La cantidad de banos es: " << cantbanos << endl;
	cout << "La cantidad de estacionamientos es: " << cantvehiculos << endl;
}

//Agregado de Hoteles
hoteles hot1(55, "Hatillo", "5 estrellas");
hoteles hot2(45, "Merendon", "4 estrellas");
hoteles hot3(35, "Jucutuma", "3 estrellas");
hoteles hot4(15, "Comayaguela", "2 estrellas");

//Apartamentos
apartamentos ap1(500, "LomaLinda", 5, 3, 4);
apartamentos ap2(450, "Fesitranh", 4, 3, 3);
apartamentos ap3(400, "Castanos", 3, 2, 2);

//Agregado de camas
habitacion hab1(55, "Hatillo", "5 estrellas", 1);
habitacion hab2(45, "Merendon", "4 estrellas", 1);
habitacion hab3(35, "Jucutuma", "3 estrellas", 2);
habitacion hab4(15, "Comayaguela", "2 estrellas", 3);

int main(){
	int opcion=0;

	while (opcion != 3) {
		cout << "Seleccione 1 para ver hoteles disponibles" << endl;
		cout << "Seleccione 2 para ver apartamentos dispobibles" << endl;
		cout << "Seleccione 3 para ver cantidad de camas de habitaciones" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			hot1.mostrarhoteles();
			cout << endl << endl;
			hot2.mostrarhoteles();
			cout << endl << endl;
			hot3.mostrarhoteles();
			cout << endl << endl;
			hot4.mostrarhoteles();
			break;
		case 2:
			ap1.mostrarapartamentos();
			cout << endl << endl;
			ap2.mostrarapartamentos();
			cout << endl << endl;
			ap3.mostrarapartamentos();
			cout << endl << endl;
			break;
		case 3:
			hab1.mostrarCamas();
			cout << endl << endl;
			hab2.mostrarCamas();
			cout << endl << endl;
			hab3.mostrarCamas();
			cout << endl << endl;
			hab4.mostrarCamas();
			cout << endl << endl;
		default:
			break;
		}
		cout << "Seleccione cualquier numero para ver opciones o seleccione 3 para salir de programa" << endl<<endl;
		cin >> opcion;
	}
	
	system("pause");
	return 0;
}
