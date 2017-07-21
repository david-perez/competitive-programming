#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    set<string> st;
    string s, prep = "";
    while (getline(cin, s)) {
        for (char &c : s)
            if (!isalpha(c) && c != '-') c = ' ';

        stringstream ss(s);
        string word;
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!prep.empty()) {
                word.insert(0, prep);
                prep = "";
            }
            if (ss.eof() && word[word.length()-1] == '-') {
                word.pop_back();
                prep = word;
            } else st.insert(word);
        }
    }

    if (!prep.empty()) st.insert(prep);
    for (const string &word : st) cout << word << endl;

    return 0;
}
