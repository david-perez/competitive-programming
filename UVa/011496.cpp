#include <iostream>

using namespace std;

int isPeak(int i, int j, int k) {
   return (i < j && j > k) || (i > j && j < k) ? 1 : 0;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        int i0, i1, i, j, k, cnt = 0;
        cin >> i0 >> i1;
        i = i0, j = i1;
        N -= 2;
        while (N--) {
            cin >> k;
            cnt += isPeak(i, j, k);
            i = j, j = k;
        }

        cout << cnt + isPeak(i, j, i0) + isPeak(j, i0, i1) << endl;
    }

    return 0;
}
