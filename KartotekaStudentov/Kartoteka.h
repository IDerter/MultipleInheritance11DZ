#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
class Student
{
private:
	int age;
	int nummarks;
	std::string name;
	std::string surname;
	float arifmmarks;
	std::vector <int> marks;
	int number;
public:
	int GetAge();
	void SetAge(int valueage);
	int GetNummarks();
	void SetNummarks(int valueage);
	std::string GetName();
	void SetName(std::string valueaname);
	std::string GetSurname();
	void SetSurname(std::string valueaname);
	float ArifmMarks(std::vector <int>& mas, int nummark);
	void SetMarks(std::vector <int>& mas, int nummarks);
	void GetMarks();
	//int* GetMarksN();
	void SetNumber(int number);
	int GetNumber();
	float GetArifMarks();
	Student AddStudent(Student&, std::vector <std::string>&, std::vector <std::string>&);
	Student(int age = 18, int nummarks = 5, std::string name = "Ivan", std::string surname = "Ivanov")//, float arifmmarks = 3)//, float srmark = 4)
	{
		this->age = age;
		this->nummarks = nummarks;
		this->name = name;
		this->surname = surname;
		//this->arifmmarks = this->GetArifMarks();
		/*for (int i = 0; i < GetNummarks(); i++)
		{
			int a = 2 + rand() % 4;
			marks.push_back(a);
			std::cout << marks[i] << " ";
		}
		*/
	}
	
	Student& operator = (const Student& stud)
	{
		if (this == &stud) // Проверка на самоприсваивание
			return *this;
		// Выполняем копирование значений
		age = stud.age;
		nummarks = stud.nummarks;
		name = stud.name;
		surname = stud.surname;
		return *this; // Возвращаем текущий объект
	}

	friend std::ostream& operator <<(std::ostream& os, const Student& student);
	friend std::istream& operator >>(std::istream& os, Student& student);


};