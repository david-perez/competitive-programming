#include <iostream>

using namespace std;

string pre, in;

void post(int i1, int j1, int i2, int j2) {
    char root = pre[i1];
    int k = i2;
    while (in[k] != root) k++;

    if (k != i2) post(i1+1, i1+k-i2, i2, k-1);
    if (k != j2) post(i1+k-i2+1, j1, k+1, j2);
    cout << root;
}

int main() {
    while (cin >> pre >> in) {
        post(0, pre.length()-1, 0, in.length()-1);
        cout << endl;
    }

    return 0;
}