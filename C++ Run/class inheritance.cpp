#include <iostream>

using namespace std;

class Person {
private:
    string name;
    string family;
    int id;
    int tel;

public:
    string getName(){
        return name;
    }
    void setName(string name){
        Person::name =name;
    }
    string getFamily(){
        return family;
    }
    void setFamily(string family){
        Person::family =family;
    }

    int getId(){
        return id;
    }
    void setId(int id){
        Person::id =id;
    }

    int getTel(){
        return tel;
    }
    void setTel(int tel){
        Person::tel =tel;
    }
};
class Student : public Person {
private:
string Subject;

public:
string getSubject(){
    return Subject;
}
void setSubject(string subject){
    Student::Subject =subject;
}
};
class Professor :public Person{
private:
int workingHours;

public:
int getWorkingHours(){
    return workingHours;
}
void setWorkingHours(int workingHours){
    Professor::workingHours =workingHours;
}
};

class Worker : public Person{
private:
int salary;

public:
int getSalary(){
    return salary;
}
void setSalary(int salary){
    Worker::salary = salary;
}
};

int main() {
    Student student;
    student.setSubject("Math");
    cout<< "Student's Subject :" << student.getSubject()<<endl;
    
    return 0;
}