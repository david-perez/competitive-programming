#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<1000000> bs; // 10^6
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

bool isPrime(ll N) { // only works for 0 <= N <= primes[primes.size()-1]^2
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int reverse(int n) {
    int ret = 0;
    while (n) {
        ret = ret*10 + n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    sieve(1000000);
    int N;
    while (cin >> N) {
        if (!isPrime(N)) printf("%d is not prime.\n", N);
        else if (N != reverse(N) && isPrime(reverse(N))) printf("%d is emirp.\n", N);
        else printf("%d is prime.\n", N);
    }

    return 0;
}