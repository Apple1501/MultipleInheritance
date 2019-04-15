#pragma once
#ifndef Students
#define Students

#include <iostream>
#include <fstream>
#include <cstring>

#define NAMESIZE_MAX 225
#define NAMESIZE 20

using namespace std;

class Information;
class GradesForTheExam;
class Subjects;

template <class T>
// Шаблон списка
class List
{
//	friend class List<Prep>;
	friend class People;
	friend class Working;
	friend class List<Information>;
	friend class List<GradesForTheExam>;
	friend class Information;
	friend class GradesForTheExam;
	friend class List<People>;
	friend class List<Working>;
	friend class Prep;
	List<T> *next;
	T data;
	// Конструктор
	List(T & v) { data = v; next = NULL; }
public:
	List<T> *get_next() { return next; }
	T get_data() { return data; }
	// Добавлениe элемента 
	void AddExamens(string ch, int number, int mark,List<Subjects> *);
	void AddExam(string ch, int number, int mark, List<Subjects> *&);
	void LoadInFile(const char *StudentsOut);
	void WriteExamens(std::ofstream &f);
	void LoadOnScreen();
	void WriteExamensOnScreen();
	int LoadFromFile(const char *StudentsIn, List<Subjects> *&);
	int LoadFromFile(const char *PrepIn);
	int Dobstudent(string ch, string m, int b, string gr, List<Subjects> *&R); 
	int DobPrep(string ch, string m, int b, string gr, string polisit, int salary, List<Subjects> *&R);
	int ReadExamens(int Exames, std::ifstream &f, List<Subjects> *&);
	int LoadSubjectsFromFile(const char *SubjectsIn);
	void LoadSubjectsInFile(const char *SubjectsOut);
	void Delete();
	float Avg();
	void Connect(List<Information> *P);
	//void LoadFromList(List<T> *&H);
	int Null() { if (next == NULL) return 0; else return 1; };
	//void DelElement(string ch);
	//void deleteElement(List<T> *&pointer);
	
	//Конструктор
	List()
	{
		next = NULL;
	};
	//Деструктор
	~List()
	{
		//if (next != NULL) delete next;
	};
	//Функция добавления элемнта в список
	void AddElements(T &c)
	{
		List *p, *q;
		p = new List(c);
		q = this;
		p->next = q->next;
		q->next = p;
	};

};
class Working // класс работники 
{
	string posit;//кафедра, к которой пренадлежит работник 
	int salary; //Заработная плата 


public:
	int ReadWorking(Working *a, std::ifstream &f/*, List<Subjects> *&R*/);
	void  WriteWorking(std::ofstream &f);
	string get_posit() { return posit; }
	void set_posit(string name) { posit = name; }
	void set_salary(int Agv) { salary = Agv; }
	int get_salary() { return salary; }

	virtual void  WriteOnScreenWorking()
	{
		this->WriteOnScreenWorking();

		if (this->posit != "NONAME"&& this->posit != "" /*|| (this->get_posit().length()) != 0*/)
		{
			cout << "Кафедра  - " << this->posit << "\n";
			cout << "Зарплата - " << this->salary << "\n";
		}

	}



	Working()
	{
		string posit = "NONAME";
		int salary = 0;

	}
	~Working()
	{

	};


};

class People
{
	//friend class Working;
	string Fam;
	string Name;
	int Age;
	
	


public:
	int ReadPeople(People *a, std::ifstream &f/*, List<Subjects> *&R*/);
	void  WritePeople(std::ofstream &f);
	//friend void Working::WriteOnScreenWorking();
	string get_Fam() { return Fam; }
	void set_Fam(string name) { Fam = name; }
	string get_Name() { return Name; }
	void set_Name(string nam) { Name = nam; }
	void set_Age(int Agv) { Age = Agv; }
	int get_Age() { return Age; }
	
	virtual void  WriteOnScreenPeople()
	{
		this->WriteOnScreenPeople();

		if (this->Fam != "NONAME"&& this->Fam != "" || (this->get_Name().length()) != 0)
		{
			cout << "Фамилия - " << this->Fam << "\n";
			cout << "Имя - " << this->Name << "\n";
			cout << "Возраст - " << this->Age << "\n";
		}

	}
	


	People()
	{
		string Fam = "NONAME";
		string Name = "NONAME";
		int Age = 0;

	}
	~People()
	{

	};


};


