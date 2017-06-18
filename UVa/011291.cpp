#include <iostream>
#include <sstream>

using namespace std;

stringstream ss;

double smeech() {
    while (isspace(ss.peek())) ss.get();
    if (ss.peek() == '(') {
        char par;
        ss >> par;
        double p;
        ss >> p;
        double e1 = smeech(), e2 = smeech();
        ss >> par;
        return p*(e1 + e2) + (1-p)*(e1 - e2);
    } else {
        int x;
        ss >> x;
        return x;
    }
}

int main() {
    string s;
    while (getline(cin, s) && s != "()") {
        ss.clear();
        ss << s;
        printf("%.2f\n", smeech());
    }

    return 0;
}
