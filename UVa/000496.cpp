#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        stringstream ss(s), st(t);
        int a, b;
        set<int> A, B;
        while (ss >> a) A.insert(a);
        while (st >> b) B.insert(b);

        if (A == B) {
            cout << "A equals B" << endl;
            continue;
        }

        vector<int> AB(min(A.size(), B.size()));
        auto it = set_intersection(A.begin(), A.end(), B.begin(), B.end(), AB.begin());
        AB.resize(it - AB.begin());

        if (AB.empty()) cout << "A and B are disjoint" << endl;
        else if (includes(A.begin(), A.end(), B.begin(), B.end())) cout << "B is a proper subset of A" << endl;
        else if (includes(B.begin(), B.end(), A.begin(), A.end())) cout << "A is a proper subset of B" << endl;
        else cout << "I'm confused!" << endl;
    }

    return 0;
}