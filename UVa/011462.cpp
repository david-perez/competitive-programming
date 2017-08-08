#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int a[101];
        for (int i = 0; i < 101; i++) a[i] = 0;
        while (n--) {
            int x;
            cin >> x;
            a[x]++;
        }

        bool first = true;
        for (int i = 1; i <= 100; i++)
            while (a[i]--) {
                printf("%s%d", first ? "" : " ", i);
                first = false;
            }
        cout << endl;
    }
    
    return 0;
}
