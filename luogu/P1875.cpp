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
const int N = 3 + 1e5;

LL d[N], dd[N];
LL cnt[N];
int n, u[N], v[N], w[N];
int m;
int p[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        dd[i] = d[i];
    }
    while (true) {
        ++m;
        if (cin >> u[m] >> v[m] >> w[m]) {
        } else {
            --m;
            break;
        }
    }
    while (true) {
        int flag = 0;
        for (int i = 1; i <= m; ++i) {
            if (d[w[i]] > d[u[i]] + d[v[i]]) {
                d[w[i]] = d[u[i]] + d[v[i]];
                flag = 1;
            }
        }
        if (!flag) {
            break;
        }
    }

    cout << d[0] << ' ';
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    sort(p, p + n, [&](int a, int b) {
        return d[a] < d[b];
    });
    for (int i = 0; i < n; ++i) {
        int x = p[i];
        if (dd[x] == d[x]) {
            ++cnt[x];
        }
        for (int j = 1; j <= m; ++j) {
            if (w[j] == x) {
                if (d[w[j]] == d[u[j]] + d[v[j]]) {
                    cnt[w[j]] += cnt[u[j]] * cnt[v[j]];
                }
            }
        }
    }
    cout << cnt[0] << endl;

    return 0;
}