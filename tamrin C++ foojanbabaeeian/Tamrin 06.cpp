#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int n;
    cout << "what is n :";
    cin >> n;
    for (int I=1; I<=n; I=I+2){
        cout << "Odd numbers smaller than n are : " <<I <<endl;
    }
    cout << "end" << endl;
    return 0;
}