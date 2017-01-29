#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

// N, E, S, W
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int x, y, d, s1, s2, c;
vii v;
set<ii> s;

ii next() {
    x += dr[d];
    y += dc[d];
    s1++;
    if (s1 == s2) {
        d = (d + 1) % 4;
        s1 = 0;
        c = (c + 1) % 2;
        if (c == 0)
            s2++;
    }

    return ii(y, x);
}

int gcd(int a, int b) {
    while (b) {
        int aux = b;
        b = a%b; a = aux;
    }
    return a;
}

int main() {
    v.push_back(ii(1, 1));
    s.insert(ii(1, 1));
    x = 1, y = 1, d = 2, s1 = 0, s2 = 2, c = 0;

    int k;
    while (cin >> k) {
        while (v.size() - 1 < k) {
            ii q = next();

            if (q.second == 0) continue;
            int g = gcd(q.first, q.second);
            q.first /= g, q.second /= g;
            if (s.count(q) == 0) {
                s.insert(q);
                v.push_back(q);
            }
        }

        ii q = v[k];
        if (q.second < 0) {
            q.first *= -1;
            q.second *= -1;
        }
        printf("%d / %d\n", q.first, q.second);
    }

    return 0;
}