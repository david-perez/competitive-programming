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
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    int T;
    int parties[100];
    
    cin >> T;
    while (T--) {
        int N, P;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; i++)
            cin >> parties[i];
        
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            if (i % 7 == 6 || i % 7 == 0) continue;
            for (int j = 0; j < P; j++)
                if (i % parties[j] == 0) {
                    sum++;
                    break;
                }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}