//Информация о студенте: оценки и средний балл
class Information :public People
{
	//string StudentName;
	int  CountOfExam;
	float Avg;
	List<GradesForTheExam> *pass;
	string Group;

public:

	string get_Group() { return Group; }
	void set_Group(string name) { Group = name; }
	List<GradesForTheExam> *get_pass() { return pass; };
	void set_pass(List<GradesForTheExam> *pass) { this->pass = pass; }
	void set_avg(float avg) { Avg = avg; }
	float get_avg() { return Avg; }


	void WriteStudent(std::ofstream &f);
	void WriteOnScreenStudent();


	void DeleteExams();
	void  WriteOnScreenPeople(); /*override
	{
		if ((this->get_Age() != 0) && (&(this->get_Fam()) != 0))
		{
			cout << "Фамилия - " << this->get_Fam() << "\n";
			cout << "Имя - " << this->get_Name() << "\n";
			cout << "Возраст - " << this->get_Age() << "\n";
			cout << "Группа - " << this->Group << "\n";
			cout << "Средний балл - " << this->Avg << "\n";
			if (this->pass != NULL)
			{
				//this->pass->WriteExamensOnScreen();
				cout << "\n";
			}
		}
	}*/

	//void EditData(List<Subjects>*&L);
	int  ReadStudent(Information *a, std::ifstream &f, List<Subjects> *&);
	//Конструктор
	Information()
	{
		CountOfExam = 0;
		Avg = 0;
		pass = NULL;
		
	};
	Information(string ch,string m,int b, string gr)
	{
		set_Fam(ch);
		set_Name(m);
		set_Age(b);
		Group = gr;
		CountOfExam = 0;
		Avg = 0;
		pass = NULL;
		
	};
	//Деструктор
	~Information()
	{
		DeleteExams();
	};
};
class Prep :public People, public Working
{
	string Dolznoct;
public:
	string get_Dol() { return Dolznoct; }
	void set_Dol(string name) { Dolznoct = name; }
	int ReadPrep(Prep *a, std::ifstream &f);
	void WritePrep(std::ofstream &f);
	void WriteOnScreenPrep();
	void WriteOnScreenPeople() override
	
	{
		if ((this->get_Age() != 0) || (&(this->get_Fam()) != 0))
		{
			cout << "Фамилия - " << this->get_Fam() << "\n";
			cout << "Имя - " << this->get_Name() << "\n";
			cout << "Возраст - " << this->get_Age() << "\n";
			if (this->Dolznoct != "NONAME")
			{
				cout << "Должность - " << this->Dolznoct;
				cout << endl;
				WriteOnScreenWorking();

			}
		}
	}
	void  WriteOnScreenWorking() override
	{
		if ((this->get_salary() != 0) || (&(this->get_posit()) != 0))
		{
			cout << "Кафедра  - " << this->get_posit() << "\n";
			cout << "Зарплата - " << this->get_salary() << "\n";
			cout << endl;
						
		}
	}

	Prep()
	{
		Dolznoct = "NONAME";
	}
	Prep(string ch, string m, int b, string gr, string polisit, int salary)
	{
		set_Fam(ch);
		set_Name(m);
		set_Age(b);
		Dolznoct = gr;
		set_posit(polisit);
		set_salary(salary);

	}
	~Prep()
	{

	};

};

//Оценки за экзамены
class GradesForTheExam
{

	int subject;
	List<Subjects> *Sub;
	int mark;
public:
	int get_subject() { return subject; }
	void set_subject(int subject) { this->subject = subject; }
	int get_mark() { return mark; }
	void set_mark(int mark) { this->mark = mark; }
	List<Subjects> *get_sub() { return Sub; }
	void set_sub(List<Subjects> *Sub) { this->Sub = Sub; }
	



	int  ReadExam(std::ifstream &f, List<Subjects> *&);
	void WriteExam(std::ofstream &f);
	void WriteExamOnScreen();
	GradesForTheExam()
	{
		subject = 0;
		mark = 0;
	};
	~GradesForTheExam()
	{
	};
	
};




