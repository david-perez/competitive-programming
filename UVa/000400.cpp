#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
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

int main() {
    int N;
    while (cin >> N) {
        int maxLength = 0;
        string s;
        vector<string> files;
        while (N--) {
            cin >> s;
            maxLength = max(maxLength, (int) s.size());
            files.push_back(s);
        }

        sort(files.begin(), files.end());

        int C = 62 / (maxLength + 2);
        int R = ceil((double) files.size() / C);
        vector<string> out(R);

        for (int f = 0, i = 0; f < files.size(); f++, i = (i+1) % R) {
            out[i].append(files[f]);
            for (int j = 0; j < maxLength + 2 - files[f].size(); j++) out[i].append((" "));
        }

        for (int i = 0; i < 60; i++) cout << '-';
        cout << endl;
        for (int i = 0; i < out.size(); i++) cout << out[i] << endl;
    }

    return 0;
}