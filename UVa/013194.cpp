#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

bitset<1000000> bs; // 10^6
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

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], sum = 1;
    while (PF * PF <= N) {
        ll p = 1;
        while (N % PF == 0) {
            N /= PF;
            p *= PF;
        }
        if (p != 1) sum *= ((p * PF) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }

    if (N != 1) sum *= N + 1;
    return sum;
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll sum = sumDiv(n) - n;
        if (sum < n) cout << "deficient" << endl;
        else if (sum == n) cout << "perfect" << endl;
        else cout << "abundant" << endl;
    }
    
    return 0;
}