//Информация о предмете: номер и название
class Subjects
{
	friend class List<Information>;
	friend class List<GradesForTheExam>;
	friend class Information;
	friend class GradesForTheExam;
	friend int List<Information>::LoadFromFile(const char *StudentsIn, List<Subjects> *&R);
	friend int Information::ReadStudent(Information *a, std::ifstream &f, List<Subjects> *&R);
	friend int List<GradesForTheExam>::ReadExamens(int Exames, std::ifstream &f, List<Subjects> *&R);
	friend int  GradesForTheExam::ReadExam(std::ifstream &f, List<Subjects> *&R);
public:
	int NumberOfSubject;
	char NameOfSubject[20];
	//Конструктор
	Subjects()
	{
		NumberOfSubject = 0;
		strcpy_s(NameOfSubject, "NONAME");
	};
	//Деструктор
	~Subjects()
	{
	};
	int ReadSubject(std::ifstream &f);
	void  WriteSubjects(std::ofstream &f);
	void WriteSubjectsOnScreen();
};

//Функция загрузки списка из файла
template<>
int List<Information>::LoadFromFile(const char *StudentsIn, List<Subjects> *&R)
{
	std::ifstream f_in(StudentsIn);
	int n = 0;//обнуляем счетчик студентов
	while (f_in)//пока файл существует
	{
		Information a;
		int flag = this->data.ReadPeople(&a,f_in);
     	 flag = this->data.ReadStudent(&a, f_in, *&R); //вызов функции для ввода очередного студента из файла
		if (!flag) // проверить флаг на успешный ввод при flag == 0
		{
			this->AddElements(a); n++;
		}
		else break;
	}
	f_in.close();
	return n;
}



void  Information::WriteOnScreenPeople()
{
	if (this->get_Age() != 0)
	{
		cout << "Фамилия - " << this->get_Fam() << "\n";
		cout << "Имя - " << this->get_Name() << "\n";
		cout << "Возраст - " << this->get_Age() << "\n";
		cout << "Группа - " << this->Group << "\n";
		cout << "Средний балл - " << this->Avg << "\n";
		if (this->pass != NULL)
		{
			this->pass->WriteExamensOnScreen();
			
		}
	}
}

template<class T>

void List<T>::Connect(List<Information> *P)
{
	List<People> *q;
	for (q = this->next; q->next != NULL; q = q->next)
	{
	}
	q->next = (List<People>*)P;
}
// функция для ввода очередного студента из файла

int Information::ReadStudent(Information *a, std::ifstream &f, List<Subjects> *&R)
{
	int flag = 1; //нет считывания из файла
	try
	{
		f >> (a->Group);
		if (a->get_Group().length() == 0) return 1;
		f >> (a->CountOfExam);
		float n = a->CountOfExam;
		List<GradesForTheExam> *b = new List<GradesForTheExam>();
		a->Avg = b->ReadExamens(a->CountOfExam, f, *&R) / n;
		a->pass = b;
		return 0;
	}
	catch (...)
	{
		return 1;
	}

}

int List<Prep>::LoadFromFile( const char *PrepIn)
{
	std::ifstream f_in(PrepIn);
	int n = 0;//обнуляем счетчик студентов
	while (f_in)//пока файл существует
	{
		Prep a;
		int flag = this->data.ReadPeople(&a, f_in);
		 flag = this->data.ReadWorking(&a, f_in);//вызов функции для ввода очередного студента из файла
		 flag = this->data.ReadPrep(&a, f_in);
		
		if (!flag) // проверить флаг на успешный ввод при flag == 0
		{
			this->AddElements(a); n++;
		}
		else break;
	}
	f_in.close();
	return n;
}
int People::ReadPeople(People *a, std::ifstream &f/*, List<Subjects> *&R*/)
{
	int flag = 1; //нет считывания из файла
	try
	{
		f >> a->Fam;
		if (a->get_Fam().length() == 0) return 1; // if (strlen(a->StudentName) == 0) return 1; //проверяем пустую строку
		f >> a->Name;
		if (a->get_Name().length() == 0) return 1;
		int n;
		f >> n;
		a->set_Age(n);

	}
	catch (...)
	{
		return 1;
	}

}
int Working::ReadWorking(Working *a, std::ifstream &f/*, List<Subjects> *&R*/)
{
	int flag = 1; //нет считывания из файла
	try
	{
		f >> a->posit;
		if (a->get_posit().length() == 0) return 1; // if (strlen(a->StudentName) == 0) return 1; //проверяем пустую строку

		int n;
		f >> n;
		a->set_salary(n);

	}
	catch (...)
	{
		return 1;
	}

}

