/*
    Indexing square stuff qith only one variable

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <cmath>

using namespace std;

const int  SIZE = 3;

int main() {
    int index = pow(SIZE, 2);
    for (auto i = 0; i < index; i++)
    {
        if (!(i % SIZE))
        {
            cout << "\n\n";
        }
        cout << "(" << i / SIZE << ", " << i % SIZE << ")\t";
    }
    cout << endl << endl;
    return 0;
}