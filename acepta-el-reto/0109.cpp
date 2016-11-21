#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string categoria;
    while (cin >> categoria && categoria != "FIN") {
        set<string> teams;
        map<string, int> points;
        int matches = 0;

        string team1;
        while (cin >> team1 && team1 != "FIN") {
            int p1, p2;
            string team2;
            cin >> p1 >> team2 >> p2;

            teams.insert(team1);
            teams.insert(team2);

            matches++;

            if (p1 > p2) {
                points[team1] += 2;
                points[team2]++;
            } else {
                points[team2] += 2;
                points[team1]++;
            }
        }

        vector<pair<int, string>> pts;
        for (auto p : points)
            pts.push_back(make_pair(p.second, p.first));
        sort(pts.begin(), pts.end(), greater<pair<int, string>>());

        int undisputed = teams.size()*(teams.size()-1) - matches;
        if (pts.size() >= 2 && pts[0].first == pts[1].first) printf("EMPATE %d\n", undisputed);
        else printf("%s %d\n", pts[0].second.c_str(), undisputed);
    }

    return 0;
}