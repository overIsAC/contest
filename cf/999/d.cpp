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
vector<int> ve[N];
vector<int> cache;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ve[a[i] % m].push_back(i);
    }

    int q = n / m;
    LL ans = 0;
    for (int i = 0; i < m; ++i) {
        while (ve[i].size() > q) {
            cache.push_back(ve[i].back());
            ve[i].pop_back();
        }
        while (ve[i].size() < q && cache.size()) {
            int p = cache.back();
            cache.pop_back();
            int w = (i - a[p]) % m;
            w = (w + m) % m;
            ans += w;
            a[p] += w;
            ve[i].push_back(p);
        }
    }
    for (int i = 0; i < m; ++i) {
        while (ve[i].size() < q) {
            int p = cache.back();
            cache.pop_back();
            int w = (i - a[p]) % m;
            w = (w + m) % m;
            ans += w;
            a[p] += w;
            ve[i].push_back(p);
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}