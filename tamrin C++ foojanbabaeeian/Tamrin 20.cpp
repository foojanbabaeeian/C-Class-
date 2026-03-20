#include <iostream>
using namespace std;

int main(){
    cout << "Start" <<endl;
    int N;
    int F=1;
    cout << "What is N : ";
    cin >> N;
    while (N<0){
        cout << "What is a natural value for N : ";
        cin >> N;
    }
    for (int I=1;I<=N;I++){
        F=F*I;
    }
    cout<< N <<" factorial is "<< F<<endl;
    cout << "End " <<endl;
    return 0;
}

