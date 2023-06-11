#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e6;

int tr[N][26], cnt[N], id;
char s[N];
int n, k;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i <= id; ++i) {
            memset(tr[i], 0, sizeof(tr[i]));
            cnt[i] = 0;
        }
        id = 0;

        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> s + 1;
            int m = strlen(s + 1), rt = 0;
            for (int j = 1; j <= m; ++j) {
                int &p = tr[rt][s[j] - 'a'];
                if (!p) {
                    p = ++id;
                }
                rt = p;
                cnt[p] += 1;
            }
        }
        cnt[0] = n;

        ans.clear();
        int rt = 0;
        while (k > 0) {
            int temp = cnt[rt];
            for (int i = 0; i < 26; ++i) {
                if (!tr[rt][i]) {
                    continue;
                }
                temp -= cnt[tr[rt][i]];
                --k;
                if (!k) {
                    break;
                }
            }
            k -= temp;
            if (k <= 0) {
                break;
            }
            int p = -1;
            for (int i = 0; i < 26; ++i) {
                if (!tr[rt][i] || cnt[tr[rt][i]] == 1) {
                    continue;
                }
                k -= cnt[tr[rt][i]] - 1;
                p = i;
                if (k <= 0) {
                    break;
                }
            }
            if (p == -1) {
                break;
            }
            k += cnt[tr[rt][p]];
            rt = tr[rt][p];
            ans += p + 'a';
            // cout << k << ' ' << ans << endl;
        }
        if (ans.empty()) {
            ans = "EMPTY";
        }
        cout << ans << endl;
    }

    return 0;
}
/*

3 2
pppp
ppp
pppppppppppppppp
*/