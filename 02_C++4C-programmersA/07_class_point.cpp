
/*
    Class Point

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

using namespace std;

class Point
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
    Point(double x =0.0, double y = 0.0):x(x),y(y){}
    /*
        Constructors
        ============
        Its signature is void.
        Constructors that may be called without any argument are
        default constructors. Usually it creates a obj with null value
        Its has a initializer list.
    */   
    double x, y;
    double getx() {return x;}           // member function or method
    void setx(double v) {x = v;}        // mutator method
};

Point operator+ (const Point& p1, const Point& p2){
    Point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
}

ostream& operator<< (ostream& out, const Point& p){
    /*
        Usual signature for overloading ostream& operator:
        (ostream& out, const my_type&  v )
        both arguments are passed by reference
        my_type is passeds wuth a const modifier so as not
        to be modified.
    */
    out << "Point(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    
    /* code */

    Point a, b = {2.5, 4.5}, c;

    cout << "a Point initialized null:\na = " << a << endl;
    a.x = 3.5;
    a.y = 2.5;

    cout << "a Point after assignment:\na = " << a << endl;
    cout << "b = " << b << endl;

    c = a + b;

    cout << "c = " << c << endl;
    
    return 0;
}