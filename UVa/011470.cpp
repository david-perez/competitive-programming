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
    int matrix[10][10];
    int n, t = 1;
    
    cin >> n;
    while (n != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        
        vi sums;
        
        for (int k = 0; k <= n/2 - (n % 2 == 0 ? 1 : 0); k++) {
            int sum = 0;
            int side = n-2*k;
            
            for (int j = k; j < k+side; j++) sum += matrix[k][j]; // up horizontal
            for (int j = k; j < k+side; j++) sum += matrix[k+side-1][j]; // down horizontal
            
            for (int i = k; i < k+side; i++) sum += matrix[i][k]; // left vertical
            for (int i = k; i < k+side; i++) sum += matrix[i][k+side-1]; // right vertical
            
            // subtract corners
            sum -= matrix[k][k];
            sum -= matrix[k][k+side-1];
            sum -= matrix[k+side-1][k];
            sum -= matrix[k+side-1][k+side-1];
            
            if (k == n/2 && n % 2 != 0) sum = matrix[k][k]; // innermost cell in an odd dimension matrix
            
            sums.push_back(sum);
        }
        
        printf("Case %d: ", t);
        for (int i = 0; i < sums.size(); i++) {
            cout << sums[i];
            if (i != sums.size()-1) cout << ' ';
        }
        cout << endl;
            
        t++;
        cin >> n;
    }
    
    return 0;
}