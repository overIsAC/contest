#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

string s, t;
map<int, multiset<string> > mp;
int n;

int main() {
    cin >> s >> n;
    while (n--) {
        cin >> t;
        if (t.size() != s.size()) {
            mp[0].insert(t);
        } else {
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                cnt += s[i] == t[i];
            }
            mp[cnt].insert(t);
        }
    }
    for (auto &i : mp.rbegin()->second) {
        cout << i << endl;
    }
    return 0;
}