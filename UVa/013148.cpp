#include <iostream>
#include <set>

using namespace std;

int pow6(int x) {
    int pow3 = x*x*x;
    return pow3 * pow3;
}

int main() {
    // I refuse to write an if / switch statement to solve the problem.
    set<int> s;
    for (int x = 1; pow6(x) < 100000000; x++) // Hopefully the compiler will cache the call to pow6()
        s.insert(pow6(x));

    int n;
    while (cin >> n && n != 0)
        cout << (s.count(n) > 0 ? "Special" : "Ordinary") << endl;
}