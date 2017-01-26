#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    vi f;
    for (int i = 2, x = 1; x < 100000; i++) {
        f.push_back(x);
        x *= i;
    }

    int N;
    while (cin >> N) {
        int k = 0, i = f.size()-1;
        while (N != 0) {
            if (f[i] <= N) {
                N -= f[i];
                k++;
            } else i--;
        }

        cout << k << endl;
    }

    return 0;
}