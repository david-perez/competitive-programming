#include <iostream>

using namespace std;

string s, t;

void f(int i) {
    if (i == s.length()) {
        cout << t << endl;
        return;
    }
    
    for (int j = 0; j <= t.length(); j++) {
        t = t.insert(j, 1, s[i]);
        f(i+1);
        t = t.erase(j, 1);
    }
}

int main() {
    bool b = false;
    while (cin >> s) {
        if (b) cout << endl;
        b = true;
        t = "";
        f(0);
    }
    
    return 0;
}
