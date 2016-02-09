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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    int grades[1000];
    int C, N;
    cin >> C;
    while (C--) {
        cin >> N;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> grades[i];
            sum += grades[i];
        }
        double avg = sum / N;
        int abavg = 0;
        for (int i = 0; i < N; i++)
            if (grades[i] > avg) abavg++;
        printf("%.3f%\n", abavg/(double)N*100);
    }
    
    return 0;
}
