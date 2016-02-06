#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    stringstream inSS;
    string input = "Hello";
    
    inSS << "Hello";
    
    for (int i = 0; i < input.size();i++) {
    char test = inSS.get();
    if (test < 91) {
        cout << "is upper" << endl;
    }
    cout << test << endl;
    }
    
    return 0;
}