#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000000> bs; // 10^7
vector<ll> primes;

void sieve(ll upperbound) { // finds primes in [0...upperbound]
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

vector<int> primeFactors(int N) {
    vector<int> factors;
    int PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N); // N is prime
    return factors;
}

vi digits(ll n) {
    vi ret;
    while (n != 0) {
        ret.push_back(n % 10);
        n /= 10;
    }
    return ret;
}

bool smith(int n) {
    vector<int> factors = primeFactors(n);
    if (factors.size() == 1) return false; // prime numbers are not smith numbers

    vi dig = digits(n);
    int A = 0;
    for (int &d : dig)
        A += d;

    int B = 0;
    for (int &f : factors)
        for (int &d : digits(f))
            B += d;

    return A == B;
}

int main() {
    sieve(100000); // 10^5

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int i = n+1;
        while (!smith(i))
            i++;

        cout << i << endl;
    }

    return 0;
}