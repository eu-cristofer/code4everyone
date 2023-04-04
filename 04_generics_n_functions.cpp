
/*
    Generic and Functions

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

// standard C fucntion code
double sum(double data[], int size){
    double s = 0;
    int i;

    for(i = 0; i < size; i++)
        s += data[i];
    return s;
}

// generic C++ function code
template <class T>      //T is generic type, metavariable T
T sum_generic(const T data[], int size, T s = 0){  //s receive a default value
    for(int i = 0; i < size; i++)
        s += data[i];
    return s;
}

int main(int argc, const char * argv[]) {
    
    /* signature #1 */
    double data[] = {1,2,3};
    std::cout << "out:\t" << sum_generic(data,3) << std::endl;
    
    /* signature #1 */
    std::cout << "out:\t" << sum_generic(data,3,100.0) << std::endl;
    return 0;
}
