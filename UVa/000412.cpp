#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        int a[N];
        for (int i = 0; i < N; i++) cin >> a[i];
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = i+1; j < N; j++)
                if (gcd(a[i], a[j]) == 1) cnt++;

        if (cnt == 0) cout << "No estimate for this data set." << endl;
        else printf("%.6f\n", sqrt(3.0*N*(N-1)/cnt));
    }

    return 0;
}