int Prep::ReadPrep(Prep *a, std::ifstream &f)
{
	int flag = 1; //нет считывания из файла
	try
	{
		f >> (a->Dolznoct);
		if (a->get_Dol().length() == 0) return 1;
		
		return 0;
	}
	catch (...)
	{
		return 1;
	}

}

template<>
//Функция считывания n экзаменов и добавление их список оценок
int List<GradesForTheExam>::ReadExamens(int Exames, std::ifstream &f, List<Subjects> *&R)
{
	int n = 0;
	

	for (int i = 0; i < Exames; i++)
	{
		GradesForTheExam a;
		int flag = a.ReadExam(f, *&R); //вызов функции для ввода в переменную (а) очередного экзамена из файла (f)
		if (flag) 
		{
			AddElements(a);
			n += flag;
		}
		else break;
	}

	return n;
}

//Функция считывания одного экзамена
int  GradesForTheExam::ReadExam(std::ifstream &f, List<Subjects> *&R)
{
	f >> (this->subject);//прочитать из файла f номер предмета
	f >> (this->mark);//прочитать из файла f оценку
	int n = this->mark;
	List<Subjects> *q = R;
	for (q = R->next; q != NULL; q = q->next)
	{
		
		//Сравниваем номер предмета из списка предметов с номером предмета из списка экзаменов для данного студента
		if (this->subject == (q->data).NumberOfSubject)
		{
			this->Sub = q;
			
		}
	}
	
	
	return n;
}

//Функция загрузки списка в файл
template<>
void List<Information>::LoadInFile(const char *StudentsOut)
{
	std::ofstream f_out;
	f_out.open(StudentsOut, std::ios::app);
	f_out << "	Список \n\nНачало:\n\n";
	List<Information> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WritePeople(f_out);
		q->data.WriteStudent(f_out);
	}
	f_out << "\nКонец\n\n";
}

/*void List<People>::LoadInFile(const char *StudentsOut)
{
	std::ofstream f_out;
	f_out.open(StudentsOut, std::ios::app);
	f_out << "	Список \n\nНачало:\n\n";
	List<People> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WritePeople(f_out);
	}
	f_out << "\nКонец\n\n";
}*/


void   People::WritePeople(std::ofstream &f)
{
	if (this->Fam != "NONAME"&&this->Fam!="")
		//сначала вызываю родительскую функцию 
	{
		f << "Фамилия - " << this->Fam << "\n";
		f << "Имя - " << this->Name << "\n";
		f << "Возраст- " << this->Age << "\n";
		/*if (this->pass != NULL)
		{
			this->pass->WriteExamens(f);
			f << "\n";
		}*/
	}
}
void   Working::WriteWorking(std::ofstream &f)
{
	if (this->posit!= "NONAME"&&this->posit != "")
		//сначала вызываю родительскую функцию 
	{
		f << "Кафедра - " << this->posit << "\n";
		f << "Зарплата- " << this->salary << "\n";
		
	}
}
template<>
void List<Prep>::LoadInFile(const char *StudentsOut)
{
	std::ofstream f_out;
	f_out.open(StudentsOut, std::ios::app);
	f_out << "	Список \n\nНачало:\n\n";
	List<Prep> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WritePeople(f_out);
		q->data.WritePrep(f_out);
		q->data.WriteWorking(f_out);


	}
	f_out << "\nКонец\n\n";
}

void List<People>::LoadInFile(const char *StudentsOut)
{
	std::ofstream f_out;
	f_out.open(StudentsOut, std::ios::app);
	f_out << "	Список \n\nНачало:\n\n";
	List<People> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WritePeople(f_out);
	//	q->data.WritePrep(f_out);
	}
	f_out << "\nКонец\n\n";
}
//Функция записи в файл информации о студенте
void   Information::WriteStudent(std::ofstream &f)
{
	
		f << "Группа- " << this->Group << "\n";
		f << "Средний балл - " << this->Avg << "\n";
		if (this->pass != NULL)
		{
			this->pass->WriteExamens(f);
			f << "\n";
		}
	
}
void   Prep::WritePrep(std::ofstream &f)
{
	if (this->Dolznoct != "NONAME")
	{
		f << "Должность- " << this->Dolznoct << "\n";
	}
	

}

