#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    int N;
    for (int M = 1; cin >> N; M++) {
        vi v;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        ll P = 1;
        bool pos = false;
        for (int i = 0; i < N; i++) {
            ll p = 1;
            for (int j = i; j < N; j++) {
                p *= v[j];
                P = max(P, p);
                pos |= p > 0;
            }
        }

        if (pos) printf("Case #%d: The maximum product is %lld.\n\n", M, P);
        else printf("Case #%d: The maximum product is 0.\n\n", M);
    }

    return 0;
}