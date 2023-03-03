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
pair<int, char> a[N];
int prea[N], preb[N], sufa[N], sufb[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        prea[i] = prea[i - 1];
        preb[i] = preb[i - 1];
        if (a[i].second == '0') {
            ++prea[i];
        } else {
            ++preb[i];
        }
    }
    for (int i = n; i > 0; --i) {
        sufa[i] = sufa[i + 1];
        sufb[i] = sufb[i + 1];
        if (a[i].second == '0') {
            ++sufa[i];
        } else {
            ++sufb[i];
        }
    }
    int ans = max(sufb[1], prea[n]);
    for (int i = 2; i < n; ++i) {
        if (a[i - 1].first == a[i].first) {
            continue;
        }
        ans = max(ans, prea[i - 1] + sufb[i]);
    }
    cout << ans << endl;

        return 0;
}