#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

int main() {
    int N, t = 1;
    while (cin >> N) {
        vi v;
        set<int> s;
        int x;
        cin >> x;
        bool b2 = 1 <= x;
        v.push_back(x);
        while (N-- > 1) {
            cin >> x;
            b2 &= (v[v.size()-1] < x);
            v.push_back(x);
            if (b2)
                for (int &y : v) {
                    if (s.count(x + y)) {
                        b2 = false;
                        break;
                    }
                    s.insert(x + y);
                }
        }

        printf("Case #%d: It is %sa B2-Sequence.\n\n", t++, b2 ? "" : "not ");
    }

    return 0;
}