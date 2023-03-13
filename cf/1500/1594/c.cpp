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

int n;
char s[N], c;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c;
        cin >> s + 1;
        vector<int> ans;
        if (s[n] != c) {
            int p = 0;
            for (int i = 2; i < n; ++i) {
                if (n % i == 0) {
                    continue;
                }
                bool ok = true;
                for (int j = i; j <= n; j += i) {
                    if (s[j] != c) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    p = i;
                }
            }
            if (!p) {
                p = n - 1;
            }
            ans.push_back(p);
            for (int i = 1; i <= n; ++i) {
                if (i % p) {
                    s[i] = c;
                }
            }
        }
        if (count(s + 1, s + n + 1, c) != n) {
            ans.push_back(n);
        }
        cout << ans.size() << '\n';
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}