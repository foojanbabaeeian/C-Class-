#include <iostream>
using namespace std;
// comment

/*int main() {
    int x = 10;
    int y = 10;

    cout << (x==y);
    return 0;
}*/
/*int main(){
    int radius =1;
    float pi=3.14, area;
    area= radius * radius * pi;

    cout <<"circle area"<<area;
}*/
/*int main(){
    cout <<"start"<<endl;

    int x=10;
    if (x%2 ==0) {
        cout << "Even" << endl;
    }
    else{
        cout <<"Odd"<<endl;
    }

    cout <<"End";
    return 0;
}*/
int main(){
    cout <<"start"<<endl;

    int age;
    cout<< "Enter Your Age";
    cin>>age;
    cout << "input"<<age<<endl;

    if (age == 10) {
        cout << "Teen" << endl;
    }
    else if (age == 20){
        cout <<"Young"<<endl;
    }
    else if(age==30){
        cout<<"adult"<<endl;
    }
    else if(age==40){
        cout<<"old"<<endl;
    }
    else {
        cout<<"very old"<<endl;
    }
    cout <<"End";
    return 0;
}