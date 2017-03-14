#include <iostream>

using namespace std;

int p[9];

void printTerm(int i, bool first) {
    if (first) {
        if (p[i] < 0) printf("-");
    } else printf(" %c ", (p[i] < 0 ? '-' : '+'));

    p[i] = abs(p[i]);
    if (i == 1) { // x term
        if (p[i] == 1) printf("x");
        else printf("%dx", p[i]);
    } else if (i == 0) // constant term
        printf("%d", p[i]);
    else {
        if (p[i] == 1) printf("x^%d", i);
        else printf("%dx^%d", p[i], i);
    }
}

int main() {
    while (cin >> p[8]) {
        for (int i = 7; i >= 0; i--)
            cin >> p[i];

        // find first term
        int i = 8;
        while (i >= 0 && p[i] == 0) i--;

        if (i < 0) { // polynomial is the constant zero
            cout << 0 << endl;
            continue;
        }

        // print first term
        printTerm(i, true);

        // find the last term
        int j = 0;
        while (p[j] == 0) j++;

        if (i == j) { // only one term
            cout << endl;
            continue;
        }

        // print the rest of the terms
        for (int k = i-1; k >= j; k--)
            if (p[k] != 0)
                printTerm(k, false);

        cout << endl;
    }

    return 0;
}