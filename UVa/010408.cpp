#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> ii;

struct comp {
    bool operator() (const ii &x, const ii &y) {
        return x.first * y.second < x.second * y.first;
    }
};

set<ii, comp> Fn;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    for (int b = 1; b <= 1000; b++)
        for (int a = 1; a <= b; a++) {
            int g = gcd(a, b);
            Fn.insert(ii(a / g, b / g));
        }

    int n, k;
    while (cin >> n >> k) {
        auto it = Fn.begin();
        for (int i = 0; !(((*it).second <= n && ++i == k)); ++it) { }
        printf("%d/%d\n", (*it).first, (*it).second);
    }

    return 0;
}