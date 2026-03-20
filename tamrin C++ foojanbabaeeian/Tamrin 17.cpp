#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int A;
    cout << "Enter A : " <<endl;
    cin >> A;
    while(A<=0){
        cout << "Enter another A : " <<endl;
        cin >> A;
    }
    if (A%2==0){
        cout <<"The number is Even"<<endl;
    }else{
        cout<<"The number is Odd"<<endl;
    }
    cout << "end" << endl;
    return 0;
}
