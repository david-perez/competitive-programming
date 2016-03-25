#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

int pts[43] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,50,51,54,57,60};

int main() {
    int score;
    while (cin >> score && score > 0) {
        int perms = 0, combs = 0;
        for (int i = 0; i < 43; i++)
            for (int j = i; j < 43 && pts[i] + pts[j] <= score; j++)
                for (int k = j; k < 43 && pts[i] + pts[j] + pts[k] <= score; k++)
                    if (pts[i] + pts[j] + pts[k] == score) {
                        combs++;
                        if (pts[i] == pts[j] && pts[j] == pts[k]) perms++;
                        else if (pts[i] == pts[j] || pts[j] == pts[k] || pts[i] == pts[k]) perms += 3;
                        else perms += 6;
                    }
        if (combs == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combs);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perms);
        }
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}