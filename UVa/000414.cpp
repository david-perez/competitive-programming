#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int N;
    while (cin >> N && N != 0) {
        cin.get();
        vi v;
        string s;

        int minSpaces = 25;
        while (N--) {
            int spaces = 0;
            getline(cin, s);
            for (char &c : s)
                if (c == ' ') spaces++;

            v.push_back(spaces);
            minSpaces = min(minSpaces, spaces);
        }

        int ans = 0;
        for (int i : v)
            ans += (i - minSpaces);

        cout << ans << endl;
    }

    return 0;
}