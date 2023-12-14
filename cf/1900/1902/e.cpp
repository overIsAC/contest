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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n;
string s[N];
int tr[N][26], cnt[N], id;
LL sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];

        int rt = 0;

        for (auto& j : s[i]) {
            int& p = tr[rt][j - 'a'];
            if (!p) {
                p = ++id;
            }
            ++cnt[p];
            sum[p] += s[i].size();

            rt = p;
        }
        cnt[0] += 1;
        sum[0] += s[i].size();
    }
    for (int i = 0; i < n; ++i) {
        reverse(s[i].begin(), s[i].end());
        int x = 0;
        int flag = 1;
        int rt = 0;
        for (auto& j : s[i]) {
            int u = 0;
            LL v = 0;
            for (int k = 0; k < 26; ++k) {
                if (tr[rt][k]) {
                    u += cnt[tr[rt][k]];
                    v += sum[tr[rt][k]];
                }
            }

            ans += (LL)(cnt[rt] - u) * (s[i].size() - x);

            if (tr[rt][j - 'a']) {
                u -= cnt[tr[rt][j - 'a']];
                v -= sum[tr[rt][j - 'a']];
            }
            ans += (LL)u * s[i].size() + v;
            ans -= (LL)x * u * 2;

            ++x;

            int& p = tr[rt][j - 'a'];
            if (!p) {
                flag = 0;
                break;
            }

            rt = p;
        }
        if (flag) {
            int u = 0;
            LL v = 0;
            for (int k = 0; k < 26; ++k) {
                if (tr[rt][k]) {
                    u += cnt[tr[rt][k]];
                    v += sum[tr[rt][k]];
                }
            }
            ans += (LL)u * s[i].size() + v;
            ans -= (LL)s[i].size() * u * 2;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}

/*
a

baba

*/