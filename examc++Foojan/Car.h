//
// Created by WIN on 5/1/2022.
//
#include <iostream>

using namespace std;
#ifndef EXAMC__FOOJAN_CLASS_H
#define EXAMC__FOOJAN_CLASS_H


class Car {
private:
    string car_name;
    string person_full_name;
    int price;
public:

    Car(string car_name,string person_full_name ,int price);

    void setPersonFullName(string person_full_name);

    string getPersonFullName();

    const string getCarName();

    void setCarName(string car_name);

    int getPrice();


};


#endif //EXAMC__FOOJAN_CLASS_H
