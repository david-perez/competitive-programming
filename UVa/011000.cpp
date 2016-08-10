#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <forward_list>
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
typedef unsigned long long ull;
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

#define INF 1000000000 // 10^9

string sols[] = {
        "0 1",
        "1 2",
        "2 4",
        "4 7",
        "7 12",
        "12 20",
        "20 33",
        "33 54",
        "54 88",
        "88 143",
        "143 232",
        "232 376",
        "376 609",
        "609 986",
        "986 1596",
        "1596 2583",
        "2583 4180",
        "4180 6764",
        "6764 10945",
        "10945 17710",
        "17710 28656",
        "28656 46367",
        "46367 75024",
        "75024 121392",
        "121392 196417",
        "196417 317810",
        "317810 514228",
        "514228 832039",
        "832039 1346268",
        "1346268 2178308",
        "2178308 3524577",
        "3524577 5702886",
        "5702886 9227464",
        "9227464 14930351",
        "14930351 24157816",
        "24157816 39088168",
        "39088168 63245985",
        "63245985 102334154",
        "102334154 165580140",
        "165580140 267914295",
        "267914295 433494436",
        "433494436 701408732",
        "701408732 1134903169",
        "1134903169 1836311902",
        "1836311902 2971215072",
        "2971215072 4807526975"
};

void precompute() {
    ll f = 1, m = 0;
    cout << m << ' ' << m + f << endl;
    for (int i = 1; i <= 45; i++) {
        ll m0 = m;
        m = m + f;
        f = m0 + 1;
        cout << m << ' ' << m + f << endl;
    }
}

int main() {
    int N;
    while (cin >> N && N != -1)
        cout << sols[N] << endl;

    return 0;
}