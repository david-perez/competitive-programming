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

bool symmetric(long matrix[100][100], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != matrix[n-i-1][n-j-1])
                return false;
    return true;
}

int main() {
    int t, n;
    char b;
    long matrix[100][100];
    
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> b >> b >> n;
        
        bool ok = true;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] < 0)
                    ok = false;
            }
        
        cout << "Test #" << c << ": " << (ok && symmetric(matrix, n) ? "Symmetric." : "Non-symmetric.") << endl;
    }
    
    return 0;
}
