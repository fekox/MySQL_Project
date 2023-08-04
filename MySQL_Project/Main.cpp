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
void testDataBaseConection();
void insertData();
void deleteData();
void updateData();
void readData();

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
		cout << "4- Read data\n";
		cout << "5- Quit\n\n";

		cout << "Type one option (1-2-3-4-5):";
		cin >> menuChoice;

		system("Cls");

	} while (menuChoice > 5 || menuChoice < 1);

	switch (menuChoice)
	{
		case InsertData:
			testDataBaseConection();
			insertData();

			break;

		case DeleteData:
			testDataBaseConection();
			deleteData();
			break;

		case UpdateData:
			testDataBaseConection();
			updateData();
			break;

		case LookData:
			testDataBaseConection();
			readData();
			break;

		case Quit:
			break;
	}
}

void testDataBaseConection()
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
		string deleteData;

		cout << "Type the name of the table: ";
		cin >> tableName;
		system("Cls");

		cout << "Type the name of the table field: ";
		cin >> fieldName;
		system("Cls");

		cout << "Type the name of the data you want to delete: ";
		cin >> deleteData;
		system("Cls");

		string deletePos = "delete from " + tableName + " where " + fieldName + " like " + "'" + deleteData + "'";

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

		string updatePos = "update " + tableName + " set " + fieldName + " = '" + valueUpdate +"' where " + fieldToUpdate + " = '" + valueToUpdate + "'";

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

void readData()
{
	MYSQL_ROW row;
	MYSQL_RES* result;

	if (testConection)
	{
		string tableName;
		int maxRows;

		cout << "Type the name of the table: ";
		cin >> tableName;
		system("Cls");

		do
		{
			cout << "Type the maximum number of rows that the table has: ";
			cin >> maxRows;
			system("Cls");

			if (maxRows > 5 || maxRows < 1)
			{
				cout << "The number entered is not valid.\n" << endl;
				system("Pause");
				system("Cls");
			}

		} while (maxRows > 5 || maxRows < 1);

		string select = "select * from " + tableName;

		const char* copySelect = select.c_str();
		query_state = mysql_query(testConection, copySelect);

		if (!query_state)
		{
			result = mysql_store_result(testConection);

			while (row = mysql_fetch_row(result))
			{
				switch (maxRows)
				{
					case 1:
						cout << row[0] << endl;
					break;

					case 2:
						cout << row[0] << "\t" << row[1] << endl;
					break;

					case 3:
						cout << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
					break;

					case 4:
						cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;
					break;

					case 5:
						cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\t" << row[4] << endl;
					break;

				}
			}

			cout << "\n";
			system("Pause");
			system("Cls");

			menu();
		}

		else
		{
			cout << "Look data failed.\n" << endl;
			cout << "Possible mistakes:\n" << endl;
			cout << "-Check if the table name was written correctly. \n" << endl;

			system("Pause");
			system("Cls");

			menu();
		}
	}
}