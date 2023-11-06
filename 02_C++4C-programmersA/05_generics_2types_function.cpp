/*
    Generic two types function

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <typeinfo>

// generic C++ function code
template <class T1, class T2>      //T is generic type, metavariable T
void copy(const T1 source[], T2 destination[], int size){
    for(int i = 0; i < size; ++i)
        destination[i] = static_cast<T2>(source[i]);    //safe casting
}

int main(int argc, const char * argv[]) {
    int a[] = {1,2,3};
    double b[3];

    copy(a, b, 3);
    
    std::cout << typeid(b[0]).name() << std::endl;

    copy(b, a, 3);
    
    std::cout << typeid(a[0]).name() << std::endl;

    return 0;
}