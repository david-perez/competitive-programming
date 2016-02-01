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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int main() {
    int C, S, b, T = 0;
    while (scanf("%d %d", &C, &S) == 2) {
        vi masses;
        int sum = 0;
        for (int i = 0; i < S; i++) {
            cin >> b;
            masses.push_back(b);
            sum += b;
        }
        
        for (int i = S+1; i <= 2*C; i++)
            masses.push_back(0);
        
        sort(masses.begin(), masses.end());
        
        double avg = (double) sum / C;
        double imbalance = 0;
        printf("Set #%d\n", ++T);
        for (int i = 0; i < C; i++) {
            printf(" %d:", i);
            if (masses[i] != 0) printf(" %d", masses[i]);
            if (masses[2*C-1-i] != 0) printf(" %d", masses[2*C-1-i]);
            cout << endl;
            imbalance += fabs(masses[i] + masses[2*C-1-i] - avg);
        }
        
        printf("IMBALANCE = %.5f\n\n", imbalance);
    }
   
    return 0;
}