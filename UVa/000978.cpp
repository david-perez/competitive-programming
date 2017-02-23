#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        priority_queue<int> lg, lb;
        int B, SG, SB;
        cin >> B >> SG >> SB;
        while (SG--) {
            int p;
            cin >> p;
            lg.push(p);
        }

        while (SB--) {
            int p;
            cin >> p;
            lb.push(p);
        }

        queue<int> qg, qb;
        while (!(lg.empty() || lb.empty())) {
            for (int i = 0; i < B; i++) {
                if (lg.empty() || lb.empty()) break;
                int g = lg.top(); lg.pop();
                int b = lb.top(); lb.pop();

                if (g > b) {
                    g -= b;
                    qg.push(g);
                } else if (b > g) {
                    b -= g;
                    qb.push(b);
                }
            }

            while (!qg.empty()) {
                lg.push(qg.front());
                qg.pop();
            }

            while (!qb.empty()) {
                lb.push(qb.front());
                qb.pop();
            }
        }

        if (lg.empty() && lb.empty()) cout << "green and blue died" << endl;
        else if (!lg.empty()) {
            cout << "green wins" << endl;
            while (!lg.empty()) {
                cout << lg.top() << endl;
                lg.pop();
            }
        } else {
            cout << "blue wins" << endl;
            while (!lb.empty()) {
                cout << lb.top() << endl;
                lb.pop();
            }
        }

        if (N != 0) cout << endl;
    }

    return 0;
}