#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> vd;

int main() {
    int N, r;
    for (int t = 1; cin >> N >> r && !(N == 0 && r == 0); t++) {
        vd p, q;
        vector<bool> v;
        for (int i = 0; i < N; i++) {
            double x;
            cin >> x;
            q.push_back(0);
            p.push_back(x);
            v.push_back(i >= (N - r));
        }
        
        double P = 0;
        do {
            double prob = 1;
            for (int i = 0; i < N; i++)
                prob *= v[i] ? p[i] : (1 - p[i]);

            for (int i = 0; i < N; i++)
                if (v[i]) q[i] += prob;

            P += prob;
        } while (next_permutation(v.begin(), v.end()));

        printf("Case %d:\n", t);
        for (int i = 0; i < N; i++)
            printf("%.6f\n", q[i] / P);
    }
    
    return 0;
}
