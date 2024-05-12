// OOP_11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string surname;

public:
    void SetName(string name)
    {
        this->name = name;
    }
    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    string GetName() const
    {
        return name;
    }

    string GetSurname() const
    {
        return surname;
    }
   
    Person(): Person ("Ivan", "Ivanov") {}

    //главный к-тор
    Person(string name, string surname) {
        SetName (name);
        SetSurname (surname);
    }

    ~Person() {}

    void Print() const{
        cout << name <<" "<< surname << "\n";
    }
};


class Student: public Person {
protected:
    int* marks=nullptr;
    int* marks_count = 0;
 
public:
    void SetMarks(int mark, int marks_count)
    {
        marks = new int[marks_count];
        for (int i = 0; i < marks_count; i++) {
            //marks[i] = rand() % 12 + 1;
            marks[i] = mark;
        }
    }

    void GetMarks(int* marks, int marks_count) const
    {
        for (int i = 0; i < marks_count; i++) {
            cout << marks [i] << ",";
        };
    }

    Student() : Student("Mark", "Twen",12, 3) {}

    //главный к-тор
    Student(string name, string surname, int mark, int marks_count) : Person (name, surname) {
        SetMarks(mark, marks_count);
    }

    ~Student() {
        delete[] marks;
    }

    void PassExam() {
        cout << "Congratulations!!!\n";
    }

    void OversleepCouples() {
        cout << "Zzzz\n";
    }

    void Print() const {
        Person::Print();
        GetMarks(marks, 2);
    }
};

class Aspirant: public Student {
protected:
    string name_candidate_work;

public:
    void SetNameCandidateWork(string name_candidate_work)
    {
        this->name_candidate_work = name_candidate_work;
    }
   
    string GetNameCandidateWork() const
    {
        return name_candidate_work;
    }

    Aspirant() : Aspirant("Copy constructors") {}

    //главный к-тор
    Aspirant(string name_candidate_work) {
        SetNameCandidateWork(name_candidate_work);
    }

    ~Aspirant() {}

    void Print() const {
        Student::Print();
        cout << name_candidate_work << "\n";
    }

    void DefenseOfTheCandidateWork() {
        cout << "So Happy!";
    }
};

int main()
{
    //Person p ("Vova", "Vovochkin");
   // p.Print();
   // Student s;
   // s.Print();
   
    
    //Student s("Vova", "Vovochkin", 10, 2);
    //s.Print();
    //Aspirant a;
    //a.Print();
    Aspirant a ("Functions");
    a.Print();
     
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
