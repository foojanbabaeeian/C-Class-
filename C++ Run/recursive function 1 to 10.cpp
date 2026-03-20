#include <iostream>

using namespace std;

int i=1;
int test(int num){
    cout<<i<<endl;
    if (num==1){
        return 1;
    }else{
        i++;
        return test(num-1);
    }
}
int main() {
    test(10);
    return 0;
}
