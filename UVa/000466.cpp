#include <iostream>

using namespace std;

int n;
char a[10][10], b[10][10];

bool equal() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

void rotate90cw() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(a[i][j], a[j][i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n/2; j++)
            swap(a[i][j], a[i][n - 1 - j]);
}

void reflectv() {
    for (int i = 0; i < n/2; i++)
        for (int j = 0; j < n; j++)
            swap(a[i][j], a[n - 1 - i][j]);
}

int main() {
    for (int t = 1; cin >> n; t++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2*n; j++)
                if (j < n) cin >> a[i][j];
                else cin >> b[i][j-n];

        if (equal()) {
            printf("Pattern %d was preserved.\n", t);
            continue;
        }

        bool done = false;

        rotate90cw();
        for (int deg = 90; deg <= 270; deg += 90, rotate90cw())
            if (equal()) {
                done = true;
                printf("Pattern %d was rotated %d degrees.\n", t, deg);
                break;
            }
        if (done) continue;

        reflectv();
        if (equal()) {
            printf("Pattern %d was reflected vertically.\n", t);
            continue;
        }

        for (int deg = 90; deg <= 270; deg += 90) {
            rotate90cw();
            if (equal()) {
                done = true;
                printf("Pattern %d was reflected vertically and rotated %d degrees.\n", t, deg);
                break;
            }
        }
        if (done) continue;

        printf("Pattern %d was improperly transformed.\n", t);
    }

    return 0;
}
