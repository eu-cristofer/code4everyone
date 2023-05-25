
/*
    Class point

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

using namespace std;

class point
{
private:
    /*
        Private it is like a black box.
        For example,  Apple doesn't want you to mess with that,
        so that keeps it a lot simpler. So again, that's a really
        important principle in building things. Hide away as much
        as possible that the non-expert, the ordinary user doesn't
        need to know and just give them the public controls, the
        little knobs or whatever are on the face of the device.

        In class point we're trying to create a new user defined
        object and some of what we want to understand is how to 
        use the OO technology.
        
        What are some of its key elements?
        The overriding principle in the object-orient technology
        is to make your new data object seem natural, seem compa-
        tible with the existing programming language data type such
        as int or float. Among the principles, we try to follow are
        data hiding. So private Is where we hide representation.
    */
    // double x, y;
public:
    double x, y;
    double getx() {return x;}           // member function or method
    void setx(double v) {x = v;}        // mutator method
};

point operator+ (const point& p1, const point& p2){
    point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    /*
        Usual signature for overloading ostream& operator:
        (ostream& out, const my_type&  v )
        both arguments are passed by reference
        my_type is passeds wuth a const modifier so as not
        to be modified.
    */
    out << "( " << p.x << ", " << p.y << " )";
    return out;
}

int main() {
    
    /* code */

    point a = {3.5, 2.5}, b = {2.5, 4.5}, c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    c = a + b;

    cout << "c = " << c << endl;
    
    return 0;
}