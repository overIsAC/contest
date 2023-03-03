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
const int N = 3 + 1e5;

int n, m, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> u, v;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (i + m <= n || i - m >= 1) {
                u.push_back(i);
                v.push_back(i);
            }
        }
        sort(u.begin(), u.end(), [&](const int &x, const int &y) {
            return a[x] < a[y];
        });
        for (int i = 0; i < u.size(); ++i) {
            u[i] = a[u[i]];
        }
        for (int i = 0; i < u.size(); ++i) {
            a[v[i]] = u[i];
        }
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i + 1]) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}