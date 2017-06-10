#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> m;
    string t;
    int M = 0;
    while (cin >> t) {
        int l = 1;
        for (int i = 0; i <= t.size(); i++)
            for (char c = 'a'; c <= 'z'; c++) {
                string s = t;
                s.insert(i, 1, c);
                if (s > t) break;
                if (m.count(s) > 0) l = max(l, m[s] + 1);
            }

        for (int i = 0; i < t.size(); i++) {
            string s = t;
            s.erase(i, 1);
            if (s < t && m.count(s) > 0) l = max(l, m[s] + 1);
        }

        for (int i = 0; i < t.size(); i++)
            for (char c = 'a'; c <= 'z'; c++) {
                if (t[i] == c) continue;
                string s = t;
                s[i] = c;
                if (s > t) break;
                if (m.count(s) > 0) l = max(l, m[s] + 1);
            }

        m[t] = l;
        M = max(M, l);
    };

    printf("%d\n", M);

    return 0;
}
