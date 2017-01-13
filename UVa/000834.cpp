#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n, d;
vi v;

void f() {
    if (n % d == 0) {
        v.push_back(n / d);
        return;
    }
    int i = n / d;
    v.push_back(i);

    n -= i*d;
    int aux = n;
    n = d;
    d = aux;

    f();
}

int main() {
    while (cin >> n >> d) {
        v.clear();
        f();

        printf("[%d", v[0]);
        if (v.size() > 1) {
            cout << ';';
            for (int i = 1; i < v.size()-1; i++)
                printf("%d,", v[i]);
            cout << v[v.size()-1];
        }
        cout << ']' << endl;
    }

    return 0;
}