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

// https://www.cambridge.org/core/journals/mathematical-gazette/article/8980-a-heron-type-formula-for-the-reciprocal-area-of-a-triangle/7570E2DA337B8A6339CB4DA3356204F4
int main() {
    int n;
    cin >> n;
    while (n != 0) {
        double ha, hb, hc;
        cin >> ha >> hb >> hc;
        double H = 0.5 * (1/ha + 1/hb + 1/hc);
        double T = H * (H - 1/ha) * (H - 1/hb) * (H - 1/hc);
        if (T > 0) printf("%.3f\n", 1 / (4 * sqrt(T)));
        else {
            n--;
            cout << "These are invalid inputs!" << endl;
        }
    }

    return 0;
}