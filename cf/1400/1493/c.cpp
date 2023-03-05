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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (n % k) {
            cout << -1 << endl;
            continue;
        }
        string t = s;
        sort(t.begin(), t.end());
        bool ok = true;
        for (int i = 0; i < n; i += k) {
            for (int j = i + 1; j < i + k; ++j) {
                if (t[j] != t[j - 1]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << s << endl;
            continue;
        }
        int cnt[26] = {};
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        db("");
        string ans;
        for (int i = n - 1; i >= 0 && ans.empty(); --i) {
            --cnt[s[i] - 'a'];
            for (int z = s[i] + 1; z <= 'z' && ans.empty(); ++z) {
                ++cnt[z - 'a'];
                s[i] = z;
                int temp = 0;
                for (int j = 0; j < 26; ++j) {
                    if (cnt[j] % k == 0) {
                        continue;
                    }
                    temp += k - cnt[j] % k;
                }
                db(temp);
                if (temp <= n - 1 - i) {
                    ans = s.substr(0, i + 1);
                    db(temp);
                    db(ans);
                    string t;
                    for (int j = 0; j < 26; ++j) {
                        if (cnt[j] % k == 0) {
                            continue;
                        }
                        for (int q = 0; q < k - cnt[j] % k; ++q) {
                            t += (char)(j + 'a');
                        }
                    }
                    temp = n - 1 - i - temp;
                    db(t);
                    db(temp);
                    while (temp--) {
                        t += 'a';
                    }
                    sort(t.begin(), t.end());
                    ans += t;
                    break;
                }
                --cnt[z - 'a'];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*

123
4 2
baza
4 2
azaz
4 2
zaab
*/