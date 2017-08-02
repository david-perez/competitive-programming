#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int N;
    while (cin >> N) {
        vvi adjList(N, vi());
        vector<bool> awake(N, false);
        map<char, int> atv; // area -> vertex

        int M, V = 0;
        string s;
        cin >> M >> s;
        for (int i = 0; i < 3; i++) {
            if (atv.count(s[i]) == 0) atv[s[i]] = V++;
            awake[atv[s[i]]] = true;
        }

        while (M--) {
            cin >> s;
            if (atv.count(s[0]) == 0) atv[s[0]] = V++;
            if (atv.count(s[1]) == 0) atv[s[1]] = V++;
            adjList[atv[s[0]]].push_back(atv[s[1]]);
            adjList[atv[s[1]]].push_back(atv[s[0]]);
        }

        int years = -1, awake_cnt;
        bool done = false;
        while (!done) {
            years++;
            vi towake;
            awake_cnt = 0;
            for (int u = 0; u < N; u++)
                if (!awake[u]) {
                    int cnt = 0;
                    for (int j = 0; j < adjList[u].size(); j++) if (awake[adjList[u][j]]) cnt++;
                    if (cnt >= 3) towake.push_back(u);
                } else awake_cnt++;

            for (int u : towake) awake[u] = true;
            done = towake.empty();
        }

        if (awake_cnt == N) printf("WAKE UP IN, %d, YEARS\n", years);
        else cout << "THIS BRAIN NEVER WAKES UP" << endl;
    }

    return 0;
}
