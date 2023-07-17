#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 2e5;

int n, k;
char s[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<PII> a(n);
        for (auto &[x, y] : a) {
            cin >> x >> y;
        }
        int ans = 0;
        for (int i = 29; i >= 0; --i) {
            int ok = 1;
            for (auto &[x, y] : a) {
                int r = y >> i & 1;
                if (r < 1) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                for (auto &[x, y] : a) {
                    if (y >> i & 1) {
                        y = 1 << i;
                        y = y - 1;
                    }
                }
                continue;
            }
            ans |= 1 << i;
        }
        cout << ans << endl;
    }
    return 0;
}