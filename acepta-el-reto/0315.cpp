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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

bool gameover;
int F, C;
char grid[50][50];

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

void press(int r, int c) {
    if (r < 0 || r >= F || c < 0 || c >= C) return;
    if (grid[r][c] == '*') {
        gameover = true;
        return;
    }
    if (grid[r][c] != '-') return;
    
    int bombs = 0;
    for (int d = 0; d < 8; d++) {
        if (r + dr[d] < 0 || r + dr[d] >= F || c + dc[d] < 0 || c + dc[d] >= C) continue;
        if (grid[r + dr[d]][c + dc[d]] == '*') bombs++;
    }
    
    grid[r][c] = '+';
    
    if (bombs == 0)
        for (int d = 0; d < 8; d++)
            press(r + dr[d], c + dc[d]);
    
    grid[r][c] = '0' + bombs;
}

int main() {
    while (scanf("%d %d", &F, &C) == 2) {
        string s;
        for (int i = 0; i < F; i++) {
            getline(cin, s);
            for (int j = 0; j < C; j++)
                cin >> grid[i][j];
        }
        
        gameover = false;
        int moves, r, c;
        cin >> moves;
        while (moves--) {
            cin >> r >> c;
            press(r-1, c-1);
        }
        
        if (!gameover) {
            for (int i = 0; i < F; i++) {
                for (int j = 0; j < C; j++) {
                    if (grid[i][j] == '0') cout << '-';
                    else if (grid[i][j] == '-' || grid[i][j] == '*') cout << 'X';
                    else cout << grid[i][j];
                }
                cout << endl;
            }
        } else cout << "GAME OVER" << endl;
    }
    
    return 0;
}