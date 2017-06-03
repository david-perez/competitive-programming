#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

bitset<100000> bs; // 10^5
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

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        int cnt = 0;
        for (int i = 0; i < primes.size() && 2*primes[i] <= n; i++)
            for (int j = i; j < primes.size() && (primes[i] + primes[j] <= n); j++)
                if (primes[i] + primes[j] == n) cnt++;

        cout << cnt << endl;
    }

    return 0;
}
