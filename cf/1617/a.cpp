#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

map<char, int> id;

int main() {
    int T;
    cin >> T;
    for (int i = 'a'; i <= 'z'; ++i) {
        id[i] = i - 'a';
    }
    while (T--) {
        string s, t;
        cin >> s >> t;
        set<char> ss(s.begin(), s.end());
        set<char> tt(t.begin(), t.end());
        set<char> sss = ss;
        sss.insert(tt.begin(), tt.end());
        if (ss.size() == sss.size() && is_sorted(t.begin(), t.end())) {
            id['b'] = 2;
            id['c'] = 1;
        } else {
            id['b'] = 1;
            id['c'] = 2;
        }
        sort(s.begin(), s.end(),
             [](const char& a, const char& b) { return id[a] < id[b]; });
        cout << s << endl;
    }
    return 0;
}