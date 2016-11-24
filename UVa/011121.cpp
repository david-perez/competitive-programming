#include <iostream>
#include <stack>

using namespace std;

div_t euc_div(int a, int d) {
    div_t divT = div(a, d);
    int I = divT.rem >= 0 ? 0 : (d > 0 ? 1 : -1);
    int qE = divT.quot - I;
    int rE = divT.rem + I * d;
    return div_t{qE, rE};
}

int main() {
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        printf("Case #%d: ", t);
        int n;
        cin >> n;
        stack<int> s;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        while (n != 0) {
            div_t q = euc_div(n, -2);
            s.push(q.rem);
            n = (q.quot);
        }

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }

    return 0;
}