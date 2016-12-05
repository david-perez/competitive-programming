#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

div_t euc_div(int a, int d) {
    div_t divT = div(a, d);
    int I = divT.rem >= 0 ? 0 : (d > 0 ? 1 : -1);
    int qE = divT.quot - I;
    int rE = divT.rem + I * d;
    return div_t{qE, rE};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (b == 0) cout << "DIV0" << endl;
        else {
            div_t res = euc_div(a, b);
            printf("%d %d\n", res.quot, res.rem);
        }
    }
}