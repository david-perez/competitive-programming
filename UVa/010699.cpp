#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;

bitset<1000001> bs; // 10^6 + 1
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

set<ll> primeFactors(int N) {
    set<ll> factors;
    int PF_idx = 0; ll PF = primes[PF_idx];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            factors.insert(PF);
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.insert((ll) N); // N is prime
    return factors;
}

int main() {
    sieve();
    int N;
    while (cin >> N && N != 0)
        printf("%d : %d\n", N, primeFactors(N).size());

    return 0;
}