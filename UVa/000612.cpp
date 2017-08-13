#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int inv(string &s, int i, int j) {
    if (j <= i) return 0;

    int mid = (i + j) / 2;
    int invl = inv(s, i, mid);
    int invr = inv(s, mid+1, j);

    string t;
    int invm = 0;
    int u = i, v = mid+1;
    while (u <= mid && v <= j) {
        if (s[u] <= s[v]) t += s[u++];
        else {
            invm += mid - u + 1;
            t += s[v++];
        }
    }

    while (u <= mid) t += s[u++];
    while (v <= j) t += s[v++];

    for (int k = i; k <= j; k++) s[k] = t[k-i];
    
    return invl + invr + invm;
}

bool cmp(string s, string t) {
    return inv(s, 0, n-1) < inv(t, 0, n-1);
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int m;
        cin >> n >> m;
        vector<string> v;
        while (m--) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        stable_sort(v.begin(), v.end(), cmp);
        for (string &s : v) cout << s << endl;

        if (M > 0) cout << endl;
    }

    return 0;
}
