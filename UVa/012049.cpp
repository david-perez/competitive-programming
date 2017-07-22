#include <iostream>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        map<int, int> m;
        while (N--) {
            int x;
            cin >> x;
            m[x]++;
        }

        int cnt = 0;
        while (M--) {
            int x;
            cin >> x;

            if (m.count(x) == 0 || m[x] == 0) cnt++;
            else m[x]--;
        }

        for (const auto &p: m)
            if (p.second > 0) cnt += p.second;

        cout << cnt << endl;
    }

    return 0;
}
