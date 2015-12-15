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

int main() {
    vi a; int b;
    while (cin >> b)
        a.push_back(b);
    
    vi L, L_id, P;
    L.assign(a.size(), 0);
    L_id.assign(a.size(), 0);
    P.assign(a.size(), -1);
    
    int lis_len = 0, lis_end = 0;
    for (int i = 0; i < a.size(); i++) {
        int pos = lower_bound(L.begin(), L.begin()+lis_len, a[i]) - L.begin();
        L[pos] = a[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos-1] : -1;
        if (pos == lis_len) {
            lis_len++;
            lis_end = i;
        }
    }
    
    cout << lis_len << endl << '-' << endl;
    
    stack<int> s;
    int x = lis_end;
    for (; P[x] >= 0; x = P[x]) s.push(a[x]);
    cout << a[x] << endl;
    for (; !s.empty(); s.pop()) cout << s.top() << endl;
    
    return 0;
}