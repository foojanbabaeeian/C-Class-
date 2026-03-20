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
};
Class Student : Person {
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
Class Professor :Person{
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

Class Worker : Person{
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
    cout<< "Student;s Subject :" <<student.getSubject()<<endl;
    return 0;
}