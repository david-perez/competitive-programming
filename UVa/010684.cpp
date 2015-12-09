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
    int N, max_so_far, max_to_here, b;
    cin >> N;
    while (N != 0) {
        max_so_far = 0;
        max_to_here = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> b;
            max_to_here += b;
            max_to_here = max(0, max_to_here);
            max_so_far = max(max_so_far, max_to_here);
        }
        
        if (max_so_far > 0) printf("The maximum winning streak is %d.\n", max_so_far);
        else printf("Losing streak.\n");
        
        cin >> N;
    }
    
    return 0;
}
