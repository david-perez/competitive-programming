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
    int grid[100][100];
    int N, b;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (i > 0) grid[i][j] += grid[i-1][j];
            if (j > 0) grid[i][j] += grid[i][j-1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
        }
    
    int maxSum = -127*100*100;
    for (int i0 = 0; i0 < N; i0++)
        for (int j0 = 0; j0 < N; j0++)
            for (int i1 = i0; i1 < N; i1++)
                for (int j1 = j0; j1 < N; j1++) {
                    int sum = grid[i1][j1];
                    if (i0 > 0) sum -= grid[i0-1][j1];
                    if (j0 > 0) sum -= grid[i1][j0-1];
                    if (i0 > 0 && j0 > 0) sum += grid[i0-1][j0-1];
                    maxSum = max(maxSum, sum);
                }
    
    cout << maxSum << endl;
    
    return 0;
}