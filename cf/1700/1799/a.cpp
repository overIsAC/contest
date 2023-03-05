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

int removed[N];
int n, m, p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            removed[i] = -1;
        }
        map<int, int> mp;
        for (int i = 1; i <= m; ++i) {
            int p;
            cin >> p;
            if (!mp[p]) {
                if (n + 1 >= mp.size()) {
                    removed[n - mp.size() + 1] = i;
                }
                mp[p] = i;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << removed[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}