//Функция записи в файл спсика экзаменов для одного студента
template<>
void List<GradesForTheExam>::WriteExamens(std::ofstream &f)
{
	List<GradesForTheExam> *q;
	
		for (q = this->next; q != NULL; q = q->next)
		{
			q->data.WriteExam(f);
		}
	
}
//Функция записи информации об экзамене
void GradesForTheExam::WriteExam(std::ofstream &f)
{
	Subjects su;
	su = (this->Sub)->data;
	
			f << this->subject << " {" << su.NameOfSubject << "}(" << this->mark << ");";
		
}

//Функция загрузки списка предметов из файла

template<>
int List<Subjects>::LoadSubjectsFromFile(const char *SubjectsIn)
{
	std::ifstream fin(SubjectsIn);
	int number = 0;
	while (fin)
	{
		Subjects subject;
		int flag = subject.ReadSubject(fin);
		if (!flag)
		{
			AddElements(subject);
			number++;
		}
		else break;
	}
	return number;
}
//Функция загрузки информации об одном предмете 
int  Subjects::ReadSubject(std::ifstream &f)
{
	try
	{
		f >> (NumberOfSubject);
		f >> (NameOfSubject);
		if (strlen(NameOfSubject) == 0) return 1;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}
//Функция загрузки списка предметов в файл
template<>
void List<Subjects>::LoadSubjectsInFile(const char *SubjectsOut)
{
	std::ofstream f_out;
	f_out.open(SubjectsOut, std::ios::app);
	f_out << "	Список предметов\n\nНачало:\n\n";
	List<Subjects> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteSubjects(f_out);
	}
	f_out << "\nКонец\n\n";
}
//Функция загрузки информации об одном предмете 
void   Subjects::WriteSubjects(std::ofstream &f)
{
	f << "Номер - " << this->NumberOfSubject << "\n";
	f << "Название - " << this->NameOfSubject << "\n";
	f << "\n";
}
//Функции вывода списков на экран
template<>
void List<Information>::LoadOnScreen()
{
	cout << "	Список студентов\n\nНачало:\n\n";
	List<Information> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		//if (q->data.get_student_name == "NONAME")
		{
			q->data.WriteOnScreenPeople();
			//q->data.WriteOnScreenStudent();
		}
	}
	cout << "\nКонец\n\n";
}

/*void  People::WriteOnScreenPeople()
{
	if (this->Fam != "NONAME"&& this->Fam!="")
	{
		cout << "Фамилия - " << this->Fam << "\n";
		cout << "Имя - " << this->Name << "\n";
		cout << "Возраст - " << this->Age << "\n";
		
	}

}*/

void  Information::WriteOnScreenStudent()
{
	
		cout << "Группа - " << this->Group << "\n";
		cout << "Средний балл - " << this->Avg << "\n";
		if (this->pass != NULL)
		{
			this->pass->WriteExamensOnScreen();
			cout << "\n";
		}
	
}

void List<Prep>::LoadOnScreen() // преподаватели
{
	cout << "	Список студентов\n\nНачало:\n\n";
	List<Prep> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		if (q->data.get_Fam() != "" && q->data.get_Name()!="")
		{
			q->data.WriteOnScreenPeople();
			
			
		}
	}
	cout << "\nКонец\n\n";
}

void List<People>::LoadOnScreen()
{

	cout << "	Список \n\nНачало:\n\n";
	List<People> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		if ((q->data.get_Fam().length()) != 0)
		{
			q->data.WriteOnScreenPeople();
			
			
		}
	}
	cout << "\nКонец\n\n";
}

void  Prep::WriteOnScreenPrep()
{
	if (this->Dolznoct != "NONAME"&&this->Dolznoct!="")
	{
		cout << "Должность - " << this->Dolznoct << "\n";

	}

}
template<>
void List<GradesForTheExam>::WriteExamensOnScreen()
{
	List<GradesForTheExam> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteExamOnScreen();
	}
}

void GradesForTheExam::WriteExamOnScreen()
{

	cout << this->subject << " " << Sub->data.NameOfSubject << " " << "(" << this->mark << ");";
}
template<>
void List<Subjects>::LoadOnScreen()
{
	cout << "	Список предметов\n\nНачало:\n\n";
	List<Subjects> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteSubjectsOnScreen();
	}
	cout << "\nКонец\n\n";
}
void   Subjects::WriteSubjectsOnScreen()
{
	cout << "Название - " << this->NameOfSubject << " ";
	cout << "Номер - " << this->NumberOfSubject << "\n";
	cout << "\n";
}

