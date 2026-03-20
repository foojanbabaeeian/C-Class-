#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int A,B,max,min;
    cout << "Enter A and B" <<endl;
    cin >> A >>B;
    while(A==B) {
        cout << "Enter A and B which are not equal" <<endl;
        cin >> A >>B;
    }if (A>B){
        max=A;
        min=B;
        cout << "max is A : " << max <<endl;
        cout << "min s B : " << min << endl;
    }else{
        max=B;
        min=A;
        cout << "max is B : " << max <<endl;
        cout << "min is A : " << min << endl;
    }

    cout << "end" << endl;
    return 0;
}
