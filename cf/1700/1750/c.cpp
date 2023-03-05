#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
char a[N], b[N];
int pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a + 1 >> b + 1;
        vector<PII> u, v;
        for (int i = 1; i <= n; ++i) {
            int j = i;
            while (j + 1 <= n && a[j + 1] == a[j]) {
                ++j;
            }
            u.push_back({i, j});
            i = j;
        }
        for (int i = 1; i <= n; ++i) {
            int j = i;
            while (j + 1 <= n && b[j + 1] == b[j]) {
                ++j;
            }
            v.push_back({i, j});
            i = j;
        }
        if (u != v) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<PII> ans;
        for (auto& i : u) {
            if (a[i.first] == '1') {
                ans.push_back(i);
                if (1 < i.first) {
                    b[1] ^= 1;
                }
            }
        }
        if (b[1] == '1') {
            ans.push_back({1, 1});
            ans.push_back({2, n});
            ans.push_back({1, n});
        }
        cout << ans.size() << endl;
        for (auto& i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }

    return 0;
}