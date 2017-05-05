#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;

bitset<1000000> bs; // 10^6
vector<ll> dprimes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (ll j = i * i; j < bs.size(); j += i) bs[j] = 0;
            ll k = i;
            int sum = 0;
            while (k) {
                sum += k % 10;
                k /= 10;
            }

            if (bs[sum]) dprimes.push_back(i);
        }
}

int main() {
    sieve();
    int N;
    cin >> N;
    while (N--) {
        int t1, t2;
        cin >> t1 >> t2;
        auto it1 = lower_bound(dprimes.begin(), dprimes.end(), t1);
        auto it2 = upper_bound(dprimes.begin(), dprimes.end(), t2);
        cout << distance(it1, it2) << endl;
    }
    
    return 0;
}
