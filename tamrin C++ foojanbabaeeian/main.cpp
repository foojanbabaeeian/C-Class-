#include <iostream>

using namespace std;

int main() {
    cout << "Start" << endl;
    int N;
    int sum = 0;
    cout << "What is N : ";
    cin >> N;
    for (int I = 1; I <= (N / 2); I++) {
        if (N % I == 0) {
            sum = sum + I;
        }
    }
    if (sum == N) {
        cout << N << " is kamel" << endl;
    } else {
        cout << N << " is not kamel " << endl;
    }

    cout << "End " << endl;
    return 0;
}

