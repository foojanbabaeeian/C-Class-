#include <iostream>
using namespace std;

int main() {
    cout << "start" << endl;

    float X,Y;
    cout << "Give me num X and Y :";
    cin >> X;
    cin >> Y;
    if (X>Y){
        cout << X+Y <<endl;
    }else if(X<Y){
        cout<< Y-X <<endl;
    }else{
        cout<< X << endl;
    }

    cout << "end" << endl;
    return 0;
}
