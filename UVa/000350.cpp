#include <iostream>

using namespace std;

int Z, I, M, L, lambda;

int f(int x) {
    return (Z * x + I) % M;
}

void brent(int x0) {
    int power = lambda = 1;
    int tortoise = x0, hare = f(x0);
    while (tortoise != hare) {
        if (power == lambda) {
            tortoise = hare;
            power *= 2;
            lambda = 0;
        }
        hare = f(hare);
        lambda++;
    }
}

int main() {
    for (int t = 1; cin >> Z >> I >> M >> L && !(Z == 0 && I == 0 && M == 0 && L == 0); t++) {
        brent(L);
        printf("Case %d: %d\n", t, lambda);
    }

    return 0;
}
