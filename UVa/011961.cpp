#include <iostream>
#include <set>

using namespace std;

char d[4] = {'A', 'C', 'G', 'T'};
set<string> s;
int N, K;

void f(string &t, int k, int i) {
    if (k == K) {
        s.insert(t);
        return;
    }

    if (i == N) return;

    char c = t[i];
    for (int j = 0; j < 4; j++) {
        t[i] = d[j];
        f(t, k + 1, i + 1);
    }

    t[i] = c;
    f(t, k, i + 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        s.clear();
        string t;
        cin >> t;
        f(t, 0, 0);

        cout << s.size() << endl;
        for (const string &mutation : s)
            cout << mutation << endl;
    }
    
    return 0;
}
