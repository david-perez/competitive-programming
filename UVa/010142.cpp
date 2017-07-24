#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <sstream>

using namespace std;

typedef vector<int> vi;

vector<list<int>> ballots;
map<int, int> votes;

bool count(int &mv, vi &lv) {
    for (auto &p : votes) p.second = 0;
    for (auto &l : ballots) votes[l.front()]++;

    int m = 1001;
    for (auto &p : votes) {
        m = min(m, p.second);
        if (2*p.second > ballots.size()) {
            mv = p.first;
            return false;
        }
    }

    for (auto &p : votes)
        if (p.second == m) lv.push_back(p.first);

    return lv.size() == votes.size();
}

void remove(vi &lv) {
    for (int cand : lv) {
        for (auto &l : ballots) {
            auto it = l.begin();
            while (it != l.end()) {
                if (*it == cand) it = l.erase(it);
                else ++it;
            }
        }
        votes.erase(cand);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n; cin.get();
        string candidates[n];
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            candidates[i] = s;
            votes[i] = 0;
        }

        ballots.clear();
        string s;
        while (getline(cin, s) && !s.empty()) {
            stringstream ss(s);
            list<int> l;
            int v;
            while (ss >> v) l.push_back(v-1);
            ballots.push_back(l);
        }

        while (true) {
            int most_voted = -1;
            vi least_voted;
            bool tied = count(most_voted, least_voted);
            if (tied) {
                for (int cand : least_voted)
                    cout << candidates[cand] << endl;
                break;
            } else if (most_voted != -1) {
                cout << candidates[most_voted] << endl;
                break;
            } else remove(least_voted);
        }

        if (T > 0) cout << endl;
    }

    return 0;
}
