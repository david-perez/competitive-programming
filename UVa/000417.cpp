#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<string, int> m;

void preprocess() {
    queue<string> q;
    for (char c = 'a'; c <= 'z'; c++)
        q.push(string(1, c));

    int cnt = 1;
    while (!q.empty()) {
        string s = q.front();
        q.pop();

        m[s] = cnt++;
        if (s.length() < 5)
            for (char c = s[s.length()-1] + 1; c <= 'z'; c++)
                q.push(s + c);
    }
}

int main() {
    preprocess();

    string s;
    while (cin >> s) {
        auto it = m.find(s);
        if (it != m.end())
            cout << (*it).second << endl;
        else cout << 0 << endl;
    }
}