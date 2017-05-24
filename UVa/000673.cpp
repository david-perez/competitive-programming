#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n; cin.get();
    while (n--) {
        stack<char> st;
        bool ok = true;
        
        getline(cin, s);
        for (char &c : s) {
            if (c == '(' || c == '[') st.push(c);
            else if (st.empty() || (st.top() == '(' && c == ']') || (st.top() == '[' && c == ')')) {
                ok = false;
                break;
            } else st.pop();
        }
        
        cout << (ok && st.empty() ? "Yes" : "No") << endl;
    }
    
    return 0;
}
