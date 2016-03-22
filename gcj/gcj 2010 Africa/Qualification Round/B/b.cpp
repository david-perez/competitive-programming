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
    int N;
    cin >> N; cin.get();
    for (int t = 1; t <= N; t++) {
        printf("Case #%d: ", t);
        stack<string> words;
        string line; getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word)
            words.push(word);
        while (words.size() > 1) {
            printf("%s ", words.top().c_str());
            words.pop();
        }
        cout << words.top() << endl;
    }

    return 0;
}