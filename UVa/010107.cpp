#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
    vi v;
    int x;
    while (cin >> x) {
        v.push_back(x);
        sort(v.begin(), v.end());
        cout << (v.size() % 2 == 0 ? (v[v.size()/2 - 1] + v[v.size()/2]) / 2 : v[v.size()/2]) << endl;
    }

    return 0;
}
