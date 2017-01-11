#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vii v;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(ii(x, y));
        }

        sort(v.begin(), v.end());

        bool ok = true;
        for (int i = 1; i < n; i++) {
            ii q = v[i];
            ii p = v[i-1];

            // q ha gastado más que p
            if (q.first > p.first && q.second <= p.second) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "SI" : "NO") << endl;
    }

    return 0;
}