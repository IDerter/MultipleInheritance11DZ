#include "Kartoteka.h"
#include <vector>
#include <string>
using namespace std;
std::ostream& operator<<(std::ostream& os, const Student& student) //возвращает ссылку на объект типа ostream
{
    os << student.age << '/' << student.nummarks << '/' << student.name <<  '/' <<  student.surname;
    return os;
}

std::istream& operator>> (std::istream& in, Student& student) //возвращает ссылку на объект типа ostream
{
    in >> student.age;
    in >> student.nummarks;
    in >> student.name;
    in >> student.surname;
    return in;
}
std::ostream& operator<<(std::ostream& stream, const std::vector<Student>& vec)
{
    for (const auto& b : vec)
        stream << b;
    return stream;
}
int Random(int min, int max) {
    return min + rand() % (max - min);
}
void PrintVector(std::vector <Student>& stud)
{
    for (int i = 0; i < size(stud); i++)
    {
        int a = stud[i].GetNumber();
        vector <int> masmarks;
        cout << stud[a] << " " << "Оценки: ";
        stud[a].GetMarks();
        cout << " Средняя оценка студента : " << stud[a].GetArifMarks() << endl;
    }
}
Student AddStudent(Student &stud,std::vector <std::string>& name, std::vector <std::string>& surname)
{
    stud.SetAge(18 + rand() % 5);
    stud.SetName(name[rand() % 10]);
    stud.SetName(surname[rand() % 10]);
    stud.SetNummarks(1 + rand() % 5);
    return stud;
}
int main()
{
    setlocale(LC_ALL, "rus");
    static int countobj = 0;
    vector <string> surname = { "Пупкин","Петров","Батурин","Сидоров","Иванов","Смирнов","Кузнецов","Попов","Васильев","Михайлов"};
    vector <string> name = { "Василий","Петя","Иван","Кирилл","Никита","Максим","Даниил","Владимир","Родион","Денис" };
    int a; //кол-во студентов
    do {
        cout << "Введите количество студентов: ";
        cin >> a;
    } while (a <= 0);
    vector <Student> stud;
    int random = Random(0, a-1);
    cout << "Номер старосты: " << random+1<<endl;
    bool flag = true;
    while (flag)
    {
        for (int i = 0; i < a; i++)
        {
            if (random == i)
            {
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, 4); //красный
            }
            stud.push_back(Student(18 + rand() % 5, 1 + rand() % 5, name[rand() % 10], surname[rand() % 10]));
            vector <int> masmarks;
            //float* mas = new float[stud[i].GetNummarks()]; //указатель на массив который хранит оценки студента
            stud[i].SetNumber(i);
            cout << stud[i] << " " << "Оценки: ";
            stud[i].SetMarks(masmarks, stud[i].GetNummarks());
            cout << " Средняя оценка студента : " << stud[i].ArifmMarks(masmarks, stud[i].GetNummarks()) << endl;
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, 7); //белый
        }
        int choose = 0;
        while (choose != 3)
        {
            cout << "Если хотите добавить студента нажмите - 1, удалить - 2, выйти 3" << endl;
            cin >> choose;
            if (choose == 1)
            {
                Student stud1;
                AddStudent(stud1, name, surname);
                stud.push_back(stud1);
                vector <int> masmarks;
               // float* mas = new float[stud1.GetNummarks()]; //указатель на массив который хранит оценки студента
                cout << stud1 << " " << "Оценки: ";
                stud1.SetMarks(masmarks, stud1.GetNummarks());
                cout << " Средняя оценка студента : " << stud1.ArifmMarks(masmarks, stud1.GetNummarks()) << endl;
            }
            else if (choose == 2)
            {
                int indexdel = 0;
                cout << "Введите номер удаляемого объекта" << endl;
                do {
                    cin >> indexdel;
                } while (indexdel > size(stud) - 1 || indexdel < 0);
                
                stud.erase(stud.begin() + indexdel);
                system("cls");
                PrintVector(stud);
            }
            else if (choose == 3)
            {
                flag = false;
            }
            
        }
    }
}
