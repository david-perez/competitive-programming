#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, d, r;
    while (cin >> n >> d >> r && !(n == 0 && d == 0 && r == 0)) {
        int m[n], e[n];
        for (int i = 0; i < n; i++) cin >> m[i];
        for (int i = 0; i < n; i++) cin >> e[i];

        sort(m, m + n, greater<int>());
        sort(e, e + n);
        int over = 0;
        for (int i = 0; i < n; i++) over += max(0, m[i] + e[i] - d);

        cout << over * r << endl;
    }
    
    return 0;
}
