/*
    Lambda expression

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>
#include <numeric>

using namespace std;

// Function to print vector
void printVector(vector<int> v)
{
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i)
    {
        cout << i << "\t";
    });
    cout << endl;
}

// Function to print vector raised to power 2
void printVectorPower2(vector<int> v)
{
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i)
    {
        cout << pow(i,2) << "\t";
    });
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    /* code */
    vector<int> vec {1, 2, 3};
    int sum = 0;

    printVector(vec);
    printVectorPower2(vec);
    sum = accumulate(vec.begin(),vec.end(),0);
    cout << "The sum is: " << sum << endl;
    
    return 0;
}