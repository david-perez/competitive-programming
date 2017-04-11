#include <iostream>

using namespace std;

int main() {
    int c[19] = {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6, 2, 14, 10, 6, 2, 14, 10, 6};
    string n[19] = {"1s", "2s", "2p", "3s", "3p", "4s", "3d", "4p", "5s", "4d", "5p", "6s", "4f", "5d", "6p", "7s", "5f", "6d", "7p"};

    string s;
    while (cin >> s && s != "Exit") {
        int Z;
        cin >> Z;

        int i = 0;
        while (Z > c[i]) {
            printf("%s%d ", n[i].c_str(), c[i]);
            Z -= c[i];
            i++;
        }

        printf("%s%d\n", n[i].c_str(), Z);
    }

    return 0;
}