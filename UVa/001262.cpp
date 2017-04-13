#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    char g1[6][5], g2[6][5];
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        K--;

        for (int i = 0; i < 6; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; j++)
                g1[i][j] = s[j];
        }

        for (int i = 0; i < 6; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; j++)
                g2[i][j] = s[j];
        }

        vector<char> a[5];
        int k[5]; k[4] = 1;
        for (int j = 4; j >= 0; j--) {
            set<char> s1, s2;
            for (int i = 0; i < 6; i++) {
                s1.insert(g1[i][j]);
                s2.insert(g2[i][j]);
            }
            vector<char> v(5);
            auto it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
            v.resize(it - v.begin());
            a[j] = v;
            if (j < 4)
                k[j] = k[j+1] * a[j+1].size();
        }

        if (k[0] * a[0].size() < K+1) {
            cout << "NO" << endl;
            continue;
        }

        for (int j = 0; j < 5; j++) {
            cout << a[j][K / k[j]];
            K -= K / k[j] * k[j];
        }
        cout << endl;
    }

    return 0;
}