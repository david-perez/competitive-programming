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

const int size = 15;

int main() {
    freopen("0018.txt", "r", stdin);
    int triangle[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    
    for (int i = size-2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);   
    
    cout << triangle[0][0] << endl;
    
    return 0;
}