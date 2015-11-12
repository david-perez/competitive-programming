#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int x1, h, x2;
    
    int skyline[10000] = {0};
    
    while (scanf("%d %d %d", &x1, &h, &x2) == 3)
        for (int i = x1; i < x2; i++)
            skyline[i] = max(skyline[i], h);
    
    bool e = false;
    h = 0;
    for (int i = 0; i < 10000; i++) {
        if (skyline[i] != h) {
            if (e) cout << ' ';
            cout << i << " " << skyline[i];
            e = true;
            h = skyline[i];
        } 
    }
    cout << endl;
    
    return 0;
}