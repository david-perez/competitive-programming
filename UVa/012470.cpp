#include <iostream>

using namespace std;

typedef long long ll;

struct Matrix { ll mat[3][3]; };

int mod = 1000000009;

Matrix matMul(Matrix &a, Matrix &b) {
    Matrix ans;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = ans.mat[i][j] = 0; k < 3; k++)
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
    return ans;
}

int T(ll n) {
    Matrix ans;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ans.mat[i][j] = i == j;
    
    Matrix base = {{{0,1,0}, {0,0,1}, {1,1,1}}};
    n--;
    while (n) {
        if (n % 2 == 1) ans = matMul(ans, base);
        base = matMul(base, base);
        n /= 2;
    }

    return (ans.mat[0][1] + ans.mat[0][2]*2) % mod;
}

int main() {
    ll n;
    while (cin >> n && n != 0)
        cout << T(n) << endl;

    return 0;
}
