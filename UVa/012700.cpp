#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        int B = 0, W = 0, tie = 0, A = 0;
        for (char &c : s) {
            if (c == 'B') B++;
            else if (c == 'W') W++;
            else if (c == 'T') tie++;
            else A++;
        }

        printf("Case %d: ", t);
        if (B > 0 && W == 0 && tie == 0) cout << "BANGLAWASH" << endl;
        else if (W > 0 && B == 0 && tie == 0) cout << "WHITEWASH" << endl;
        else if (A == N) cout << "ABANDONED" << endl;
        else if (B == W) printf("DRAW %d %d\n", B, tie);
        else if (B > W) printf("BANGLADESH %d - %d\n", B, W);
        else printf("WWW %d - %d\n", W, B);
    }

    return 0;
}