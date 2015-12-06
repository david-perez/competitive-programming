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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int dateToInt(int d, int m, int y) {
    return
            1461*(y+4800+(m-14)/12)/4+
            367*(m-2-(m-14)/12*12)/12-
            3*((y+4900+(m-14)/12)/100)/4+
            d-32075;
}

void intToDate(int jd, int &d, int &m, int &y) {
    int x, n, i, j;
    x = jd+68569; n = 4*x/146097;
    x -= (146097*n+3)/4;
    i = (4000*(x+1))/1461001;
    x -= 1461*i/4-31; j = 80*x/2447;
    d = x-2447*j/80;
    x = j/11; m = j+2-12*x;
    y = 100*(n-49)+i+x;
}

void print(vi &u) {
    int d, m, y;
    for (int i = 0; i < u.size(); i++) {
        intToDate(u[i], d, m, y);
        printf("%d/%d/%d ", d, m, y);
    }
    cout << endl;
}

int main() {
    int viajes, consultas;
    int d, m, y;
    int a, b, c;
    
    cin >> viajes;
    while (viajes != 0) {
        vi u, v;
        
        a = dateToInt(12, 6, 1968);
        while (viajes--) {
            scanf("%d/%d/%d", &d, &m, &y);
            b = dateToInt(d, m, y);
            u.push_back(a);
            v.push_back(b);
            
            scanf("%d/%d/%d", &d, &m, &y);
            a = dateToInt(d, m, y);
        }
        b = dateToInt(31, 12, 9999);
        u.push_back(a);
        v.push_back(b);
        
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        
        cin >> consultas;
        while (consultas--) {
            scanf("%d/%d/%d", &d, &m, &y);
            c = dateToInt(d, m, y);
            
            //print(u);
            //print(v);
            
            vi::iterator upu = upper_bound(u.begin(), u.end(), c);
            vi::iterator lowv = lower_bound(v.begin(), v.end(), c);
            
            cout << (upu - u.begin()) - (lowv - v.begin()) << endl;
        }
        
        cout << "----" << endl;
        cin >> viajes;
    }
    
    return 0;
}