#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct employee {
    string info[8];

    bool operator < (const employee& e) const {
        return info[2] < e.info[2];
    }
};

int main() {
    int d;
    cin >> d; cin.get();
    vector<employee> v;
    while (d--) {
        string dept;
        getline(cin, dept);
        string s;
        while (getline(cin, s) && !s.empty()) {
            stringstream ss(s);
            string token;
            employee e;
            for (int i = 0; i < 7 && getline(ss, token, ','); i++)
                e.info[i] = token;
            e.info[7] = dept;
            v.push_back(e);
        }
    }

    sort(v.begin(), v.end());
    for (employee &e : v) {
        cout << "----------------------------------------" << endl;
        printf("%s %s %s\n", e.info[0].c_str(), e.info[1].c_str(), e.info[2].c_str());
        printf("%s\n", e.info[3].c_str());
        printf("Department: %s\n", e.info[7].c_str());
        printf("Home Phone: %s\n", e.info[4].c_str());
        printf("Work Phone: %s\n", e.info[5].c_str());
        printf("Campus Box: %s\n", e.info[6].c_str());
    }

    return 0;
}
