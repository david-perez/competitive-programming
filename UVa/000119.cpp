#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    bool f = true;
    while (cin >> N) {
        if (!f) cout << endl;
        f = false;
        int adjMat[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adjMat[i][j] = 0;
        map<string, int> sti;
        string its[N];

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            sti[s] = i;
            its[i] = s;
        }

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            int u = sti[s], C, m;
            cin >> C >> m;
            if (m != 0) {
                int d = C / m;
                while (m--) {
                    string t;
                    cin >> t;
                    int v = sti[t];
                    adjMat[u][v] = d;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            int net = 0;
            for (int j = 0; j < N; j++) {
                net -= adjMat[i][j];
                net += adjMat[j][i];
            }
            printf("%s %d\n", its[i].c_str(), net);
        }
    }

    return 0;
}
