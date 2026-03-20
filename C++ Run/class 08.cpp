#include <iostream>

using namespace std;

class Car {
private:
    string name;
    int model;

public:
    string getName(){
        return name;
    }
    void setName(){
        Car::name =name;
    }
    int getModel(){
        return model;
    }
    void setModel(int model){
        if(model<1999){
            cout<<"Invalid model"<<endl;
        }else{
            Car::model=model;
            cout<<model<<endl;
        }
    }
};

int main() {
    Car car1;
    car1.setModel(1996);
    cout<< "Model of the car:" <<car1.getModel()<<endl;
    return 0;
}