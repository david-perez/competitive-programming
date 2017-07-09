#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

bitset<10000000> bs; // 10^7
vector<ll> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (ll j = i * i; j < bs.size(); j += i) bs[j] = 0;
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

    int N;
    cin >> N;
    while (N--) {
        int L, U;
        cin >> L >> U;
        int P = L, D = nod(L);
        for (int n = L + 1; n <= U; n++) {
            int x = nod(n);
            if (x > D) {
                D = x;
                P = n;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, P, D);
    }

    return 0;
}
