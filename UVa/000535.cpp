#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define PI acos(-1)

double toRad(double deg) {
    return deg / 180 * PI;
}

double dist(double phi1, double theta1, double phi2, double theta2) {
    double dot = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    if (dot > 1) dot = 1;
    if (dot < -1) dot = -1;
    return acos(dot);
}

int main() {
    map<string, pair<double, double>> m;
    string s;
    while (cin >> s && s != "#") {
        double lat, lng;
        cin >> lat >> lng;
        double phi = toRad(90 - lat), theta = toRad(lng);
        m[s] = make_pair(phi, theta);
    }

    string A, B;
    while (cin >> A >> B && !(A == "#" && B == "#")) {
        printf("%s - %s\n", A.c_str(), B.c_str());
        if (m.count(A) > 0 && m.count(B) > 0)
            printf("%d km\n", (int) round(6378 * dist(m[A].first, m[A].second, m[B].first, m[B].second)));
        else cout << "Unknown" << endl;
    }
    
    return 0;
}
