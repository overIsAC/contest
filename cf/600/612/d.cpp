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
const int N = 3 + 2e6;

int n, k, l[N], r[N], b[N], t;
int pre[N];
int v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        b[++t] = l[i];
        b[++t] = r[i];
    }
    sort(b + 1, b + t + 1);
    t = unique(b + 1, b + t + 1) - b - 1;
    for (int i = 1; i <= n; ++i) {
        int L = lower_bound(b + 1, b + t + 1, l[i]) - b;
        int R = lower_bound(b + 1, b + t + 1, r[i]) - b;
        ++pre[L];
        --pre[R + 1];
        ++v[R];
    }
    for (int i = 1; i <= t; ++i) {
        pre[i] += pre[i - 1];
    }
    vector<PII> ans;
    for (int i = 1; i <= t; ++i) {
        if (pre[i] < k) {
            continue;
        }
        int j = i;
        while (pre[j] - v[j] >= k && j + 1 <= t && pre[j + 1] >= k) {
            ++j;
        }
        ans.push_back({b[i], b[j]});
        i = j;
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}