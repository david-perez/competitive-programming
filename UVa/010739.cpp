#include <iostream>

using namespace std;

string s;
int memo[1000][1000];

int f(int i, int j) {
    if (i >= j) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (s[i] == s[j]) return memo[i][j] = f(i+1, j-1);
    return memo[i][j] = 1 + min(f(i+1, j-1), min(f(i+1, j), f(i, j-1)));
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            for (int j = 0; j < s.length(); j++)
                memo[i][j] = -1;
        printf("Case %d: %d\n", t, f(0, s.length()-1));
    }

    return 0;
}
