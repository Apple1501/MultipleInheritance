// popt3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<string>

#include"global.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char comand = -1;
	cout << "0. Выйти" << endl;
	cout << "1. Загрузить списки студентов и преподавателей из файла" << endl;
	cout << "2. Загрузить список в файл" << endl;
	cout << "3. Вывести список студентов на экран" << endl;
	cout << "4. Загрузить список предметов из файла" << endl;
	cout << "5. Загрузить список предметов в файл" << endl;
	cout << "6. Вывести список предметов на экран" << endl;
	cout << "7. Добавить экзамен и нового студента, преподавателя" << endl;
	cout << "8. Открыть файл StudentOut" << endl;
	cout << "9. Удалить элемент" << endl;

	
	cin >> comand;

	while (comand != '0' && comand != '1' && comand != '2' && comand != '3' && comand != '4' && comand != '5'&& comand != '6'&& comand != '7'&&comand!='8'&&comand!='9'&&comand!='c')
	{
		cout << "Введите команду" << endl;
		cin >> comand;
	}
	List<People> *L = new List<People>();
	List<Information> *P = new List<Information>();
	List<Prep> *F = new List<Prep>;
	List<Prep> *I = new List<Prep>;
	List<Subjects> *K = new List<Subjects>();
	List<Subjects> *R = new List<Subjects>();

	R->LoadSubjectsFromFile("SubjectsIn.txt");
	while (comand != '0')
	{
		if (comand == '1')
		{
			List<Subjects> *R = new List<Subjects>();

			R->LoadSubjectsFromFile("SubjectsIn.txt");
          	P->LoadFromFile("StudentsIn.txt", *&R);
			F->LoadFromFile("PrepIn.txt"); //для общего списка 
			
			I->LoadFromFile("PrepIn.txt");

			
			cout << "Cписок студентов загружен из файла" << endl;
		}
		if (comand == '2')
		{
			char fl = -1;
			cout << "Кого вы хотите вывести в файл?" << endl;
			cout << "1. Студентов" << endl;
			cout << "2. Преподавателей" << endl;
			cout << "3. Всех" << endl;
			cin >> fl;

			if (fl == '1')
			{
				P->LoadInFile("StudentsOut.txt");
				cout << "Cписок студентов загружен в файл" << endl;
			}

			if (fl == '2')
			{
				F->LoadInFile("StudentsOut.txt");
				cout << "Cписок преподавателей загружен в файл" << endl;
			
			}
			if (fl == '3')
			{
				L->LoadInFile("StudentsOut.txt");
				cout << "Cписок людей загружен в файл" << endl;

			}

			
		}
		if (comand == '3')
		{
			cout << "Кого вы хотите вывести на экран?" << endl;
			cout << "1. Студентов" << endl;

			cout << "2. Преподавателей" << endl;
			cout << "3. Всех" << endl;
			char nom=-1;
			cin >> nom;
			if (nom == '1') 
			{
				P->LoadOnScreen();
			}
			if (nom == '2') {
				I->LoadOnScreen();
			}
			if (nom == '3') 
			{
				if ((L->Null() == 0))
				{
					if (P->Null() != 0)
					{
						if (P->Null() != 0)
						{
							L = (List<People>*)F;
							L->Connect(P);
						}
						else L = (List<People>*)F;
					}
					else L = (List<People>*)P;
					
				}
				
				L->LoadOnScreen();  
				
			}
			
		}
		if (comand == '4')
		{
			K->LoadSubjectsFromFile("SubjectsIn.txt");
		}
		if (comand == '5')
		{
			K->LoadSubjectsInFile("SubjectsOut.txt");
		}
		if (comand == '6')
		{
			K->LoadOnScreen();
		}
		if (comand == '7')
		{
			

			char vab=-1;
			cout << "1. Добавить нового студента" << endl;
			cout << "2. Изменить оценку" << endl;
			cout << "3. Добавить нового преподавателя" << endl;
			cin >> vab;

			if (vab == '1')
			{
				
				cout << "Введите фамилию студента" << endl;
				string ch,m,gr;
				int b;
				cin >> ch;
				cout << "Введите имя студента" << endl;
				cin >> m;
				cout << "Введите возраст студента" << endl;
				cin >> b;
				cout << "Введите группу студента" << endl;
				cin >> gr;
				
				P->Dobstudent(ch,m,b,gr,*&R);
			}

			if (vab == '2')
			{
				
				cout << "Введите фамилию студента" << endl;
				string ch;
				cin >> ch;
				cout << "Введите номер предмета" << endl;
				int number = 0;
				cin >> number;
				cout << "Введите оценку" << endl;
				int mark = 0;
				cin >> mark;

				P->AddExamens(ch, number, mark, R);


			}
			if (vab == '3') 
			{
				cout << "Введите фамилию " << endl;
				string ch, m, gr,polisit;
				int b,k;
				cin >> ch;
				cout << "Введите имя" << endl;
				cin >> m;
				cout << "Введите возраст" << endl;
				cin >> b;
				cout << "Введите должность" << endl;
				cin >> gr;
				cout << "Введите кафедру" << endl;
				cin >> polisit;
				cout << "Введите зарплату" << endl;
				cin >> k;


				I->DobPrep(ch, m, b, gr, polisit,k, *&R);
			}
			
		}

		if (comand == '8')
		{
			system("notepad D:\\0\\Доки\\Прога\\2 сем\\Тема № 8 Множественное наследование\\popt3 — копия\\popt3\\StudentsOut.txt");

		}
		if (comand=='9')
		{
			char e;
			cout << "Кого вы хотите удалить?" << endl;
			cout << "1. Студента" << endl;
			cout << "2. Преподавателя" << endl;
			cin >> e;

			if (e == '1')
			{
				P->Delete();
			}

			if (e == '2') 
			{
				I->Delete();
			}
	
		}
		
		
		cout << "1. Загрузить список студентов из файла" << endl;
		cout << "2. Загрузить список людей в файл" << endl;
		cout << "3. Вывести список студентов на экран" << endl;
		cout << "4. Загрузить список предметов из файла" << endl;
		cout << "5. Загрузить список предметов в файл" << endl;
		cout << "6. Вывести список предметов на экран" << endl;
		cout << "7. Добавить экзамен или нового студента, преподавателя" << endl;
		cout << "8. Открыть файл StudentOut" << endl;
		cout << "9. Удалить элемент" << endl;
		cout << "0. Выйти" << endl;
		cin >> comand;

	}
	system("pause");

	return 0;
}

