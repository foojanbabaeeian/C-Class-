//
// Created by SONY on 6/12/2022.
//
#include <iostream>
#include "person.h"

using namespace std;
#ifndef RESTAURANTMENU_FOOD_H
#define RESTAURANTMENU_FOOD_H


class food{
private:
    int price,quantity,time,calories, j;
    string name, ingredients, day;
public:
    int getPrice() const;

    void setPrice(int price);

    int getQuantity() const;

    void setQuantity(int quantity);

    int getTime() const;

    void setTime(int time);

    int getCalories() const;

    void setCalories(int calories);

    int getJ() const;

    void setJ(int j);

    const string &getName() const;

    void setName(const string &name);

    const string &getIngredients() const;

    void setIngredients(const string &ingredients);

    const string &getDay() const;

    void setDay(const string &day);

    void show();
    void add();
    void Delete();
    void search();
    void displayAll();
    friend class selectfood;
    friend class person;
};


#endif //RESTAURANTMENU_FOOD_H
