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

int main() {
    double R, N;
    while (cin >> R >> N) {
        if (R == 0 || N == 1) {
            printf("%.10f %.10f %.10f\n", R, 0.0, 0.0);
            continue;
        }

        double x = PI / N;
        double r = R*(sin(x)) / (1+sin(x));
        double I = 2*N * ((R-r)*cos(x)*r*0.5 - (PI / 2 - x)*r*r*0.5);
        double E = PI*R*R - N*PI*r*r - I;
        printf("%.10f %.10f %.10f\n", r, I, E);
    }

    return 0;
}