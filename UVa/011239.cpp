#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        string s;
        map<string, set<string>> m;
        set<string> st;
        getline(cin, s);
        while (!(s == "1" || s == "0")) {
            m[s];
            string t;
            while (getline(cin, t) && !(t == "1" || t == "0") && all_of(t.begin(), t.end(), [](char ch) { return islower(ch) || isdigit(ch); })) {
                if (m[s].count(t) == 0 && st.count(t) > 0)
                    for (auto &p : m) p.second.erase(t);
                else {
                    m[s].insert(t);
                    st.insert(t);
                }
            }
            s = t;
        }

        set<pair<int, string>> sol;
        for (auto &p : m) sol.insert(make_pair(-p.second.size(), p.first));

        for (auto &p : sol) printf("%s %d\n", p.second.c_str(), -p.first);
        if (s == "0") break;
    }

    return 0;
}
