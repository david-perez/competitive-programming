#include <iostream>
#include <bitset>

using namespace std;

bitset<52*20 + 1> bs;

void sieve() {
    bs.set();
    bs[0] =  0; bs[1] = 1;
    for (int i = 2; i < bs.size(); i++)
        if (bs[i])
            for (int j = i * i; j < bs.size(); j += i) bs[j] = 0;
}

int main() {
    sieve();
    string t = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", s;
    while (cin >> s) {
        int n = s.length();
        for (char &c : s) n += t.find(c);
        printf("It is %sa prime word.\n", bs[n] ? "" : "not ");
    }

    return 0;
}
