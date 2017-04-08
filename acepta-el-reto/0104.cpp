#include <iostream>

using namespace std;

bool isBalanced(int pi, int di, int pd, int dd, int &w) {
    bool left = true;
    if (pi == 0) {
        int pii, dii, pdi, ddi;
        cin >> pii >> dii >> pdi >> ddi;
        left = isBalanced(pii, dii, pdi, ddi, pi);
    }

    bool right = true;
    if (pd == 0) {
        int pid, did, pdd, ddd;
        cin >> pid >> did >> pdd >> ddd;
        right = isBalanced(pid, did, pdd, ddd, pd);
    }

    w = pi + pd;
    return left && right && pi*di == pd*dd;
}

int main() {
    int pi, di, pd, dd, w;
    while (cin >> pi >> di >> pd >> dd && !(pi == 0 && di == 0 && pd == 0 && dd == 0))
        cout << (isBalanced(pi, di, pd, dd, w) ? "SI" : "NO") << endl;

    return 0;
}