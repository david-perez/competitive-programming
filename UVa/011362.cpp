#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> phones;
        int n;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            phones.push_back(s);
        }

        sort(phones.begin(), phones.end());

        bool consistent = true;
        for (int i = 0; i < phones.size() - 1; i++) {
            string p1 = phones[i];
            string p2 = phones[i+1];

            if (p2.find(p1) == 0) {
                consistent = false;
                break;
            }
        }

        cout << (consistent ? "YES" : "NO") << endl;
    }

    return 0;
}