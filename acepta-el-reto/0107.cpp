#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<100000> bs; // 10^5
vi primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (ll j = (ll) i * i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main() {
    double delta[6] = {1, .1, .01, .001, .0001, .00001};
    sieve();
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        if (n == 1) {
            cout << "Menor" << endl;
            continue;
        }

        int pi = distance(primes.begin(), upper_bound(primes.begin(), primes.end(), n));
        double error = abs((double) pi / n - (double) 1 / log(n));

        if (error < delta[m]) cout << "Menor" << endl;
        else if (error == delta[m]) cout << "Igual" << endl;
        else cout << "Mayor" << endl;
    }

    return 0;
}