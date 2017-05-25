#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
    int T, M = 1000, ram[1000], reg[10];
    cin >> T; cin.get();
    string s; getline(cin, s);
    for (int t = 1; t <= T; t++) {
        if (t > 1) cout << endl;

        int l = 0;
        while (getline(cin, s) && !s.empty()) {
            stringstream ss(s);
            ss >> ram[l++];
        }

        while (l < 1000) ram[l++] = 0;
        memset(reg, 0, sizeof reg);

        int pc = 0, cnt = 0;
        while (++cnt) {
            int ins = ram[pc++];
            int p = (ins / 10) % 10, q = ins % 10;

            if (ins < 100 && reg[q] != 0) pc = reg[p];
            else if (ins == 100) break;
            else if (ins / 100 == 2) reg[p] = q;
            else if (ins / 100 == 3) reg[p] = (reg[p] + q) % M;
            else if (ins / 100 == 4) reg[p] = (reg[p] * q) % M;
            else if (ins / 100 == 5) reg[p] = reg[q];
            else if (ins / 100 == 6) reg[p] = (reg[p] + reg[q]) % M;
            else if (ins / 100 == 7) reg[p] = (reg[p] * reg[q]) % M;
            else if (ins / 100 == 8) reg[p] = ram[reg[q]];
            else if (ins / 100 == 9) ram[reg[q]] = reg[p];
        }

        cout << cnt << endl;
    }

    return 0;
}
