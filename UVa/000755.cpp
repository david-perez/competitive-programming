#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    string r = "2223334445556667Q77888999";
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<string> s;
        map<string, int> dup;
        while (n--) {
            string t;
            cin >> t;
            for (int i = 0; i < t.length(); i++) {
                if (isdigit(t[i])) continue;
                if (t[i] == '-') { t.erase(i, 1); i--; }
                else t[i] = r[t[i] - 'A'];
            }
            if (t[3] != '-') t.insert(3, "-");

            if (s.count(t) > 0) dup[t]++;
            else s.insert(t);
        }

        if (dup.empty()) cout << "No duplicates." << endl;
        else for (auto &p : dup) printf("%s %d\n", p.first.c_str(), 1 + p.second);

        if (T > 0) cout << endl;
    }

    return 0;
}
