#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k;
string s;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s;
        int ans = n;
        int cnt = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            cnt += s[i] == 'W';
            if (i - j + 1 > k) {
                cnt -= s[j] == 'W';
                ++j;
            }
            if (i - j + 1 == k) {
                ans = min(ans, cnt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}