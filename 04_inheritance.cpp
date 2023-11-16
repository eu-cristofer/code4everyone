/*
    Inheritance basics

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template<class T>
class duo{
protected:
    T first, second;
public:
    // Constructor
    duo(T n, T m):first(n), second(m){}
    void set_first(T n){first = n;}
    void set_second(T m){second = m;}
    T get_first(){return first;}
    T get_second(){return second;}
};

template<class T>
class point:public duo<T>{
public:
    using duo<T>::duo;
    double length(){return sqrt(this->first * this->first + this->second * this->second);}
};


int main(int argc, const char * argv[]) {
    
    // Create an object
    duo<std::string> test_duo("cris", "keka");
    cout << "Hello " << test_duo.get_first() << endl;;
    cout << "Hello " << test_duo.get_second() << endl;
    
    point<int> position(3,4);
    cout << position.length() << endl;

    point<char> position_c((char)3,(char)4);
    cout << position_c.length() << endl;
    return 0;
}