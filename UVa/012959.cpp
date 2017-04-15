#include <iostream>

using namespace std;

int main() {
    int J, R, pts[500];
    while (cin >> J >> R) {
        for (int i = 0; i < J; i++) pts[i] = 0;
        int m = 0, j = 0;
        while (R--)
            for (int i = 0; i < J; i++) {
                int x;
                cin >> x;
                pts[i] += x;
                if (pts[i] >= m) {
                    m = pts[i];
                    j = i;
                }
            }

        cout << j+1 << endl;
    }

    return 0;
}