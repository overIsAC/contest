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

int n, a[N];
vector<int> edge[N];
int du[N];
bool vis[N];
int sz[N];

int valid(int x) {
    return 0 < x && x <= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            du[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int x = i, y = a[i] + i;
            if (valid(y)) {
                edge[x].push_back(y);
                ++du[y];
            }
            sz[x] = 1;
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!du[i]) {
                q.push(i);
            }
        }
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int &y : edge[x]) {
                sz[y] += sz[x];
                if (!--du[y]) {
                    q.push(y);
                }
            }
        }
        int now = 1;
        LL ans = 0;
        LL step = 0;
        while (valid(now) && du[now] == 0) {
            ++step;
            ans += sz[now];
            now = a[now] + now;
        }
        LL circle = 0;
        for (int i = 1; i <= n; ++i) {
            if (du[i]) {
                circle += sz[i];
            }
            db(du[i]);
        }
        if (valid(now) && du[now]) {
            int p = now;
            if (p == a[p] + p) {
                db(circle);
                db(ans);
                db(step);
                ans += (circle - sz[p]) * (step + 1);
                // cout << " " << ans << endl;
                ans += sz[p];
                // cout << " " << ans << endl;
                ans += (LL)(n - (step + 1)) * (2 * n + 1);
                ans += step;
                // cout << " " << ans << endl;
                // cout << "???" << endl;
                db("");
            } else {
                db(now);
                db(step);
                do {
                    ++step;
                    now = a[now] + now;
                } while (p != now);
                db(step);
                db(circle);
                ans = circle * step;
                ans += (n - step) * (2 * n + 1);
                db("");
            }
        } else {
            db("");
            ans += circle * step;
        }
        cout << (LL)(2 * n + 1) * n - ans << endl;
    }
    return 0;
}