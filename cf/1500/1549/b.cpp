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
const int N = 3 + 2e5;

int n, m;

int tr[N];
int cnt[N];
int temp;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == '1') {
                if (i >= 1 && s[i - 1] == '1') {
                    ++ans;
                } else if (s[i] == '0') {
                    ++ans;
                    s[i] = '2';
                } else if (i + 1 < n && s[i + 1] == '1') {
                    ++ans;
                    s[i + 1] = '2';
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}