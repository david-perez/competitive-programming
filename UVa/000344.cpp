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
#include <list>
#include <forward_list>
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
typedef unsigned long long ull;
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

string sols[] = {
        "1: 1 i, 0 v, 0 x, 0 l, 0 c",
        "2: 3 i, 0 v, 0 x, 0 l, 0 c",
        "3: 6 i, 0 v, 0 x, 0 l, 0 c",
        "4: 7 i, 1 v, 0 x, 0 l, 0 c",
        "5: 7 i, 2 v, 0 x, 0 l, 0 c",
        "6: 8 i, 3 v, 0 x, 0 l, 0 c",
        "7: 10 i, 4 v, 0 x, 0 l, 0 c",
        "8: 13 i, 5 v, 0 x, 0 l, 0 c",
        "9: 14 i, 5 v, 1 x, 0 l, 0 c",
        "10: 14 i, 5 v, 2 x, 0 l, 0 c",
        "11: 15 i, 5 v, 3 x, 0 l, 0 c",
        "12: 17 i, 5 v, 4 x, 0 l, 0 c",
        "13: 20 i, 5 v, 5 x, 0 l, 0 c",
        "14: 21 i, 6 v, 6 x, 0 l, 0 c",
        "15: 21 i, 7 v, 7 x, 0 l, 0 c",
        "16: 22 i, 8 v, 8 x, 0 l, 0 c",
        "17: 24 i, 9 v, 9 x, 0 l, 0 c",
        "18: 27 i, 10 v, 10 x, 0 l, 0 c",
        "19: 28 i, 10 v, 12 x, 0 l, 0 c",
        "20: 28 i, 10 v, 14 x, 0 l, 0 c",
        "21: 29 i, 10 v, 16 x, 0 l, 0 c",
        "22: 31 i, 10 v, 18 x, 0 l, 0 c",
        "23: 34 i, 10 v, 20 x, 0 l, 0 c",
        "24: 35 i, 11 v, 22 x, 0 l, 0 c",
        "25: 35 i, 12 v, 24 x, 0 l, 0 c",
        "26: 36 i, 13 v, 26 x, 0 l, 0 c",
        "27: 38 i, 14 v, 28 x, 0 l, 0 c",
        "28: 41 i, 15 v, 30 x, 0 l, 0 c",
        "29: 42 i, 15 v, 33 x, 0 l, 0 c",
        "30: 42 i, 15 v, 36 x, 0 l, 0 c",
        "31: 43 i, 15 v, 39 x, 0 l, 0 c",
        "32: 45 i, 15 v, 42 x, 0 l, 0 c",
        "33: 48 i, 15 v, 45 x, 0 l, 0 c",
        "34: 49 i, 16 v, 48 x, 0 l, 0 c",
        "35: 49 i, 17 v, 51 x, 0 l, 0 c",
        "36: 50 i, 18 v, 54 x, 0 l, 0 c",
        "37: 52 i, 19 v, 57 x, 0 l, 0 c",
        "38: 55 i, 20 v, 60 x, 0 l, 0 c",
        "39: 56 i, 20 v, 64 x, 0 l, 0 c",
        "40: 56 i, 20 v, 65 x, 1 l, 0 c",
        "41: 57 i, 20 v, 66 x, 2 l, 0 c",
        "42: 59 i, 20 v, 67 x, 3 l, 0 c",
        "43: 62 i, 20 v, 68 x, 4 l, 0 c",
        "44: 63 i, 21 v, 69 x, 5 l, 0 c",
        "45: 63 i, 22 v, 70 x, 6 l, 0 c",
        "46: 64 i, 23 v, 71 x, 7 l, 0 c",
        "47: 66 i, 24 v, 72 x, 8 l, 0 c",
        "48: 69 i, 25 v, 73 x, 9 l, 0 c",
        "49: 70 i, 25 v, 75 x, 10 l, 0 c",
        "50: 70 i, 25 v, 75 x, 11 l, 0 c",
        "51: 71 i, 25 v, 75 x, 12 l, 0 c",
        "52: 73 i, 25 v, 75 x, 13 l, 0 c",
        "53: 76 i, 25 v, 75 x, 14 l, 0 c",
        "54: 77 i, 26 v, 75 x, 15 l, 0 c",
        "55: 77 i, 27 v, 75 x, 16 l, 0 c",
        "56: 78 i, 28 v, 75 x, 17 l, 0 c",
        "57: 80 i, 29 v, 75 x, 18 l, 0 c",
        "58: 83 i, 30 v, 75 x, 19 l, 0 c",
        "59: 84 i, 30 v, 76 x, 20 l, 0 c",
        "60: 84 i, 30 v, 77 x, 21 l, 0 c",
        "61: 85 i, 30 v, 78 x, 22 l, 0 c",
        "62: 87 i, 30 v, 79 x, 23 l, 0 c",
        "63: 90 i, 30 v, 80 x, 24 l, 0 c",
        "64: 91 i, 31 v, 81 x, 25 l, 0 c",
        "65: 91 i, 32 v, 82 x, 26 l, 0 c",
        "66: 92 i, 33 v, 83 x, 27 l, 0 c",
        "67: 94 i, 34 v, 84 x, 28 l, 0 c",
        "68: 97 i, 35 v, 85 x, 29 l, 0 c",
        "69: 98 i, 35 v, 87 x, 30 l, 0 c",
        "70: 98 i, 35 v, 89 x, 31 l, 0 c",
        "71: 99 i, 35 v, 91 x, 32 l, 0 c",
        "72: 101 i, 35 v, 93 x, 33 l, 0 c",
        "73: 104 i, 35 v, 95 x, 34 l, 0 c",
        "74: 105 i, 36 v, 97 x, 35 l, 0 c",
        "75: 105 i, 37 v, 99 x, 36 l, 0 c",
        "76: 106 i, 38 v, 101 x, 37 l, 0 c",
        "77: 108 i, 39 v, 103 x, 38 l, 0 c",
        "78: 111 i, 40 v, 105 x, 39 l, 0 c",
        "79: 112 i, 40 v, 108 x, 40 l, 0 c",
        "80: 112 i, 40 v, 111 x, 41 l, 0 c",
        "81: 113 i, 40 v, 114 x, 42 l, 0 c",
        "82: 115 i, 40 v, 117 x, 43 l, 0 c",
        "83: 118 i, 40 v, 120 x, 44 l, 0 c",
        "84: 119 i, 41 v, 123 x, 45 l, 0 c",
        "85: 119 i, 42 v, 126 x, 46 l, 0 c",
        "86: 120 i, 43 v, 129 x, 47 l, 0 c",
        "87: 122 i, 44 v, 132 x, 48 l, 0 c",
        "88: 125 i, 45 v, 135 x, 49 l, 0 c",
        "89: 126 i, 45 v, 139 x, 50 l, 0 c",
        "90: 126 i, 45 v, 140 x, 50 l, 1 c",
        "91: 127 i, 45 v, 141 x, 50 l, 2 c",
        "92: 129 i, 45 v, 142 x, 50 l, 3 c",
        "93: 132 i, 45 v, 143 x, 50 l, 4 c",
        "94: 133 i, 46 v, 144 x, 50 l, 5 c",
        "95: 133 i, 47 v, 145 x, 50 l, 6 c",
        "96: 134 i, 48 v, 146 x, 50 l, 7 c",
        "97: 136 i, 49 v, 147 x, 50 l, 8 c",
        "98: 139 i, 50 v, 148 x, 50 l, 9 c",
        "99: 140 i, 50 v, 150 x, 50 l, 10 c",
        "100: 140 i, 50 v, 150 x, 50 l, 11 c"
};

map<int, string> cvt;

string AtoR(int A) {
    stringstream ss;
    for (auto rit = cvt.rbegin(); rit != cvt.rend(); ++rit)
        while (A >= rit->first) {
            ss << rit->second;
            A -= rit->first;
        }
    return ss.str();
}

void generateSols() {
    cvt[100] = "c"; cvt[90] = "xc"; cvt[50] = "l"; cvt[40] = "xl";
    cvt[10] = "x"; cvt[9] = "ix"; cvt[5] = "v"; cvt[4] = "iv";
    cvt[1] = "i";

    map<char, int> cnt; cnt['i'] = cnt['v'] = cnt['x'] = cnt['l'] = cnt['c'] = 0;
    for (int i = 1; i <= 100; i++) {
        string s = AtoR(i).c_str();
        for (auto &c : s) cnt[c]++;
        printf("\"%d: %d i, %d v, %d x, %d l, %d c\",\n", i, cnt['i'], cnt['v'], cnt['x'], cnt['l'], cnt['c']);
    }
}

int main() {
    //generateSols();
    int n;
    while (cin >> n && n != 0)
        cout << sols[n-1] << endl;

    return 0;
}