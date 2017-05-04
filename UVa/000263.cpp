#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll u;
    while (cin >> u && u != 0) {
        set<ll> s;
        int n = 0;
        printf("Original number was %lld\n", u);
        while (s.count(u) == 0)  {
            s.insert(u);
            string t2 = to_string(u);
            sort(t2.begin(), t2.end());
            string t1 = t2;
            reverse(t1.begin(), t1.end());
            ll t2n = stoll(t2), t1n = stoll(t1);
            u = t1n - t2n;
            printf("%lld - %lld = %lld\n", t1n, t2n, u);
            n++;
        }
        printf("Chain length %d\n\n", n);
    }
    
    return 0;
}
