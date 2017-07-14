#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vvi adjList(1000001, vi());
        for (int pos = 1; pos <= n; pos++) {
            int x;
            cin >> x;
            adjList[x].push_back(pos);
        }

        while (m--) {
            int k, v;
            cin >> k >> v;
            if (adjList[v].size() < k) cout << 0 << endl;
            else cout << adjList[v][k-1] << endl;
        }
    }

    return 0;
}
