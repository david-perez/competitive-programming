#include <iostream>

using namespace std;

typedef long long ll;

int lambda, n;

int f(int x) {
    return stoi(to_string((ll) x*x).substr(0, n));
}

int brent(int x0) {
    int power = lambda = 1;
    int tortoise = x0, hare = f(x0), M = max(tortoise, hare);
    while (tortoise != hare) {
        if (power == lambda) {
            tortoise = hare;
            power *= 2;
            lambda = 0;
        }
        hare = f(hare);
        lambda++;
        M = max(M, hare);
    }

    return M;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> n >> k;
        cout << brent(k) << endl;
    }

    return 0;
}
