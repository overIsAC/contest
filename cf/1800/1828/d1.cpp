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
const int N = 3 + 5e3;

int a[N], n, b[N];
int stk[N], top;
int mn[N][N], mx[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            int cnt = a[i];
            for (int j = i; j <= n; ++j) {
                cnt = min(cnt, a[j]);
                mn[i][j] = cnt;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int cnt = a[i];
            for (int j = i; j <= n; ++j) {
                cnt = max(cnt, a[j]);
                mx[i][j] = cnt;
            }
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            top = 0;
            vector<PII> ve;
            int cnt = 0;

            auto fixed = [&]() {
                while (ve.size() > 1) {
                    auto v = ve.back();
                    ve.pop_back();
                    auto u = ve.back();
                    ve.pop_back();
                    cnt -= u.second - u.first;
                    cnt -= v.second - v.first;
                    if (u.second >= v.first) {
                        ve.push_back({min(u.first, v.first), max(u.second, v.second)});
                        cnt += max(u.second, v.second) - min(u.first, v.first);
                        continue;
                    }
                    if (mx[u.first][u.second] >= mn[v.first][v.second]) {
                        ve.push_back({min(u.first, v.first), max(u.second, v.second)});
                        cnt += max(u.second, v.second) - min(u.first, v.first);
                        continue;
                    }
                    ve.push_back(u);
                    ve.push_back(v);
                    cnt += u.second - u.first;
                    cnt += v.second - v.first;
                    break;
                }
            };

            for (int j = i; j <= n; ++j) {
                int l = j, r = j;
                while (top && a[stk[top]] > a[j]) {
                    l = stk[top];
                    --top;
                }
                ve.push_back({l, r});
                cnt += r - l;
                fixed();
                ans += cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}