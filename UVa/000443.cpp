#include <iostream>

using namespace std;

int main() {
    int humble[5842];
    int i2, i3, i5, i7;

    i2 = i3 = i5 = i7 = 0;
    humble[0] = 1;
    for (int i = 1; i < 5842; i++) {
        humble[i] = min(min(2*humble[i2], 3*humble[i3]), min(5*humble[i5], 7*humble[i7]));

        if (humble[i] == 2*humble[i2]) i2++;
        if (humble[i] == 3*humble[i3]) i3++;
        if (humble[i] == 5*humble[i5]) i5++;
        if (humble[i] == 7*humble[i7]) i7++;
    }

    string s[] = {"st", "nd", "rd"};
    int n;
    while (cin >> n && n != 0)
        printf("The %d%s humble number is %d.\n", n, (1 <= n % 10 && n % 10 <= 3 && !(11 <= n % 100 && n % 100 <= 13) ? s[n % 10 - 1].c_str() : "th"), humble[n-1]);

    return 0;
}