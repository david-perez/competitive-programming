#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000 // 10^9

int N;
int adjMat[22][22];

void floyd() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
}

int main() {
    for (int t = 1; cin >> N && N != 0; t++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (i == j) adjMat[i][j] = 0;
                else adjMat[i][j] = INF;
            }

        int M;
        cin >> M;

        vector<string> names;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            names.push_back(s);
        }

        while (M--) {
            int i, j, k;
            cin >> i >> j >> k;
            i--, j--;
            adjMat[i][j] = k;
            adjMat[j][i] = k;
        }

        floyd();

        int m = INF;
        int ind = -1;
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int i = 0; i < N; i++)
                s += adjMat[i][j];

            if (s < m) {
                m = s;
                ind = j;
            }
        }

        printf("Case #%d : %s\n", t, names[ind].c_str());
    }

    return 0;
}