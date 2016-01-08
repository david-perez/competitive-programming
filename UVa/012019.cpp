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
#include <ctime>

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

string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    int t, m, d;
    cin >> t;
    
    while (t--) {
        cin >> m >> d;
        tm time_in = {0, 0, 0, d, m-1, 2011-1900};
        
        time_t time_temp = mktime(&time_in);
        tm const *time_out = localtime(&time_temp);
        
        if (time_out ->tm_wday == 0) cout << "Sunday" << endl;
        else cout << days[(time_out->tm_wday)-1] << endl;
    }

    return 0;
}