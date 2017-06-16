#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<1000001> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (ll j = i*i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int nod(int n) {
    int d = 1;
    for (int idx = 0, p = primes[idx]; p*p <= n; p = primes[++idx]) {
        int m = 0;
        while (n % p == 0) {
            n /= p;
            m++;
        }
        d *= m + 1;
    }
    if (n != 1) d *= 2;
    return d;
}

int main() {
    sieve();
    vi seq;
    for (int ni = 1; ni < 1e6; ni += nod(ni)) seq.push_back(ni);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int A, B;
        cin >> A >> B;
        auto lo = lower_bound(seq.begin(), seq.end(), A), hi = upper_bound(seq.begin(), seq.end(), B);
        printf("Case %d: %d\n", t, distance(lo, hi));
    }

    return 0;
}
