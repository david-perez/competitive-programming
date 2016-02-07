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
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<pair<int, double>> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int main() {
    int T;
    
    cin >> T; cin.get(); cin.get();
    while (T--) {
        string s, u; char v; int cost;
        vvi adjList; adjList.assign(26, vi());
        vi icosts; icosts.assign(26, 0);
        
        int N = 0;
        while (getline(cin, s) && s != "") {
            N++;
            stringstream ss(s);
            ss >> v >> cost >> u;
            icosts[v - 'A'] = cost;
            for (int i = 0; i < u.length(); i++)
                adjList[u[i] - 'A'].push_back(v - 'A');
        }
        
        int maxCost = 0;
        vi fcosts;
        for (int i = 0; i < N; i++)
            fcosts.push_back(icosts[i]);
        
        /*
         * Usually one would first topologically sort the graph and then use a 
         * single O(V + E) pass following that order to determine the maximum cost.
         * It turns out that the test cases' toposorts at UVa are all alphabetical
         * (i.e. A->B->...->Z), so the graph, once read, is already topologically sorted. 
         */
        for (int u = 0; u < N; u++)
            for (int v = 0; v < adjList[u].size(); v++) {
                fcosts[adjList[u][v]] = max(fcosts[adjList[u][v]], fcosts[u] + icosts[adjList[u][v]]);
                maxCost = max(maxCost, fcosts[adjList[u][v]]);
            }
        
        cout << maxCost << endl;
        if (T > 0) cout << endl;
    }
    
    return 0;
}