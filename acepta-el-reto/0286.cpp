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

void print(vector<ii> &v) {
    int d, m, y;
    for (int i = 0; i < v.size(); i++) {
        ii p = v[i];
        intToDate(p.first, d, m, y);
        cout << d << "/" << m << "/" << y << " - ";
        intToDate(p.second, d, m, y);
        cout << d << "/" << m << "/" << y << endl;
    }
}

void print(multimap<int, ii > &mp) {
    int d, m, y;
    for (multimap<int, ii>::iterator it=mp.begin(); it!=mp.end(); ++it) {
        ii p = (*it).second;
        intToDate(p.first, d, m, y);
        cout << d << "/" << m << "/" << y << " - ";
        intToDate(p.second, d, m, y);
        cout << d << "/" << m << "/" << y << endl;
    }
}

int main() {
    int viajes, consultas;
    int d, m, y;
    int a, b, c;
    
    cin >> viajes;
    while (viajes != 0) {
        multimap<int, ii> u; // a |-> (a, b)
        multimap<int, ii> v; // b |-> (a, b)
        
        a = dateToInt(12, 6, 1968);
        while (viajes--) {
            scanf("%d/%d/%d", &d, &m, &y);
            b = dateToInt(d, m, y);
            u.insert(pair<int, ii>(a, ii(a, b)));
            v.insert(pair<int, ii>(b, ii(a, b)));
            
            scanf("%d/%d/%d", &d, &m, &y);
            a = dateToInt(d, m, y);
        }
        b = dateToInt(31, 12, 9999);
        u.insert(pair<int, ii>(a, ii(a, b)));
        v.insert(pair<int, ii>(b, ii(a, b)));
        
        /*
        cout << endl;
        print(u);
        cout << endl;
        */
        
        cin >> consultas;
        while (consultas--) {
            scanf("%d/%d/%d", &d, &m, &y);
            c = dateToInt(d, m, y);
            
            multimap<int, ii>::iterator it1 = u.upper_bound(c); // points to first element after c. O(logn)
            multimap<int, ii>::iterator it2 = v.lower_bound(c); // points to c or goes after. O(logn)
            
            vector<ii> v1;
            for (multimap<int, ii >::iterator it = u.begin(); it != it1; ++it)
                v1.push_back((*it).second);
            sort(v1.begin(), v1.end());
            
            /*
            cout << endl;
            print(v1);
            cout << endl;
            */
            
            vector<ii> v2;
            for (multimap<int, ii >::iterator it = it2; it != v.end(); ++it)
                v2.push_back((*it).second);
            sort(v2.begin(), v2.end());
            
            /*
            cout << endl;
            print(v2);
            cout << endl;
            */
            
            vector<ii> sol(50000);
            vector<ii>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), sol.begin());
            cout << it-sol.begin() << endl; // it - sol.begin() is the number of elements in the intersection
        }
        
        cout << "----" << endl;
        cin >> viajes;
    }
    
    return 0;
}