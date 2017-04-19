#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void precompute() {
    for (ll z = 1; z <= 65535; z++) {
        string s = to_string(z*z);
        for (int i = 0; i < s.length(); i++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            ll x = s1.empty() ? 0 : stol(s1), y = stol(s2);
            if (y != 0 && z == x + y)
                cout << z << endl;
        }
    }
}

int main() {
    // precompute();

    vi v;
    v.push_back(1);
    v.push_back(9);
    v.push_back(45);
    v.push_back(55);
    v.push_back(99);
    v.push_back(297);
    v.push_back(703);
    v.push_back(999);
    v.push_back(2223);
    v.push_back(2728);
    v.push_back(4879);
    v.push_back(4950);
    v.push_back(5050);
    v.push_back(5292);
    v.push_back(7272);
    v.push_back(7777);
    v.push_back(9999);
    v.push_back(17344);
    v.push_back(22222);
    v.push_back(38962);

    int n;
    while (cin >> n && n != 0)
        cout << (binary_search(v.begin(), v.end(), n) ? "SI" : "NO") << endl;

    return 0;
}
