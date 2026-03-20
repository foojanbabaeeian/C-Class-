#include <iostream>

using namespace std;
int kmm(int x,int y){
    if (x<y){
        //swap
        int temp=x;
        x=y;
        y=temp;
    }
    int result=x*y;
    for (int i=2;i<x;i++){
        if((x%i==0)and(y%i==0)){
            result=result/i;
            x=x/i;
            y=y/i;
        }
    }
    return result;
}
int main() {
    int x,y;
    cout<<"x";
    cin>>x;
    cout<<"y";
    cin>>y;
    cout<<kmm(x,y);
    return 0;
}
