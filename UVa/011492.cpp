#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void dijkstra(int s, vector<vii> &adjList, vi &dist) {
    dist.assign(adjList.size(), INT_MAX);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq; pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < adjList[u].size(); j++) {
            ii v = adjList[u][j];
            if (dist[u] + v.first < dist[v.second]) {
                dist[v.second] = dist[u] + v.first;
                pq.push(ii(dist[v.second], v.second));
            }
        }
    }
}

int main() {
    int M;
    while (cin >> M && M != 0) {
        vector<vii> adjList(M+2, vii());
        map<string, int> wtv; // word -> vertex
        map<string, vector<string>> m; // language -> words
        int V = 1;
        string O, D;
        cin >> O >> D;

        for (int i = 0; i < M; i++) {
            string I1, I2, P;
            cin >> I1 >> I2 >> P;
            m[I1].push_back(P);
            m[I2].push_back(P);
            if (wtv.count(P) == 0) wtv[P] = V++;
        }

        for (auto &p : m) {
            vector<string> words = p.second;
            for (int i = 0; i < words.size(); i++)
                for (int j = i+1; j < words.size(); j++) {
                    if (words[i][0] == words[j][0]) continue;
                    int u = wtv[words[i]], v = wtv[words[j]];
                    adjList[u].push_back(ii(words[i].length(), v));
                    adjList[v].push_back(ii(words[j].length(), u));
                }
        }

        for (string word : m[O]) adjList[0].push_back(ii(0, wtv[word]));
        for (string word : m[D]) adjList[wtv[word]].push_back(ii(word.length(), M+1));

        vi dist(M+2, INT_MAX);
        dijkstra(0, adjList, dist);
        if (dist[M+1] == INT_MAX) cout << "impossivel" << endl;
        else cout << dist[M+1] << endl;
    }

    return 0;
}
