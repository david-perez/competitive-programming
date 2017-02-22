#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct arr {
    int D;
    vector<int> C;
};

int main() {
    int N, R;
    cin >> N >> R;
    map<string, int> m;
    vector<arr> mem;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s] = i;

        arr A;
        int CD, B;
        cin >> B >> CD >> A.D;
        A.C = vector<int>(A.D+1);
        A.C[A.D] = CD;
        vector<int> L(A.D+1), U(A.D+1);
        for (int d = 1; d <= A.D; d++)
            cin >> L[d] >> U[d];

        for (int d = A.D; d >= 2; d--)
            A.C[d-1] = A.C[d] * (U[d] - L[d] + 1);

        A.C[0] = B;
        for (int d = 1; d <= A.D; d++)
            A.C[0] -= A.C[d]*L[d];

        A.C = A.C;
        mem.push_back(A);
    }

    while (R--) {
        string s;
        cin >> s;
        printf("%s[", s.c_str());
        arr A = mem[m[s]];
        int addr = A.C[0];
        for (int d = 1; d < A.D; d++) {
            int id;
            cin >> id;
            printf("%d, ", id);
            addr += A.C[d]*id;
        }
        int iD;
        cin >> iD;
        printf("%d] = ", iD);
        addr += A.C[A.D]*iD;

        cout << addr << endl;
    }

    return 0;
}