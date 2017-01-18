#include <iostream>
#include <vector>
#include <map>
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

bool isPrime(ll N) { // only works for 0 <= N <= primes[primes.size()-1]^2
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main() {
    sieve(2000);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        map<char, int> m;
        string s;
        cin >> s;

        for (char &c : s)
            m[c]++;

        printf("Case %d: ", t);
        bool empty = true;
        for (auto &p : m)
            if (isPrime(p.second)) {
                empty = false;
                cout << p.first;
            }

        if (empty) cout << "empty";

        cout << endl;
    }

    return 0;
}