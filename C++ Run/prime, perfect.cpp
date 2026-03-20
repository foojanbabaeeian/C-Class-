#include <iostream>

using namespace std;

bool Find_TumNumber(int number);

bool Find_AvalNumber(int number);

int main() {
    int N;
    cout << "What is Number : " << endl;
    cin >> N;


    if (Find_AvalNumber(N)) {
        cout << N << " is prime" << endl;
    } else {
        cout << N << " is not prime" << endl;
    }

    if (Find_TumNumber(N)) {
        cout << N << " is a tum number and kamel" << endl;
    } else {
        cout << N << " is not a tum number" << endl;
    }
    return 0;
}

bool Find_AvalNumber(int number) {
    int check = 0;
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            check = check + 1;
        }
    }
    if (check == 0) {
        return true;
    } else if (check > 0) {
        return false;
    }
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
