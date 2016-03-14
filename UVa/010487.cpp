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
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

int main() {
    int t = 1;
    int n;
    while (cin >> n && n != 0) {
        vi nums;
        while (n--) {
            int x; cin >> x;
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end());
        int m; cin >> m;
        printf("Case %d:\n", t++);
        while (m--) {
            int q; cin >> q;
            int closestSum = nums[0] + nums[1];
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i+1; j < nums.size(); j++) {
                    int sum = nums[i] + nums[j];
                    if (abs(sum - q) < abs(closestSum - q))
                        closestSum = sum;
                    if (sum > q) break;
                }
                if (nums[i] > q) break;
            }

            printf("Closest sum to %d is %d.\n", q, closestSum);
        }
    }

    return 0;
}