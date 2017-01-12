#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vi v;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        int j = 0;
        for (int i = v.size() - 1; i >= 1; i--)
            if (v[i] == v[i-1]) {
                j = i;
                break;
            }

        v[j]++;
        for (int k = j+1; k < v.size(); k++)
            v[k] = v[j];

        for (int i = 0; i < v.size()-1; i++)
            cout << v[i] << ' ';
        cout << v[v.size()-1] << endl;
    }

    return 0;
}