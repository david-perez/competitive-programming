#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

bitset<101> bs;
vi primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (ll j = i*i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

map<int, int> primeFactors(int n) {
    map<int, int> m;
    for (int idx = 0, p = primes[idx]; p*p <= n; p = primes[++idx])
        while (n % p == 0) {
            m[p]++;
            n /= p;
        }
    if (n != 1) m[n]++;
    return m;
};

int main() {
    sieve();
    vector<map<int, int>> v(101, map<int, int>()), sols(101, map<int, int>());
    for (int i = 1; i <= 100; i++) v[i] = primeFactors(i);
    sols[2][2] = 1;
    for (int n = 3; n <= 100; n++) {
        sols[n] = sols[n-1];
        for (const auto &p : v[n]) sols[n][p.first] += p.second;
    }

    int N;
    while (cin >> N && N != 0) {
        printf("%3d! =", N);
        for (int i = 0; i < primes.size() && primes[i] <= sols[N].rbegin()->first; i++) {
            if (i > 0 && i % 15 == 0) cout << endl << "      ";
            printf("%3d", sols[N][primes[i]]);
        }
        cout << endl;
    }

    return 0;
}
