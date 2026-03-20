#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int S=0;
    for (int I=1000; I<=2000; I=I+2){
        cout<< "I is:" <<I<<endl;
        S=S+I;
    }
    cout <<"Sum is :"<< S<<endl;
    cout << "end" << endl;
    return 0;
}
