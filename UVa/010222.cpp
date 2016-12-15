#include <iostream>

using namespace std;

int main() {
    string s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    char c;
    while (scanf("%c", &c) != EOF) {
        if (isalpha(c)) c = tolower(c);
        if (isspace(c)) cout << c;
        else cout << s[s.find(c) - 2];
    }
}