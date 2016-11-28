#include <iostream>

using namespace std;

int main() {
    string s;
    bool b = false;
    while (getline(cin, s)) {
        for (char &c : s)
            if (c == '"') {
                cout << (b ? "''" : "``");
                b = !b;
            } else cout << c;
        cout << endl;
    }

    return 0;
}