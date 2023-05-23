
/*
    Code Title

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

days operator++ (days &d) {
    return static_cast<days>((static_cast<int>(d +1 ))% 7);
}

int main(int argc, const char * argv[]) {
    
    /* code */

    days d = SAT, e;

    e = ++d;

    std::cout << d << '\t' << e <<  std::endl;
    
    return 0;
}
