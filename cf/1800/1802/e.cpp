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
vector<int> a[N];
int p[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            a[i].clear();
            int m, b;
            cin >> m >> b;
            a[i].push_back(b);
            for (int j = 1; j < m; ++j) {
                cin >> b;
                if (b > a[i].back()) {
                    a[i].push_back(b);
                }
            }
            p[i] = i;
        }
        sort(p + 1, p + n + 1, [&](const int &u, const int &v) {
            if (a[u].back() == a[v].back()) {
                return a[u].size() < a[v].size();
            }
            int p1 = a[u].size(), p2 = a[v].size();
            if (!p1 && !p2) {
                return false;
            }
            if (!p1) {
                return true;
            }
            if (!p2) {
                return false;
            }
            if (a[u].back() > a[v].back()) {
                while (p1 >= 1 && a[u][p1 - 1] > a[v].back() ) {
                    --p1;
                }
                return p1 > a[v].size();
            } else {
                while (p2 >= 1 && a[v][p2 - 1] > a[u].back()) {
                    --p2;
                }
                return a[u].size() > p2;
            }
        });

        int ans = 0;
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            cout << "   " << i << endl;
            for (auto &j : a[p[i]]) {
                if (mx < j) {
                    mx = j;
                    ++ans;
                }
                cout << ' ' << j ;
            }
            cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}