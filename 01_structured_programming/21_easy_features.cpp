
/*
    Easy to use features

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

using namespace :: std;

long long fact(int n)                   // note the long long
{
    long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

int main(void) {
    
    cout << "This program uses some features not in C89\n";

    for (auto i = 0; i < 16; i++)       // duck typing declaration
    {
        cout << "factorial of " << i << " is " << fact(i) << endl;
    }
    cout << " Thats all folks" << endl;

    return 0;
}
