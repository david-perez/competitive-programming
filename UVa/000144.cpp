#include <iostream>
#include <queue>

using namespace std;

struct machine {
    int k, in, out;

    machine(int _k) : k(_k) {
        in = 1;
        out = 0;
        moveCoins();
    }

    void moveCoins() {
        out = in;
        in++;
        if (in > k) in = 1;
    }

    int pay(int card) {
        int toPay = 40 - card;
        if (toPay >= out) {
            card += out;
            out = 0;
            moveCoins();
        } else {
            card += toPay;
            out -= toPay;
        }

        return card;
    }
};

struct student {
    int id, card;

    student(int _id) : id(_id) {
        card = 0;
    }
};

int main() {
    int N, k;
    while (cin >> N >> k && !(N == 0 && k == 0)) {
        queue<student> q;
        for (int i = 1; i <= N; i++)
            q.push(student(i));

        machine m(k);
        while (!q.empty()) {
            student s = q.front();
            q.pop();
            s.card = m.pay(s.card);
            if (s.card == 40) printf("%3d", s.id);
            else q.push(s);
        }

        cout << endl;
    }

    return 0;
}