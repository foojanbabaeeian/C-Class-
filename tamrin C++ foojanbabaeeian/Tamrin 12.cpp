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
    if (a*a==(b*b)+(c*c)) {
        cout<<"triangle can be a right triangle"<<endl;
    }else if(b*b==(a*a)+(c*c)){
        cout<<"triangle can be a right triangle"<<endl;
    }else if(c*c==(a*a)+(b*b)){
        cout<<"triangle can be a right triangle"<<endl;
    }else {
        cout<<"triangle can not be a right triangle"<<endl;
    }
    cout << "end" << endl;
    return 0;
}
