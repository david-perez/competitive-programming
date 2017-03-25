#include <iostream>

using namespace std;

int main() {
    int cat[11] = {1, 1};
    for (int n = 2; n <= 10; n++) {
        cat[n] = 0;
        for (int i = 0; i <= n-1; i++)
            cat[n] += cat[n-1-i]*cat[i];
    }

    int n; bool nl = false;
    while (cin >> n) {
        if (nl) cout << endl;
        cout << cat[n] << endl;
        nl = true;
    }
}