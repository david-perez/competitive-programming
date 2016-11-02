#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <forward_list>
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
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

#define INF 1000000000 // 10^9
#define PI acos(-1)
#define EPS 1e-9

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, D;
        cin >> N >> D;

        vi v;
        v.push_back(0);
        for (int i = 0; i < N; i++) {
            char S;
            int M;
            cin >> S; cin.ignore(); cin >> M;
            v.push_back(M);
            if (S == 'B')
                v.push_back(M);
        }
        v.push_back(D);

        int maxx = 0;
        for (int i = 2;i < v.size(); i += 2)
            maxx = max(maxx, v[i] - v[i-2]);

        for (int i = 3; i < v.size(); i += 2)
            maxx = max(maxx, v[i] - v[i-2]);

        printf("Case %d: %d\n", t, maxx);
    }
}