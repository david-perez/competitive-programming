#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        vector<set<int>> u;
        for (int i = 0; i < 3; i++) {
            int S;
            cin >> S;
            set<int> s;
            for (int j = 0; j < S; j++) {
                int p;
                cin >> p;
                s.insert(p);
            }
            u.push_back(s);
        }

        vector<vector<int>> v;
        for (int i = 0; i < 3; i++) {
            set<int> X = u[i];
            set<int> Y = u[(i + 1) % 3];
            set<int> Z = u[(i + 2) % 3];

            vector<int> XdY(X.size());
            auto it = set_difference(X.begin(), X.end(), Y.begin(), Y.end(), XdY.begin());
            XdY.resize(it - XdY.begin());

            vector<int> XdYZ(XdY.size());
            it = set_difference(XdY.begin(), XdY.end(), Z.begin(), Z.end(), XdYZ.begin());
            XdYZ.resize(it - XdYZ.begin());

            v.push_back(XdYZ);
        }

        printf("Case #%d:\n", C);
        int M = max(v[0].size(), max(v[1].size(), v[2].size()));
        for (int i = 0; i < 3; i++)
            if (v[i].size() == M) {
                printf("%d %d", i+1, M);
                for (int j = 0; j < M; j++)
                    printf(" %d", v[i][j]);
                cout << endl;
            }
    }

    return 0;
}