void List<Information>::AddExamens(string ch, int number, int mark, List<Subjects> *L)
{
	List<Information> *q = new List<Information>();
	for (q = this->next; q != NULL; q = q->next)
	{
	
		if (ch == (q->data).get_Fam())
		{
			List<GradesForTheExam> *b = new List<GradesForTheExam>();
				b = q->data.get_pass();
				int flag = 0;
				if (b != NULL)
				{


					while (b != NULL)
					{
						
						if (number == b->data.get_subject()) { b->data.set_mark(mark); flag++; };
							b = b->next;
							
							
					}
					if (flag == 0)
					{
						q->data.get_pass()->AddExam(ch, number, mark, *&L);
					}
					q->data.set_avg(q->data.get_pass()->Avg());


				}
				else
				{
					b = new List<GradesForTheExam>();
					b->AddExam(ch, number, mark, *&L);
					q->data.set_pass(b);
					q->data.set_avg(q->data.get_pass()->Avg());
					
				}
		
	    }
	}
}
template<>
float List<GradesForTheExam>::Avg()
{
	float  sum = 0;
	int n = 0;
	List<GradesForTheExam> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		sum = sum + q->get_data().get_mark();
		n++;
	}
	sum = sum / n;
	return sum;
	
}

template<>
void List<GradesForTheExam>::AddExam(string ch, int number, int mark, List<Subjects> *&L)
{
	//AddElements();
	GradesForTheExam W;
	
	W.set_subject(number); // W.subject = number;
	W.set_mark(mark);

	//List<Subjects> *q = new List<Subjects>;
	 List<Subjects> *q = L;

	for (q=L->next; q != NULL; q = q->next)
	{

		//Сравниваем номер предмета из списка предметов с номером предмета из списка экзаменов для данного студента
		if (number == (q->data).NumberOfSubject)
		{
			W.set_sub(q);
			AddElements(W);
			
			
		}
		

	}

	
	
}
template <class T>
void List<T>::Delete()
{
	string s_name;
	cout << "Введите Фамилию "<<endl;
	cin >> s_name;
	
	
	List<T> *res;
	List<T> *U = this->next;

	while (U != NULL)
	{//написать функцию для поиска имени

		if ((U->data).get_Fam() == s_name)
			break;
		U = U->next;
	}
	res = U;
	if (res == NULL)
	{
		cout << "Человек не найден.\n";
		return;
	}
	
	List<T> *a, *p;
	for (a = this; (a->next != NULL) && (a->next != res); a = a->next);
	if (a->next == NULL) return;
	p = a->next; a->next = p->next;
	p->next = NULL;
	///p->data.DeleteExams();
	delete p;
}



void Information::DeleteExams()
{
	pass->~List();
}


//Добавление нового студента
  int List<Information>::Dobstudent(string ch,string m,int b, string gr, List<Subjects> *&R)
{
	  int flag = 0;
	  List<Information> *q;
	  for (q = this->next; q != NULL; q = q->next)
	  {
		  if ((q->data.get_Fam() == ch) && (q->data.get_Name() == m) && (q->data.get_Age() == b) && (q->data.get_Group() == gr))
		  {
			  cout << "Такой студент уже есть." << endl;
			  flag = 1;
		  }
	  }
	  if (flag == 0)
	  {
		  int n = 0;//обнуляем счетчик студентов
		  Information a(ch, m, b, gr);
		  this->AddElements(a); n++;
		  return n;
	  }
	
}

  int List<Prep>:: DobPrep(string ch, string m, int b, string gr, string polisit, int salary, List<Subjects> *&R)
  {
	  int flag = 0;
	  List<Prep> *q;
	  for (q = this->next; q != NULL; q = q->next)
	  {
		  if ((q->data.get_Fam() == ch) && (q->data.get_Name() == m) && (q->data.get_Age() == b) && (q->data.get_Dol() == gr))
		  {
			  cout << "Такой преподаватель уже есть." << endl;
			  flag = 1;
		  }
	  }
	  
	  if (flag == 0)
	  {
		  int n = 0;//обнуляем счетчик студентов
		  Prep a(ch, m, b, gr, polisit,salary);
		  this->AddElements(a); n++;
		  return n;
	  }
  }

#endif