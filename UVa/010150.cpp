#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool doublets(string &s, string &t) {
    if (s.length() != t.length()) return false;
    int diff = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != t[i]) {
            if (diff >= 1) return false;
            diff++;
        }

    return true;
}

void bfs(int s, int t, vvi &adjList, vi &d, vi &pi) {
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (d[t] == -1 && !q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                pi[v] = u;
                q.push(v);
            }
        }
    }
}

void printPath(int v, int u, vi &pi, vector<string> &words) {
    if (u == v) cout << words[u] << endl;
    else {
        printPath(pi[v], u, pi, words);
        cout << words[v] << endl;
    }
}

int main() {
    map<string, int> dict;
    vector<string> words;
    string s;
    int V = 0;
    while (getline (cin, s) && !s.empty()) {
        words.push_back(s);
        dict[s] = V++;
    }

    vvi adjList(V, vi());
    for (int u = 0; u < words.size(); u++)
        for (int v = u+1; v < words.size(); v++)
            if (doublets(words[u], words[v])) {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }

    string t;
    bool nl = false;
    while (cin >> s >> t) {
        if (nl) cout << endl;
        nl = true;

        int u = dict[s], v = dict[t];
        vi d(V, -1), pi(V, -1);
        bfs(u, v, adjList, d, pi);
        if (d[v] != -1) printPath(v, u, pi, words);
        else cout << "No solution." << endl;
    }

    return 0;
}
