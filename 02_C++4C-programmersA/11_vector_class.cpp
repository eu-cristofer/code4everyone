
/*
    Code Title

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    /* code */
    vector<int> daysInMonth { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    

    for (int i = 0; i < daysInMonth.size(); i++){
        /* code */
        cout << daysInMonth[i] << endl;
    }
    
    
    return 0;
}
