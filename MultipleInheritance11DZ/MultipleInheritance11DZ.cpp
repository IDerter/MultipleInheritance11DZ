#pragma once

#include "MultipleInheritance.h"
int Rectangle::Count = 0; //Если инициализация находится в файле заголовка, то каждый файл, содержащий заголовочный файл, будет иметь определение статического члена. Таким образом, во время фазы ссылки вы получите ошибки компоновщика, поскольку код для инициализации переменной будет определен в нескольких исходных файлах.
int main()
{
   /* Rhombus rhomb;
    Rectangle rect1;
    std::cout << "AreaRhomb: " << rhomb.CalcArea(10, 5) << std::endl << "AreaRectangle: " << rect1.CalcArea(5, 20) << std::endl;
    Rectangle rect2;
    */
    //vec.push_back(rect1.CalcArea(8, 20));
   // vec.push_back(rect2.CalcArea(4, 20));
	int size;
	std::cout << "Enter size:\n";
	std::cin >> size;
	std::vector <Rectangle*> vec;
	std::vector <float> vecintc;
	for (int i = 0; i < size; i++)
	{
		float a = rand() * 100.0 / RAND_MAX;
		float b = rand() * 50.0 / RAND_MAX;
		vec.push_back(new Rectangle(a, b));
		vecintc.push_back(vec[i]->CalcArea(a, b));
		vec[i]->SetNumber(i + 1);
		std::cout << "S: " << vecintc[i] << " - " << vec[i]->GetNumber() << std::endl;;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0;j<size-i-1;j++)
		{
			if (vecintc[j] > vecintc[j + 1])
			{
				std::swap(vecintc[j], vecintc[j + 1]);
			}
		}
	}
	std::cout << "SortVersion:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "S: " << vecintc[i] << " - " << vec[i]->GetNumber() << std::endl;;
	}
	for (int i = 0; i < size; i++)
	{
		delete vec[i];
	}
}
