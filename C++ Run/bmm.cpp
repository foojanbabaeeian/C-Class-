#include <iostream>

using namespace std;
int bmm(int x,int y){
    if (x>y){
        //swap
        int temp=x;
        x=y;
        y=temp;
    }
    int result;
    for (int i=1;i<=x;i++){
        if((x%i==0)and(y%i==0)){
            result=i;
        }
    }
    return result;
}
int main() {
    cout<<bmm(36,18);
    return 0;
}
