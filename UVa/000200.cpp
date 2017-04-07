#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(int u, vvi &adjList, vi &dfs_num, vi &topo) {
    dfs_num[u] = 1;
    for (int v = 0; v < adjList[u].size(); v++)
        if (dfs_num[adjList[u][v]] == 0)
            dfs(adjList[u][v], adjList, dfs_num, topo);
    topo.push_back(u); // read topo in reverse order
}

int main() {
    string s;
    while (cin >> s) {
        vvi adjList(26, vi());
        int root = s[0] - 'A';
        string t;
        while (cin >> t && t != "#") {
            int i = 0;
            while (i < s.length() && i < t.length() && s[i] == t[i]) i++;

            if (i < s.length()) // if i >= s.length(), then t is longer than s and no conclusion can be drawn.
                adjList[s[i] - 'A'].push_back(t[i] - 'A');

            s = t;
        }

        vi topo, dfs_num(26);
        dfs(root, adjList, dfs_num, topo);

        for (int i = topo.size()-1; i >= 0; i--)
            cout << char(topo[i] + 'A');
        cout << endl;
    }

    return 0;
}