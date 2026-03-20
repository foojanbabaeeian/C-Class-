#include <iostream>
using namespace std;

int main(){
    cout << "Start" <<endl;
    int N;
    int S=0;
    cout << "What is N : ";
    cin >> N;
    while (N<0){
        cout << "What is a natural value for N : ";
        cin >> N;
    }
    for (int c=1;c<=N;c++){
        int F=1;
        for (int I=1;I<=c;I++){
            F=F*I;
        }
        S=S+F;
    }
    cout << "factorial's sum until the " << N<<"th num is : " << S<<endl;
    cout << "End " <<endl;
    return 0;
}

