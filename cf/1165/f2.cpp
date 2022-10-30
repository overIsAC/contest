#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, a[N];
PII b[N];
int cnt[N];

bool ok(int v) {
    int nn = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = a[i];
        nn += a[i];
    }
    int now = v;
    for (int i = min(m, v); i; --i) {
        now = min(now, b[i].first);
        while (now >= 1 && cnt[b[i].second]) {
            --cnt[b[i].second];
            v -= 1;
            nn -= 1;
            now -= 1;
        }
    }
    return v >= nn * 2;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b + 1, b + 1 + m);
    int l = 1, r = 4e5;
    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
    return 0;
}