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

class User {
private:
    string username;
    string password;
    int id;
    int tel;

public:
    string getUserName(){
        return username;
    }
    void setUserName(string username){
        User::username =username;
    }
    string getPassword(){
        return password;
    }
    void setPassword(string password){
        User::password =password;
    }
};
class Student : public Person, public User{
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

class workerMali :public Worker{
private:
    int workingHours;

public:
    int getWorkingHours(){
        return workingHours;
    }
    void setWorkingHours(int workingHours){
        workerMali::workingHours =workingHours;
    }
};
class workerEdari :public Worker, public User{
private:
    int workingHours;

public:
    int getWorkingHours(){
        return workingHours;
    }
    void setWorkingHours(int workingHours){
        workerEdari::workingHours =workingHours;
    }
};

int main() {
    Student foojan;
    foojan.setFamily("Babaeeian");
    foojan.setName("foojan");
    foojan.setId(363);
    foojan.setSubject("C++");
    cout<< "foojan's Subject :" << foojan.getSubject()<<endl;
    cout<< "foojan's name and family name :" << foojan.getName() << " " << foojan.getFamily()<<endl;
    workerMali farhad;
    farhad.setSalary(10000);
    cout<< "farhad's Salary :" << farhad.getSalary()<<endl;
    User farbod;
    farbod.setUserName("farbod70");
    cout<< "farbod's Username: " << farbod.getUserName()<<endl;
    return 0;
}