#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

int main() {
    int N;
    cin >> N;
    while (N--) {
        vi v;
        int P;
        cin >> P; cin.get();
        int n = 1000;
        for  (int p = 1; p <= P; p++) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int x, cnt = 0;
            while (ss >> x) cnt++;
            if (cnt < n) {
                v.clear();
                v.push_back(p);
                n = cnt;
            } else if (cnt == n) v.push_back(p);
        }

        printf("%d", v[0]);
        for (int i = 1; i < v.size(); i++) printf(" %d", v[i]);
        cout << endl;
    }

    return 0;
}
