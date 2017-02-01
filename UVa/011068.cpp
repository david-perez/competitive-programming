#include <iostream>

using namespace std;

struct point { double x, y; };
struct line { int a, b, c; };

bool areParallel(line l1, line l2) {
    return l1.a == l2.a && l1.b == l2.b;
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    int det = l1.a*l2.b - l1.b*l2.a;
    p.x = (double) (l1.c*l2.b - l1.b*l2.c) / det + 0.0; // get rid of signed zero
    p.y = (double) (l1.a*l2.c - l1.c*l2.a) / det + 0.0;
}

int main() {
    line l1, l2;
    while (cin >> l1.a >> l1.b >> l1.c && !(l1.a == 0 && l1.b == 0 && l1.c == 0)) {
        cin >> l2.a >> l2.b >> l2.c;

        point p;
        if (areIntersect(l1, l2, p))
            printf("The fixed point is at %.2f %.2f.\n", p.x, p.y);
        else cout << "No fixed point exists." << endl;
    }

    return 0;
}