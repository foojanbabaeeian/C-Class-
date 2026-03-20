#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int i,j,k,t;
    for (int N=2; N<=6;N=N+2) {
        cout<< "enter i,j,k :"<<endl;
        cin >> i >>j>> k;
        t=i+j+k;
        cout<< "t is: " << t << endl;
    }
    cout << "end" << endl;
    return 0;
}
