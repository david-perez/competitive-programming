#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

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

bool isPrime(int N) { // only works for 0 <= N <= primes[primes.size()-1]^2
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

vi digits(int N) {
    vi d;
    while (N != 0) {
        d.push_back(N % 10);
        N /= 10;
    }
    return d;
}

bool isPalindrome(int N) {
    vi d = digits(N);
    for (int i = 0, j = d.size()-1; i <= j; i++, j--)
        if (d[i] != d[j])
            return false;
    return true;
}

int main() {
    sieve(1000000);

    int n;
    while (cin >> n) {
        cout << 2*n << endl;
        if (isPrime(n) && isPalindrome(n))
            break;
    }

    return 0;
}