#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0, j = 0;
        string c;
        while (i < s.length() && j < t.length())
            if (s[i] == t[j]) {
                c += s[i];
                i++, j++;
            } else if (s[i] < t[j]) i++;
            else j++;

        cout << c << endl;
    }

    return 0;
}