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

struct sort_pred {
    bool operator() (const ii &left, const ii &right) {
        return left.first != right.first ? left.first > right.first : left.second < right.second;
    }
};

int main() {
    vii alphabet; alphabet.assign(26, ii(0,0));
    int n;
    string s;
    cin >> n; cin.get();
    while (n--) {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(s[i])) continue;
            alphabet[toupper(s[i])-'A'].first++;
            alphabet[toupper(s[i])-'A'].second = toupper(s[i])-'A';
        }
    }
    
    sort(alphabet.begin(), alphabet.end(), sort_pred());
    
    for (int i = 0; i < alphabet.size() && alphabet[i].first > 0; i++)
        printf("%c %d\n", alphabet[i].second+'A', alphabet[i].first);
    
    return 0;
}