#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int a,sum=0;
    for (int I=1; I<=100;I++) {
        cout<<"Give me the "<< I <<" th num : ";
        cin >> a;
        sum =sum + a;
    }
    cout<< "sum is"<< sum <<endl;
    cout << "end" << endl;
    return 0;
}
