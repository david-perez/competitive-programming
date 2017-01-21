#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main() {
    char s[1024];
    int A[100001];
    for (int i = 0; i < 100001; i++)
        A[i] = INT_MAX;

    for (int n = 0; n < 100001; n++) {
        sprintf(s, "%d", n);
        int sum = n;
        for (int i = 0; i < strlen(s); i++)
            sum += s[i] - '0';
        A[sum] = min(A[sum], n); // n is a generator of sum
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << (A[N] == INT_MAX ? 0 : A[N]) << endl;
    }

    return 0;
}