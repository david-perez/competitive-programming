#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string S;
        cin >> S;
        ll B = 0, p = 1;
        for (int i = S.length()-1; i >= 0; i--) {
            if (S[i] == 'C') B += p;
            else if (S[i] == 'G') B += 2*p;
            else if (S[i] == 'T') B += 3*p;
            p *= 4;
        }

        printf("Case %d: (%lu:%lld)\n", t, S.length(), B);
    }

    return 0;
}
