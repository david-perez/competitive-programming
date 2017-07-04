#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vi v;
        v.push_back(n);
        bool boring = n < 2 || m <= 1;
        while (!boring && n != 1)
            if (n % m != 0) boring = true;
            else {
                n /= m;
                v.push_back(n);
            }

        if (boring) cout << "Boring!" << endl;
        else {
            cout << v[0];
            for (int i = 1; i < v.size(); i++) printf(" %d", v[i]);
            cout << endl;
        }
    }

    return 0;
}
