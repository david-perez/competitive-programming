#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int d2, m2, y2, d1, m1, y1;
        scanf("%d/%d/%d", &d2, &m2, &y2);
        scanf("%d/%d/%d", &d1, &m1, &y1);

        printf("Case #%d: ", t);
        if (y1 > y2 || (y1 == y2 && m1 > m2) || y1 == y2 && m1 == m2 && d1 > d2) cout << "Invalid birth date" << endl;
        else {
            int s = y2 - y1;
            if (m2 < m1 || (m2 == m1 && d2 < d1)) s--;
            if (s > 130) cout << "Check birth date" << endl;
            else cout << s << endl;
        }
    }

    return 0;
}
