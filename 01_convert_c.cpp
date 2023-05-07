//
//  Convert the C code to C++
//  Assignment # 1
//  This code converts C code to C++ and calculates the sum of elements in a vector.
//  It also outputs the sum to the console.
//  
//  Author: Cristofer Costa
//  Contact: cristofercosta@yahoo.com.br
//
#include <iostream>
#include <vector>

using namespace :: std;

const int N = 40;

inline void sum(int& p, vector<int>& d) {
    // This function calculates the sum of elements 
    // in a vector and updates the integer parameter
    // with the result.
    p = 0;
    for(const int& i : d)
        p = p + d.at(i);
}
int main() {
    int accum = 0;
    vector<int> data;

    // Add elements to the vector.
    for(int i = 0; i < N; i++)
        data.push_back(i);

    sum(accum, data);
    cout << "Sum is "
         << accum
         << endl;
    return 0;
}