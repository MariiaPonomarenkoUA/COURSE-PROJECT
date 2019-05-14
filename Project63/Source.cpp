#include <iostream>
#include <string>
#include <fstream>
//#include <Windows.h>

using namespace std;

struct Date
{
	char year[5];
	char month[3];
	char day[3];
};

struct Time
{
	int hour;
	int minute;
};

struct Timesheet
{
	Time AM_in;
	Time PM_out;
	int days_worked;
	int hours_worked;
	int days_sick_leave;
	int days_annual_leave;
	int days_other_leaves;
};
struct Employee
{
	char name[50];
	char surname[50];
	char sex[2];
	char post[30];
	char department[30];
	char number[4];
	Date hiring;
	Date firing;
	Timesheet timesheet;
	void ShowEmployeeInfo()
	{
		cout << "Name: " << name << "\nSurname: " << surname << "\nSex: " << sex << "\nPost: " << post << "\nDepartment: " << department << "\nNumber: " << number << endl;
		cout << "Hiring: " << hiring.year << "/" << hiring.month << "/" << hiring.day << "\nFiring: " << firing.year << "/" << firing.month << "/" << firing.day << endl;
		cout << "=================================================" << endl;
	}
};

int CounterOfRows(string path);
void Fill(Employee *Employee_list, int counter, string path);
void ShowEmployeeList(Employee *Employee_list, int counter, string path);
int MaxNameLenghtCounter(Employee *Employee_list, int counter, string path);
int MaxSurnameLenghtCounter(Employee *Employee_list, int counter, string path);
int MaxPostLenghtCounter(Employee *Employee_list, int counter, string path);
int MaxDeptLenghtCounter(Employee *Employee_list, int counter, string path);

int main()
{
	int counter = 0;
	string path = "Employees.txt";
	int exit = false;
	int choise = 0;

	counter = CounterOfRows(path);
	Employee *Employee_list = new Employee[counter];
	Fill(Employee_list, counter, path);
	cout << "++++++++++++++++++++ WELCOME TO ACCOUNTANT.TIMESHEET.0.1 - DEMO VERSION ++++++++++++++++++++" << endl;
	cout << "\nThe Software Product is protected by copyright laws and international treaty provisions." << endl;
	cout << "____________________________________________________________________________________________" << endl << endl;

	for (int i = 0; exit == false; i++)
	{
		cout << "Show database of employees - 1\nEdit the database of employees - 2\nShow timeshit - 3\nWorking time statistics - 4\nFind employee data 5\nClear the screen - 9\nExit - 0" << endl << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			ShowEmployeeList(Employee_list, counter, path);
			cout << "\nPress any key to continue..." << endl;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 9:
			system("cls");
			break;
		case 0:
			system("cls");
			cout << "Good bye!" << endl << endl;
			exit = true;
			break;
		default:
			cout << "ERROR. Wrong choise, try again" << endl;
			break;
		}
	}












	system("pause");
	return 0;
}

int CounterOfRows(string path) //counter of employees, employer=row
{

	ifstream readFile;
	int counter = 0;
	readFile.open(path);
	string data;
	while (!readFile.eof()) //eof - оч≥куванн€ к≥нц€ файла
	{
		getline(readFile, data); //зчитуванн€ р€дками
		counter++;
	}
	return counter;
}

