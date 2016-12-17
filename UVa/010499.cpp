#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll N;
    while (cin >> N && N > 0)
        cout << (N == 1 ? 0 : N*25) << '%' << endl;
}