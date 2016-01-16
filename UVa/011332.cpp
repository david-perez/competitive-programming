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

long f(long n) {
    long sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10; 
    }
    
    return sum;
}

int main() {
    long n;
    
    cin >> n;
    while (n != 0) {
        while (n / 10 != 0) n = f(n);
        cout << n << endl;
        
        cin >> n;
    }
    
    return 0;
}