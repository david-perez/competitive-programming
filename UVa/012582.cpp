#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

bitset<26> appeared;

void readTree(int u, vector<vi> &adjList) {
    appeared.set(u);
    char b;
    cin >> b;
    int v = b - 'A';
    while (u != v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        readTree(v, adjList);
        
        cin >> b;
        v = b - 'A';
    }
}

void print(const vector<vi> &adjList) {
    for (int u = 0; u < adjList.size(); u++) {
        cout << u << ": ";
        for (int v = 0; v < adjList[u].size(); v++)
            cout << adjList[u][v] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    int u; char b;
    for (int i = 1; i <= t; i++) {
        vector<vi> adjList;
        adjList.assign(26, vi());
        appeared.reset();
        
        cin >> b;
        u = b - 'A';
        readTree(u, adjList);
        //print(adjList);
        
        printf("Case %d\n", i);
        for (int u = 0; u < adjList.size(); u++) {
            if (!appeared[u]) continue;
            printf("%c = %d\n", u + 'A', adjList[u].size());
        }
    }

    return 0;
}