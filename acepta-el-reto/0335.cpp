#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        cout << n*(n+1)*(n+2)/6 << endl;
    }
    
    return 0;
}