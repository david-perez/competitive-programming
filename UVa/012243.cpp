#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s) && s != "*") {
        stringstream ss(s);
        string t;
        ss >> t;
        char c = tolower(t[0]);
        bool taut = true;
        while (taut && ss >> t)
            taut = tolower(t[0]) == c;

        cout << (taut ? "Y" : "N") << endl;
    }

    return 0;
}
