#include <iostream>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        map<string, string> ctp;
        map<string, int> votes;
        int n;
        string c;
        cin >> n; getline(cin, c);
        while (n--) {
            string p;
            getline(cin, c);
            getline(cin, p);
            ctp[c] = p;
            votes[c] = 0;
        }

        int m, M = 0;
        cin >> m; getline(cin, c);
        string winner = "tie";
        while (m--) {
            getline(cin, c);
            if (votes.count(c) > 0) {
                votes[c]++;
                if (votes[c] > M) M = votes[c], winner = ctp[c];
                else if (votes[c] == M) winner = "tie";
            }
        }

        cout << winner << endl;
        if (T > 0) cout << endl;
    }

    return 0;
}
