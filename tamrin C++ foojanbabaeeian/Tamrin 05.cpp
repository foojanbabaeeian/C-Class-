#include <iostream>
using namespace std;

/*int main()
{
    cout << "start" << endl;
    int I=10;
    while (I<100){
        cout << "I is : " <<I <<endl;
        I=I+2;
    }
    cout << "end" << endl;
    return 0;
}*/
int main() {
    cout << "start" << endl;
    for (int I=10; I < 100; I=I+2) {
        cout << "I is : " << I << endl;
    }
    cout << "end" << endl;
    return 0;
}