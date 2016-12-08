#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
    int N, M;
    for (int t = 0; cin >> N >> M; t++) {
        if (t != 0) cout << endl;

        vi sums(N + M + 1, 0);

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                sums[i+j]++;

        int M = *max_element(sums.begin(), sums.end());
        for (int i = 0; i < sums.size(); i++)
            if (sums[i] == M) cout << i << endl;
    }

    return 0;
}