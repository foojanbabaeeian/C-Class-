//
// Created by SONY on 6/12/2022.
//

#ifndef RESTAURANTMENU_PERSON_H
#define RESTAURANTMENU_PERSON_H
#include <iostream>
using namespace std;

class person{
private:
    float payments=0;
    long i; //s.i is record address for each Person
    int num=1,Id,foodTaken;
    string firstName, lastName;
public:
    float getPayments() const;

    void setPayments(float payments);

    long getI() const;

    void setI(long i);

    int getNum() const;

    void setNum(int num);

    int getId() const;

    void setId(int id);

    int getFoodTaken() const;

    void setFoodTaken(int foodTaken);

    const string &getFirstName() const;

    void setFirstName(const string &firstName);

    const string &getLastName() const;

    void setLastName(const string &lastName);

public:

    void show();
    void add();
    void Delete();
    void search();
    void displayAll();
    friend class selectfood;
    friend class food;
};


#endif //RESTAURANTMENU_PERSON_H
