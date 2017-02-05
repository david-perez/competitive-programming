#include <iostream>

using namespace std;

struct point {
    double x, y;

    point() {
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
    double a, b, c; // ax + by + c = 0

    bool operator== (const line &l2) {
        return (a == l2.a && b == l2.b && c == l2.c);
    }
};

line pointsToLine(point p, point q) {
    line l;
    if (p.x == q.x) {
        l.a = 1; l.b = 0; l.c = -p.x;
    } else {
        l.a = (q.y - p.y) / (p.x - q.x);
        l.b = 1;
        l.c = -(l.a * p.x) - p.y;
    }
    return l;
}

bool areParallel(line l1, line l2) {
    return l1.a == l2.a && l1.b == l2.b;
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    double det = l1.a*l2.b - l1.b*l2.a;
    p.x = (l1.b*l2.c - l1.c*l2.b) / det + 0.0; // get rid of signed zero
    p.y = (l1.c*l2.a - l1.a*l2.c) / det + 0.0;
    return true;
}

int main() {
    int N;
    cin >> N;

    cout << "INTERSECTING LINES OUTPUT" << endl;
    while (N--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
        line l1 = pointsToLine(p1, p2), l2 = pointsToLine(p3, p4);
        point p;
        if (l1 == l2) cout << "LINE" << endl;
        else if (areIntersect(l1, l2, p)) printf("POINT %.2f %.2f\n", p.x, p.y);
        else cout << "NONE" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}