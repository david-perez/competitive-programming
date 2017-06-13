#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    string s;
    while (cin >> s) {
        string t = s;
        sort(s.begin(), s.end(), greater<char>());
        sort(t.begin(), t.end());

        int z = 0;
        for (int i = 0; i < t.length() && t[i] == '0'; t.erase(i, 1), z++);

        ll a = stoll(s), b;
        if (t.empty()) b = 0;
        else {
            t.insert(1, z, '0');
            b = stoll(t);
        }

        printf("%lld - %lld = %lld = 9 * %lld\n", a, b, a - b, (a - b) / 9);
    }

    return 0;
}
