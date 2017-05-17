#include <iostream>

using namespace std;

int N, memo[1000][1000];
string s;

int len(int l, int r) {
    if (l == r) return 1;
    if (l+1 == r) {
        if (s[l] == s[r]) return 2;
        return 1;
    }

    if (memo[l][r] != 0) return memo[l][r];

    if (s[l] == s[r]) return memo[l][r] = 2 + len(l+1, r-1);
    return memo[l][r] = max(len(l+1, r), len(l, r-1));
}

int main() {
    int T;
    cin >> T; cin.get();
    while (T--) {
        getline(cin, s);
        N = s.length();

        if (N == 0) {
            cout << 0 << endl;
            continue;
        }

        for (int l = 0; l < N; l++)
            for (int r = l; r < N; r++)
                memo[l][r] = 0;
        
        cout << len(0, N-1) << endl;
    }
    
    return  0;
}
