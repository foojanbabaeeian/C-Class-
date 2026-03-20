#include <iostream>

using namespace std;

int main() {
    cout << "Start" << endl;
    int N;
    cout << "What is N : ";
    cin >> N;
    for (int t = 2; t <= N; t++) {
        int sum = 0;
        for (int I = 1; I <= (t / 2); I++) {
            if (t % I == 0) {
                sum = sum + I;
            }
        }
        if (sum == t) {
            cout << t << endl;
        }
    }
    cout << "End " << endl;
    return 0;
}

