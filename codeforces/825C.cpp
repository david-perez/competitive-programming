#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        double d = ceil((double) a[i] / 2);
        while (k < d) {
            cnt++;
            k *= 2;
        }

        k = max(k, a[i]);
    }

    cout << cnt << endl;

    return 0;
}
