#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;

bitset<10001> bs;
vi primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < bs.size(); i++) if (bs[i]) {
        for (int j = i * i; j < bs.size(); j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        int cnt = 0;
        for (auto it = primes.begin(); it != primes.end() && *it <= n; ++it) {
            int sum = 0;
            for (auto i = it; i != primes.end() && sum < n; ++i)
                sum += *i;
            if (sum == n) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}