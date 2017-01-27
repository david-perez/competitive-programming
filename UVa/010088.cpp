#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct point {
    int x, y;

    point(int _x, int _y) : x(_x), y(_y) {}
};

ll darea(vector<point> &p) {
    ll result = 0, x1, y1, x2, y2;
    for (int i = 0; i < p.size()-1; i++) {
        x1 = p[i].x; x2 = p[i+1].x;
        y1 = p[i].y; y2 = p[i+1].y;
        result += (x1*y2 - x2*y1);
    }

    return abs(result);
}

int gcd(int a, int b) {
    int x, y;
    int xx = y = 0, yy = x = 1;
    while (b) {
        int q = a/b, t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<point> pol;
        while (N--) {
            int x, y;
            cin >> x >> y;
            pol.push_back(point(x, y));
        }
        pol.push_back(pol[0]);

        ll b = 0;
        for (int i = 0; i < pol.size()-1; i++) {
            int x1 = pol[i].x, x2 = pol[i+1].x;
            int y1 = pol[i].y, y2 = pol[i+1].y;
            b += abs(gcd(y2-y1, x2-x1)); // http://math.stackexchange.com/a/628141
        }

        ll i = (darea(pol) + 2 - b) / 2; // https://en.wikipedia.org/wiki/Pick's_theorem
        cout << i << endl;
    }

    return 0;
}