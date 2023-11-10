// Librerias
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
// Variables Globales
int getSeleccion();
void showOpciones();
void getOperacion();
float getValor(string texto);
// Prototipos de funcion
float SumayResta();
float Multiplicacion();
float Division();
float Potencia();
float Logaritmo();
void NotacionCientifica();
void AritmeticaPuntoFlotante();
float SistemaNumerico();
float valorAbsoluto();
float RaizCuadrada();
void showOptsTri();
float FuncionesTri();
int opcionTri();
float resultadoTri(float num);
// CONVERSIONES
float Dec_Binario(int num) {
	int dividendo = 0, cociente = 0;
	float residuo = 0, k = 1, octal = 0;
	cociente = num;
	while (cociente >= 2) {
		dividendo = cociente;
		cociente = dividendo / 2;
		residuo = (float)(dividendo % 2);
		octal += residuo * k;
		k = k * 10;
	}
	octal += cociente * k;
	return octal;
}
float Dec_Octal(int num) {
	int dividendo = 0, cociente = 0;
	float residuo = 0, k = 1, octal = 0;
	cociente = num;
	while (cociente >= 8) {
		dividendo = cociente;
		cociente = dividendo / 8;
		residuo = (float)(dividendo % 8);
		octal += residuo * k;
		k = k * 10;
	}
	octal += cociente * k;
	return octal;
}
float Dec_Hexa(int num) {
	int dividendo = 0, cociente = 0;
	float residuo = 0, k = 1, octal = 0;
	cociente = num;
	while (cociente >= 16) {
		dividendo = cociente;
		cociente = dividendo / 16;
		residuo = (float)(dividendo % 16);
		octal += residuo * k;
		k = k * 10;
	}
	octal += cociente * k;
	return octal;
}
// Variables
int slt; // Seleccion del usuario
float resultado;
// Funcion principal
int main() { getOperacion(); }
// Validar que el usuario ingrese valores entre 1 y 13
int getSeleccion() {
	int valor = 0;
	bool valido = false;
	while (valido == false) {
		showOpciones();
		cin >> valor;
		if (valor > 13 || valor < 1 || typeid(valor) == typeid(string)) {
			valido = false;
			system("cls");
			cout << "VALOR INVALIDO (elija las opciones disponibles [1-13])" << endl;
		}
		else {
			valido = true;
		}
	}
	return valor;
}
// Mostrar menu de opciones
void showOpciones() {
	cout << "Seleccione la operacion que desee realizar: " << endl << endl;
	cout << "Suma y Resta....................................[1]" << endl;
	cout << "Multiplicacion..................................[2]" << endl;
	cout << "Division........................................[3]" << endl;
	cout << "Potencia........................................[4]" << endl;
	cout << "Raices cuadradas y superiores...................[5]" << endl;
	cout << "Logaritmo.......................................[6]" << endl;
	cout << "Notacion Cientifica.............................[7]" << endl;
	cout << "Aritmetica de punto flotante....................[8]" << endl;
	cout << "Sistemas de numeracion..........................[9]" << endl;
	cout << "Funciones de trigonometria......................[10]" << endl;
	cout << "Valor absoluto..................................[11]" << endl;
	cout << "Instrucciones...................................[12]" << endl;
}
// Casos
void getOperacion() {
	switch (getSeleccion()) {
	case 1:
		resultado = SumayResta();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 2:
		resultado = Multiplicacion();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 3:
		resultado = Division();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 4:
		resultado = Potencia();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 5:
		resultado = RaizCuadrada();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 6:
		resultado = Logaritmo();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 7:
		NotacionCientifica();
		break;
	case 8:
		AritmeticaPuntoFlotante();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 9:
		resultado = SistemaNumerico();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 10:
		resultado = FuncionesTri();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 11:
		resultado = valorAbsoluto();
		cout << "El resultado es: " << resultado << endl;
		break;
	case 12:
		cout << "INDICACIONES IMPORTANTES" << endl;
		cout << "- escriba "
			"pi"
			" o "
			"e"
			" para usar el numero pi y el numero neperiano respectivamente"
			<< endl;
		cout << "- las funciones trigonometricas se calculan en radianes" << endl;
		break;
	}
	bool valido = false;
	string flag;
	do {
		cout << "Desea volver a hacer una operacion (S/N)?" << endl;
		cin >> flag;
		if (flag == "s" || flag == "S") {
			valido = true;
			getOperacion();
		}
		else if (flag == "n" || flag == "N") {
			valido = false;
			cout << "***********************: " << endl;
		}
	} while (valido);
}
// Valores pi y e
float getValor(string texto) {
	float valor = 0;
	if (texto == "pi") {
		valor = 3.1416f;
	}
	else if (texto == "e") {
		valor = 2.718f;
	}
	else {
		valor = stof(texto);
	}
	return valor;
}
float SumayResta() {
	int cantidad = 0;
	float suma = 0;
	string sumando = "0", signo = "+";
	bool valido = false;
	cout << "Ingrese cantidad de numeros a operar: ";
	do {
		cin >> cantidad;
		if (cantidad > 1) {
			valido = true;
		}
		else {
			valido = false;
			cout << "Porfavor ingrese una cantidad mayor a 1:" << endl;
		}
	} while (!valido);
	valido = false; // resetando...
	for (int i = 0; i < cantidad; i++) {
		valido = false; // reseteando el valor...
		while (valido == false) {
			cout << "Ingrese el numero " << i + 1 << " : ";
			cin >> sumando;
			if (getValor(sumando) >= 0 || getValor(sumando) <= 0) {
				valido = true;
			}
			else {
				valido = false;
				cout << "Dato invalido, ingrese un numero" << endl;
			}
		}
		if (signo == "+" || i == 0) {
			suma += getValor(sumando);
		}
		else if (signo == "-") {
			suma -= getValor(sumando);
		}
		if (i != cantidad - 1)
			valido = false; // reseteamos este valor para la siguiente validación...
		while (valido == false) {
			cout << "Desea sumar o restar?, escriba (+/-): ";
			cin >> signo;
			if (signo == "+" || signo == "-") {
				valido = true;
			}
			else {
				valido = false;
				cout << "Dato invalido, ingrese signos (+/-)" << endl;
			}
		}
	}
	return suma;
}
float Multiplicacion() {
	int cantidad = 0;
	float producto = 1;
	string multiplo = "0";
	bool valido = false;
	cout << "Ingrese cantidad de numeros a multiplicar: ";
	do {
		cin >> cantidad;
		if (cantidad > 1) {
			valido = true;
		}
		else {
			valido = false;
			cout << "Porfavor ingrese una cantidad mayor a 1:" << endl;
		}
	} while (!valido);
	for (int i = 0; i < cantidad; i++) {
		cout << "Ingrese multiplo " << i + 1 << " : ";
		cin >> multiplo;
		producto = producto * getValor(multiplo);
	}
	return producto;
}
float Division() {
	int cantidad = 0;
	float division = 1;
	string divisor = "0";
	bool valido = false;
	cout << "Ingrese cantidad de numeros a dividir: ";
	do {
		cin >> cantidad;
		if (cantidad > 1) {
			valido = true;
		}
		else {
			valido = false;
			cout << "Porfavor ingrese una cantidad mayor a 1:" << endl;
		}
	} while (!valido);
	for (int i = 0; i < cantidad; i++) {
		cout << "Ingrese divisor " << i + 1 << " : ";
		cin >> divisor;
		if (i == 0)
			division = getValor(divisor);
		else
			division = division / getValor(divisor);
	}
	return division;
}
float Potencia() {
	float base, exponente, potencia = 1;
	cout << "Ingrese el numero base: ";
	cin >> base;
	cout << "Ingrese el numero exponente: ";
	cin >> exponente;
	potencia = pow(base, exponente);
	return potencia;
}
float RaizCuadrada() {
	float n = 0, m = 0, raiz = 0;
	cout << "Ingresar radicando:";
	cin >> n;
	cout << "Ingresar el numero indice: ";
	cin >> m;
	raiz = pow(n, (1 / m));
	return raiz;
}
float Logaritmo() {
	float base = 0, argumento = 0;
	float logaritmo = 0;
	bool valido = false;
	do {
		cout << "Ingresar la base de logaritmo diferente a 0:";
		cin >> base;
		if (base == 0)
			valido = false;
		else
			valido = true;
	} while (!valido);
	cout << "Ingresar argumento:";
	cin >> argumento;
	logaritmo = (log(argumento) / log(base));
	cout << "log" << base << "(" << argumento << ")"
		<< "=" << logaritmo << endl;
	return logaritmo;
}
void NotacionCientifica() {
	float numero;
	cout << "Ingrese un numero grande para calcular su notacion cientifica: ";
	cin >> numero;
	cout << "Su notacion cientifica es: ";
	cout << numero;
}
void AritmeticaPuntoFlotante() {
	double x;
	cout << "Ingresar numero:" << endl;
	cin >> x;
	cout << setprecision(4);
	cout << "float:";
	cout << x << endl;
	cout << setprecision(8);
	cout << "double:";
	cout << x << endl;
	cout << setprecision(16);
	cout << "long double:";
	cout << x << endl;
}
float SistemaNumerico() {
	int opcion1 = 1;
	float old_num = 0,
		new_num = 0; // old es el ingresado y new es la transformacion
	bool valido = false;
	// CUAL ES ESE NUMERO...?
	cout << "Que numero desea transformar?: ";
	cin >> old_num;
	cout << "Binario......[1] " << endl;
	cout << "Octal........[2] " << endl;
	cout << "Hexadecimal..[3]" << endl;
	do {
		cout << "A que sistema numerico lo quiere pasar?: " << endl;
		cin >> opcion1;
		if (opcion1 > 3 || opcion1 < 1) {
			valido = false;
			cout << "Dato nvalido, por favor seleccion una de las opciones "
				"disponibles";
		}
		else
			valido = true;
	} while (!valido);
	switch (opcion1) {
	case 1: // A binario...
		new_num = Dec_Binario(old_num);
		break;
	case 2: // A octal...
		new_num = Dec_Octal(old_num);
		break;
	case 3: // A hexadecimal...
		new_num = Dec_Hexa(old_num);
		break;
	}
	return new_num;
}
float FuncionesTri() {
	float num, result;
	cout << "Ingresar el numero:";
	cin >> num;
	cout << endl;
	result = resultadoTri(num);
	return result;
}
int opcionTri() {
	int valor = 0;
	bool valido = false;
	while (valido == false) {
		showOptsTri();
		cin >> valor;
		if (valor > 3 || valor < 1 || typeid(valor) == typeid(string)) {
			valido = false;
			system("cls");
			cout << "VALOR INVALIDO (elija las opciones disponibles)" << endl;
		}
		else {
			valido = true;
		}
	}
	return valor;
}
void showOptsTri() {
	cout << "MENU DE OPCIONES:" << endl;
	cout << "Convertir a seno:[1]" << endl;
	cout << "Convertir a coseno:[2]" << endl;
	cout << "Convertir a tangente:[3]" << endl;
	cout << "Elige una opcion:" << endl;
}
float resultadoTri(float num) {
	float result{};
	switch (opcionTri()) {
	case 1:
		result = sin(num * 3.14159 / 180);
		break;
	case 2:
		result = cos(num * 3.14159 / 180);
		break;
	case 3:
		result = tan(num * 3.14159 / 180);
		break;
	}
	return result;
}
float valorAbsoluto() {
	float n, m;
	cout << "Ingrese el numero a hallar su V.A: ";
	cin >> n;
	if (n < 0) {
		m = n * -1;
	}
	else if (n > 0) {
		m = n * 1;
	}
	return m;
}
