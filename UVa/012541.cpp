#include <iostream>
#include <climits>

using namespace std;

int dateToInt(int m, int d, int y) {
    return
            1461*(y+4800+(m-14)/12)/4+
            367*(m -2-(m-14)/12*12)/12-
            3*((y+4900+(m-14)/12)/100)/4+
            d-32075;
}

int main() {
    int n;
    cin >> n;

    string oldest, youngest;
    int o = INT_MAX, y = 0;
    
    while (n--) {
        string s;
        int dd, mm, yyyy;
        cin >> s >> dd >> mm >> yyyy;

        int j = dateToInt(mm, dd, yyyy);
        if (j > y) {
            y = j;
            youngest = s;
        } else if (j < o) {
            o = j;
            oldest = s;
        }
    }

    cout << youngest << endl << oldest << endl;
    
    return 0;
}
