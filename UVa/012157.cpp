#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int mile = 0, juice = 0;
        while (N--) {
            int m;
            cin >> m;
            mile += 1 + m/30;
            juice += 1 + m/60;
        }

        mile *= 10, juice *= 15;
        printf("Case %d: ", t);
        if (mile == juice) printf("Mile Juice %d\n", mile);
        else if (mile < juice) printf("Mile %d\n", mile);
        else printf("Juice %d\n", juice);
    }

    return 0;
}
