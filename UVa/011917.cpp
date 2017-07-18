#include <iostream>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        map<string, int> m;
        int n;
        cin >> n;
        while (n--) {
            string s;
            int x;
            cin >> s >> x;
            m[s] = x;
        }

        int D;
        cin >> D;
        string s;
        cin >> s;
        if (m.count(s) == 0 || D + 5 < m[s]) printf("Case %d: Do your own homework!\n", t);
        else if (m[s] <= D) printf("Case %d: Yesss\n", t);
        else printf("Case %d: Late\n", t);
    }

    return 0;
}
