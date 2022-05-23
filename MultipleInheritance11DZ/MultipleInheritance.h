#pragma once
#include <iostream>
#include <vector>
class Figure
{
public:
	virtual float CalcArea(float,float) = 0; // виртуальный метод подсчета площади
	virtual float CalcPer(float, float) = 0;
};
class Quadrangle : public Figure
{
protected:
	float a, b, c, d; //стороны четырехугольника
};
class Rhombus : public Quadrangle
{
public:
	float CalcArea(float d1, float d2) override;
	float CalcPer(float a,float b) override;
};
class Rectangle : public Quadrangle
{

static int Count;
int number;
public:
	float CalcArea(float a, float b) override;
	float CalcPer(float a, float b) override;
	Rectangle(float a = 0,float b = 0)
	{
		this->a = a;
		this->b = b;
		Count++;
		
	}
	~Rectangle()
	{
		std::cout << "Destructor" << std::endl;
	}
	 int GetCount();
	 void SetNumber(int num);
	 int GetNumber();

};
