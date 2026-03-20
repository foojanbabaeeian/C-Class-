#include <iostream>
using namespace std;

int main()
{
    cout << "start" << endl;
    int T;
    cout <<"T" <<endl;
    cin >> T;
    int H= T/3600;
    cout <<H <<endl;
    int M= (T-(H*3600))/60;
    cout << M <<endl;
    int S= (T-(H*3600)-(M*60));
    cout << S <<endl;
    cout << "H:M:S is ";
    cout <<  H << ":" << M << ":" << S  << ":"  <<endl ;
    cout << "end" << endl;
    return 0;
}

