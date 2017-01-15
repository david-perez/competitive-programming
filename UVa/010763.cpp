#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n;
    while (cin >> n && n != 0) {
        multiset<ii> s;
        while (n--) {
            int u, v;
            cin >> u >> v;
            auto it = s.find(ii(v, u));
            if (it != s.end())
                s.erase(it);
            else
                s.insert(ii(u, v));
        }

        cout << (s.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}