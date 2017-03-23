#include <iostream>
#include <cfloat>

using namespace std;

int main() {
    int n, p;
    for (int t = 1; cin >> n >> p && !(n == 0 && p == 0); t++) {
        cin.get();
        if (t > 1) cout << endl;

        string s;
        for (int i = 0; i < n; i++)
            getline(cin, s);

        string prop;
        int compliance = 0;
        double price = DBL_MAX;
        for (int i = 0; i < p; i++) {
            double d;
            int r;
            getline(cin, s);
            cin >> d >> r; cin.get();
            if (r > compliance || r == compliance && d < price) {
                prop = s;
                compliance = r;
                price = d;
            }

            for (int j = 0; j < r; j++) getline(cin, s);
        }

        printf("RFP #%d\n%s\n", t, prop.c_str());
    }

    return 0;
}