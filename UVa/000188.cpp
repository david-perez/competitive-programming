#include <iostream>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;

int wordToInt(string &s) {
    int ret = 0;
    for (char &c : s)
        ret = ret * 32 + (c - 'a' + 1);

    return ret;
}

int main() {
    string s;
    while (getline(cin, s)) {
        cout << s << endl;

        stringstream ss(s);
        vi w;
        int m = INT_MAX;
        while (ss >> s) {
            int wi = wordToInt(s);
            m = min(m, wi);
            w.push_back(wi);
        }

        int nextC = m, n = w.size(), C;
        bool conflicts = true, mult = false;
        while (conflicts || !mult) {
            C = nextC;
            nextC++;
            conflicts = false, mult = false;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) {
                    mult |= C % w[i] == 0 || C % w[j] == 0;
                    if ((C / w[i]) % n == (C / w[j]) % n) {
                        conflicts = true;
                        nextC = max(nextC, min((C / w[i] + 1) * w[i], (C / w[j] + 1) * w[j]));
                    }
                }
        }

        cout << C << endl << endl;
    }

    return 0;
}