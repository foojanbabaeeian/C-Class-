#include <iostream>
using namespace std;

int main(){
    cout << "Start" <<endl;
    int a;
    int sum =0;
    int count=0;
    int  max, min;
    cout << "What is number a : ";
    cin >> a;
    max =a;
    min=a;
    int max_num =1;
    while (a!=0) {
        sum = sum + a;
        count++;

        if (max<=a){
            max=a;
            max_num = count;
        }
        if (min>=a){
            min=a;
        }

        cout << "what is the new a ;";
        cin >> a;
    }
    cout << "count is" <<count <<endl;
    cout << "Sum is " << sum << endl;
    cout <<"Average" << sum/count <<endl;
    cout << "max is" <<max <<endl;
    cout << "min is " << min << endl;
    cout << "max number is " << max_num << endl;
    cout << "End " <<endl;
    return 0;
}

