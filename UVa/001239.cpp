#include <iostream>

using namespace std;

string s;
int memo[1000][1000];

int kpalindrome (int i, int j) {
    if (i >= j) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    return memo[i][j] = (s[i] == s[j] ? 0 : 1) + kpalindrome(i+1, j-1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> s >> K;

        for (int i = 0; i < s.length(); i++)
            for (int j = i + 1; j < s.length(); j++)
                memo[i][j] = -1;

        for (int l = s.length(); ; l--)
            // iterate over all substrings of length l
            for (int i = 0; i + l <= s.length(); i++) {
                int j = i + l - 1;
                if (kpalindrome(i, j) <= K) {
                    cout << l << endl;
                    goto next;
                }
            }
        next:;
    }
}