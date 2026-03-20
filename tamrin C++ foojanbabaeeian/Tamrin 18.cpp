#include <iostream>
using namespace std;

int main(){
    cout << "Start" <<endl;
    int N;
    int sum =0;
    int count=0;
    cout << "What is N : ";
    cin >> N;
    for (int I=1;I<=N;I++){
        if(N%I==0){
            cout << "I is :" << I <<endl;
            count ++;
            sum=sum+I;
        }
    }
    cout << "count is : " <<count <<endl;
    cout << "Sum is : " << sum << endl;

    cout << "End " <<endl;
    return 0;
}

