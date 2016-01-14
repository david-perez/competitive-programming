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
    int n;
    
    cout << "PERFECTION OUTPUT" << endl;
    
    cin >> n;
    while (n != 0) {
        int s = (n == 1 ? 0 : 1); // 1 is deficient because 1 is not a proper divisor of 1
        for (int i = 2; i < sqrt(n); i++) // O(sqrt(n))
            if (n % i == 0) {
                s += i;
                s += n / i;
            }
        
        printf("%*d  ", 5, n);
        if (s == n) cout << "PERFECT" << endl;
        else if (s < n) cout << "DEFICIENT" << endl;
        else cout << "ABUNDANT" << endl;
        
        cin >> n;
    }
    
    cout << "END OF OUTPUT" << endl;
    
    return 0;
}