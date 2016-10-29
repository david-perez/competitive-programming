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
    int K;
    cin >> K;
    for (int k = 1; k <= K; k++) {
        int N;
        cin >> N;

        set<int> friends[N];
        map<int, int> stamps; // number of ocurrences of each stamp

        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            for (int j = 0; j < M; j++) {
                int A;
                cin >> A;
                if (stamps.count(A) == 0)
                    stamps[A] = 1;
                else if (friends[i].count(A) == 0)
                    stamps[A]++;

                friends[i].insert(A);
            }
        }

        int unique = 0;
        for (auto &p : stamps)
            if (p.second == 1) unique++;

        printf("Case %d:", k);
        for (int i = 0; i < N; i++) {
            int share = 0;
            for (int s : friends[i])
                if (stamps[s] == 1)
                    share++;

            printf(" %.6f%%", (unique == 0 ? 100.0 / N : 100.0 * share / unique));
        }

        cout << endl;
    }

    return 0;
}