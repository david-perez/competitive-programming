#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        for (int i = s.length()-1; i >= 0; i--)
            if (isupper(s[s.length() - 1 - i]))
                cout << char(toupper(s[i]));
            else
                cout << char(tolower(s[i]));

        cout << endl;
    }

    return 0;
}