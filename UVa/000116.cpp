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
    int m, n; long min_weight;
    while (scanf("%d %d", &m, &n) == 2) {
        long matrix[m+2][n];
        for (int j = 0; j < n; j++) matrix[0][j] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        for (int j = 0; j < n; j++) matrix[m+1][j] = 0;
        
        matrix[0][n-1] = matrix[m][n-1];
        matrix[m+1][n-1] = matrix[1][n-1];
        int j = n-2;
        while (j >= 0) {
            for (int i = 1; i <= m; i++)
                matrix[i][j] = matrix[i][j] + min(matrix[i-1][j+1], min(matrix[i][j+1], matrix[i+1][j+1]));
            
            matrix[0][j] = matrix[m][j];
            matrix[m+1][j] = matrix[1][j];
            
            j--;
        }
        
        int min_ind = 1;
        for (int i = 1; i <= m; i++)
            min_ind = matrix[i][0] < matrix[min_ind][0] ? i : min_ind;
        
        cout << min_ind << (0 < n-1 ? ' ' : '\n');
        
        min_weight = matrix[min_ind][0];
        for (int j = 1; j <= n-1; j++) {
            if (min_ind == 1) {
                if (matrix[min_ind-1][j] < matrix[min_ind][j] && matrix[min_ind-1][j] < matrix[min_ind+1][j]) min_ind--;
                else if (matrix[min_ind+1][j] <= matrix[min_ind-1][j] && matrix[min_ind+1][j] < matrix[min_ind][j]) min_ind++;
            } else if (min_ind == m) {
                if (matrix[min_ind+1][j] <= matrix[min_ind-1][j] && matrix[min_ind+1][j] <= matrix[min_ind][j]) min_ind++;
                else if (matrix[min_ind-1][j] <= matrix[min_ind][j] && matrix[min_ind-1][j] <= matrix[min_ind][j]) min_ind--;
            } else {
                if (matrix[min_ind-1][j] <= matrix[min_ind][j] && matrix[min_ind-1][j] <= matrix[min_ind+1][j]) min_ind--;
                else if (matrix[min_ind+1][j] < matrix[min_ind-1][j] && matrix[min_ind+1][j] < matrix[min_ind][j]) min_ind++;
            }
            
            if (min_ind == 0) min_ind = m;
            else if (min_ind == m+1) min_ind = 1;
            
            cout << min_ind << (j < n-1 ? ' ' : '\n');
        }
        
        cout << min_weight << endl;
    }
    
    return 0;
}