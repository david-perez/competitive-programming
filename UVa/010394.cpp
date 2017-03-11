#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

bitset<20000001> bs; // 2*10^7 + 1
vector<ll> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < bs.size(); i++) if (bs[i]) {
        for (ll j = i * i; j < bs.size(); j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    sieve();
    vector<ii> twins;
    for (int i = 0; i < primes.size()-1; i++)
        if (primes[i+1] - primes[i] == 2)
            twins.push_back(ii(primes[i], primes[i+1]));

    int S;
    while (cin >> S)
        printf("(%d, %d)\n", twins[S-1].first, twins[S-1].second);

    return 0;
}