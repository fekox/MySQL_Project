#include <mysql.h>
#include <iostream>

using namespace std;

int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "Mr1052", "MySQL_Project", 3306, NULL, 0);

	if (conectar)
	{
		cout << "Conexion completada." << endl;
	}

	else
	{
		cout << "No se pudo conectar.\n" << endl;
		cout << "Posibles errores:\n" << endl;
		cout << "-Comprueba si la base de datos fue creada en MySQL.\n" << endl;
		cout << "-Comprueba si algunos de los nombres esta mal escrito." << endl;
	}

	cout << "\n";
	system("Pause");
}