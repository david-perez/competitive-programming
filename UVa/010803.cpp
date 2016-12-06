#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define INF 1000000000 // -10^9

int n;
double adjMat[100][100];

void floyd() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

double dist(ii p1, ii p2) {
    int dy = p2.second - p1.second;
    int dx = p2.first - p1.first;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        cin >> n;
        vii towns;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            towns.push_back(ii(x, y));
            for (int j = 0; j < towns.size(); j++) {
                ii p1(x, y);
                ii p2(towns[j].first, towns[j].second);
                double d = dist(p1, p2);
                if (d > 10) d = INF;
                adjMat[i][j] = d;
                adjMat[j][i] = d;
            }
        }

        floyd();

        double M = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                M = max(M, adjMat[i][j]);

        printf("Case #%d:\n", t);
        if (M == INF) cout << "Send Kurdy" << endl << endl;
        else printf("%.4f\n\n", M);
    }

    return 0;
}