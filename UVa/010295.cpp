#include <iostream>
#include <map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    map<string, int> f;
    for (int i = 0; i < m; i++) {
        string s;
        int d;
        cin >> s >> d;
        f[s] = d;
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        string s;
        while (cin >> s && s != ".")
            sum += f[s];

        cout << sum << endl;
    }

    return 0;
}