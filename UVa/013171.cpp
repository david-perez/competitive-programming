#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, y, c;
        string s;
        cin >> m >> y >> c >> s;

        for (char &ch : s) {
            if (ch == 'M') m--;
            else if (ch == 'Y') y--;
            else if (ch == 'C') c--;
            else if (ch == 'R') y--, m--;
            else if (ch == 'B') y--, m--, c--;
            else if (ch == 'G') y--, c--;
            else if (ch == 'V') m--, c--;

            if (m < 0 || y < 0 || c < 0) break;
        }

        if (m < 0 || y < 0 || c < 0) cout << "NO" << endl;
        else printf("YES %d %d %d\n", m, y, c);
    }

    return 0;
}