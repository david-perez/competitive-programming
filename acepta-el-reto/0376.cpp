#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vi v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        int p = 0;
        for (int i = 1; i <= n - 2; i++)
            if (v[i-1] < v[i] && v[i] > v[i+1])
                p++;

        if (v[0] > v[1] && v[n-1] < v[0])
            p++;

        if (v[n-1] > v[n-2] && v[n-1] > v[0])
            p++;

        cout << p << endl;
    }

    return 0;
}