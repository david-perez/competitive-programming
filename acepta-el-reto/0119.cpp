#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    vi squares;
    for (int i = 1; i*i <= 10000000; i++)
        squares.push_back(i*i);

    int n;
    while (cin >> n && n != 0) {
        int escudos = 0;
        int i = squares.size() - 1;
        while (n != 0) {
            if (n >= squares[i]) {
                int sq_root = i+1;
                if (sq_root == 1) escudos += 5;
                else escudos += squares[i] + (sq_root - 2) * 4 + 8;

                n -= squares[i];
            } else i--;
        }

        cout << escudos << endl;
    }

    return 0;
}