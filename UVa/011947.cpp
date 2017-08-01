#include <iostream>

using namespace std;

int dateToInt(int m, int d, int y) {
    return
            1461*(y+4800+(m-14)/12)/4+
            367*(m -2-(m-14)/12*12)/12-
            3*((y+4900+(m-14)/12)/100)/4+
            d-32075;
}

void intToDate(int jd, int &m, int &d, int &y) {
    int x, n, i, j;
    x=jd+68569; n=4*x/146097;
    x-=(146097*n+3)/4;
    i=(4000*(x+1))/1461001;
    x-=1461*i/4-31; j=80*x/2447;
    d=x-2447*j/80;
    x=j/11; m=j+2-12*x;
    y=100*(n-49)+i+x;
}

string zodiac(int m, int d) {
    if ((m == 1 && d >= 21) || (m == 2 && d <= 19)) return "aquarius";
    if ((m == 2 && d >= 20) || (m == 3 && d <= 20)) return "pisces";
    if ((m == 3 && d >= 21) || (m == 4 && d <= 20)) return "aries";
    if ((m == 4 && d >= 21) || (m == 5 && d <= 21)) return "taurus";
    if ((m == 5 && d >= 22) || (m == 6 && d <= 21)) return "gemini";
    if ((m == 6 && d >= 22) || (m == 7 && d <= 22)) return "cancer";
    if ((m == 7 && d >= 23) || (m == 8 && d <= 21)) return "leo";
    if ((m == 8 && d >= 22) || (m == 9 && d <= 23)) return "virgo";
    if ((m == 9 && d >= 24) || (m == 10 && d <= 23)) return "libra";
    if ((m == 10 && d >= 24) || (m == 11 && d <= 22)) return "scorpio";
    if ((m == 11 && d >= 23) || (m == 12 && d <= 22)) return "sagittarius";
    if ((m == 12 && d >= 23) || (m == 1 && d <= 20)) return "capricorn";
}

int main() {
    int N;
    cin >> N; cin.get();
    for (int n = 1; n <= N; n++) {
        string s;
        getline(cin, s);
        string sm{s[0], s[1]};
        int month = stoi(sm);
        string sd{s[2], s[3]};
        int day = stoi(sd);
        string sy{s[4], s[5], s[6], s[7]};
        int year = stoi(sy);

        intToDate(dateToInt(month, day, year) + 40*7, month, day, year);
        printf("%d %0.2d/%0.2d/%0.2d %s\n", n, month, day, year, zodiac(month, day).c_str());
    }

    return 0;
}
