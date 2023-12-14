#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string s;
vector<int> ans;

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        string t;
        cin >> t;
        if (s == t) {
            ans.push_back(i);
            continue;
        }
        int p = 0;
        while (p < s.size() && p < t.size() && s[p] == t[p]) {
            ++p;
        }
        int x = p + 1, y = p + 1;
        while (x < s.size() && y < t.size() && s[x] == t[y]) {
            ++x;
            ++y;
        }
        if (x == s.size() && y == t.size()) {
            ans.push_back(i);
            continue;
        }
        x = p, y = p + 1;
        while (x < s.size() && y < t.size() && s[x] == t[y]) {
            ++x;
            ++y;
        }
        if (x == s.size() && y == t.size()) {
            ans.push_back(i);
            continue;
        }
        x = p + 1, y = p;
        while (x < s.size() && y < t.size() && s[x] == t[y]) {
            ++x;
            ++y;
        }
        if (x == s.size() && y == t.size()) {
            ans.push_back(i);
            continue;
        }
    }
    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << ' ';
    }

    return 0;
}