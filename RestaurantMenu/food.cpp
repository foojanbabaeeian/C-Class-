//
// Created by SONY on 6/12/2022.
//

#include "food.h"


int food::getPrice() const {
    return price;
}

void food::setPrice(int price) {
    food::price = price;
}

int food::getQuantity() const {
    return quantity;
}

void food::setQuantity(int quantity) {
    food::quantity = quantity;
}

int food::getTime() const {
    return time;
}

void food::setTime(int time) {
    food::time = time;
}

int food::getCalories() const {
    return calories;
}

void food::setCalories(int calories) {
    food::calories = calories;
}

int food::getJ() const {
    return j;
}

void food::setJ(int j) {
    food::j = j;
}

const string &food::getName() const {
    return name;
}

void food::setName(const string &name) {
    food::name = name;
}

const string &food::getIngredients() const {
    return ingredients;
}

void food::setIngredients(const string &ingredients) {
    food::ingredients = ingredients;
}

const string &food::getDay() const {
    return day;
}

void food::setDay(const string &day) {
    food::day = day;
}
