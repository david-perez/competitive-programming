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
    char colours[] = {'r', 'o', 'y', 'g', 'b'};

    string s;
    while (getline(cin, s) && s != "#") {
        vector<map<char, char>> m;
        do {
            stringstream ss(s);
            string token;
            map<char, char> city;
            while (getline(ss, token, ','))
                city[token[0]] = token[2];

            m.push_back(city);
        } while (getline(cin, s) && s[0] != 'e');

        int t = INT_MAX;
        int i = 0;
        for (int j = 0; j < m.size(); j++) {
            int c = 0;

            for (int k = 0; k < m.size(); k++)
                for (int l = 0; l < 5; l++)
                    if (m[j][colours[l]] != m[k][colours[l]]) c++;

            if (c < t) {
                t = c;
                i = j;
            }
        }

        cout << i+1 << endl;
    }

    return 0;
}