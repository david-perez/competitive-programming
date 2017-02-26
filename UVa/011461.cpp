#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
    vi sq;
    for (int n = 1; n*n <= 100000; n++)
        sq.push_back(n*n);

    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0))
        cout << distance(lower_bound(sq.begin(), sq.end(), a), upper_bound(sq.begin(), sq.end(), b)) << endl;

    return 0;
}