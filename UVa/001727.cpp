#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        int mdays = 31, wday;

        if (s1 == "APR" || s1 == "JUN" || s1 == "SEP" || s1 == "NOV") mdays = 30;
        else if (s1 == "FEB") mdays = 28;

        if (s2 == "SUN") wday = 0;
        else if (s2 == "MON") wday = 1;
        else if (s2 == "TUE") wday = 2;
        else if (s2 == "WED") wday = 3;
        else if (s2 == "THU") wday = 4;
        else if (s2 == "FRI") wday = 5;
        else if (s2 == "SAT") wday = 6;

        int wkendays = 0;
        for (int i = 1; i <= mdays; i++, wday = (wday + 1) % 7)
            if (wday == 5 || wday == 6) wkendays++;

        cout << wkendays << endl;
    }

    return 0;
}