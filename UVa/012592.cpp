#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cin.get();
        map<string, string> m;
        for (int i = 0; i < n; i++) {
            string s, t;
            getline(cin, s);
            getline(cin, t);
            m[s] = t;
        }

        int Q;
        cin >> Q; cin.get();
        while (Q--) {
            string s;
            getline(cin, s);
            cout << m[s] << endl;
        }
    }

    return 0;
}
