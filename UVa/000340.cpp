#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int N;
int s[1000], g[1000];

ii hints() { // O(2*N)
    multiset<int> code, guess;
    int strong = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == g[i]) strong++;
        else {
            code.insert(s[i]);
            guess.insert(g[i]);
        }
    }

    int weak = 0;
    auto it1 = code.begin(), it2 = guess.begin();
    while (it1 != code.end() && it2 != guess.end()) {
        int x = *it1, y = *it2;
        if (x == y) {
            weak++;
            ++it1, ++it2;
        } else if (x < y) ++it1;
        else ++it2;
    }

    return ii(strong, weak);
}

ii hints2() { // O(20 + N)
    int unms[10], unmg[10];
    for (int i = 0; i < 10; i++)
        unms[i] = unmg[i] = 0;

    int strong = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == g[i]) strong++;
        else {
            unms[s[i]]++;
            unmg[g[i]]++;
        }
    }

    int weak = 0;
    for (int i = 0; i < 10; i++)
        weak += min(unms[i], unmg[i]);

    return ii(strong, weak);
}

int main() {
    for (int t = 1; cin >> N && N != 0; t++) {
        printf("Game %d:\n", t);

        for (int i = 0; i < N; i++)
            cin >> s[i];

        while (true) {
            bool allZeros = true;
            for (int i = 0; i < N; i++) {
                cin >> g[i];
                if (g[i] != 0)
                    allZeros = false;
            }

            if (allZeros) break;

            // ii p = hints();
            ii p = hints2();
            printf("    (%d,%d)\n", p.first, p.second);
        }
    }

    return 0;
}