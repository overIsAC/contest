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
const int N = 3 + 2e5;

int n, a[N], m;
char s[N];
set<int> pre[2], dif[N];

int main() {
    cin >> n >> m;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dif[a[i]].insert(i);
        dif[a[i] + m].insert(-i);
    }
    int ans= 0;
    for (int i = 1; i < N; ++i) {
        for (auto &j : dif[i]) {
            int v = j;
            int p = s[abs(v)] == 'R';
            if (v < 0) {
                pre[p].erase(abs(v));
            }else {
                pre[p].insert(v);
            }
        }
        ans += pre[1].empty() && pre[0].size();
    }
    cout << ans << endl;

    return 0;
}