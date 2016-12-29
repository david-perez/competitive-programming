#include <iostream>

using namespace std;

int main() {
    int S;
    cin >> S;
    for (int t = 1; t <= S; t++) {
        bool b = true;
        for (int i = 0; i < 13; i++) {
            int x;
            cin >> x;
            if (x == 0) b = false;
        }

        printf("Set #%d: %s\n", t, b ? "Yes" : "No");
    }
}