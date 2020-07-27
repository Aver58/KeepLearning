using namespace std;
#include <iostream>

class Student
{
private:
    int age;
    string name;

public:
    Student(int, string);
    void show(int _age, string _name);
    void show2();
};

Student::Student(int _age, string _name)
{
    this->age = _age;
    this->name = _name;
}

void Student::show(int _age, string _name)
{
    //printf("Age : %d\n Name : %s", _age, _name);
    cout<<"Age : "<<_age<<"\nName : "<<_name<<endl;
}

void Student::show2()
{
    cout<<"Age : "<<this->age<<"\nName : "<<this->name<<endl;
}

//int main()
//{
//    //两种实例化类的方式
//    Student s(16, "puyangsky");
//    s.show(14, "puyangsky");
//    s.show2();
//
//
//    Student* s1 = new Student(16, "puyangsky");
//    s1->show2();
//
//    getchar();
//    return 0;
//}