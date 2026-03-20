#include <iostream>

using namespace std;

bool Find_TumNumber(int number);

int main() {

    /* Q 21 */
    cout << "Start" << endl;
    int N;
    cout << "What is N : " << endl;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        if (Find_TumNumber(i)){
            cout << i << " ";
        }
    }
    return 0;
}

bool Find_TumNumber(int number) {
    int Sum = 0;

    for (int j = 1; j <= number; ++j) {
        if (number % j == 0 && j < number) {
            Sum += j;
        }
    }

    return Sum == number;
}