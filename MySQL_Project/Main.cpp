#include <mysql.h>
#include <iostream>

using namespace std;

MYSQL* testConection;
int query_state;

enum Menu
{
	InsertData = 1,
	DeleteData,
	UpdateData,
	LookData,
	Quit
};

void menu();
void testServerConection();
void insertData();
void deleteData();
void updateData();

int main()
{
	menu();
}

void menu()
{
	int menuChoice = 0;

	do
	{
		system("Cls");

		cout << "\tFinal Exam" << endl;
		cout << "\tBase de Datos\n\n";

		cout << "1- Insert data\n";
		cout << "2- Delete data\n";
		cout << "3- Update data\n";
		cout << "4- Consult data\n";
		cout << "5- Quit\n\n";

		cout << "Tipe one option (1-2-3-4-5):";
		cin >> menuChoice;

		system("Cls");

	} while (menuChoice > 5 || menuChoice < 1);

	switch (menuChoice)
	{
		case InsertData:
			testServerConection();
			insertData();

			break;

		case DeleteData:
			testServerConection();
			deleteData();
			break;

		case UpdateData:
			testServerConection();
			updateData();
			break;

		case LookData:
			testServerConection();
			break;

		case Quit:
			break;
	}
}

void testServerConection()
{
	testConection = mysql_init(0);
	testConection = mysql_real_connect(testConection, "localhost", "root", "Mr1052", "MySQL_Project", 3306, NULL, 0);

	if (testConection)
	{
		cout << "Successful connection." << endl;

		cout << "\n";
		system("Pause");
		system("Cls");
	}

	else
	{
		cout << "Failed connection.\n" << endl;
		cout << "Possible mistakes:\n" << endl;
		cout << "-Check if the database was created in MySQL workbench.\n" << endl;
		cout << "-Check if some of the names on the code are misspelled." << endl;

		cout << "\n";
		system("Pause");
		system("Cls");

		menu();
	}
}

void insertData()
{
	if (testConection)
	{
		string tableName;
		string fieldName;
		string newNamePosition;

		cout << "Type the name of the table: ";
		cin >> tableName;
		system("Cls");

		cout << "Type the name of the table field: ";
		cin >> fieldName;
		system("Cls");

		cout << "Type the name of the new position: ";
		cin >> newNamePosition;
		system("Cls");

		string insert = "insert into " + tableName + "(" + fieldName + ")" + "values('" + newNamePosition + "')";

		const char* copyInsert = insert.c_str();
		query_state = mysql_query(testConection, copyInsert);

		if (!query_state)
		{
			cout << "Insert completed.\n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}

		else
		{
			cout << "Insert failed.\n" << endl;
			cout << "Possible mistakes:\n" << endl;
			cout << "-Check if the table name was written correctly. \n" << endl;
			cout << "-Check if the field name was written correctly.\n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}
	}
}

void deleteData()
{
	if (testConection)
	{
		string tableName;
		string fieldName;

		cout << "Type the name of the table: ";
		cin >> tableName;
		system("Cls");

		cout << "Type the name of the table field: ";
		cin >> fieldName;
		system("Cls");

		string deletePos = "alter table " + tableName + " drop column " + fieldName;

		const char* copyDelete = deletePos.c_str();
		query_state = mysql_query(testConection, copyDelete);

		if (!query_state)
		{
			cout << "Delete completed.\n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}

		else
		{
			cout << "Delete failed.\n" << endl;
			cout << "Possible mistakes:\n" << endl;
			cout << "-Check if the table name was written correctly. \n" << endl;
			cout << "-Check if the field name was written correctly.\n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}
	}
}

void updateData()
{
	if (testConection)
	{
		string tableName;
		string fieldName;
		string fieldToUpdate;

		string valueToUpdate;
		string valueUpdate;

		cout << "Type the name of the table: ";
		cin >> tableName;
		system("Cls");

		cout << "Type the name of the table field: ";
		cin >> fieldName;
		system("Cls");

		cout << "Type the value you want to add: ";
		cin >> valueUpdate;
		system("Cls");

		cout << "Type the name of the field you want to update: ";
		cin >> fieldToUpdate;
		system("Cls");

		cout << "Type the value you want to modify: ";
		cin >> valueToUpdate;
		system("Cls");

		string updatePos = "update " + tableName + " set " + fieldName + " = " + valueUpdate +" where " + fieldToUpdate + " = " + valueToUpdate;

		const char* copyUpdate = updatePos.c_str();
		query_state = mysql_query(testConection, copyUpdate);

		if (!query_state)
		{
			cout << "Update completed.\n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}

		else
		{
			cout << "Update failed.\n" << endl;
			cout << "Possible mistakes:\n" << endl;
			cout << "-Check if the table name was written correctly. \n" << endl;
			cout << "-Check if the first field name was written correctly.\n" << endl;
			cout << "-Check if the second field name was written correctly.\n" << endl;
			cout << "-Check if the second value was written correctly.\n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}
	}
}