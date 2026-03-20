//
// Created by WIN on 5/1/2022.
//

#include "Car.h"



void Car::setPersonFullName(string person_full_name) {
    Car::person_full_name = person_full_name;
}

const string Car::getCarName() {
    return car_name;
}

void Car::setCarName(string car_name) {
    Car::car_name = car_name;
}

int Car::getPrice() {
    return price;
}

Car::Car(string car_name, string person_full_name, int price) {
    Car:: car_name = car_name;
    Car:: person_full_name = person_full_name;
    Car:: price = price;

}