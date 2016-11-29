#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int A[1000][1000];

int main() {
    int tx, ty, mx, my;
    while (cin >> tx >> ty >> mx >> my && !(tx ==  0 && ty == 0 && mx == 0 && my == 0)) {
        for (int i = 0; i < ty; i++) {
            for (int j = 0; j < tx; j++) {
                char c;
                cin >> c;
                if (c == 'X') A[i][j] = 1;
                else A[i][j] = 0;
                if (i > 0) A[i][j] += A[i-1][j];
                if (j > 0) A[i][j] += A[i][j-1];
                if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }
        }

        vi v(max(8, mx*my+1), 0);
        for (int i0 = 0; i0 + my - 1 < ty; i0++) {
            int i1 = i0 + my - 1;
            for (int j0 = 0; j0 + mx - 1 < tx; j0++) {
                int j1 = j0 + mx - 1;
                int dead = A[i1][j1];
                if (i0 > 0) dead -= A[i0-1][j1];
                if (j0 > 0) dead -= A[i1][j0-1];
                if (i0 > 0 && j0 > 0) dead += A[i0-1][j0-1];
                v[dead]++;
            }
        }

        for (int i = 0; i < 7; i++)
            cout << v[i] << ' ';
        cout << v[7] << endl;
    }

    return 0;
}