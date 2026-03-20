#include <iostream>
using namespace std;

int main() {
    cout << "start" << endl;

    float X;
    cout << "Give me num X:";
    cin >> X;
    if (X<0){
        cout << X+1 <<endl;
    }else if(X<1 and 0<=X){
        cout<< -(X*X) <<endl;
    }else if(X>=1){
        cout<< 1/X << endl;
    }

    cout << "end" << endl;
    return 0;
}
