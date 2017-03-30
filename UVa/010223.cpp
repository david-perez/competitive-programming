#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cat[20];
    cat[0] = cat[1] = 1;
    for (int n = 2; n < 20; n++) {
        cat[n] = 0;
        for (int i = 0; i <= n-1; i++)
            cat[n] += cat[i]*cat[n-1-i];
    }

    unsigned int n;
    while (cin >> n)
        cout << distance(cat, find(cat + 1, cat + 20, n)) << endl;

    return 0;
}