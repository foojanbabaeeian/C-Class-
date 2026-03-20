#include<iostream>


using namespace std;

// Function Declaration
int test();
int rectangleArea(int width, int height); //Function signature
int squareArea(int width);
void sayHello();

//start point
int main(){

//cout << rectangleArea(10,8);

    cout << squareArea(10) << endl;

    int a = rectangleArea(10,8) ;
    cout << a <<endl;


    sayHello();
    return 0;
}


int rectangleArea(int width, int height){
    return width * height;
}


int squareArea(int width){
    return width * width, 10, 100;
}

void sayHello(){
    cout <<"Hello" << endl;
//return not needed

    cout << test();
}

int test(){
    return 1;
}
