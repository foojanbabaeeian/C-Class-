//
// Created by SONY on 6/12/2022.
//

#include "person.h"

float person::getPayments() const {
    return payments;
}

void person::setPayments(float payments) {
    person::payments = payments;
}

long person::getI() const {
    return i;
}

void person::setI(long i) {
    person::i = i;
}

int person::getNum() const {
    return num;
}

void person::setNum(int num) {
    person::num = num;
}

int person::getId() const {
    return Id;
}

void person::setId(int id) {
    Id = id;
}

int person::getFoodTaken() const {
    return foodTaken;
}

void person::setFoodTaken(int foodTaken) {
    person::foodTaken = foodTaken;
}

const string &person::getFirstName() const {
    return firstName;
}

void person::setFirstName(const string &firstName) {
    person::firstName = firstName;
}

const string &person::getLastName() const {
    return lastName;
}

void person::setLastName(const string &lastName) {
    person::lastName = lastName;
}
