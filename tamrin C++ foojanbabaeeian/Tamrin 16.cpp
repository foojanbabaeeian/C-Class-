#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int A,B,C,max;
    cout << "Enter A and B and C respectively : " <<endl;
    cin >> A >>B >>C;
    if (A>B){
        if (A>C){
            max=A;
        }else if(C>A){
            max=C;
        }
    }else if (B>A) {
        if (B > C) {
            max = B;
        }else if (C > B) {
            max = C;
        }
    }
    cout <<"max number between three is: " << max <<endl;
    cout << "end" << endl;
    return 0;
}
