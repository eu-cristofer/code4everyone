/*
    Code sample to ilustrate exception handling
 */

#include <iostream>

using namespace std;

int main() {

    int age;

    cout << "Please inform your age:\n";
    cin >> age;

    try {
        if (age >= 18) {
            cout << "Access granted - you are old enough.";
        } else {
            throw (age);
        }
    } 
    catch (int myNum) {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Age is: " << myNum << endl;  
    }
    return 0;
}
