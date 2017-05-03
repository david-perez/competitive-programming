#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n, m, cap, c[20];
    bitset<20> b;
    for (int t = 1; cin >> n >> m >> cap && !(n == 0 && m == 0 && cap == 0); t++) {
        b.reset();
        for (int i = 0; i < n; i++) cin >> c[i];
        int x = 0, M = 0;
        while (m--) {
            int i;
            cin >> i; i--;
            if (b[i]) {
                b[i] = 0;
                x -= c[i];
            } else {
                b[i] = 1;
                x += c[i];
                M = max(M, x);
            }
        }

        printf("Sequence %d\n", t);
        if (M > cap) cout << "Fuse was blown." << endl << endl;
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", M);
    }
    
    return 0;
}
