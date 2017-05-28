#include <iostream>
#include <set>;

using namespace std;

bool palinword(string &s) {
    set<string> st;
    for (int i = 1; i < s.length()-1; i++) {
        if (s[i-1] == s[i+1]) st.insert(s.substr(i-1, 3));
        int j = i+1;
        if (i < s.length()-2 && s[i] == s[j] && s[i-1] == s[j+1]) {
            string t = s.substr(i-1, 4);
            if (string(4, t[0]) == t) {
                if (st.count(string(3, t[0])) == 0) st.insert(t);
            } else st.insert(s.substr(i-1, 4));
        }
    }

    return st.size() >= 2;
}

int main() {
    string s;
    while (cin >> s)
        if (palinword(s))
            cout << s << endl;

    return 0;
}
