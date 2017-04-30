#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;

bitset<100> bs; // 10^2
vi primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (int j = i * i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int sumDiv(int N) {
    int PF_idx = 0, PF = primes[PF_idx], sum = 1;
    while (PF * PF <= N) {
        int p = 1;
        while (N % PF == 0) {
            N /= PF;
            p *= PF;
        }
        if (p != 1) sum *= ((p * PF) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }

    if (N != 1) sum *= N + 1;
    return sum;
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = sumDiv(n) - n;
        if (sum < n) cout << "deficient" << endl;
        else if (sum == n) cout << "perfect" << endl;
        else cout << "abundant" << endl;
    }
    
    return 0;
}
