
/*
    enum days defining operations

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

days operator++ (const days &d) {
    /* 
        Note that the argument d is being passed by reference
        using the "&d" syntax. Therefore the obejct is not copied.
    */
    return static_cast<days>((static_cast<int>(d + 1)) % 7);
}

int main(int argc, const char * argv[]) {
    
    days d = SAT, e;
    e = ++d;
    cout << d << '\t' << e <<  endl;
    
    return 0;
}