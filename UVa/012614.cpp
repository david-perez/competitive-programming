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

int main() {
    int n;
    cin >> n;
    int cards; int a[100000];
    for (int i = 0; i < n; i++) {
        cin >> cards;
        for (int j = 0; j < cards; j++)
            cin >> a[j];
        sort(a, a+cards);
        cout << "Case " << i+1 << ": " << a[cards-1] << endl;
    }

    return 0;
}
