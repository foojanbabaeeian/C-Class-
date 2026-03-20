#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int a,b,c;
    cout<< "a :";
    cin >> a;
    cout<< "b :";
    cin >> b;
    cout<< "c :";
    cin >> c;
    if (a<=b+c) {
        if (b <= a + c) {
            if (c <= b + c) {
                cout << "Can form a triangle"<<endl;
            }
        }
    }else {
        cout<< "can not form a triangle"<<endl;
    }
    cout << "end" << endl;
    return 0;
}
