#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    string s[4] = {"Happy", "birthday", "to", "you"};
    int i = 0, k = 0;
    while (i < n) {
        printf("%s: %s\n", p[i++].c_str(), (k % 16) == 11 ? "Rujia" : s[k % 4].c_str());
        k++;
    }

    while ((k % 16) != 0) {
        printf("%s: %s\n", p[i % n].c_str(), (k % 16) == 11 ? "Rujia" : s[k % 4].c_str());
        k++;
        i++;
    }

    return 0;
}
