#include <iostream>

using namespace std;

bool adjMat[26][26];

void floyd() {
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                adjMat[i][j] |= adjMat[i][k] && adjMat[k][j];
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                adjMat[i][j] = i == j;

        while (m--) {
            char x, y;
            cin >> x >> y;
            adjMat[x - 'a'][y - 'a'] = true;
        }

        floyd();

        while (n--) {
            string s, t;
            cin >> s >> t;
            bool ok = s.length() == t.length();
            if (ok) for (int k = 0; ok && k < s.length(); k++) ok &= adjMat[s[k] - 'a'][t[k] - 'a'];
            cout << (ok ? "yes" : "no") << endl;
        }
    }

    return 0;
}
