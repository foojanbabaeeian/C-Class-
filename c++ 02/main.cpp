#include <iostream>
#include <iostream>
using namespace std;
/*int main()
{
    int num;

    cout<< "Enter Number: ";
    cin>> num;

    for (int i=10; i<= num; i++){
        cout<< i << endl;
    }

}*/

/*int main()
{
    int num;
    int sum =0, count =0;

    cout<< "Enter Number: ";
    cin>> num;

    max =num;
    min =num;
    while (num !=0){
        sum =sum+num;
        count ++ ;

        if(num >max){
            max= num;

        }else if(num<min){
            min =num;
        }
        cout<< "Enter number" << endl;
        cin >> num;

        cout << "sum: " <<sum<< endl;
        cout << "avg" <<sum/count;
    }

}*/

int main()
{
    int num;
    int count =0;
    int max, max_location=0;

    cout<< "Enter Number: ";
    cin>> num;

    max =num ;
    max_location ++;

    while (num !=0){
        count ++;

        if(num > max){
            cout<<"largest number: " <<num;

            cout<< "Enter Number: ";
            cin>> num;
        }else if(max > num){
            cout <<"largest number" <<max;
        }
        cout << max <<endl;
    }

}