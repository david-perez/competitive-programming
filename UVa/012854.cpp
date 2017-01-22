#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        stringstream ss(s), st(t);
        bool b = true;
        for (int i = 0; i < 5; i++) {
            int x, y;
            ss >> x;
            st >> y;
            if (!(x ^ y)) {
                b = false;
                break;
            }
        }

        cout << (b ? 'Y' : 'N') << endl;
    }

    return 0;
}