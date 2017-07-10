#include <iostream>

using namespace std;

int main() {
    char buffer[1000];
    int n, t = 0, now, hh, mm, ss, v = 0, u;
    double d = 0;

    while (cin.getline(buffer, sizeof(buffer))){
        n = sscanf(buffer, "%d:%d:%d %d", &hh, &mm, &ss, &u);
        now = hh*60*60 + mm*60 + ss;

        d += (now - t) * v;
        t = now;

        if (n == 3) printf("%02d:%02d:%02d %.2f km\n", hh, mm, ss, d/(60*60));
        else if (n == 4) v = u;
    }

    return 0;
}
