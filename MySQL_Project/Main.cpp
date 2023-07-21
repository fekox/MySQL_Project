#include <mysql.h>
#include <iostream>

using namespace std;

void menu();

int main()
{
	//MYSQL* conectar;
	//conectar = mysql_init(0);
	//conectar = mysql_real_connect(conectar, "localhost", "root", "Mr1052", "MySQL_Project", 3306, NULL, 0);

	//if (conectar)
	//{
	//	cout << "Conexion completada." << endl;
	//}

	//else
	//{
	//	cout << "No se pudo conectar.\n" << endl;
	//	cout << "Posibles errores:\n" << endl;
	//	cout << "-Comprueba si la base de datos fue creada en MySQL.\n" << endl;
	//	cout << "-Comprueba si algunos de los nombres esta mal escrito." << endl;
	//}

	//cout << "\n";
	//system("Pause");
}

void menu()
{
	int menuChoice = 0;

	do
	{
		system("Cls");

		cout << "Trabajo Practico Integrador" << endl;
		cout << "\tBase de Datos\n\n";

		cout << "1- Insertar datos\n";
		cout << "2- Eliminar datos\n";
		cout << "3- Actualizar datos\n";
		cout << "4- Consultar datos\n\n";

		cout << "Ingresa una opsion (1-2-3-4):" << endl;
		cin >> menuChoice;

	} while (menuChoice > 4 || menuChoice < 1);
}