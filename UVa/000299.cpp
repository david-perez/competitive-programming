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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

/**
 * Sorts a vector in O(N^2).
 * @param v
 * @return the number of inversions in v, i.e. the number of "swaps" the algorithm performs.
 */
int bubbleSort(vi &v) {
    if (v.size() <= 1) return 0; // 0 > v.size() - 1 evaluates to false, avoiding edge case
    bool swapped;
    int swaps = 0, k = v.size() - 1, i, t, buff;
    do {
        swapped = false;
        for (i = 0; i < k; i++) {
            if (v[i+1] < v[i]) {
                swap(v[i], v[i+1]);
                swaps++;
                swapped = true;
                t = i;
            }
        }
        k = t;
    } while (swapped);
    return swaps;
}

int main() {
    int n, l, b;
    cin >> n;
    while (n--) {
        cin >> l;
        vi perm;
        for (int i = 0; i < l; i++) {
            cin >> b;
            perm.push_back(b);
        }
        printf("Optimal train swapping takes %d swaps.\n", bubbleSort(perm));
    }

    return 0;
}