
/*
    ADT as a Class

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

using namespace :: std;

class rectangle
{
private:
    double height, width;
public:
    rectangle(double h, double w)                   // constructor
    {
        height = h;
        width = w;
    }
    double area(void){return height * width;}       // method
};


int main(void) {
    
    /* code */
    rectangle r(2.5, 2);
    double area = r.area();
    cout << "The area is: " << area << endl;
    return 0;
}
