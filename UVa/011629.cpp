#include <iostream>
#include <map>

using namespace std;

int main() {
    int p, g;
    cin >> p >> g;
    map<string, int> m;
    while (p--) {
        char s[100];
        int i, d;
        scanf("%s %d.%d", s, &i, &d);
        m[s] = i*10 + d;
    }

    for (int t = 1; t <= g; t++) {
        int cnt = 0;
        string s;
        while (cin >> s && !(s == "<" || s == "<=" || s == "=" || s == ">=" || s == ">"))
            if (s != "+") cnt += m[s];

        int res;
        cin >> res;
        res *= 10;
        bool c = (s == "<" && cnt < res) ||
                 (s == "<=" && cnt <= res) ||
                 (s == "=" && cnt == res) ||
                 (s == ">=" && cnt >= res) ||
                 (s == ">" && cnt > res);

        printf("Guess #%d was %scorrect.\n", t, c ? "" : "in");
    }

    return 0;
}
