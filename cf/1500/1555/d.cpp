#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
char s[N];

int main() {
    vector<vector<int>> pre;
    string t = "abc";
    cin >> n >> m >> s + 1;
    do {
        pre.push_back({0});
        auto &p = pre.back();
        for (int i = 1; i <= n; ++i) {
            p.push_back(p.back() + (s[i] != t[i % 3]));
        }
    } while (next_permutation(t.begin(), t.end()));
    while (m--) {
        int ans = 1e9;
        int l, r;
        cin >> l >> r;
        for (auto &p : pre) {
            ans = min(ans, p[r] - p[l - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}