#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int N;
    for (int t = 1; cin >> N && N != -1; t++) {
        vii intervals;
        while (N--) {
            int a, b;
            cin >> a >> b;
            intervals.push_back(ii(a, -1));
            intervals.push_back(ii(b, +1));
        }

        sort(intervals.begin(), intervals.end());

        int enforcers = 0, maxEnforcers = 0;
        for (ii &p : intervals) {
            enforcers -= p.second;
            maxEnforcers = max(maxEnforcers, enforcers);
        }

        printf("Case %d: %d\n", t, maxEnforcers);
    }

    return 0;
}