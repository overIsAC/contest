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
const int N = 3 + 3e5;

int n, a[N], k;
int pre[N];
int b[N], t, cnt[N];

int ok(LL o) {
    for (int i = 1; i <= t; ++i) {
        cnt[i] = 0;
    }
    priority_queue<int> q;
    int sz = 0;
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        int &p = a[i];
        sum += b[p];
        q.push(p);
        ++cnt[p];
        ++sz;
        while (sum > o) {
            int x = q.top();
            q.pop();
            if (!cnt[x]) {
                continue;
            }
            --sz;
            --cnt[x];
            sum -= b[x];
        }
        pre[i] = sz;
        if (sz >= k) {
            return 1;
        }
    }
    for (int i = 1; i <= t; ++i) {
        cnt[i] = 0;
    }
    q = priority_queue<int>();
    sz = 0;
    sum = 0;
    for (int i = n; i >= 1; --i) {
        int &p = a[i];
        sum += b[p];
        q.push(p);
        ++cnt[p];
        ++sz;
        while (sum > o) {
            int x = q.top();
            q.pop();
            if (!cnt[x]) {
                continue;
            }
            --sz;
            --cnt[x];
            sum -= b[x];
        }
        if (sz + pre[i - 1] >= k) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        LL L = *min_element(a + 1, a + n + 1), R = accumulate(a + 1, a + n + 1, 0LL);
        sort(b + 1, b + n + 1);
        t = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 1; i <= n; ++i) {
            a[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
        }
        while (L < R) {
            LL mid = (L + R) / 2;
            if (ok(mid)) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        cout << R << '\n';
    }
    return 0;
}