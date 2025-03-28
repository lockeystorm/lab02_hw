#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "What's your name? ";
    getline(cin, name);
    cout << "Hello world from " << name << endl;
    return 0;
}
