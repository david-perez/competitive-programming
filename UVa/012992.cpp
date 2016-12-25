#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        printf("Case #%d: %d\n", t, 2*(N-1) + 1);
    }

    return 0;
}