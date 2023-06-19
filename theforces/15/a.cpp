#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

string t[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        assert(s.size() <= 1e5);
        map<char, int> mp;
        int mx = 0;
        for (auto &i : s) {
            ++mp[i];
            t[mp[i]] += i;
            mx = max(mx, mp[i]);
        }
        int p = 1;
        for (int i = 1; i <= mx; ++i) {
            if (t[p].size() >= t[i].size()) {
                p = i;
            }
        }
        cout << t[p] << endl;
        for (int i = 1; i <= mx; ++i) {
            t[i] = "";
        }
    }
    return 0;
}