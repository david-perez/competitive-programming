#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000000> p; // 10^7
bitset<1000001> c;
vi primes;

void sieve(ll upperbound) { // finds primes in [0...upperbound]
    _sieve_size = upperbound + 1;
    p.set();
    p[0] = p[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (p[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) p[j] = 0;
        primes.push_back(i);
    }
}

bool isPrime(ll N) { // only works for 0 <= N <= primes[primes.size()-1]^2
    if (N <= _sieve_size) return p[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main() {
    sieve(10000000);

    int L, U;
    while (cin >> L >> U) {
        c.reset(); // [L...U]
        for (int i = 0; i < primes.size() && (ll) primes[i] * primes[i] <= U; i++) {
            int pr = primes[i];
            ll start = L % pr == 0 ? L : (ll) L + (pr - L % pr);
            for (ll n = start; n <= U; n += pr)
                if (n != pr)
                    c[n - L] = 1;
        }
        if (L == 1) c[0] = 1;

        int maxD = -1, minD = INT_MAX;
        int D1, D2, C1, C2, p1 = 0;
        for (ll p2 = L; p2 <= U; p2++)
            if (!c[p2 - L]) {
                if (p1 != 0) {
                    if (p2 - p1 > maxD) {
                        maxD = p2 - p1;
                        D1 = p1;
                        D2 = p2;
                    }

                    if (p2 - p1 < minD) {
                        minD = p2 - p1;
                        C1 = p1;
                        C2 = p2;
                    }
                }
                p1 = p2;
            }

        if (maxD != -1) printf("%d,%d are closest, %d,%d are most distant.\n", C1, C2, D1, D2);
        else cout << "There are no adjacent primes." << endl;
    }

    return 0;
}