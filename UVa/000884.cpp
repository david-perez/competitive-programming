#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

bitset<1000001> bs; // 10^6
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

int numPF(ll N) {
    int PF_idx = 0, ans = 0;
    ll PF = primes[PF_idx];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            ans++;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) ans++; // N is prime
    return ans;
}

int main() {
    sieve();
    int sols[1000001];
    sols[2] = 1;
    for (int n = 2; n <= 1000000; n++)
        sols[n] = sols[n-1] + numPF(n);

    int n;
    while (cin >> n)
        cout << sols[n] << endl;
    
    return 0;
}
