#include<iostream>
using namespace std;

// Function Declaration
bool isValid(string username, string pass){
    if (username == "ali" && pass =="ali123") {
        return true;
    }else{
        return false;
    }
}//Function signature


//start point
int main(){
    string user,pass;
    cout << "username:" << endl;
    cin>> user;
    cout << "pass:" << endl;
    cin >>pass;
    if(isValid(user,pass)==true){
        cout <<"welcome"<<endl;
    }else{
        cout<<"invalid User/pass"<<endl;
    }
    cout<<isValid(user,pass);

return 0;
}



