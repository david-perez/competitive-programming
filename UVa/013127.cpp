#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>

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
    int N, M, B, P;
    while (cin >> N >> M >> B >> P) {
        vector<vii> adjList(N+1, vii());
        while (M--) {
            int U, V, T;
            cin >> U >> V >> T;
            adjList[U].push_back(ii(T, V));
            adjList[V].push_back(ii(T, U));
        }

        vi banks;
        while (B--) {
            int b;
            cin >> b;
            banks.push_back(b);
        }

        while (P--) {
            int p;
            cin >> p;
            adjList[N].push_back(ii(0, p)); // connect artificial vertex unidirectionally to every police station
        }

        vi dist;
        dijkstra(N, adjList, dist);

        set<int> furthestBanks;
        int E = -1;
        for (int &b : banks) {
            if (dist[b] > E) {
                furthestBanks.clear();
                furthestBanks.insert(b);
                E = dist[b];
            } else if (dist[b] == E)
                furthestBanks.insert(b);
        }

        int S = furthestBanks.size();
        if (E == INT_MAX) // unreachable banks
            printf("%d *\n", S);
        else
            printf("%d %d\n", S, E);

        cout << *(furthestBanks.begin());
        for (auto it = ++furthestBanks.begin(); it != furthestBanks.end(); ++it)
            printf(" %d", *it);
        cout << endl;
    }

    return 0;
}