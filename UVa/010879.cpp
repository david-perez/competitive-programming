#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000000> bs; // 10^7
vi primes;

void sieve(ll upperbound) { // finds primes in [0...upperbound]
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

vi get3factors(int N) {
    vi factors;
    int PF_idx = 0, PF = primes[PF_idx];
    while (true) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
            if (factors.size() == 2) {
                factors.push_back(N);
                return factors;
            }
        }
        PF = primes[++PF_idx];
    }
}

int main() {
    sieve(10000000); // overkill but much more efficient than trial division when K is product of 3 large primes.
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        int K;
        cin >> K;

        vi factors = get3factors(K);
        int x = factors[0], y = factors[1], z = factors[2];
        printf("Case #%d: %d = %d * %d = %d * %d\n", t, K, x, y*z, x*y, z);
    }

    return 0;
}