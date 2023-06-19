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
const int N = 3 + 2e5;

int n;
PII a[N];
int pre[N], suf[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    pre[1] = 1;
    pre[2] = 1;
    for (int i = 3; i <= n; ++i) {
        if (pre[i - 1] && 2 * a[i - 1].first == a[i - 2].first + a[i].first) {
            pre[i] = 1;
        }
    }
    suf[n] = 1;
    suf[n - 1] = 1;
    for (int i = n - 2; i >= 1; --i) {
        if (suf[i + 1] && 2 * a[i + 1].first == a[i + 2].first + a[i].first) {
            suf[i] = 1;
        }
    }
    if (n <= 3) {
        cout << a[2].second << endl;
        return 0;
    }
    if (suf[2]) {
        cout << a[1].second << endl;
        return 0;
    }
    if (pre[n - 1]) {
        cout << a[n].second << endl;
        return 0;
    }
    for (int i = 2; i < n; ++i) {
        int d1 = a[i - 1].first - a[i - 2].first;
        int d2 = a[i + 2].first - a[i + 1].first;
        int d3 = a[i + 1].first - a[i - 1].first;
        if (i - 2 >= 1 && (d1 != d3 || !pre[i - 1])) {
            continue;
        }
        if (i + 2 <= n && (d2 != d3 || !suf[i + 1])) {
            continue;
        }
        cout << a[i].second << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}