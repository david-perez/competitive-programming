#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<1001> bs;
vi primes;

void sieve() {
    bs.set();
    bs[0] = 0;
    bs[1] = 1; // in this problem, 1 is considered to be a prime number
    primes.push_back(1);
    for (int i = 2; i < bs.size(); i++) if (bs[i]) {
        for (int j = i * i; j < bs.size(); j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    sieve();
    int N, C;
    while (cin >> N >> C) {
        int L = distance(primes.begin(), upper_bound(primes.begin(), primes.end(), N));
        int j = L / 2;
        j = (L % 2 == 0 ? max(0, j - 1 - (C-1)) : max(0, j - (C - 1)));
        printf("%d %d:", N, C);
        for (int i = (L % 2 == 0 ? 2*C : 2*C - 1); i > 0 && j < L; i--, j++)
            cout << ' ' << primes[j];
        cout << endl << endl;
    }

    return 0;
}