void Fill(Employee *Employee_list, int counter, string path) // write elements from text file to array of structure
{
	ifstream readFile;
	char data_c;
	readFile.open(path);
	int i = 0;
	int j = 0;

	if (!readFile.is_open())
	{
		cout << "Can't open file" << endl;
	}
	else
	{
		int tmp = 0;
		while (readFile.get(data_c))   //посимвольне зчитуванн€
		{
			if (int(data_c) != 47 && int(data_c) != 10 && tmp == 0) //write name
			{
				/*cout << "Test===" << char(65) << "=========Test";*/
				Employee_list[j].name[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 0) //end of name
			{
				Employee_list[j].name[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 1) //write surname
			{
				Employee_list[j].surname[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 1) //end 
			{
				Employee_list[j].surname[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 2) //fill sex
			{
				Employee_list[j].sex[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 2) //end 
			{
				Employee_list[j].sex[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 3) //fill post
			{
				Employee_list[j].post[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 3) //end 
			{
				Employee_list[j].post[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 4) //fill department
			{
				Employee_list[j].department[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 4) //end 
			{
				Employee_list[j].department[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 5) //fill number
			{
				Employee_list[j].number[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 5) //end 
			{
				Employee_list[j].number[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 6) //fill year of hiring
			{
				Employee_list[j].hiring.year[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 6) //end 
			{
				Employee_list[j].hiring.year[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 7) //fill month of hiring
			{
				Employee_list[j].hiring.month[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 7) //end 
			{
				Employee_list[j].hiring.month[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 8) //fill day of hiring
			{
				Employee_list[j].hiring.day[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 8) //end 
			{
				Employee_list[j].hiring.day[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 9) //fill year of firing
			{
				Employee_list[j].firing.year[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 9) //end 
			{
				if (i == 0)
				{
					Employee_list[j].firing.year[i] = '-';
					Employee_list[j].firing.year[i + 1] = '\0';
				}
				else
				{
					Employee_list[j].firing.year[i] = '\0';
				}
				i = 0;
				tmp++;
			}
			//=================================================================================================================================
			else if (int(data_c) != 47 && tmp == 10) //fill month of firing
			{
				Employee_list[j].firing.month[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 10) //end 
			{
				if (i == 0)
				{
					Employee_list[j].firing.month[i] = '-';
					Employee_list[j].firing.month[i + 1] = '\0';
				}
				else
				{
					Employee_list[j].firing.month[i] = '\0';
				}
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 11) //fill day of firing
			{
				Employee_list[j].firing.day[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 11) //end 
			{
				if (i == 0)
				{
					Employee_list[j].firing.day[i] = '-';
					Employee_list[j].firing.day[i + 1] = '\0';
				}
				else
				{
					Employee_list[j].firing.day[i] = '\0';
				}
				i = 0;
				tmp = 0;
				j++;
			}
		}
	}
	readFile.close();
}

void ShowEmployeeList(Employee *Employee_list, int counter, string path)
{
	int nameL = 0, surnameL = 0, postL = 0, deptL = 0; //helper for a build normal tables
	nameL = MaxNameLenghtCounter(Employee_list, counter, path);
	surnameL = MaxSurnameLenghtCounter(Employee_list, counter, path);
	postL = MaxPostLenghtCounter(Employee_list, counter, path);
	deptL = MaxDeptLenghtCounter(Employee_list, counter, path);

	cout << "Name";
	for (int i = 0; i < (nameL - strlen("Name")); i++)
	{
		cout << " ";
	}
	cout << "\tSurname";
	for (int i = 0; i < (surnameL - strlen("Surname")); i++)
	{
		cout << " ";
	}
	cout << "\t\tSex\tPost";
	for (int i = 0; i < (postL - strlen("Post")); i++)
	{
		cout << " ";
	}
	cout << "\tDepartment";
	for (int i = 0; i < (deptL - strlen("Department")); i++)
	{
		cout << " ";
	}
	cout << "\tNumber\tHiring";
	for (int i = 0; i < 4; i++)
	{
		cout << " ";
	}

	cout << "\tFiring";
	for (int i = 0; i < 4; i++)
	{
		cout << " ";
	}

	cout << "\n" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << Employee_list[i].name;
		for (int j = 0; j < (nameL - strlen(Employee_list[i].name)); j++)
		{
			cout << " ";
		}
		cout << "\t" << Employee_list[i].surname;
		for (int j = 0; j < (surnameL - strlen(Employee_list[i].surname)); j++)
		{
			cout << " ";
		}
		cout << "\t\t" << Employee_list[i].sex << "\t" << Employee_list[i].post;
		for (int j = 0; j < (postL - strlen(Employee_list[i].post)); j++)
		{
			cout << " ";
		}

		cout << "\t" << Employee_list[i].department;
		for (int j = 0; j < (deptL - strlen(Employee_list[i].department)); j++)
		{
			cout << " ";
		}

		cout << "\t" << Employee_list[i].number;
		//for (int j = 0; j < (4 - strlen(Employee_list[i].number)); j++)
		//{
		//	cout << " ";
		//}

		cout << "\t" << Employee_list[i].hiring.year << "/" << Employee_list[i].hiring.month << "/" << Employee_list[i].hiring.day;
		for (int j = 0; j < 4; j++)
		{
			cout << " ";
		}
		cout << "\t" << Employee_list[i].firing.year << "/" << Employee_list[i].firing.month << "/" << Employee_list[i].firing.day << endl;

	}
	cout << endl;

	//cout << name << "\t" << surname << "\t" << sex << "\t" << post << "\t" << department << "\t" << number << "\t" << hiring.year << "/" << hiring.month << "/" << hiring.day << "\t" << firing.year << "/" << firing.month << "/" << firing.day << endl;
	//cout << "Name: " << Employee_list[0].name;
	//cout << "Surname: " << Employee_list[0].surname << endl;
	//cout << "Sex: " << Employee_list[0].sex << endl;
	//cout << "Post: " << Employee_list[0].post << endl;
	//cout << "Department: " << Employee_list[0].department << endl;
	//cout << "Number: " << Employee_list[0].number << endl;
	//cout << "Hiring: " << Employee_list[0].hiring.year << "/" << Employee_list[0].hiring.month << "/" << Employee_list[0].hiring.day << endl;
	//cout << "Firing: " << Employee_list[0].firing.year << "/" << Employee_list[0].firing.month << "/" << Employee_list[0].firing.day << endl;

	/*Employee_list[i].ShowEmployeeInfo();*/
}

int MaxNameLenghtCounter(Employee *Employee_list, int counter, string path)
{
	int max = strlen("Name");
	for (int i = 0; i < counter; i++)
	{
		if (strlen(Employee_list[i].name) >= max)
		{
			max = strlen(Employee_list[i].name);
		}
	}
	return max;
}

int MaxSurnameLenghtCounter(Employee *Employee_list, int counter, string path)
{
	int max = strlen("Surname");
	for (int i = 0; i < counter; i++)
	{
		if (strlen(Employee_list[i].surname) >= max)
		{
			max = strlen(Employee_list[i].surname);
		}
	}
	return max;
}

int MaxPostLenghtCounter(Employee *Employee_list, int counter, string path)
{
	int max = strlen("Post");
	for (int i = 0; i < counter; i++)
	{
		if (strlen(Employee_list[i].post) >= max)
		{
			max = strlen(Employee_list[i].post);
		}
	}
	return max;
}

int MaxDeptLenghtCounter(Employee *Employee_list, int counter, string path)
{
	int max = strlen("Department");
	for (int i = 0; i < counter; i++)
	{
		if (strlen(Employee_list[i].department) >= max)
		{
			max = strlen(Employee_list[i].department);
		}
	}
	return max;
}


/*ofstream writeFile;*/
	/*ofstream overWriteFile;
	/*ifstream readFile;*/
	/*overWriteFile.open(path, ofstream::app);
	writeFile.open(path);
	overWriteFile.close();
	writeFile.close();*/
