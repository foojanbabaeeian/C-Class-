#include <iostream>
using namespace std;

int main() {
    cout << "start" << endl;

    float X;
    cout << "Give me num X :";
    cin >> X;
    if (X>0){
        X=X*2;
        cout << X <<endl;
    }else{
        X= -X;
        cout<< X <<endl;
    }

    cout << "end" << endl;
    return 0;
}
