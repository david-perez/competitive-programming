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

int main() {
    string days[6] = {"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};

    double d;
    while (cin >> d && d != -1) {
        double M, m, s;
        M = m = s = d;
        int iM, im;
        iM = im = 0;
        bool eM, em;
        eM = em = false;

        for (int i = 1; i <= 5; i++){
            cin >> d;
            s += d;
            if (d == M) eM = true;
            else if (d > M) {
                M = d;
                iM = i;
                eM = false;
            } else if (d == m) em = true;
            else if (d < m) {
                m = d;
                im = i;
                em = false;
            }
        }

        if (eM || em) {
            cout << "EMPATE" << endl;
            continue;
        }

        printf("%s %s %s\n", days[iM].c_str(), days[im].c_str(), (s / 6 < d ? "SI" : "NO"));
    }

    return 0;
}