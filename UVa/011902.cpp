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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int adjMatrix[100][100];
int reachable[100];
int reachable_without_v[100];
int sol[100][100];
int n;
int dfs_num[100]; // visited nodes

void dfs(int u) {
    reachable[u] = 1;
    dfs_num[u] = 1;
    for (int j = 0; j < n; j++) {
        if (adjMatrix[u][j] == 1 && dfs_num[j] == 0) dfs(j);
    }
}

void dfs_mod(int u, const int &v) { // will not go through vertex v
    dfs_num[u] = 1;
    if (u == v) return;
    reachable_without_v[u] = 1;
    for (int j = 0; j < n; j++) {
        if (adjMatrix[u][j] == 1 && dfs_num[j] == 0) dfs_mod(j, v);
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int k = 0; k < t; k++) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            dfs_num[i] = 0;
            reachable[i] = 0; // candidates that can be dominated
            for (int j = 0; j < n; j++) cin >> adjMatrix[i][j];
        }
        
        dfs(0);
        for (int v = 0; v < n; v++) {
            for (int j = 0; j < n; j++) { // clean
                reachable_without_v[j] = 0;
                dfs_num[j] = 0;
            }
            
            dfs_mod(0, v);
            // reachable nodes that are not reachable without v are dominated by v
            for (int j = 0; j < n; j++) sol[v][j] = reachable[j] ^ reachable_without_v[j];
        }
        
        // print solution
        printf("Case %i:\n", k + 1);
        cout << '+';
        for (int j = 0; j < 2*n - 1; j++) cout << '-';
        cout << '+' << endl;
        for (int i = 0; i < n; i++) {
            cout << '|';
            for (int j = 0; j < n; j++) {
                cout << (sol[i][j] == 1 ? 'Y' : 'N');
                cout << '|';
            }
            cout << endl;
            cout << '+';
            for (int j = 0; j < 2*n - 1; j++) cout << '-';
            cout << '+' << endl;
        }
    }   
    
    return 0;
}